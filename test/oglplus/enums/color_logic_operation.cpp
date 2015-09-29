//  File test/oglplus/enums/color_logic_operation.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_color_logic_operation

#include <boost/test/unit_test.hpp>
#include "common.hpp"

BOOST_AUTO_TEST_SUITE(enum_color_logic_operation)

BOOST_AUTO_TEST_CASE(enum_color_logic_operation_values)
{
	using namespace oglplus;
	enum_values ev;
	color_logic_operation x;

#ifdef GL_AND
	x = ev.and_;
	BOOST_CHECK(x == ev.and_);
# ifdef GL_AND_INVERTED
	BOOST_CHECK(x != ev.and_inverted);
# endif
# ifdef GL_AND_REVERSE
	BOOST_CHECK(x != ev.and_reverse);
# endif
# ifdef GL_CLEAR
	BOOST_CHECK(x != ev.clear);
# endif
# ifdef GL_COPY
	BOOST_CHECK(x != ev.copy);
# endif
# ifdef GL_COPY_INVERTED
	BOOST_CHECK(x != ev.copy_inverted);
# endif
# ifdef GL_EQUIV
	BOOST_CHECK(x != ev.equiv);
# endif
# ifdef GL_INVERT
	BOOST_CHECK(x != ev.invert);
# endif
# ifdef GL_NAND
	BOOST_CHECK(x != ev.nand);
# endif
# ifdef GL_NOOP
	BOOST_CHECK(x != ev.noop);
# endif
# ifdef GL_NOR
	BOOST_CHECK(x != ev.nor);
# endif
# ifdef GL_OR
	BOOST_CHECK(x != ev.or_);
# endif
# ifdef GL_OR_INVERTED
	BOOST_CHECK(x != ev.or_inverted);
# endif
# ifdef GL_OR_REVERSE
	BOOST_CHECK(x != ev.or_reverse);
# endif
# ifdef GL_SET
	BOOST_CHECK(x != ev.set);
# endif
# ifdef GL_XOR
	BOOST_CHECK(x != ev.xor_);
# endif
#endif

#ifdef GL_AND_INVERTED
	x = ev.and_inverted;
# ifdef GL_AND
	BOOST_CHECK(x != ev.and_);
# endif
	BOOST_CHECK(x == ev.and_inverted);
# ifdef GL_AND_REVERSE
	BOOST_CHECK(x != ev.and_reverse);
# endif
# ifdef GL_CLEAR
	BOOST_CHECK(x != ev.clear);
# endif
# ifdef GL_COPY
	BOOST_CHECK(x != ev.copy);
# endif
# ifdef GL_COPY_INVERTED
	BOOST_CHECK(x != ev.copy_inverted);
# endif
# ifdef GL_EQUIV
	BOOST_CHECK(x != ev.equiv);
# endif
# ifdef GL_INVERT
	BOOST_CHECK(x != ev.invert);
# endif
# ifdef GL_NAND
	BOOST_CHECK(x != ev.nand);
# endif
# ifdef GL_NOOP
	BOOST_CHECK(x != ev.noop);
# endif
# ifdef GL_NOR
	BOOST_CHECK(x != ev.nor);
# endif
# ifdef GL_OR
	BOOST_CHECK(x != ev.or_);
# endif
# ifdef GL_OR_INVERTED
	BOOST_CHECK(x != ev.or_inverted);
# endif
# ifdef GL_OR_REVERSE
	BOOST_CHECK(x != ev.or_reverse);
# endif
# ifdef GL_SET
	BOOST_CHECK(x != ev.set);
# endif
# ifdef GL_XOR
	BOOST_CHECK(x != ev.xor_);
# endif
#endif

#ifdef GL_AND_REVERSE
	x = ev.and_reverse;
# ifdef GL_AND
	BOOST_CHECK(x != ev.and_);
# endif
# ifdef GL_AND_INVERTED
	BOOST_CHECK(x != ev.and_inverted);
# endif
	BOOST_CHECK(x == ev.and_reverse);
# ifdef GL_CLEAR
	BOOST_CHECK(x != ev.clear);
# endif
# ifdef GL_COPY
	BOOST_CHECK(x != ev.copy);
# endif
# ifdef GL_COPY_INVERTED
	BOOST_CHECK(x != ev.copy_inverted);
# endif
# ifdef GL_EQUIV
	BOOST_CHECK(x != ev.equiv);
# endif
# ifdef GL_INVERT
	BOOST_CHECK(x != ev.invert);
# endif
# ifdef GL_NAND
	BOOST_CHECK(x != ev.nand);
# endif
# ifdef GL_NOOP
	BOOST_CHECK(x != ev.noop);
# endif
# ifdef GL_NOR
	BOOST_CHECK(x != ev.nor);
# endif
# ifdef GL_OR
	BOOST_CHECK(x != ev.or_);
# endif
# ifdef GL_OR_INVERTED
	BOOST_CHECK(x != ev.or_inverted);
# endif
# ifdef GL_OR_REVERSE
	BOOST_CHECK(x != ev.or_reverse);
# endif
# ifdef GL_SET
	BOOST_CHECK(x != ev.set);
# endif
# ifdef GL_XOR
	BOOST_CHECK(x != ev.xor_);
# endif
#endif

#ifdef GL_CLEAR
	x = ev.clear;
# ifdef GL_AND
	BOOST_CHECK(x != ev.and_);
# endif
# ifdef GL_AND_INVERTED
	BOOST_CHECK(x != ev.and_inverted);
# endif
# ifdef GL_AND_REVERSE
	BOOST_CHECK(x != ev.and_reverse);
# endif
	BOOST_CHECK(x == ev.clear);
# ifdef GL_COPY
	BOOST_CHECK(x != ev.copy);
# endif
# ifdef GL_COPY_INVERTED
	BOOST_CHECK(x != ev.copy_inverted);
# endif
# ifdef GL_EQUIV
	BOOST_CHECK(x != ev.equiv);
# endif
# ifdef GL_INVERT
	BOOST_CHECK(x != ev.invert);
# endif
# ifdef GL_NAND
	BOOST_CHECK(x != ev.nand);
# endif
# ifdef GL_NOOP
	BOOST_CHECK(x != ev.noop);
# endif
# ifdef GL_NOR
	BOOST_CHECK(x != ev.nor);
# endif
# ifdef GL_OR
	BOOST_CHECK(x != ev.or_);
# endif
# ifdef GL_OR_INVERTED
	BOOST_CHECK(x != ev.or_inverted);
# endif
# ifdef GL_OR_REVERSE
	BOOST_CHECK(x != ev.or_reverse);
# endif
# ifdef GL_SET
	BOOST_CHECK(x != ev.set);
# endif
# ifdef GL_XOR
	BOOST_CHECK(x != ev.xor_);
# endif
#endif

#ifdef GL_COPY
	x = ev.copy;
# ifdef GL_AND
	BOOST_CHECK(x != ev.and_);
# endif
# ifdef GL_AND_INVERTED
	BOOST_CHECK(x != ev.and_inverted);
# endif
# ifdef GL_AND_REVERSE
	BOOST_CHECK(x != ev.and_reverse);
# endif
# ifdef GL_CLEAR
	BOOST_CHECK(x != ev.clear);
# endif
	BOOST_CHECK(x == ev.copy);
# ifdef GL_COPY_INVERTED
	BOOST_CHECK(x != ev.copy_inverted);
# endif
# ifdef GL_EQUIV
	BOOST_CHECK(x != ev.equiv);
# endif
# ifdef GL_INVERT
	BOOST_CHECK(x != ev.invert);
# endif
# ifdef GL_NAND
	BOOST_CHECK(x != ev.nand);
# endif
# ifdef GL_NOOP
	BOOST_CHECK(x != ev.noop);
# endif
# ifdef GL_NOR
	BOOST_CHECK(x != ev.nor);
# endif
# ifdef GL_OR
	BOOST_CHECK(x != ev.or_);
# endif
# ifdef GL_OR_INVERTED
	BOOST_CHECK(x != ev.or_inverted);
# endif
# ifdef GL_OR_REVERSE
	BOOST_CHECK(x != ev.or_reverse);
# endif
# ifdef GL_SET
	BOOST_CHECK(x != ev.set);
# endif
# ifdef GL_XOR
	BOOST_CHECK(x != ev.xor_);
# endif
#endif

#ifdef GL_COPY_INVERTED
	x = ev.copy_inverted;
# ifdef GL_AND
	BOOST_CHECK(x != ev.and_);
# endif
# ifdef GL_AND_INVERTED
	BOOST_CHECK(x != ev.and_inverted);
# endif
# ifdef GL_AND_REVERSE
	BOOST_CHECK(x != ev.and_reverse);
# endif
# ifdef GL_CLEAR
	BOOST_CHECK(x != ev.clear);
# endif
# ifdef GL_COPY
	BOOST_CHECK(x != ev.copy);
# endif
	BOOST_CHECK(x == ev.copy_inverted);
# ifdef GL_EQUIV
	BOOST_CHECK(x != ev.equiv);
# endif
# ifdef GL_INVERT
	BOOST_CHECK(x != ev.invert);
# endif
# ifdef GL_NAND
	BOOST_CHECK(x != ev.nand);
# endif
# ifdef GL_NOOP
	BOOST_CHECK(x != ev.noop);
# endif
# ifdef GL_NOR
	BOOST_CHECK(x != ev.nor);
# endif
# ifdef GL_OR
	BOOST_CHECK(x != ev.or_);
# endif
# ifdef GL_OR_INVERTED
	BOOST_CHECK(x != ev.or_inverted);
# endif
# ifdef GL_OR_REVERSE
	BOOST_CHECK(x != ev.or_reverse);
# endif
# ifdef GL_SET
	BOOST_CHECK(x != ev.set);
# endif
# ifdef GL_XOR
	BOOST_CHECK(x != ev.xor_);
# endif
#endif

#ifdef GL_EQUIV
	x = ev.equiv;
# ifdef GL_AND
	BOOST_CHECK(x != ev.and_);
# endif
# ifdef GL_AND_INVERTED
	BOOST_CHECK(x != ev.and_inverted);
# endif
# ifdef GL_AND_REVERSE
	BOOST_CHECK(x != ev.and_reverse);
# endif
# ifdef GL_CLEAR
	BOOST_CHECK(x != ev.clear);
# endif
# ifdef GL_COPY
	BOOST_CHECK(x != ev.copy);
# endif
# ifdef GL_COPY_INVERTED
	BOOST_CHECK(x != ev.copy_inverted);
# endif
	BOOST_CHECK(x == ev.equiv);
# ifdef GL_INVERT
	BOOST_CHECK(x != ev.invert);
# endif
# ifdef GL_NAND
	BOOST_CHECK(x != ev.nand);
# endif
# ifdef GL_NOOP
	BOOST_CHECK(x != ev.noop);
# endif
# ifdef GL_NOR
	BOOST_CHECK(x != ev.nor);
# endif
# ifdef GL_OR
	BOOST_CHECK(x != ev.or_);
# endif
# ifdef GL_OR_INVERTED
	BOOST_CHECK(x != ev.or_inverted);
# endif
# ifdef GL_OR_REVERSE
	BOOST_CHECK(x != ev.or_reverse);
# endif
# ifdef GL_SET
	BOOST_CHECK(x != ev.set);
# endif
# ifdef GL_XOR
	BOOST_CHECK(x != ev.xor_);
# endif
#endif

#ifdef GL_INVERT
	x = ev.invert;
# ifdef GL_AND
	BOOST_CHECK(x != ev.and_);
# endif
# ifdef GL_AND_INVERTED
	BOOST_CHECK(x != ev.and_inverted);
# endif
# ifdef GL_AND_REVERSE
	BOOST_CHECK(x != ev.and_reverse);
# endif
# ifdef GL_CLEAR
	BOOST_CHECK(x != ev.clear);
# endif
# ifdef GL_COPY
	BOOST_CHECK(x != ev.copy);
# endif
# ifdef GL_COPY_INVERTED
	BOOST_CHECK(x != ev.copy_inverted);
# endif
# ifdef GL_EQUIV
	BOOST_CHECK(x != ev.equiv);
# endif
	BOOST_CHECK(x == ev.invert);
# ifdef GL_NAND
	BOOST_CHECK(x != ev.nand);
# endif
# ifdef GL_NOOP
	BOOST_CHECK(x != ev.noop);
# endif
# ifdef GL_NOR
	BOOST_CHECK(x != ev.nor);
# endif
# ifdef GL_OR
	BOOST_CHECK(x != ev.or_);
# endif
# ifdef GL_OR_INVERTED
	BOOST_CHECK(x != ev.or_inverted);
# endif
# ifdef GL_OR_REVERSE
	BOOST_CHECK(x != ev.or_reverse);
# endif
# ifdef GL_SET
	BOOST_CHECK(x != ev.set);
# endif
# ifdef GL_XOR
	BOOST_CHECK(x != ev.xor_);
# endif
#endif

#ifdef GL_NAND
	x = ev.nand;
# ifdef GL_AND
	BOOST_CHECK(x != ev.and_);
# endif
# ifdef GL_AND_INVERTED
	BOOST_CHECK(x != ev.and_inverted);
# endif
# ifdef GL_AND_REVERSE
	BOOST_CHECK(x != ev.and_reverse);
# endif
# ifdef GL_CLEAR
	BOOST_CHECK(x != ev.clear);
# endif
# ifdef GL_COPY
	BOOST_CHECK(x != ev.copy);
# endif
# ifdef GL_COPY_INVERTED
	BOOST_CHECK(x != ev.copy_inverted);
# endif
# ifdef GL_EQUIV
	BOOST_CHECK(x != ev.equiv);
# endif
# ifdef GL_INVERT
	BOOST_CHECK(x != ev.invert);
# endif
	BOOST_CHECK(x == ev.nand);
# ifdef GL_NOOP
	BOOST_CHECK(x != ev.noop);
# endif
# ifdef GL_NOR
	BOOST_CHECK(x != ev.nor);
# endif
# ifdef GL_OR
	BOOST_CHECK(x != ev.or_);
# endif
# ifdef GL_OR_INVERTED
	BOOST_CHECK(x != ev.or_inverted);
# endif
# ifdef GL_OR_REVERSE
	BOOST_CHECK(x != ev.or_reverse);
# endif
# ifdef GL_SET
	BOOST_CHECK(x != ev.set);
# endif
# ifdef GL_XOR
	BOOST_CHECK(x != ev.xor_);
# endif
#endif

#ifdef GL_NOOP
	x = ev.noop;
# ifdef GL_AND
	BOOST_CHECK(x != ev.and_);
# endif
# ifdef GL_AND_INVERTED
	BOOST_CHECK(x != ev.and_inverted);
# endif
# ifdef GL_AND_REVERSE
	BOOST_CHECK(x != ev.and_reverse);
# endif
# ifdef GL_CLEAR
	BOOST_CHECK(x != ev.clear);
# endif
# ifdef GL_COPY
	BOOST_CHECK(x != ev.copy);
# endif
# ifdef GL_COPY_INVERTED
	BOOST_CHECK(x != ev.copy_inverted);
# endif
# ifdef GL_EQUIV
	BOOST_CHECK(x != ev.equiv);
# endif
# ifdef GL_INVERT
	BOOST_CHECK(x != ev.invert);
# endif
# ifdef GL_NAND
	BOOST_CHECK(x != ev.nand);
# endif
	BOOST_CHECK(x == ev.noop);
# ifdef GL_NOR
	BOOST_CHECK(x != ev.nor);
# endif
# ifdef GL_OR
	BOOST_CHECK(x != ev.or_);
# endif
# ifdef GL_OR_INVERTED
	BOOST_CHECK(x != ev.or_inverted);
# endif
# ifdef GL_OR_REVERSE
	BOOST_CHECK(x != ev.or_reverse);
# endif
# ifdef GL_SET
	BOOST_CHECK(x != ev.set);
# endif
# ifdef GL_XOR
	BOOST_CHECK(x != ev.xor_);
# endif
#endif

#ifdef GL_NOR
	x = ev.nor;
# ifdef GL_AND
	BOOST_CHECK(x != ev.and_);
# endif
# ifdef GL_AND_INVERTED
	BOOST_CHECK(x != ev.and_inverted);
# endif
# ifdef GL_AND_REVERSE
	BOOST_CHECK(x != ev.and_reverse);
# endif
# ifdef GL_CLEAR
	BOOST_CHECK(x != ev.clear);
# endif
# ifdef GL_COPY
	BOOST_CHECK(x != ev.copy);
# endif
# ifdef GL_COPY_INVERTED
	BOOST_CHECK(x != ev.copy_inverted);
# endif
# ifdef GL_EQUIV
	BOOST_CHECK(x != ev.equiv);
# endif
# ifdef GL_INVERT
	BOOST_CHECK(x != ev.invert);
# endif
# ifdef GL_NAND
	BOOST_CHECK(x != ev.nand);
# endif
# ifdef GL_NOOP
	BOOST_CHECK(x != ev.noop);
# endif
	BOOST_CHECK(x == ev.nor);
# ifdef GL_OR
	BOOST_CHECK(x != ev.or_);
# endif
# ifdef GL_OR_INVERTED
	BOOST_CHECK(x != ev.or_inverted);
# endif
# ifdef GL_OR_REVERSE
	BOOST_CHECK(x != ev.or_reverse);
# endif
# ifdef GL_SET
	BOOST_CHECK(x != ev.set);
# endif
# ifdef GL_XOR
	BOOST_CHECK(x != ev.xor_);
# endif
#endif

#ifdef GL_OR
	x = ev.or_;
# ifdef GL_AND
	BOOST_CHECK(x != ev.and_);
# endif
# ifdef GL_AND_INVERTED
	BOOST_CHECK(x != ev.and_inverted);
# endif
# ifdef GL_AND_REVERSE
	BOOST_CHECK(x != ev.and_reverse);
# endif
# ifdef GL_CLEAR
	BOOST_CHECK(x != ev.clear);
# endif
# ifdef GL_COPY
	BOOST_CHECK(x != ev.copy);
# endif
# ifdef GL_COPY_INVERTED
	BOOST_CHECK(x != ev.copy_inverted);
# endif
# ifdef GL_EQUIV
	BOOST_CHECK(x != ev.equiv);
# endif
# ifdef GL_INVERT
	BOOST_CHECK(x != ev.invert);
# endif
# ifdef GL_NAND
	BOOST_CHECK(x != ev.nand);
# endif
# ifdef GL_NOOP
	BOOST_CHECK(x != ev.noop);
# endif
# ifdef GL_NOR
	BOOST_CHECK(x != ev.nor);
# endif
	BOOST_CHECK(x == ev.or_);
# ifdef GL_OR_INVERTED
	BOOST_CHECK(x != ev.or_inverted);
# endif
# ifdef GL_OR_REVERSE
	BOOST_CHECK(x != ev.or_reverse);
# endif
# ifdef GL_SET
	BOOST_CHECK(x != ev.set);
# endif
# ifdef GL_XOR
	BOOST_CHECK(x != ev.xor_);
# endif
#endif

#ifdef GL_OR_INVERTED
	x = ev.or_inverted;
# ifdef GL_AND
	BOOST_CHECK(x != ev.and_);
# endif
# ifdef GL_AND_INVERTED
	BOOST_CHECK(x != ev.and_inverted);
# endif
# ifdef GL_AND_REVERSE
	BOOST_CHECK(x != ev.and_reverse);
# endif
# ifdef GL_CLEAR
	BOOST_CHECK(x != ev.clear);
# endif
# ifdef GL_COPY
	BOOST_CHECK(x != ev.copy);
# endif
# ifdef GL_COPY_INVERTED
	BOOST_CHECK(x != ev.copy_inverted);
# endif
# ifdef GL_EQUIV
	BOOST_CHECK(x != ev.equiv);
# endif
# ifdef GL_INVERT
	BOOST_CHECK(x != ev.invert);
# endif
# ifdef GL_NAND
	BOOST_CHECK(x != ev.nand);
# endif
# ifdef GL_NOOP
	BOOST_CHECK(x != ev.noop);
# endif
# ifdef GL_NOR
	BOOST_CHECK(x != ev.nor);
# endif
# ifdef GL_OR
	BOOST_CHECK(x != ev.or_);
# endif
	BOOST_CHECK(x == ev.or_inverted);
# ifdef GL_OR_REVERSE
	BOOST_CHECK(x != ev.or_reverse);
# endif
# ifdef GL_SET
	BOOST_CHECK(x != ev.set);
# endif
# ifdef GL_XOR
	BOOST_CHECK(x != ev.xor_);
# endif
#endif

#ifdef GL_OR_REVERSE
	x = ev.or_reverse;
# ifdef GL_AND
	BOOST_CHECK(x != ev.and_);
# endif
# ifdef GL_AND_INVERTED
	BOOST_CHECK(x != ev.and_inverted);
# endif
# ifdef GL_AND_REVERSE
	BOOST_CHECK(x != ev.and_reverse);
# endif
# ifdef GL_CLEAR
	BOOST_CHECK(x != ev.clear);
# endif
# ifdef GL_COPY
	BOOST_CHECK(x != ev.copy);
# endif
# ifdef GL_COPY_INVERTED
	BOOST_CHECK(x != ev.copy_inverted);
# endif
# ifdef GL_EQUIV
	BOOST_CHECK(x != ev.equiv);
# endif
# ifdef GL_INVERT
	BOOST_CHECK(x != ev.invert);
# endif
# ifdef GL_NAND
	BOOST_CHECK(x != ev.nand);
# endif
# ifdef GL_NOOP
	BOOST_CHECK(x != ev.noop);
# endif
# ifdef GL_NOR
	BOOST_CHECK(x != ev.nor);
# endif
# ifdef GL_OR
	BOOST_CHECK(x != ev.or_);
# endif
# ifdef GL_OR_INVERTED
	BOOST_CHECK(x != ev.or_inverted);
# endif
	BOOST_CHECK(x == ev.or_reverse);
# ifdef GL_SET
	BOOST_CHECK(x != ev.set);
# endif
# ifdef GL_XOR
	BOOST_CHECK(x != ev.xor_);
# endif
#endif

#ifdef GL_SET
	x = ev.set;
# ifdef GL_AND
	BOOST_CHECK(x != ev.and_);
# endif
# ifdef GL_AND_INVERTED
	BOOST_CHECK(x != ev.and_inverted);
# endif
# ifdef GL_AND_REVERSE
	BOOST_CHECK(x != ev.and_reverse);
# endif
# ifdef GL_CLEAR
	BOOST_CHECK(x != ev.clear);
# endif
# ifdef GL_COPY
	BOOST_CHECK(x != ev.copy);
# endif
# ifdef GL_COPY_INVERTED
	BOOST_CHECK(x != ev.copy_inverted);
# endif
# ifdef GL_EQUIV
	BOOST_CHECK(x != ev.equiv);
# endif
# ifdef GL_INVERT
	BOOST_CHECK(x != ev.invert);
# endif
# ifdef GL_NAND
	BOOST_CHECK(x != ev.nand);
# endif
# ifdef GL_NOOP
	BOOST_CHECK(x != ev.noop);
# endif
# ifdef GL_NOR
	BOOST_CHECK(x != ev.nor);
# endif
# ifdef GL_OR
	BOOST_CHECK(x != ev.or_);
# endif
# ifdef GL_OR_INVERTED
	BOOST_CHECK(x != ev.or_inverted);
# endif
# ifdef GL_OR_REVERSE
	BOOST_CHECK(x != ev.or_reverse);
# endif
	BOOST_CHECK(x == ev.set);
# ifdef GL_XOR
	BOOST_CHECK(x != ev.xor_);
# endif
#endif

#ifdef GL_XOR
	x = ev.xor_;
# ifdef GL_AND
	BOOST_CHECK(x != ev.and_);
# endif
# ifdef GL_AND_INVERTED
	BOOST_CHECK(x != ev.and_inverted);
# endif
# ifdef GL_AND_REVERSE
	BOOST_CHECK(x != ev.and_reverse);
# endif
# ifdef GL_CLEAR
	BOOST_CHECK(x != ev.clear);
# endif
# ifdef GL_COPY
	BOOST_CHECK(x != ev.copy);
# endif
# ifdef GL_COPY_INVERTED
	BOOST_CHECK(x != ev.copy_inverted);
# endif
# ifdef GL_EQUIV
	BOOST_CHECK(x != ev.equiv);
# endif
# ifdef GL_INVERT
	BOOST_CHECK(x != ev.invert);
# endif
# ifdef GL_NAND
	BOOST_CHECK(x != ev.nand);
# endif
# ifdef GL_NOOP
	BOOST_CHECK(x != ev.noop);
# endif
# ifdef GL_NOR
	BOOST_CHECK(x != ev.nor);
# endif
# ifdef GL_OR
	BOOST_CHECK(x != ev.or_);
# endif
# ifdef GL_OR_INVERTED
	BOOST_CHECK(x != ev.or_inverted);
# endif
# ifdef GL_OR_REVERSE
	BOOST_CHECK(x != ev.or_reverse);
# endif
# ifdef GL_SET
	BOOST_CHECK(x != ev.set);
# endif
	BOOST_CHECK(x == ev.xor_);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
