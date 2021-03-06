/**
 *  @file eagine/message_bus/actor.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MESSAGE_BUS_ACTOR_HPP
#define EAGINE_MESSAGE_BUS_ACTOR_HPP

#include "subscriber.hpp"

namespace eagine::msgbus {
//------------------------------------------------------------------------------
template <
  std::size_t N,
  template <std::size_t> class Subscriber = static_subscriber>
class actor
  : public connection_user
  , public friend_of_endpoint {
    using friend_of_endpoint::_accept_message;
    using friend_of_endpoint::_make_endpoint;
    using friend_of_endpoint::_move_endpoint;

protected:
    bool _process_message(message_id msg_id, const message_view& message) {
        if(!_accept_message(_endpoint, msg_id, message)) {
            if(!is_special_message(msg_id)) {
                _endpoint.block_message_type(msg_id);
            }
        }
        return true;
    }

    template <
      typename Class,
      typename... MsgMaps,
      typename = std::enable_if_t<sizeof...(MsgMaps) == N>>
    actor(logger log, Class* instance, MsgMaps... msg_maps)
      : _endpoint{_make_endpoint(
          std::move(log), {this, EAGINE_MEM_FUNC_C(actor, _process_message)})}
      , _subscriber{_endpoint, instance, msg_maps...} {
        _endpoint.say_not_a_router();
        _subscriber.announce_subscriptions();
    }

    template <
      typename Derived,
      typename Class,
      typename... MsgMaps,
      typename = std::enable_if_t<
        (sizeof...(MsgMaps) == N) && std::is_base_of_v<actor, Derived>>>
    actor(Derived&& temp, Class* instance, MsgMaps... msg_maps) noexcept
      : _endpoint{_move_endpoint(
          std::move(temp._endpoint),
          {this, EAGINE_MEM_FUNC_C(actor, _process_message)})}
      , _subscriber{_endpoint, instance, msg_maps...} {
    }

    ~actor() noexcept override {
        try {
            _subscriber.retract_subscriptions();
            _endpoint.finish();
        } catch(...) {
        }
    }

public:
    actor(actor&&) = delete;
    actor(const actor&) = delete;
    actor& operator=(actor&&) = delete;
    actor& operator=(const actor&) = delete;

    endpoint& bus() noexcept {
        return _endpoint;
    }

    logger& log() noexcept {
        return _endpoint.log();
    }

    bool add_connection(std::unique_ptr<connection> conn) final {
        return _endpoint.add_connection(std::move(conn));
    }

    void allow_subscriptions() {
        _subscriber.allow_subscriptions();
    }

    void process_one() {
        _endpoint.update();
        _subscriber.process_one();
    }

    void process_all() {
        _endpoint.update();
        _subscriber.process_all();
    }

private:
    endpoint _endpoint;
    Subscriber<N> _subscriber;
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_ACTOR_HPP

