/**
 *  @file eagine/message_bus/router.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MESSAGE_BUS_ROUTER_HPP
#define EAGINE_MESSAGE_BUS_ROUTER_HPP

#include "../flat_map.hpp"
#include "../logging/logger.hpp"
#include "../program_args.hpp"
#include "../timeout.hpp"
#include "../valid_if/positive.hpp"
#include "acceptor.hpp"
#include "blobs.hpp"
#include "context_fwd.hpp"
#include <map>
#include <vector>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
struct router_pending {

    router_pending(std::unique_ptr<connection> a_connection)
      : the_connection{std::move(a_connection)} {
    }

    std::chrono::steady_clock::time_point create_time{
      std::chrono::steady_clock::now()};

    std::unique_ptr<connection> the_connection{};

    auto age() const {
        return std::chrono::steady_clock::now() - create_time;
    }
};
//------------------------------------------------------------------------------
struct routed_endpoint {
    std::vector<std::unique_ptr<connection>> connections{};
    std::vector<message_id> message_block_list{};
    std::vector<message_id> message_allow_list{};
    bool maybe_router{true};
    bool do_disconnect{false};

    routed_endpoint();
    routed_endpoint(routed_endpoint&&) noexcept = default;
    routed_endpoint(const routed_endpoint&) = default;
    routed_endpoint& operator=(routed_endpoint&&) noexcept = default;
    routed_endpoint& operator=(const routed_endpoint&) = default;
    ~routed_endpoint() noexcept = default;

    void block_message(message_id);
    void allow_message(message_id);

    bool is_allowed(message_id) const noexcept;
};
//------------------------------------------------------------------------------
class router
  : public acceptor_user
  , public connection_user {
public:
    router() = default;

    router(logger& parent) noexcept
      : _log(EAGINE_ID(MsgBusRutr), parent)
      , _context{make_context(_log)} {
    }

    router(logger& parent, const program_args& args) noexcept
      : _log(EAGINE_ID(MsgBusRutr), parent)
      , _context{make_context(_log, args)} {
        _setup_from_args(args);
    }

    void add_certificate_pem(memory::const_block blk);
    void add_ca_certificate_pem(memory::const_block blk);

    bool add_acceptor(std::unique_ptr<acceptor>) final;
    bool add_connection(std::unique_ptr<connection>) final;

    bool update(const valid_if_positive<int>& count);
    bool update() {
        return update(2);
    }

    auto& no_connection_timeout() const noexcept {
        return _no_connection_timeout;
    }

    bool is_done() const noexcept {
        return bool(no_connection_timeout());
    }

    void post_blob(
      message_id msg_id,
      identifier_t source_id,
      identifier_t target_id,
      memory::const_block blob,
      std::chrono::seconds max_time,
      message_priority priority) {
        _blobs.push_outgoing(
          msg_id, source_id, target_id, blob, max_time, priority);
    }

private:
    void _setup_from_args(const program_args&);

    bool _handle_accept();
    bool _handle_pending();
    bool _remove_timeouted();
    bool _remove_disconnected();
    void _assign_id(std::unique_ptr<connection>& conn);
    void _handle_connection(std::unique_ptr<connection> conn);

    bool _cleanup_blobs();
    bool _process_blobs();
    bool _do_allow_blob(message_id);
    bool _handle_blob(message_id msg_id, const message_view&);

    bool _handle_special(
      message_id msg_id,
      identifier_t incoming_id,
      routed_endpoint&,
      const message_view&);

    bool _do_route_message(
      message_id msg_id, identifier_t incoming_id, message_view message);

    bool _route_messages();
    bool _update_connections();

    logger _log{};
    shared_context _context{};
    const std::chrono::seconds _pending_timeout{30};
    timeout _no_connection_timeout{std::chrono::seconds{30}};
    identifier_t _id_sequence{0};
    std::intmax_t _forwarded_messages{0};
    std::vector<std::unique_ptr<acceptor>> _acceptors;
    std::vector<std::unique_ptr<connection>> _connectors;
    std::vector<router_pending> _pending;
    flat_map<identifier_t, routed_endpoint> _endpoints;
    blob_manipulator _blobs{};
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/message_bus/router.inl>
#endif

#endif // EAGINE_MESSAGE_BUS_ROUTER_HPP

