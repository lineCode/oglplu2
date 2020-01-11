/**
 *  @file eagine/msg_bus/serialize.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MSG_BUS_SERIALIZE_HPP
#define EAGINE_MSG_BUS_SERIALIZE_HPP

#include "../extract.hpp"
#include "../serialize/read.hpp"
#include "../serialize/write.hpp"
#include "message.hpp"

namespace eagine {
//------------------------------------------------------------------------------
template <typename Backend>
std::enable_if_t<
  std::is_base_of_v<serializer_backend, Backend>,
  serialization_result>
serialize_message(
  identifier_t class_id,
  identifier_t method_id,
  const message_view& msg,
  Backend& backend) {

    auto message_params = std::make_tuple(
      identifier(class_id), identifier(method_id), msg.priority);
    serialization_result errors = serialize(message_params, backend);

    if(!errors) {
        if(auto sink = backend.sink()) {
            errors |= extract(sink).write(msg.data);
        } else {
            errors |= serialization_error_code::backend_error;
        }
    }

    return errors;
}
//------------------------------------------------------------------------------
template <identifier_t ClassId, identifier_t MethodId, typename Backend>
std::enable_if_t<
  std::is_base_of_v<serializer_backend, Backend>,
  serialization_result>
serialize_message(
  message_id<ClassId, MethodId>, const message_view& msg, Backend& backend) {
    return serialize_message(ClassId, MethodId, msg, backend);
}
//------------------------------------------------------------------------------
template <typename Backend>
std::enable_if_t<
  std::is_base_of_v<deserializer_backend, Backend>,
  deserialization_result>
deserialize_message(
  identifier_t& class_id,
  identifier_t& method_id,
  stored_message& msg,
  Backend& backend) {
    std::tuple<identifier, identifier, message_priority> message_params{};
    deserialization_result errors = deserialize(message_params, backend);

    if(!errors) {
        class_id = std::get<0>(message_params).value();
        method_id = std::get<1>(message_params).value();
        msg.priority = std::get<2>(message_params);
        if(auto source = backend.source()) {
            msg.data.clear();
            extract(source).fetch_all(msg.data);
        } else {
            errors |= deserialization_error_code::backend_error;
        }
    }

    return errors;
}
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_MSG_BUS_SERIALIZE_HPP

