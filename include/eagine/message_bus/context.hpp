/**
 *  @file eagine/message_bus/context.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MESSAGE_BUS_CONTEXT_HPP
#define EAGINE_MESSAGE_BUS_CONTEXT_HPP

#include "../memory/buffer.hpp"
#include "../message_id.hpp"
#include "../ssl.hpp"
#include "../ssl_api.hpp"
#include "context_fwd.hpp"
#include "types.hpp"
#include <map>

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
class context {
public:
    context(logger& parent);
    context(logger& parent, const program_args& args);

    context(context&&) = delete;
    context(const context&) = delete;
    context& operator=(context&&) = delete;
    context& operator=(const context&) = delete;

    ~context() noexcept;

    message_sequence_t next_sequence_no(
      identifier_t class_id, identifier_t method_id) noexcept;

    void add_node_certificate_pem(memory::const_block);
    void add_ca_certificate_pem(memory::const_block);

    memory::const_block get_node_certificate_pem() const noexcept {
        return view(_node_cert_pem);
    }

    memory::const_block get_ca_certificate_pem() const noexcept {
        return view(_ca_cert_pem);
    }

private:
    logger _log{};
    //
    std::map<message_id_tuple, message_sequence_t> _msg_id_seq{};
    //
    memory::buffer _node_cert_pem{};
    memory::buffer _ca_cert_pem{};
    //
    sslp::ssl_api _ssl{};
    sslp::owned_engine _ssl_engine{};
    sslp::owned_x509_store _ssl_store{};
    sslp::owned_x509 _node_cert{};
    sslp::owned_x509 _ca_cert{};
};
//------------------------------------------------------------------------------
} // namespace msgbus
} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/message_bus/context.inl>
#endif

#endif // EAGINE_MESSAGE_BUS_CONTEXT_HPP

