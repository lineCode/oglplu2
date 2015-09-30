/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE OGLPLUS_error_handling
#include <boost/test/unit_test.hpp>

#include <oglplus/gl.hpp>
#include <oglplus/error/handling.hpp>

BOOST_AUTO_TEST_SUITE(error_handling)

BOOST_AUTO_TEST_CASE(error_handling_1)
{
	using namespace oglplus;

	int passed = 0;

	try
	{
		handle_gl_error(
			error_info()
				.gl_library_name("GL")
				.gl_function_name("Function")
				.source_function("function")
				.source_file("file.cpp")
				.source_line(12345)
				.gl_object_name(23456)
				.gl_subject_name(34567)
				.gl_error_code(GL_OUT_OF_MEMORY)
		);
		BOOST_CHECK_MESSAGE(
			false,
			"Should not get past handle_gl_error"
		);
	}
	catch(oglplus::error& e)
	{
		BOOST_CHECK(e.info().gl_error_code() == GL_OUT_OF_MEMORY);

		BOOST_CHECK((
			(e.info().gl_library_name() == nullptr) ||
			(strcmp(e.info().gl_library_name(), "GL") == 0)
		));

		BOOST_CHECK((
			(e.info().gl_function_name() == nullptr) ||
			(strcmp(e.info().gl_function_name(), "Function") == 0)
		));

		BOOST_CHECK((
			(e.info().source_function() == nullptr) ||
			(strcmp(e.info().source_function(), "function") == 0)
		));

		BOOST_CHECK((
			(e.info().source_file() == nullptr) ||
			(strcmp(e.info().source_file(), "file.cpp") == 0)
		));

		BOOST_CHECK((
			(e.info().source_line() == 0) ||
			(e.info().source_line() ==  12345)
		));

		BOOST_CHECK((
			(e.info().gl_object_name() == e.info().invalid_gl_obj_name()) ||
			(e.info().gl_object_name(), 23456)
		));

		BOOST_CHECK((
			(e.info().gl_subject_name() == e.info().invalid_gl_obj_name()) ||
			(e.info().gl_subject_name(), 34567)
		));
		++passed;
	}
	BOOST_CHECK_EQUAL(passed,1);
}

BOOST_AUTO_TEST_SUITE_END()
