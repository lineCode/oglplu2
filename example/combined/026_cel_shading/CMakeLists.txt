# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
add_custom_command(
	OUTPUT example.oglpprog
	COMMAND oglplus-bake_program_source
		--vertex vertex.glsl
		--geometry geometry.glsl
		--fragment fragment.glsl
		--output "${CMAKE_CURRENT_BINARY_DIR}/example.oglpprog"
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
	DEPENDS oglplus-bake_program_source vertex.glsl geometry.glsl fragment.glsl
)
set_source_files_properties(
	example.oglpprog
	PROPERTIES GENERATED 1
)
eagine_add_directory_example(example.cpp resources.cpp)
eagine_pack_directory_resources(example.oglpprog)

