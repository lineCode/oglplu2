# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt

if(EGL_FOUND)
	add_library(
		eglplus EXCLUDE_FROM_ALL
		_dummy.cpp
	)
	eagine_add_lib_analysis(eglplus)
	set_target_properties(
		eglplus
		PROPERTIES FOLDER "Library/EGLplus"
	)
	set_target_properties(
		eglplus PROPERTIES
		INTERFACE_COMPILE_DEFINITIONS EGLPLUS_LINK_LIB=1
	)
	target_link_libraries(
		eglplus
		PUBLIC eagine
	)
endif()
