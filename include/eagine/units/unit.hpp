/**
 *  @file eagine/unit/unit.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_UNIT_1512222148_HPP
#define EAGINE_UNITS_UNIT_1512222148_HPP

#include "default.hpp"
#include "traits.hpp"
#include "detail.hpp"

namespace eagine {
namespace units {

template <typename Unit>
struct unit_name;

template <typename Unit>
struct unit_symbol;

// unit
template <typename Dims, typename System>
struct unit
{
	typedef Dims dimension;
	typedef System system;
	typedef scales::one scale;
	typedef unit type;
};

// is_convertible
template <typename D, typename S>
struct is_convertible<unit<D, S>, unit<D, S>>
 : std::true_type
{ };

// value conv
template <typename D, typename S>
struct value_conv<unit<D, S>, unit<D, S>>
 : trivial_value_conv
{ };

// add_result
template <typename D, typename S>
struct add_result<unit<D, S>, unit<D, S>>
 : unit<D, S>
{ };

// sub_result
template <typename D, typename S>
struct sub_result<unit<D, S>, unit<D, S>>
 : unit<D, S>
{ };

// mul_l_operand
template <typename D1, typename D2, typename S>
struct mul_l_operand<unit<D1, S>, unit<D2, S>>
 : unit<D1, S>
{ };

// mul_r_operand
template <typename D1, typename D2, typename S>
struct mul_r_operand<unit<D1, S>, unit<D2, S>>
 : unit<D2, S>
{ };

// mul_result
template <typename D1, typename D2, typename S>
struct mul_result<unit<D1, S>, unit<D2, S>>
 : unit<bits::dim_add_t<D1, D2>, S>
{ };

// div_result
template <typename D1, typename D2, typename S>
struct div_result<unit<D1, S>, unit<D2, S>>
 : unit<bits::dim_sub_t<D1, D2>, S>
{ };

// quotation
template <typename U>
static constexpr inline
std::enable_if_t<
	is_unit<U>::value,
	lit_result_t<U>
> operator !(U) noexcept { return {}; }

// addition
template <typename U1, typename U2>
static constexpr inline
std::enable_if_t<
	is_unit<U1>::value && is_unit<U2>::value,
	add_result_t<U1, U2>
> operator + (U1, U2) noexcept { return {}; }

// subtraction
template <typename U1, typename U2>
static constexpr inline
std::enable_if_t<
	is_unit<U1>::value && is_unit<U2>::value,
	sub_result_t<U1, U2>
> operator - (U1, U2) noexcept { return {}; }

// multiplication
template <typename U1, typename U2>
static constexpr inline
std::enable_if_t<
	is_unit<U1>::value && is_unit<U2>::value,
	mul_result_t<U1, U2>
> operator * (U1, U2) noexcept { return {}; }

// division
template <typename U1, typename U2>
static constexpr inline
std::enable_if_t<
	is_unit<U1>::value && is_unit<U2>::value,
	div_result_t<U1, U2>
> operator / (U1, U2) noexcept { return {}; }

} // namespace units
} // namespace eagine

#endif //include guard

