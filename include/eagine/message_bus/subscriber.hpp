/**
 *  @file eagine/message_bus/subscriber.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MESSAGE_BUS_SUBSCRIBER_HPP
#define EAGINE_MESSAGE_BUS_SUBSCRIBER_HPP

#include "../maybe_unused.hpp"
#include "endpoint.hpp"
#include <array>
#include <type_traits>

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
template <typename MessageId, typename MemFuncConst>
struct message_handler_map {};
//------------------------------------------------------------------------------
#define EAGINE_MSG_MAP(CLASS_ID, METHOD_ID, CLASS, METHOD) \
    eagine::msgbus::message_handler_map<                   \
      EAGINE_MSG_TYPE(CLASS_ID, METHOD_ID),                \
      EAGINE_MEM_FUNC_T(CLASS, METHOD)>()
//------------------------------------------------------------------------------
template <std::size_t N>
class subscriber {
public:
    using handler_type = typename endpoint::handler_type;

protected:
    template <
      identifier_t ClassId,
      identifier_t MethodId,
      typename Class,
      bool (Class::*HandlerFunc)(stored_message&)>
    static constexpr inline std::tuple<identifier_t, identifier_t, handler_type>
    as_tuple(
      Class* instance,
      message_handler_map<
        message_id<ClassId, MethodId>,
        member_function_constant<
          bool (Class::*)(stored_message&),
          HandlerFunc>>) noexcept {
        return {ClassId,
                MethodId,
                handler_type{instance,
                             member_function_constant<
                               bool (Class::*)(stored_message&),
                               HandlerFunc>{}}};
    }

    template <
      identifier_t ClassId,
      identifier_t MethodId,
      typename Class,
      bool (Class::*HandlerFunc)(stored_message&) const>
    static constexpr inline std::tuple<identifier_t, identifier_t, handler_type>
    as_tuple(
      const Class* instance,
      message_handler_map<
        message_id<ClassId, MethodId>,
        member_function_constant<
          bool (Class::*)(stored_message&) const,
          HandlerFunc>>) noexcept {
        return {ClassId,
                MethodId,
                handler_type{instance,
                             member_function_constant<
                               bool (Class::*)(stored_message&) const,
                               HandlerFunc>{}}};
    }

public:
    template <
      typename... MsgHandlers,
      typename = std::enable_if_t<sizeof...(MsgHandlers) == N>>
    subscriber(endpoint& bus, MsgHandlers&&... msg_handlers)
      : _endpoint{&bus}
      , _msg_handlers{{std::forward<MsgHandlers>(msg_handlers)...}} {
        _subscribe();
    }

    template <
      typename Class,
      typename... MsgMaps,
      typename = std::enable_if_t<sizeof...(MsgMaps) == N>>
    subscriber(endpoint& bus, Class* instance, MsgMaps... msg_maps)
      : subscriber(bus, as_tuple(instance, msg_maps)...) {
    }

    subscriber(subscriber&& temp) = delete;
    subscriber(const subscriber&) = delete;
    subscriber& operator=(subscriber&&) = delete;
    subscriber& operator=(const subscriber&) = delete;

    ~subscriber() noexcept {
        _unsubscribe();
    }

    explicit operator bool() noexcept {
        return _endpoint != nullptr;
    }

    bool operator!() noexcept {
        return _endpoint == nullptr;
    }

    endpoint& bus() noexcept {
        EAGINE_ASSERT(_endpoint != nullptr);
        return *_endpoint;
    }

    const endpoint& bus() const noexcept {
        EAGINE_ASSERT(_endpoint != nullptr);
        return *_endpoint;
    }

    bool process_one() {
        for(auto& [class_id, method_id, handler] : _msg_handlers) {
            if(bus().process_one(class_id, method_id, handler)) {
                return true;
            }
        }
        return false;
    }

    span_size_t process_all() {
        span_size_t result{0};
        for(auto& [class_id, method_id, handler] : _msg_handlers) {
            result += bus().process_all(class_id, method_id, handler);
        }
        return result;
    }

    void announce_subscriptions() {
        if(_endpoint) {
            for(auto& [class_id, method_id, unused] : _msg_handlers) {
                EAGINE_MAYBE_UNUSED(unused);
                _endpoint->say_subscribes_to(class_id, method_id);
            }
        }
    }

    void allow_subscriptions() {
        if(_endpoint) {
            for(auto& [class_id, method_id, unused] : _msg_handlers) {
                EAGINE_MAYBE_UNUSED(unused);
                _endpoint->allow_message_type(class_id, method_id);
            }
        }
    }

    void retract_subscriptions() {
        if(_endpoint) {
            for(auto& [class_id, method_id, unused] : _msg_handlers) {
                EAGINE_MAYBE_UNUSED(unused);
                _endpoint->say_unsubscribes_from(class_id, method_id);
            }
        }
    }

private:
    endpoint* _endpoint{nullptr};
    std::array<const std::tuple<identifier_t, identifier_t, handler_type>, N>
      _msg_handlers;

    void _subscribe() {
        if(_endpoint) {
            for(auto& [class_id, method_id, unused] : _msg_handlers) {
                EAGINE_MAYBE_UNUSED(unused);
                _endpoint->subscribe(class_id, method_id);
            }
        }
    }

    void _unsubscribe() noexcept {
        if(_endpoint) {
            for(auto& [class_id, method_id, unused] : _msg_handlers) {
                try {
                    EAGINE_MAYBE_UNUSED(unused);
                    _endpoint->unsubscribe(class_id, method_id);
                } catch(...) {
                }
            }
        }
    }
};
//------------------------------------------------------------------------------
} // namespace msgbus
} // namespace eagine

#endif // EAGINE_MESSAGE_BUS_SUBSCRIBER_HPP

