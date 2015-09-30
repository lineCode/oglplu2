//  File test/oglplus/enums/pixel_data_type.cpp
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the enumeration source files in 'source/enums/oglplus'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt
//
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE OGLPLUS_pixel_data_type

#include <boost/test/unit_test.hpp>
#include "common.hpp"

BOOST_AUTO_TEST_SUITE(enum_pixel_data_type)

BOOST_AUTO_TEST_CASE(enum_pixel_data_type_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	pixel_data_type x;
	(void)x;

#ifdef GL_BYTE
	x = ev.byte_;
	BOOST_CHECK(x == ev.byte_);
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_32_UNSIGNED_INT_24_8_REV
	BOOST_CHECK(x != ev.float_32_unsigned_int_24_8_rev);
# endif
# ifdef GL_HALF_FLOAT
	BOOST_CHECK(x != ev.half_float);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_SHORT
	BOOST_CHECK(x != ev.short_);
# endif
# ifdef GL_UNSIGNED_BYTE
	BOOST_CHECK(x != ev.unsigned_byte);
# endif
# ifdef GL_UNSIGNED_BYTE_2_3_3_REV
	BOOST_CHECK(x != ev.unsigned_byte_2_3_3_rev);
# endif
# ifdef GL_UNSIGNED_BYTE_3_3_2
	BOOST_CHECK(x != ev.unsigned_byte_3_3_2);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_10_10_10_2
	BOOST_CHECK(x != ev.unsigned_int_10_10_10_2);
# endif
# ifdef GL_UNSIGNED_INT_10F_11F_11F_REV
	BOOST_CHECK(x != ev.unsigned_int_10f_11f_11f_rev);
# endif
# ifdef GL_UNSIGNED_INT_24_8
	BOOST_CHECK(x != ev.unsigned_int_24_8);
# endif
# ifdef GL_UNSIGNED_INT_2_10_10_10_REV
	BOOST_CHECK(x != ev.unsigned_int_2_10_10_10_rev);
# endif
# ifdef GL_UNSIGNED_INT_5_9_9_9_REV
	BOOST_CHECK(x != ev.unsigned_int_5_9_9_9_rev);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8_REV
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8_rev);
# endif
# ifdef GL_UNSIGNED_SHORT
	BOOST_CHECK(x != ev.unsigned_short);
# endif
# ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
	BOOST_CHECK(x != ev.unsigned_short_1_5_5_5_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_5_5_5_1
	BOOST_CHECK(x != ev.unsigned_short_5_5_5_1);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5
	BOOST_CHECK(x != ev.unsigned_short_5_6_5);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5_REV
	BOOST_CHECK(x != ev.unsigned_short_5_6_5_rev);
# endif
#endif

#ifdef GL_FLOAT
	x = ev.float_;
# ifdef GL_BYTE
	BOOST_CHECK(x != ev.byte_);
# endif
	BOOST_CHECK(x == ev.float_);
# ifdef GL_FLOAT_32_UNSIGNED_INT_24_8_REV
	BOOST_CHECK(x != ev.float_32_unsigned_int_24_8_rev);
# endif
# ifdef GL_HALF_FLOAT
	BOOST_CHECK(x != ev.half_float);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_SHORT
	BOOST_CHECK(x != ev.short_);
# endif
# ifdef GL_UNSIGNED_BYTE
	BOOST_CHECK(x != ev.unsigned_byte);
# endif
# ifdef GL_UNSIGNED_BYTE_2_3_3_REV
	BOOST_CHECK(x != ev.unsigned_byte_2_3_3_rev);
# endif
# ifdef GL_UNSIGNED_BYTE_3_3_2
	BOOST_CHECK(x != ev.unsigned_byte_3_3_2);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_10_10_10_2
	BOOST_CHECK(x != ev.unsigned_int_10_10_10_2);
# endif
# ifdef GL_UNSIGNED_INT_10F_11F_11F_REV
	BOOST_CHECK(x != ev.unsigned_int_10f_11f_11f_rev);
# endif
# ifdef GL_UNSIGNED_INT_24_8
	BOOST_CHECK(x != ev.unsigned_int_24_8);
# endif
# ifdef GL_UNSIGNED_INT_2_10_10_10_REV
	BOOST_CHECK(x != ev.unsigned_int_2_10_10_10_rev);
# endif
# ifdef GL_UNSIGNED_INT_5_9_9_9_REV
	BOOST_CHECK(x != ev.unsigned_int_5_9_9_9_rev);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8_REV
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8_rev);
# endif
# ifdef GL_UNSIGNED_SHORT
	BOOST_CHECK(x != ev.unsigned_short);
# endif
# ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
	BOOST_CHECK(x != ev.unsigned_short_1_5_5_5_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_5_5_5_1
	BOOST_CHECK(x != ev.unsigned_short_5_5_5_1);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5
	BOOST_CHECK(x != ev.unsigned_short_5_6_5);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5_REV
	BOOST_CHECK(x != ev.unsigned_short_5_6_5_rev);
# endif
#endif

#ifdef GL_FLOAT_32_UNSIGNED_INT_24_8_REV
	x = ev.float_32_unsigned_int_24_8_rev;
# ifdef GL_BYTE
	BOOST_CHECK(x != ev.byte_);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
	BOOST_CHECK(x == ev.float_32_unsigned_int_24_8_rev);
# ifdef GL_HALF_FLOAT
	BOOST_CHECK(x != ev.half_float);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_SHORT
	BOOST_CHECK(x != ev.short_);
# endif
# ifdef GL_UNSIGNED_BYTE
	BOOST_CHECK(x != ev.unsigned_byte);
# endif
# ifdef GL_UNSIGNED_BYTE_2_3_3_REV
	BOOST_CHECK(x != ev.unsigned_byte_2_3_3_rev);
# endif
# ifdef GL_UNSIGNED_BYTE_3_3_2
	BOOST_CHECK(x != ev.unsigned_byte_3_3_2);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_10_10_10_2
	BOOST_CHECK(x != ev.unsigned_int_10_10_10_2);
# endif
# ifdef GL_UNSIGNED_INT_10F_11F_11F_REV
	BOOST_CHECK(x != ev.unsigned_int_10f_11f_11f_rev);
# endif
# ifdef GL_UNSIGNED_INT_24_8
	BOOST_CHECK(x != ev.unsigned_int_24_8);
# endif
# ifdef GL_UNSIGNED_INT_2_10_10_10_REV
	BOOST_CHECK(x != ev.unsigned_int_2_10_10_10_rev);
# endif
# ifdef GL_UNSIGNED_INT_5_9_9_9_REV
	BOOST_CHECK(x != ev.unsigned_int_5_9_9_9_rev);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8_REV
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8_rev);
# endif
# ifdef GL_UNSIGNED_SHORT
	BOOST_CHECK(x != ev.unsigned_short);
