/**
 *  @file eagine/vect/cast.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_VECT_CAST_1509260923_HPP
#define EAGINE_VECT_CAST_1509260923_HPP

#include "fill.hpp"
#include "../int_sequence.hpp"

namespace eagine {
namespace vect {

template <typename TF, unsigned NF, bool VF, typename TT, unsigned NT, bool VT>
struct cast;

template <typename T, unsigned N, bool V>
struct cast<T, N, V, T, N, V>
{
	static constexpr inline
	data_t<T, N, V>
	apply(data_param_t<T, N, V> v, T)
	noexcept
	{
		return v;
	}
};

template <typename TF, unsigned NF, bool VF, typename TT, unsigned NT, bool VT>
struct cast
{
private:
	template <std::size_t ... I>
	using _idx_seq = integer_sequence<unsigned, I...>;
	template <std::size_t N>
	using _make_idx_seq = make_integer_sequence<unsigned, N>;

	template <unsigned ... I, unsigned ... D>
	static constexpr inline
	data_t<TT, NT, VT>
	_cast(
		data_param_t<TF, NF, VF> v,
		data_param_t<TT, sizeof...(D), VT> d,
		_idx_seq<I...>,
		_idx_seq<D...>
	) noexcept
	{
		return data_t<TT, NT, VT>{TT(v[I])..., TT(d[D])...};
	}

	template <unsigned ... I>
	static constexpr inline
	data_t<TT, NT, VT>
	_cast(
		data_param_t<TF, NF, VF> v,
		data_param_t<TT, 0u, VT>,
		_idx_seq<I...>,
		_idx_seq<>
	) noexcept
	{
		return data_t<TT, NT, VT>{TT(v[I])...};
	}
public:

	static constexpr inline
	data_t<TT, NT, VT>
	apply(
		data_param_t<TF, NF, VF> v,
		data_param_t<TT, (NT>NF)?NT-NF:0, VT> d
	)
	noexcept
	{
		typedef _make_idx_seq<(NT>NF)?NF:NT> is;
		typedef _make_idx_seq<(NT>NF)?NT-NF:0> ds;
		return _cast(v, d, is(), ds());
	}

	static constexpr inline
	data_t<TT, NT, VT>
	apply(data_param_t<TF, NF, VF> v, TT d)
	noexcept
	{
		return apply(v, fill<TT, (NT>NF)?NT-NF:0, VT>::apply(d));
	}
};

} // namespace vect
} // namespace eagine

#endif //include guard

