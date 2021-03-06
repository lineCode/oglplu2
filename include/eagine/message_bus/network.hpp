/**
 *  @file eagine/message_bus/network.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MESSAGE_BUS_NETWORK_HPP
#define EAGINE_MESSAGE_BUS_NETWORK_HPP

#include "../from_string.hpp"
#include <string>
#include <tuple>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
// IPv4
//------------------------------------------------------------------------------
using ipv4_port = unsigned short int;
static inline std::tuple<std::string, ipv4_port> parse_ipv4_addr(
  string_view addr_str) {
    auto [hostname, port_str] = split_by_last(
      addr_str ? addr_str : string_view{"localhost"}, string_view(":"));
    return {
      to_string(hostname),
      extract_or(from_string<ipv4_port>(port_str), ipv4_port{34912U})};
}
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_NETWORK_HPP