# endif
# ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
	BOOST_CHECK(x != ev.unsigned_short_1_5_5_5_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_5_5_5_1
	BOOST_CHECK(x != ev.unsigned_short_5_5_5_1);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5
	BOOST_CHECK(x != ev.unsigned_short_5_6_5);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5_REV
	BOOST_CHECK(x != ev.unsigned_short_5_6_5_rev);
# endif
#endif

#ifdef GL_HALF_FLOAT
	x = ev.half_float;
# ifdef GL_BYTE
	BOOST_CHECK(x != ev.byte_);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_32_UNSIGNED_INT_24_8_REV
	BOOST_CHECK(x != ev.float_32_unsigned_int_24_8_rev);
# endif
	BOOST_CHECK(x == ev.half_float);
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_SHORT
	BOOST_CHECK(x != ev.short_);
# endif
# ifdef GL_UNSIGNED_BYTE
	BOOST_CHECK(x != ev.unsigned_byte);
# endif
# ifdef GL_UNSIGNED_BYTE_2_3_3_REV
	BOOST_CHECK(x != ev.unsigned_byte_2_3_3_rev);
# endif
# ifdef GL_UNSIGNED_BYTE_3_3_2
	BOOST_CHECK(x != ev.unsigned_byte_3_3_2);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_10_10_10_2
	BOOST_CHECK(x != ev.unsigned_int_10_10_10_2);
# endif
# ifdef GL_UNSIGNED_INT_10F_11F_11F_REV
	BOOST_CHECK(x != ev.unsigned_int_10f_11f_11f_rev);
# endif
# ifdef GL_UNSIGNED_INT_24_8
	BOOST_CHECK(x != ev.unsigned_int_24_8);
# endif
# ifdef GL_UNSIGNED_INT_2_10_10_10_REV
	BOOST_CHECK(x != ev.unsigned_int_2_10_10_10_rev);
# endif
# ifdef GL_UNSIGNED_INT_5_9_9_9_REV
	BOOST_CHECK(x != ev.unsigned_int_5_9_9_9_rev);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8_REV
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8_rev);
# endif
# ifdef GL_UNSIGNED_SHORT
	BOOST_CHECK(x != ev.unsigned_short);
# endif
# ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
	BOOST_CHECK(x != ev.unsigned_short_1_5_5_5_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_5_5_5_1
	BOOST_CHECK(x != ev.unsigned_short_5_5_5_1);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5
	BOOST_CHECK(x != ev.unsigned_short_5_6_5);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5_REV
	BOOST_CHECK(x != ev.unsigned_short_5_6_5_rev);
# endif
#endif

#ifdef GL_INT
	x = ev.int_;
# ifdef GL_BYTE
	BOOST_CHECK(x != ev.byte_);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_32_UNSIGNED_INT_24_8_REV
	BOOST_CHECK(x != ev.float_32_unsigned_int_24_8_rev);
# endif
# ifdef GL_HALF_FLOAT
	BOOST_CHECK(x != ev.half_float);
# endif
	BOOST_CHECK(x == ev.int_);
# ifdef GL_SHORT
	BOOST_CHECK(x != ev.short_);
# endif
# ifdef GL_UNSIGNED_BYTE
	BOOST_CHECK(x != ev.unsigned_byte);
# endif
# ifdef GL_UNSIGNED_BYTE_2_3_3_REV
	BOOST_CHECK(x != ev.unsigned_byte_2_3_3_rev);
# endif
# ifdef GL_UNSIGNED_BYTE_3_3_2
	BOOST_CHECK(x != ev.unsigned_byte_3_3_2);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_10_10_10_2
	BOOST_CHECK(x != ev.unsigned_int_10_10_10_2);
# endif
# ifdef GL_UNSIGNED_INT_10F_11F_11F_REV
	BOOST_CHECK(x != ev.unsigned_int_10f_11f_11f_rev);
# endif
# ifdef GL_UNSIGNED_INT_24_8
	BOOST_CHECK(x != ev.unsigned_int_24_8);
# endif
# ifdef GL_UNSIGNED_INT_2_10_10_10_REV
	BOOST_CHECK(x != ev.unsigned_int_2_10_10_10_rev);
# endif
# ifdef GL_UNSIGNED_INT_5_9_9_9_REV
	BOOST_CHECK(x != ev.unsigned_int_5_9_9_9_rev);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8_REV
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8_rev);
# endif
# ifdef GL_UNSIGNED_SHORT
	BOOST_CHECK(x != ev.unsigned_short);
# endif
# ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
	BOOST_CHECK(x != ev.unsigned_short_1_5_5_5_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_5_5_5_1
	BOOST_CHECK(x != ev.unsigned_short_5_5_5_1);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5
	BOOST_CHECK(x != ev.unsigned_short_5_6_5);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5_REV
	BOOST_CHECK(x != ev.unsigned_short_5_6_5_rev);
# endif
#endif

#ifdef GL_SHORT
	x = ev.short_;
# ifdef GL_BYTE
	BOOST_CHECK(x != ev.byte_);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_32_UNSIGNED_INT_24_8_REV
	BOOST_CHECK(x != ev.float_32_unsigned_int_24_8_rev);
# endif
# ifdef GL_HALF_FLOAT
	BOOST_CHECK(x != ev.half_float);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
	BOOST_CHECK(x == ev.short_);
# ifdef GL_UNSIGNED_BYTE
	BOOST_CHECK(x != ev.unsigned_byte);
# endif
# ifdef GL_UNSIGNED_BYTE_2_3_3_REV
	BOOST_CHECK(x != ev.unsigned_byte_2_3_3_rev);
# endif
# ifdef GL_UNSIGNED_BYTE_3_3_2
	BOOST_CHECK(x != ev.unsigned_byte_3_3_2);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_10_10_10_2
	BOOST_CHECK(x != ev.unsigned_int_10_10_10_2);
# endif
# ifdef GL_UNSIGNED_INT_10F_11F_11F_REV
	BOOST_CHECK(x != ev.unsigned_int_10f_11f_11f_rev);
# endif
# ifdef GL_UNSIGNED_INT_24_8
	BOOST_CHECK(x != ev.unsigned_int_24_8);
# endif
# ifdef GL_UNSIGNED_INT_2_10_10_10_REV
	BOOST_CHECK(x != ev.unsigned_int_2_10_10_10_rev);
# endif
# ifdef GL_UNSIGNED_INT_5_9_9_9_REV
	BOOST_CHECK(x != ev.unsigned_int_5_9_9_9_rev);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8_REV
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8_rev);
# endif
# ifdef GL_UNSIGNED_SHORT
	BOOST_CHECK(x != ev.unsigned_short);
