//  File test/oglplus/enums/texture_compare_mode.cpp
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the enumeration source files in 'source/enums/oglplus'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//   http://www.boost.org/LICENSE_1_0.txt
//
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE OGLPLUS_texture_compare_mode

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_texture_compare_mode)

BOOST_AUTO_TEST_CASE(enum_texture_compare_mode_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	texture_compare_mode x;
	(void)x;

#ifdef GL_COMPARE_REF_TO_TEXTURE
	x = ev.compare_ref_to_texture;
	BOOST_CHECK(x == ev.compare_ref_to_texture);
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
#endif

#ifdef GL_NONE
	x = ev.none;
# ifdef GL_COMPARE_REF_TO_TEXTURE
	BOOST_CHECK(x != ev.compare_ref_to_texture);
# endif
	BOOST_CHECK(x == ev.none);
#endif
}

BOOST_AUTO_TEST_CASE(enum_texture_compare_mode_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	texture_compare_mode x;
	(void)x;

#ifdef GL_COMPARE_REF_TO_TEXTURE
	x = ev.compare_ref_to_texture;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"COMPARE_REF_TO_TEXTURE"
	) == 0);
#endif

#ifdef GL_NONE
	x = ev.none;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"NONE"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_texture_compare_mode_range)
{
	using namespace oglplus;
	texture_compare_mode x;
	(void)x;

#ifdef GL_COMPARE_REF_TO_TEXTURE
{
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_COMPARE_REF_TO_TEXTURE
	) != r.end());
}
#endif

#ifdef GL_NONE
{
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_NONE
	) != r.end());
}
#endif
}

BOOST_AUTO_TEST_SUITE_END()
