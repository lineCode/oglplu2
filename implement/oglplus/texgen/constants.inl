/**
 *  @file oglplus/texgen/constants.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <iostream>
#include <eagine/math/constants.hpp>

namespace oglplus {
namespace texgen {
namespace expr {
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream& operator << (std::ostream& out, const constant_id& e)
{
	e.constant.expression(out, e.context);
	return out;
}
//------------------------------------------------------------------------------
} // namespace expr
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
slot_data_type
base_constant::value_type(void)
{
	return slot_data_type::float_;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::string
base_constant::identifier(void)
{
	cstr_ref n = name();
	std::string result;
	result.reserve(std::size_t(7+n.size()));
	result.append("oglptg_");
	result.append(n.data(), std::size_t(n.size()));
	return result;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
base_constant::definitions(std::ostream& out, compile_context& ctxt)
{
	if(!ctxt.remembers_constant(*this))
	{
		out << "const " << data_type_name(value_type());
		out << " " << identifier() << " = ";
		value(out, ctxt);
		out << ";" << std::endl << std::endl;
		ctxt.remember_constant(*this);
	}	
	return out;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
base_constant::expression(std::ostream& out, compile_context&)
{
	return out << identifier();
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
cstr_ref
constant_pi::name(void) const
noexcept
{
	return cstr_ref("pi");
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
constant_pi::value(std::ostream& out, compile_context&)
{
	return out << eagine::math::pi;
}
//------------------------------------------------------------------------------
} // namespace texgen
} // namespace oglplus
//------------------------------------------------------------------------------