# endif
# ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
	BOOST_CHECK(x != ev.unsigned_short_1_5_5_5_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_5_5_5_1
	BOOST_CHECK(x != ev.unsigned_short_5_5_5_1);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5
	BOOST_CHECK(x != ev.unsigned_short_5_6_5);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5_REV
	BOOST_CHECK(x != ev.unsigned_short_5_6_5_rev);
# endif
#endif

#ifdef GL_UNSIGNED_BYTE
	x = ev.unsigned_byte;
# ifdef GL_BYTE
	BOOST_CHECK(x != ev.byte_);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_32_UNSIGNED_INT_24_8_REV
	BOOST_CHECK(x != ev.float_32_unsigned_int_24_8_rev);
# endif
# ifdef GL_HALF_FLOAT
	BOOST_CHECK(x != ev.half_float);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_SHORT
	BOOST_CHECK(x != ev.short_);
# endif
	BOOST_CHECK(x == ev.unsigned_byte);
# ifdef GL_UNSIGNED_BYTE_2_3_3_REV
	BOOST_CHECK(x != ev.unsigned_byte_2_3_3_rev);
# endif
# ifdef GL_UNSIGNED_BYTE_3_3_2
	BOOST_CHECK(x != ev.unsigned_byte_3_3_2);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_10_10_10_2
	BOOST_CHECK(x != ev.unsigned_int_10_10_10_2);
# endif
# ifdef GL_UNSIGNED_INT_10F_11F_11F_REV
	BOOST_CHECK(x != ev.unsigned_int_10f_11f_11f_rev);
# endif
# ifdef GL_UNSIGNED_INT_24_8
	BOOST_CHECK(x != ev.unsigned_int_24_8);
# endif
# ifdef GL_UNSIGNED_INT_2_10_10_10_REV
	BOOST_CHECK(x != ev.unsigned_int_2_10_10_10_rev);
# endif
# ifdef GL_UNSIGNED_INT_5_9_9_9_REV
	BOOST_CHECK(x != ev.unsigned_int_5_9_9_9_rev);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8_REV
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8_rev);
# endif
# ifdef GL_UNSIGNED_SHORT
	BOOST_CHECK(x != ev.unsigned_short);
# endif
# ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
	BOOST_CHECK(x != ev.unsigned_short_1_5_5_5_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_5_5_5_1
	BOOST_CHECK(x != ev.unsigned_short_5_5_5_1);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5
	BOOST_CHECK(x != ev.unsigned_short_5_6_5);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5_REV
	BOOST_CHECK(x != ev.unsigned_short_5_6_5_rev);
# endif
#endif

#ifdef GL_UNSIGNED_BYTE_2_3_3_REV
	x = ev.unsigned_byte_2_3_3_rev;
# ifdef GL_BYTE
	BOOST_CHECK(x != ev.byte_);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_32_UNSIGNED_INT_24_8_REV
	BOOST_CHECK(x != ev.float_32_unsigned_int_24_8_rev);
# endif
# ifdef GL_HALF_FLOAT
	BOOST_CHECK(x != ev.half_float);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_SHORT
	BOOST_CHECK(x != ev.short_);
# endif
# ifdef GL_UNSIGNED_BYTE
	BOOST_CHECK(x != ev.unsigned_byte);
# endif
	BOOST_CHECK(x == ev.unsigned_byte_2_3_3_rev);
# ifdef GL_UNSIGNED_BYTE_3_3_2
	BOOST_CHECK(x != ev.unsigned_byte_3_3_2);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_10_10_10_2
	BOOST_CHECK(x != ev.unsigned_int_10_10_10_2);
# endif
# ifdef GL_UNSIGNED_INT_10F_11F_11F_REV
	BOOST_CHECK(x != ev.unsigned_int_10f_11f_11f_rev);
# endif
# ifdef GL_UNSIGNED_INT_24_8
	BOOST_CHECK(x != ev.unsigned_int_24_8);
# endif
# ifdef GL_UNSIGNED_INT_2_10_10_10_REV
	BOOST_CHECK(x != ev.unsigned_int_2_10_10_10_rev);
# endif
# ifdef GL_UNSIGNED_INT_5_9_9_9_REV
	BOOST_CHECK(x != ev.unsigned_int_5_9_9_9_rev);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8_REV
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8_rev);
# endif
# ifdef GL_UNSIGNED_SHORT
	BOOST_CHECK(x != ev.unsigned_short);
# endif
# ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
	BOOST_CHECK(x != ev.unsigned_short_1_5_5_5_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_5_5_5_1
	BOOST_CHECK(x != ev.unsigned_short_5_5_5_1);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5
	BOOST_CHECK(x != ev.unsigned_short_5_6_5);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5_REV
	BOOST_CHECK(x != ev.unsigned_short_5_6_5_rev);
# endif
#endif

#ifdef GL_UNSIGNED_BYTE_3_3_2
	x = ev.unsigned_byte_3_3_2;
# ifdef GL_BYTE
	BOOST_CHECK(x != ev.byte_);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_32_UNSIGNED_INT_24_8_REV
	BOOST_CHECK(x != ev.float_32_unsigned_int_24_8_rev);
# endif
# ifdef GL_HALF_FLOAT
	BOOST_CHECK(x != ev.half_float);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_SHORT
	BOOST_CHECK(x != ev.short_);
# endif
# ifdef GL_UNSIGNED_BYTE
	BOOST_CHECK(x != ev.unsigned_byte);
# endif
# ifdef GL_UNSIGNED_BYTE_2_3_3_REV
	BOOST_CHECK(x != ev.unsigned_byte_2_3_3_rev);
# endif
	BOOST_CHECK(x == ev.unsigned_byte_3_3_2);
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_10_10_10_2
	BOOST_CHECK(x != ev.unsigned_int_10_10_10_2);
# endif
# ifdef GL_UNSIGNED_INT_10F_11F_11F_REV
	BOOST_CHECK(x != ev.unsigned_int_10f_11f_11f_rev);
# endif
# ifdef GL_UNSIGNED_INT_24_8
	BOOST_CHECK(x != ev.unsigned_int_24_8);
# endif
# ifdef GL_UNSIGNED_INT_2_10_10_10_REV
	BOOST_CHECK(x != ev.unsigned_int_2_10_10_10_rev);
# endif
# ifdef GL_UNSIGNED_INT_5_9_9_9_REV
	BOOST_CHECK(x != ev.unsigned_int_5_9_9_9_rev);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8_REV
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8_rev);
# endif
# ifdef GL_UNSIGNED_SHORT
	BOOST_CHECK(x != ev.unsigned_short);
