/**
 *  @file eagine/quantities.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_QUANTITIES_1509260923_HPP
#define EAGINE_QUANTITIES_1509260923_HPP

#include "tagged_quantity.hpp"
#include "units/trivial.hpp"
#include <cmath>

namespace eagine {

// seconds
template <typename T>
using seconds_t = tagged_quantity<T, units::second>;

template <typename T>
static inline
seconds_t<T>
seconds_(T value)
noexcept
{
	return seconds_t<T>{value};
}

// radians
template <typename T>
using radians_t = tagged_quantity<T, units::radian>;

template <typename T>
static inline
radians_t<T>
radians_(T value)
noexcept
{
	return radians_t<T>{value};
}

template <
	typename Qty,
	typename = std::enable_if_t<
		is_convertible_quantity<Qty, units::radian>::value
	>
>
static constexpr inline
auto sin(const Qty& qty)
{
	using std::sin;
	return sin(value(convert_to<units::radian>(qty)));
}

template <
	typename Qty,
	typename = std::enable_if_t<
		is_convertible_quantity<Qty, units::radian>::value
	>
>
static constexpr inline
auto cos(const Qty& qty)
{
	using std::cos;
	return cos(value(convert_to<units::radian>(qty)));
}

template <
	typename Qty,
	typename = std::enable_if_t<
		is_convertible_quantity<Qty, units::radian>::value
	>
>
static constexpr inline
auto tan(const Qty& qty)
{
	using std::tan;
	return tan(value(convert_to<units::radian>(qty)));
}

template <typename T>
static constexpr inline
auto arctan(T y, T x)
{
	using std::atan2;
	return make_tagged_quantity<units::radian>(atan2(y, x));
}

// degrees
template <typename T>
using degrees_t = tagged_quantity<T, units::degree>;

template <typename T>
static inline
degrees_t<T>
degrees_(T value)
noexcept
{
	return degrees_t<T>{value};
}

} // namespace eagine

#endif // include guard
