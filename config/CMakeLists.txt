#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
# make the info.py script
set(INFO_PY "${CMAKE_CURRENT_BINARY_DIR}/info.py")
file(WRITE ${INFO_PY} "# coding=utf-8\n")
file(APPEND ${INFO_PY} "system_config_info = {")
# GL_INIT_LIBS
file(APPEND ${INFO_PY} "'GL_INIT_LIBS': [")
foreach(GL_INIT_LIB GLFW3 GLUT GLX)
	if(${GL_INIT_LIB}_FOUND)
		file(APPEND ${INFO_PY} "'${GL_INIT_LIB}',")
	endif()
endforeach()
file(APPEND ${INFO_PY} "None],")
# GL_API_LIBS
file(APPEND ${INFO_PY} "'GL_API_LIBS': [")
foreach(GL_API_LIB GLCOREARB GLEW)
	if(${GL_API_LIB}_FOUND)
		file(APPEND ${INFO_PY} "'${GL_API_LIB}',")
	endif()
endforeach()
file(APPEND ${INFO_PY} "None],")
#  finish and fix the dictionary
file(APPEND ${INFO_PY} "}\n")
file(APPEND ${INFO_PY} "for key, value in system_config_info.items():\n")
file(APPEND ${INFO_PY} "  if(type(value) == list):\n    value.pop()\n")