# endif
# ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
	BOOST_CHECK(x != ev.unsigned_short_1_5_5_5_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_5_5_5_1
	BOOST_CHECK(x != ev.unsigned_short_5_5_5_1);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5
	BOOST_CHECK(x != ev.unsigned_short_5_6_5);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5_REV
	BOOST_CHECK(x != ev.unsigned_short_5_6_5_rev);
# endif
#endif

#ifdef GL_UNSIGNED_INT
	x = ev.unsigned_int;
# ifdef GL_BYTE
	BOOST_CHECK(x != ev.byte_);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_32_UNSIGNED_INT_24_8_REV
	BOOST_CHECK(x != ev.float_32_unsigned_int_24_8_rev);
# endif
# ifdef GL_HALF_FLOAT
	BOOST_CHECK(x != ev.half_float);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_SHORT
	BOOST_CHECK(x != ev.short_);
# endif
# ifdef GL_UNSIGNED_BYTE
	BOOST_CHECK(x != ev.unsigned_byte);
# endif
# ifdef GL_UNSIGNED_BYTE_2_3_3_REV
	BOOST_CHECK(x != ev.unsigned_byte_2_3_3_rev);
# endif
# ifdef GL_UNSIGNED_BYTE_3_3_2
	BOOST_CHECK(x != ev.unsigned_byte_3_3_2);
# endif
	BOOST_CHECK(x == ev.unsigned_int);
# ifdef GL_UNSIGNED_INT_10_10_10_2
	BOOST_CHECK(x != ev.unsigned_int_10_10_10_2);
# endif
# ifdef GL_UNSIGNED_INT_10F_11F_11F_REV
	BOOST_CHECK(x != ev.unsigned_int_10f_11f_11f_rev);
# endif
# ifdef GL_UNSIGNED_INT_24_8
	BOOST_CHECK(x != ev.unsigned_int_24_8);
# endif
# ifdef GL_UNSIGNED_INT_2_10_10_10_REV
	BOOST_CHECK(x != ev.unsigned_int_2_10_10_10_rev);
# endif
# ifdef GL_UNSIGNED_INT_5_9_9_9_REV
	BOOST_CHECK(x != ev.unsigned_int_5_9_9_9_rev);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8_REV
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8_rev);
# endif
# ifdef GL_UNSIGNED_SHORT
	BOOST_CHECK(x != ev.unsigned_short);
# endif
# ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
	BOOST_CHECK(x != ev.unsigned_short_1_5_5_5_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_5_5_5_1
	BOOST_CHECK(x != ev.unsigned_short_5_5_5_1);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5
	BOOST_CHECK(x != ev.unsigned_short_5_6_5);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5_REV
	BOOST_CHECK(x != ev.unsigned_short_5_6_5_rev);
# endif
#endif

#ifdef GL_UNSIGNED_INT_10_10_10_2
	x = ev.unsigned_int_10_10_10_2;
# ifdef GL_BYTE
	BOOST_CHECK(x != ev.byte_);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_32_UNSIGNED_INT_24_8_REV
	BOOST_CHECK(x != ev.float_32_unsigned_int_24_8_rev);
# endif
# ifdef GL_HALF_FLOAT
	BOOST_CHECK(x != ev.half_float);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_SHORT
	BOOST_CHECK(x != ev.short_);
# endif
# ifdef GL_UNSIGNED_BYTE
	BOOST_CHECK(x != ev.unsigned_byte);
# endif
# ifdef GL_UNSIGNED_BYTE_2_3_3_REV
	BOOST_CHECK(x != ev.unsigned_byte_2_3_3_rev);
# endif
# ifdef GL_UNSIGNED_BYTE_3_3_2
	BOOST_CHECK(x != ev.unsigned_byte_3_3_2);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
	BOOST_CHECK(x == ev.unsigned_int_10_10_10_2);
# ifdef GL_UNSIGNED_INT_10F_11F_11F_REV
	BOOST_CHECK(x != ev.unsigned_int_10f_11f_11f_rev);
# endif
# ifdef GL_UNSIGNED_INT_24_8
	BOOST_CHECK(x != ev.unsigned_int_24_8);
# endif
# ifdef GL_UNSIGNED_INT_2_10_10_10_REV
	BOOST_CHECK(x != ev.unsigned_int_2_10_10_10_rev);
# endif
# ifdef GL_UNSIGNED_INT_5_9_9_9_REV
	BOOST_CHECK(x != ev.unsigned_int_5_9_9_9_rev);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8_REV
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8_rev);
# endif
# ifdef GL_UNSIGNED_SHORT
	BOOST_CHECK(x != ev.unsigned_short);
# endif
# ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
	BOOST_CHECK(x != ev.unsigned_short_1_5_5_5_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_5_5_5_1
	BOOST_CHECK(x != ev.unsigned_short_5_5_5_1);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5
	BOOST_CHECK(x != ev.unsigned_short_5_6_5);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5_REV
	BOOST_CHECK(x != ev.unsigned_short_5_6_5_rev);
# endif
#endif

#ifdef GL_UNSIGNED_INT_10F_11F_11F_REV
	x = ev.unsigned_int_10f_11f_11f_rev;
# ifdef GL_BYTE
	BOOST_CHECK(x != ev.byte_);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_32_UNSIGNED_INT_24_8_REV
	BOOST_CHECK(x != ev.float_32_unsigned_int_24_8_rev);
# endif
# ifdef GL_HALF_FLOAT
	BOOST_CHECK(x != ev.half_float);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_SHORT
	BOOST_CHECK(x != ev.short_);
# endif
# ifdef GL_UNSIGNED_BYTE
	BOOST_CHECK(x != ev.unsigned_byte);
# endif
# ifdef GL_UNSIGNED_BYTE_2_3_3_REV
	BOOST_CHECK(x != ev.unsigned_byte_2_3_3_rev);
# endif
# ifdef GL_UNSIGNED_BYTE_3_3_2
	BOOST_CHECK(x != ev.unsigned_byte_3_3_2);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_10_10_10_2
	BOOST_CHECK(x != ev.unsigned_int_10_10_10_2);
# endif
	BOOST_CHECK(x == ev.unsigned_int_10f_11f_11f_rev);
# ifdef GL_UNSIGNED_INT_24_8
	BOOST_CHECK(x != ev.unsigned_int_24_8);
# endif
# ifdef GL_UNSIGNED_INT_2_10_10_10_REV
	BOOST_CHECK(x != ev.unsigned_int_2_10_10_10_rev);
# endif
# ifdef GL_UNSIGNED_INT_5_9_9_9_REV
	BOOST_CHECK(x != ev.unsigned_int_5_9_9_9_rev);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8_REV
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8_rev);
# endif
# ifdef GL_UNSIGNED_SHORT
	BOOST_CHECK(x != ev.unsigned_short);
