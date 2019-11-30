# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
cmake_minimum_required(VERSION 3.10)

function(eagine_example_common EXAMPLE_NAME)
	add_executable("${EXAMPLE_NAME}" "${EXAMPLE_NAME}.cpp")
	target_link_libraries("${EXAMPLE_NAME}" eagine)
endfunction()

eagine_example_common(base64)
