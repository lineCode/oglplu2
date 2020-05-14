#!/bin/bash
# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
install_prefix="$(<$(dirname ${0})/../INSTALL_PREFIX)"
log_args=("--use-asio-log" "--min-log-severity" "info")
conn_type="--msg-bus-asio-local-stream"
#
pids=()
#
${install_prefix}/bin/eagine-message_bus-router \
	"${log_args[@]}" \
	${conn_type} \
	& pids+=($!)
sleep 1
${install_prefix}/share/oglplus/examples/eagine-003_pong \
	"${log_args[@]}" \
	${conn_type} \
	& pids+=($!)
sleep 1
${install_prefix}/share/oglplus/examples/eagine-003_ping \
	"${log_args[@]}" \
	--ping-count 1M \
	${conn_type} \
	& pids+=($!)

for pid in ${pids[@]}
do wait ${pid}
done