# endif
# ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
	BOOST_CHECK(x != ev.unsigned_short_1_5_5_5_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_5_5_5_1
	BOOST_CHECK(x != ev.unsigned_short_5_5_5_1);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5
	BOOST_CHECK(x != ev.unsigned_short_5_6_5);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5_REV
	BOOST_CHECK(x != ev.unsigned_short_5_6_5_rev);
# endif
#endif

#ifdef GL_UNSIGNED_INT_24_8
	x = ev.unsigned_int_24_8;
# ifdef GL_BYTE
	BOOST_CHECK(x != ev.byte_);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_32_UNSIGNED_INT_24_8_REV
	BOOST_CHECK(x != ev.float_32_unsigned_int_24_8_rev);
# endif
# ifdef GL_HALF_FLOAT
	BOOST_CHECK(x != ev.half_float);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_SHORT
	BOOST_CHECK(x != ev.short_);
# endif
# ifdef GL_UNSIGNED_BYTE
	BOOST_CHECK(x != ev.unsigned_byte);
# endif
# ifdef GL_UNSIGNED_BYTE_2_3_3_REV
	BOOST_CHECK(x != ev.unsigned_byte_2_3_3_rev);
# endif
# ifdef GL_UNSIGNED_BYTE_3_3_2
	BOOST_CHECK(x != ev.unsigned_byte_3_3_2);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_10_10_10_2
	BOOST_CHECK(x != ev.unsigned_int_10_10_10_2);
# endif
# ifdef GL_UNSIGNED_INT_10F_11F_11F_REV
	BOOST_CHECK(x != ev.unsigned_int_10f_11f_11f_rev);
# endif
	BOOST_CHECK(x == ev.unsigned_int_24_8);
# ifdef GL_UNSIGNED_INT_2_10_10_10_REV
	BOOST_CHECK(x != ev.unsigned_int_2_10_10_10_rev);
# endif
# ifdef GL_UNSIGNED_INT_5_9_9_9_REV
	BOOST_CHECK(x != ev.unsigned_int_5_9_9_9_rev);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8_REV
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8_rev);
# endif
# ifdef GL_UNSIGNED_SHORT
	BOOST_CHECK(x != ev.unsigned_short);
# endif
# ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
	BOOST_CHECK(x != ev.unsigned_short_1_5_5_5_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_5_5_5_1
	BOOST_CHECK(x != ev.unsigned_short_5_5_5_1);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5
	BOOST_CHECK(x != ev.unsigned_short_5_6_5);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5_REV
	BOOST_CHECK(x != ev.unsigned_short_5_6_5_rev);
# endif
#endif

#ifdef GL_UNSIGNED_INT_2_10_10_10_REV
	x = ev.unsigned_int_2_10_10_10_rev;
# ifdef GL_BYTE
	BOOST_CHECK(x != ev.byte_);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_32_UNSIGNED_INT_24_8_REV
	BOOST_CHECK(x != ev.float_32_unsigned_int_24_8_rev);
# endif
# ifdef GL_HALF_FLOAT
	BOOST_CHECK(x != ev.half_float);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_SHORT
	BOOST_CHECK(x != ev.short_);
# endif
# ifdef GL_UNSIGNED_BYTE
	BOOST_CHECK(x != ev.unsigned_byte);
# endif
# ifdef GL_UNSIGNED_BYTE_2_3_3_REV
	BOOST_CHECK(x != ev.unsigned_byte_2_3_3_rev);
# endif
# ifdef GL_UNSIGNED_BYTE_3_3_2
	BOOST_CHECK(x != ev.unsigned_byte_3_3_2);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_10_10_10_2
	BOOST_CHECK(x != ev.unsigned_int_10_10_10_2);
# endif
# ifdef GL_UNSIGNED_INT_10F_11F_11F_REV
	BOOST_CHECK(x != ev.unsigned_int_10f_11f_11f_rev);
# endif
# ifdef GL_UNSIGNED_INT_24_8
	BOOST_CHECK(x != ev.unsigned_int_24_8);
# endif
	BOOST_CHECK(x == ev.unsigned_int_2_10_10_10_rev);
# ifdef GL_UNSIGNED_INT_5_9_9_9_REV
	BOOST_CHECK(x != ev.unsigned_int_5_9_9_9_rev);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8_REV
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8_rev);
# endif
# ifdef GL_UNSIGNED_SHORT
	BOOST_CHECK(x != ev.unsigned_short);
# endif
# ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
	BOOST_CHECK(x != ev.unsigned_short_1_5_5_5_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_5_5_5_1
	BOOST_CHECK(x != ev.unsigned_short_5_5_5_1);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5
	BOOST_CHECK(x != ev.unsigned_short_5_6_5);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5_REV
	BOOST_CHECK(x != ev.unsigned_short_5_6_5_rev);
# endif
#endif

#ifdef GL_UNSIGNED_INT_5_9_9_9_REV
	x = ev.unsigned_int_5_9_9_9_rev;
# ifdef GL_BYTE
	BOOST_CHECK(x != ev.byte_);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_32_UNSIGNED_INT_24_8_REV
	BOOST_CHECK(x != ev.float_32_unsigned_int_24_8_rev);
# endif
# ifdef GL_HALF_FLOAT
	BOOST_CHECK(x != ev.half_float);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_SHORT
	BOOST_CHECK(x != ev.short_);
# endif
# ifdef GL_UNSIGNED_BYTE
	BOOST_CHECK(x != ev.unsigned_byte);
# endif
# ifdef GL_UNSIGNED_BYTE_2_3_3_REV
	BOOST_CHECK(x != ev.unsigned_byte_2_3_3_rev);
# endif
# ifdef GL_UNSIGNED_BYTE_3_3_2
	BOOST_CHECK(x != ev.unsigned_byte_3_3_2);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_10_10_10_2
	BOOST_CHECK(x != ev.unsigned_int_10_10_10_2);
# endif
# ifdef GL_UNSIGNED_INT_10F_11F_11F_REV
	BOOST_CHECK(x != ev.unsigned_int_10f_11f_11f_rev);
# endif
# ifdef GL_UNSIGNED_INT_24_8
	BOOST_CHECK(x != ev.unsigned_int_24_8);
# endif
# ifdef GL_UNSIGNED_INT_2_10_10_10_REV
	BOOST_CHECK(x != ev.unsigned_int_2_10_10_10_rev);
# endif
	BOOST_CHECK(x == ev.unsigned_int_5_9_9_9_rev);
# ifdef GL_UNSIGNED_INT_8_8_8_8
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8_REV
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8_rev);
# endif
# ifdef GL_UNSIGNED_SHORT
	BOOST_CHECK(x != ev.unsigned_short);
