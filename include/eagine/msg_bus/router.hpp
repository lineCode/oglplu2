/**
 *  @file eagine/msg_bus/router.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MSG_BUS_ROUTER_HPP
#define EAGINE_MSG_BUS_ROUTER_HPP

#include "../branch_predict.hpp"
#include "acceptor.hpp"
#include <map>
#include <vector>

namespace eagine {
//------------------------------------------------------------------------------
struct message_bus_router_pending {

    message_bus_router_pending(std::unique_ptr<message_bus_connection> conn)
      : connection{std::move(conn)} {
    }

    std::chrono::steady_clock::time_point create_time{
      std::chrono::steady_clock::now()};
    std::unique_ptr<message_bus_connection> connection;

    auto age() const {
        return std::chrono::steady_clock::now() - create_time;
    }
};
//------------------------------------------------------------------------------
struct message_bus_routed_endpoint {
    std::vector<std::unique_ptr<message_bus_connection>> connections;
};
//------------------------------------------------------------------------------
class message_bus_router {
public:
    bool add_acceptor(std::unique_ptr<message_bus_acceptor> acceptor) {
        if(acceptor) {
            _acceptors.emplace_back(std::move(acceptor));
            return true;
        }
        return false;
    }

    void update() {
        _remove_timeouted();
        _remove_disconnected();
        _handle_pending();
        _handle_accept();
        _route_messages();
    }

private:
    void _handle_accept() {
        if(EAGINE_LIKELY(!_acceptors.empty())) {
            message_bus_acceptor::accept_handler handler{
              this, EAGINE_MEM_FUNC_C(message_bus_router, _handle_connection)};
            for(auto& acceptor : _acceptors) {
                EAGINE_ASSERT(acceptor);
                acceptor->process_accepted(handler);
            }
        }
    }

    void _handle_pending() {

        if(!_pending.empty()) {
            identifier_t id = 0;
            auto handler = [&id](
                             identifier_t class_id,
                             identifier_t method_id,
                             const message_view&) {
                // this is a special message containing endpoint id
                if(class_id == 0) {
                    id = method_id;
                    return true;
                }
                return false;
            };

            std::size_t pos = 0;
            while(pos < _pending.size()) {
                id = 0;
                auto& pending = _pending[pos];
                pending.connection->fetch_messages(
                  message_bus_connection::fetch_handler(handler));
                // if we got the endpoint id message from the connection
                if(id != 0) {
                    _endpoints[id].connections.emplace_back(
                      std::move(pending.connection));
                    _pending.erase(_pending.begin() + pos);
                } else {
                    ++pos;
                }
            }
        }
    }

    void _remove_timeouted() {
        _pending.erase(
          std::remove_if(
            _pending.begin(),
            _pending.end(),
            [this](auto& pending) {
                return pending.age() > this->_pending_timeout;
            }),
          _pending.end());
    }

    void _remove_disconnected() {
        for(auto& p : _endpoints) {
            auto& conns = std::get<1>(p).connections;
            conns.erase(
              std::remove_if(
                conns.begin(),
                conns.end(),
                [](auto& conn) { return !conn || !conn->is_usable(); }),
              conns.end());
        }
        auto it = _endpoints.begin();
        while(it != _endpoints.end()) {
            if(it->second.connections.empty()) {
                _endpoints.erase(it++);
            } else {
                ++it;
            }
        }
    }

    void _handle_connection(std::unique_ptr<message_bus_connection> conn) {
        EAGINE_ASSERT(conn);
        // find a currently unused endpoint id value
        ++_id_sequence;
        while(!_id_sequence ||
              (_endpoints.find(_id_sequence) != _endpoints.end())) {
            ++_id_sequence;
        }
        // send the special message assigning the endpoint id
        conn->send(0, _id_sequence, {});
        _pending.emplace_back(std::move(conn));
    }

    void _route_messages() {
        for(auto& [id_in, endpoint_in] : _endpoints) {
            auto handler = [this, id_in](
                             identifier_t class_id,
                             identifier_t method_id,
                             const message_view& message) {
                for(auto& [id_out, endpoint_out] : this->_endpoints) {
                    if(id_in != id_out) {
                        for(auto& conn_out : endpoint_out.connections) {
                            if(EAGINE_LIKELY(
                                 conn_out && conn_out->is_usable())) {
                                if(conn_out->send(
                                     class_id, method_id, message)) {
                                    break;
                                }
                            }
                        }
                    }
                }
                return true;
            };

            for(auto& conn_in : endpoint_in.connections) {
                if(EAGINE_LIKELY(conn_in && conn_in->is_usable())) {
                    conn_in->fetch_messages(
                      message_bus_connection::fetch_handler(handler));
                }
            }
        }
    }

    const std::chrono::seconds _pending_timeout{10};
    identifier_t _id_sequence{0};
    std::vector<std::unique_ptr<message_bus_acceptor>> _acceptors;
    std::vector<message_bus_router_pending> _pending;
    std::map<identifier_t, message_bus_routed_endpoint> _endpoints;
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_MSG_BUS_ROUTER_HPP