# endif
# ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
	BOOST_CHECK(x != ev.unsigned_short_1_5_5_5_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_5_5_5_1
	BOOST_CHECK(x != ev.unsigned_short_5_5_5_1);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5
	BOOST_CHECK(x != ev.unsigned_short_5_6_5);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5_REV
	BOOST_CHECK(x != ev.unsigned_short_5_6_5_rev);
# endif
#endif

#ifdef GL_UNSIGNED_INT_8_8_8_8
	x = ev.unsigned_int_8_8_8_8;
# ifdef GL_BYTE
	BOOST_CHECK(x != ev.byte_);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_32_UNSIGNED_INT_24_8_REV
	BOOST_CHECK(x != ev.float_32_unsigned_int_24_8_rev);
# endif
# ifdef GL_HALF_FLOAT
	BOOST_CHECK(x != ev.half_float);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_SHORT
	BOOST_CHECK(x != ev.short_);
# endif
# ifdef GL_UNSIGNED_BYTE
	BOOST_CHECK(x != ev.unsigned_byte);
# endif
# ifdef GL_UNSIGNED_BYTE_2_3_3_REV
	BOOST_CHECK(x != ev.unsigned_byte_2_3_3_rev);
# endif
# ifdef GL_UNSIGNED_BYTE_3_3_2
	BOOST_CHECK(x != ev.unsigned_byte_3_3_2);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_10_10_10_2
	BOOST_CHECK(x != ev.unsigned_int_10_10_10_2);
# endif
# ifdef GL_UNSIGNED_INT_10F_11F_11F_REV
	BOOST_CHECK(x != ev.unsigned_int_10f_11f_11f_rev);
# endif
# ifdef GL_UNSIGNED_INT_24_8
	BOOST_CHECK(x != ev.unsigned_int_24_8);
# endif
# ifdef GL_UNSIGNED_INT_2_10_10_10_REV
	BOOST_CHECK(x != ev.unsigned_int_2_10_10_10_rev);
# endif
# ifdef GL_UNSIGNED_INT_5_9_9_9_REV
	BOOST_CHECK(x != ev.unsigned_int_5_9_9_9_rev);
# endif
	BOOST_CHECK(x == ev.unsigned_int_8_8_8_8);
# ifdef GL_UNSIGNED_INT_8_8_8_8_REV
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8_rev);
# endif
# ifdef GL_UNSIGNED_SHORT
	BOOST_CHECK(x != ev.unsigned_short);
# endif
# ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
	BOOST_CHECK(x != ev.unsigned_short_1_5_5_5_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_5_5_5_1
	BOOST_CHECK(x != ev.unsigned_short_5_5_5_1);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5
	BOOST_CHECK(x != ev.unsigned_short_5_6_5);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5_REV
	BOOST_CHECK(x != ev.unsigned_short_5_6_5_rev);
# endif
#endif

#ifdef GL_UNSIGNED_INT_8_8_8_8_REV
	x = ev.unsigned_int_8_8_8_8_rev;
# ifdef GL_BYTE
	BOOST_CHECK(x != ev.byte_);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_32_UNSIGNED_INT_24_8_REV
	BOOST_CHECK(x != ev.float_32_unsigned_int_24_8_rev);
# endif
# ifdef GL_HALF_FLOAT
	BOOST_CHECK(x != ev.half_float);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_SHORT
	BOOST_CHECK(x != ev.short_);
# endif
# ifdef GL_UNSIGNED_BYTE
	BOOST_CHECK(x != ev.unsigned_byte);
# endif
# ifdef GL_UNSIGNED_BYTE_2_3_3_REV
	BOOST_CHECK(x != ev.unsigned_byte_2_3_3_rev);
# endif
# ifdef GL_UNSIGNED_BYTE_3_3_2
	BOOST_CHECK(x != ev.unsigned_byte_3_3_2);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_10_10_10_2
	BOOST_CHECK(x != ev.unsigned_int_10_10_10_2);
# endif
# ifdef GL_UNSIGNED_INT_10F_11F_11F_REV
	BOOST_CHECK(x != ev.unsigned_int_10f_11f_11f_rev);
# endif
# ifdef GL_UNSIGNED_INT_24_8
	BOOST_CHECK(x != ev.unsigned_int_24_8);
# endif
# ifdef GL_UNSIGNED_INT_2_10_10_10_REV
	BOOST_CHECK(x != ev.unsigned_int_2_10_10_10_rev);
# endif
# ifdef GL_UNSIGNED_INT_5_9_9_9_REV
	BOOST_CHECK(x != ev.unsigned_int_5_9_9_9_rev);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8);
# endif
	BOOST_CHECK(x == ev.unsigned_int_8_8_8_8_rev);
# ifdef GL_UNSIGNED_SHORT
	BOOST_CHECK(x != ev.unsigned_short);
# endif
# ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
	BOOST_CHECK(x != ev.unsigned_short_1_5_5_5_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_5_5_5_1
	BOOST_CHECK(x != ev.unsigned_short_5_5_5_1);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5
	BOOST_CHECK(x != ev.unsigned_short_5_6_5);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5_REV
	BOOST_CHECK(x != ev.unsigned_short_5_6_5_rev);
# endif
#endif

#ifdef GL_UNSIGNED_SHORT
	x = ev.unsigned_short;
# ifdef GL_BYTE
	BOOST_CHECK(x != ev.byte_);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_32_UNSIGNED_INT_24_8_REV
	BOOST_CHECK(x != ev.float_32_unsigned_int_24_8_rev);
# endif
# ifdef GL_HALF_FLOAT
	BOOST_CHECK(x != ev.half_float);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_SHORT
	BOOST_CHECK(x != ev.short_);
# endif
# ifdef GL_UNSIGNED_BYTE
	BOOST_CHECK(x != ev.unsigned_byte);
# endif
# ifdef GL_UNSIGNED_BYTE_2_3_3_REV
	BOOST_CHECK(x != ev.unsigned_byte_2_3_3_rev);
# endif
# ifdef GL_UNSIGNED_BYTE_3_3_2
	BOOST_CHECK(x != ev.unsigned_byte_3_3_2);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_10_10_10_2
	BOOST_CHECK(x != ev.unsigned_int_10_10_10_2);
# endif
# ifdef GL_UNSIGNED_INT_10F_11F_11F_REV
	BOOST_CHECK(x != ev.unsigned_int_10f_11f_11f_rev);
# endif
# ifdef GL_UNSIGNED_INT_24_8
	BOOST_CHECK(x != ev.unsigned_int_24_8);
# endif
# ifdef GL_UNSIGNED_INT_2_10_10_10_REV
	BOOST_CHECK(x != ev.unsigned_int_2_10_10_10_rev);
# endif
# ifdef GL_UNSIGNED_INT_5_9_9_9_REV
	BOOST_CHECK(x != ev.unsigned_int_5_9_9_9_rev);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8_REV
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8_rev);
# endif
	BOOST_CHECK(x == ev.unsigned_short);
# ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
	BOOST_CHECK(x != ev.unsigned_short_1_5_5_5_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_5_5_5_1
	BOOST_CHECK(x != ev.unsigned_short_5_5_5_1);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5
	BOOST_CHECK(x != ev.unsigned_short_5_6_5);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5_REV
	BOOST_CHECK(x != ev.unsigned_short_5_6_5_rev);
# endif
#endif

#ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
	x = ev.unsigned_short_1_5_5_5_rev;
# ifdef GL_BYTE
	BOOST_CHECK(x != ev.byte_);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_32_UNSIGNED_INT_24_8_REV
	BOOST_CHECK(x != ev.float_32_unsigned_int_24_8_rev);
# endif
# ifdef GL_HALF_FLOAT
	BOOST_CHECK(x != ev.half_float);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_SHORT
	BOOST_CHECK(x != ev.short_);
# endif
# ifdef GL_UNSIGNED_BYTE
	BOOST_CHECK(x != ev.unsigned_byte);
# endif
# ifdef GL_UNSIGNED_BYTE_2_3_3_REV
	BOOST_CHECK(x != ev.unsigned_byte_2_3_3_rev);
# endif
# ifdef GL_UNSIGNED_BYTE_3_3_2
	BOOST_CHECK(x != ev.unsigned_byte_3_3_2);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_10_10_10_2
	BOOST_CHECK(x != ev.unsigned_int_10_10_10_2);
# endif
# ifdef GL_UNSIGNED_INT_10F_11F_11F_REV
	BOOST_CHECK(x != ev.unsigned_int_10f_11f_11f_rev);
# endif
# ifdef GL_UNSIGNED_INT_24_8
	BOOST_CHECK(x != ev.unsigned_int_24_8);
# endif
# ifdef GL_UNSIGNED_INT_2_10_10_10_REV
	BOOST_CHECK(x != ev.unsigned_int_2_10_10_10_rev);
# endif
# ifdef GL_UNSIGNED_INT_5_9_9_9_REV
	BOOST_CHECK(x != ev.unsigned_int_5_9_9_9_rev);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8_REV
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8_rev);
# endif
# ifdef GL_UNSIGNED_SHORT
	BOOST_CHECK(x != ev.unsigned_short);
# endif
	BOOST_CHECK(x == ev.unsigned_short_1_5_5_5_rev);
# ifdef GL_UNSIGNED_SHORT_4_4_4_4
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_5_5_5_1
	BOOST_CHECK(x != ev.unsigned_short_5_5_5_1);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5
	BOOST_CHECK(x != ev.unsigned_short_5_6_5);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5_REV
	BOOST_CHECK(x != ev.unsigned_short_5_6_5_rev);
# endif
#endif

#ifdef GL_UNSIGNED_SHORT_4_4_4_4
	x = ev.unsigned_short_4_4_4_4;
# ifdef GL_BYTE
	BOOST_CHECK(x != ev.byte_);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_32_UNSIGNED_INT_24_8_REV
	BOOST_CHECK(x != ev.float_32_unsigned_int_24_8_rev);
# endif
# ifdef GL_HALF_FLOAT
	BOOST_CHECK(x != ev.half_float);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_SHORT
	BOOST_CHECK(x != ev.short_);
# endif
# ifdef GL_UNSIGNED_BYTE
	BOOST_CHECK(x != ev.unsigned_byte);
# endif
# ifdef GL_UNSIGNED_BYTE_2_3_3_REV
	BOOST_CHECK(x != ev.unsigned_byte_2_3_3_rev);
# endif
# ifdef GL_UNSIGNED_BYTE_3_3_2
	BOOST_CHECK(x != ev.unsigned_byte_3_3_2);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_10_10_10_2
	BOOST_CHECK(x != ev.unsigned_int_10_10_10_2);
# endif
# ifdef GL_UNSIGNED_INT_10F_11F_11F_REV
	BOOST_CHECK(x != ev.unsigned_int_10f_11f_11f_rev);
# endif
# ifdef GL_UNSIGNED_INT_24_8
	BOOST_CHECK(x != ev.unsigned_int_24_8);
# endif
# ifdef GL_UNSIGNED_INT_2_10_10_10_REV
	BOOST_CHECK(x != ev.unsigned_int_2_10_10_10_rev);
# endif
# ifdef GL_UNSIGNED_INT_5_9_9_9_REV
	BOOST_CHECK(x != ev.unsigned_int_5_9_9_9_rev);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8_REV
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8_rev);
# endif
# ifdef GL_UNSIGNED_SHORT
	BOOST_CHECK(x != ev.unsigned_short);
# endif
# ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
	BOOST_CHECK(x != ev.unsigned_short_1_5_5_5_rev);
# endif
	BOOST_CHECK(x == ev.unsigned_short_4_4_4_4);
# ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_5_5_5_1
	BOOST_CHECK(x != ev.unsigned_short_5_5_5_1);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5
	BOOST_CHECK(x != ev.unsigned_short_5_6_5);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5_REV
	BOOST_CHECK(x != ev.unsigned_short_5_6_5_rev);
# endif
#endif

#ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
	x = ev.unsigned_short_4_4_4_4_rev;
# ifdef GL_BYTE
	BOOST_CHECK(x != ev.byte_);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_32_UNSIGNED_INT_24_8_REV
	BOOST_CHECK(x != ev.float_32_unsigned_int_24_8_rev);
# endif
# ifdef GL_HALF_FLOAT
	BOOST_CHECK(x != ev.half_float);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_SHORT
	BOOST_CHECK(x != ev.short_);
# endif
# ifdef GL_UNSIGNED_BYTE
	BOOST_CHECK(x != ev.unsigned_byte);
# endif
# ifdef GL_UNSIGNED_BYTE_2_3_3_REV
	BOOST_CHECK(x != ev.unsigned_byte_2_3_3_rev);
# endif
# ifdef GL_UNSIGNED_BYTE_3_3_2
	BOOST_CHECK(x != ev.unsigned_byte_3_3_2);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_10_10_10_2
	BOOST_CHECK(x != ev.unsigned_int_10_10_10_2);
# endif
# ifdef GL_UNSIGNED_INT_10F_11F_11F_REV
	BOOST_CHECK(x != ev.unsigned_int_10f_11f_11f_rev);
# endif
# ifdef GL_UNSIGNED_INT_24_8
	BOOST_CHECK(x != ev.unsigned_int_24_8);
# endif
# ifdef GL_UNSIGNED_INT_2_10_10_10_REV
	BOOST_CHECK(x != ev.unsigned_int_2_10_10_10_rev);
# endif
# ifdef GL_UNSIGNED_INT_5_9_9_9_REV
	BOOST_CHECK(x != ev.unsigned_int_5_9_9_9_rev);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8_REV
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8_rev);
# endif
# ifdef GL_UNSIGNED_SHORT
	BOOST_CHECK(x != ev.unsigned_short);
# endif
# ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
	BOOST_CHECK(x != ev.unsigned_short_1_5_5_5_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4);
# endif
	BOOST_CHECK(x == ev.unsigned_short_4_4_4_4_rev);
# ifdef GL_UNSIGNED_SHORT_5_5_5_1
	BOOST_CHECK(x != ev.unsigned_short_5_5_5_1);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5
	BOOST_CHECK(x != ev.unsigned_short_5_6_5);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5_REV
	BOOST_CHECK(x != ev.unsigned_short_5_6_5_rev);
# endif
#endif

#ifdef GL_UNSIGNED_SHORT_5_5_5_1
	x = ev.unsigned_short_5_5_5_1;
# ifdef GL_BYTE
	BOOST_CHECK(x != ev.byte_);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_32_UNSIGNED_INT_24_8_REV
	BOOST_CHECK(x != ev.float_32_unsigned_int_24_8_rev);
# endif
# ifdef GL_HALF_FLOAT
	BOOST_CHECK(x != ev.half_float);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_SHORT
	BOOST_CHECK(x != ev.short_);
# endif
# ifdef GL_UNSIGNED_BYTE
	BOOST_CHECK(x != ev.unsigned_byte);
# endif
# ifdef GL_UNSIGNED_BYTE_2_3_3_REV
	BOOST_CHECK(x != ev.unsigned_byte_2_3_3_rev);
# endif
# ifdef GL_UNSIGNED_BYTE_3_3_2
	BOOST_CHECK(x != ev.unsigned_byte_3_3_2);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_10_10_10_2
	BOOST_CHECK(x != ev.unsigned_int_10_10_10_2);
# endif
# ifdef GL_UNSIGNED_INT_10F_11F_11F_REV
	BOOST_CHECK(x != ev.unsigned_int_10f_11f_11f_rev);
# endif
# ifdef GL_UNSIGNED_INT_24_8
	BOOST_CHECK(x != ev.unsigned_int_24_8);
# endif
# ifdef GL_UNSIGNED_INT_2_10_10_10_REV
	BOOST_CHECK(x != ev.unsigned_int_2_10_10_10_rev);
# endif
# ifdef GL_UNSIGNED_INT_5_9_9_9_REV
	BOOST_CHECK(x != ev.unsigned_int_5_9_9_9_rev);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8_REV
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8_rev);
# endif
# ifdef GL_UNSIGNED_SHORT
	BOOST_CHECK(x != ev.unsigned_short);
# endif
# ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
	BOOST_CHECK(x != ev.unsigned_short_1_5_5_5_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4_rev);
# endif
	BOOST_CHECK(x == ev.unsigned_short_5_5_5_1);
# ifdef GL_UNSIGNED_SHORT_5_6_5
	BOOST_CHECK(x != ev.unsigned_short_5_6_5);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5_REV
	BOOST_CHECK(x != ev.unsigned_short_5_6_5_rev);
# endif
#endif

#ifdef GL_UNSIGNED_SHORT_5_6_5
	x = ev.unsigned_short_5_6_5;
# ifdef GL_BYTE
	BOOST_CHECK(x != ev.byte_);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_32_UNSIGNED_INT_24_8_REV
	BOOST_CHECK(x != ev.float_32_unsigned_int_24_8_rev);
# endif
# ifdef GL_HALF_FLOAT
	BOOST_CHECK(x != ev.half_float);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_SHORT
	BOOST_CHECK(x != ev.short_);
# endif
# ifdef GL_UNSIGNED_BYTE
	BOOST_CHECK(x != ev.unsigned_byte);
# endif
# ifdef GL_UNSIGNED_BYTE_2_3_3_REV
	BOOST_CHECK(x != ev.unsigned_byte_2_3_3_rev);
# endif
# ifdef GL_UNSIGNED_BYTE_3_3_2
	BOOST_CHECK(x != ev.unsigned_byte_3_3_2);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_10_10_10_2
	BOOST_CHECK(x != ev.unsigned_int_10_10_10_2);
# endif
# ifdef GL_UNSIGNED_INT_10F_11F_11F_REV
	BOOST_CHECK(x != ev.unsigned_int_10f_11f_11f_rev);
# endif
# ifdef GL_UNSIGNED_INT_24_8
	BOOST_CHECK(x != ev.unsigned_int_24_8);
# endif
# ifdef GL_UNSIGNED_INT_2_10_10_10_REV
	BOOST_CHECK(x != ev.unsigned_int_2_10_10_10_rev);
# endif
# ifdef GL_UNSIGNED_INT_5_9_9_9_REV
	BOOST_CHECK(x != ev.unsigned_int_5_9_9_9_rev);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8_REV
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8_rev);
# endif
# ifdef GL_UNSIGNED_SHORT
	BOOST_CHECK(x != ev.unsigned_short);
# endif
# ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
	BOOST_CHECK(x != ev.unsigned_short_1_5_5_5_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_5_5_5_1
	BOOST_CHECK(x != ev.unsigned_short_5_5_5_1);
# endif
	BOOST_CHECK(x == ev.unsigned_short_5_6_5);
# ifdef GL_UNSIGNED_SHORT_5_6_5_REV
	BOOST_CHECK(x != ev.unsigned_short_5_6_5_rev);
# endif
#endif

#ifdef GL_UNSIGNED_SHORT_5_6_5_REV
	x = ev.unsigned_short_5_6_5_rev;
# ifdef GL_BYTE
	BOOST_CHECK(x != ev.byte_);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_32_UNSIGNED_INT_24_8_REV
	BOOST_CHECK(x != ev.float_32_unsigned_int_24_8_rev);
# endif
# ifdef GL_HALF_FLOAT
	BOOST_CHECK(x != ev.half_float);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_SHORT
	BOOST_CHECK(x != ev.short_);
# endif
# ifdef GL_UNSIGNED_BYTE
	BOOST_CHECK(x != ev.unsigned_byte);
# endif
# ifdef GL_UNSIGNED_BYTE_2_3_3_REV
	BOOST_CHECK(x != ev.unsigned_byte_2_3_3_rev);
# endif
# ifdef GL_UNSIGNED_BYTE_3_3_2
	BOOST_CHECK(x != ev.unsigned_byte_3_3_2);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_10_10_10_2
	BOOST_CHECK(x != ev.unsigned_int_10_10_10_2);
# endif
# ifdef GL_UNSIGNED_INT_10F_11F_11F_REV
	BOOST_CHECK(x != ev.unsigned_int_10f_11f_11f_rev);
# endif
# ifdef GL_UNSIGNED_INT_24_8
	BOOST_CHECK(x != ev.unsigned_int_24_8);
# endif
# ifdef GL_UNSIGNED_INT_2_10_10_10_REV
	BOOST_CHECK(x != ev.unsigned_int_2_10_10_10_rev);
# endif
# ifdef GL_UNSIGNED_INT_5_9_9_9_REV
	BOOST_CHECK(x != ev.unsigned_int_5_9_9_9_rev);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8_REV
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8_rev);
# endif
# ifdef GL_UNSIGNED_SHORT
	BOOST_CHECK(x != ev.unsigned_short);
# endif
# ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
	BOOST_CHECK(x != ev.unsigned_short_1_5_5_5_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_5_5_5_1
	BOOST_CHECK(x != ev.unsigned_short_5_5_5_1);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5
	BOOST_CHECK(x != ev.unsigned_short_5_6_5);
# endif
	BOOST_CHECK(x == ev.unsigned_short_5_6_5_rev);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
