/**
 *  @file oalplus/alut_api.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_ALUT_API_HPP
#define OALPLUS_ALUT_API_HPP

#include "alut_api/api.hpp"
#include "alut_api/api_traits.hpp"
#include "alut_api/constants.hpp"
#include "alut_api_fwd.hpp"

namespace eagine::oalp {
//------------------------------------------------------------------------------
template <typename ApiTraits>
class basic_alut_api
  : protected ApiTraits
  , public basic_alut_operations<ApiTraits>
  , public basic_alut_constants<ApiTraits> {
public:
    basic_alut_api(ApiTraits traits)
      : ApiTraits{std::move(traits)}
      , basic_alut_operations<ApiTraits>{*static_cast<ApiTraits*>(this)}
      , basic_alut_constants<ApiTraits>{
          *static_cast<ApiTraits*>(this),
          *static_cast<basic_alut_operations<ApiTraits>*>(this)} {
    }

    basic_alut_api()
      : basic_alut_api{ApiTraits{}} {
    }
};

template <std::size_t I, typename ApiTraits>
typename std::tuple_element<I, basic_alut_api<ApiTraits>>::type& get(
  basic_alut_api<ApiTraits>& x) noexcept {
    return x;
}

template <std::size_t I, typename ApiTraits>
const typename std::tuple_element<I, basic_alut_api<ApiTraits>>::type& get(
  const basic_alut_api<ApiTraits>& x) noexcept {
    return x;
}
//------------------------------------------------------------------------------
} // namespace eagine::oalp

// NOLINTNEXTLINE(cert-dcl58-cpp)
namespace std {
//------------------------------------------------------------------------------
template <typename ApiTraits>
struct tuple_size<eagine::oalp::basic_alut_api<ApiTraits>>
  : public std::integral_constant<std::size_t, 2> {};

template <typename ApiTraits>
struct tuple_element<0, eagine::oalp::basic_alut_api<ApiTraits>> {
    using type = eagine::oalp::basic_alut_operations<ApiTraits>;
};

template <typename ApiTraits>
struct tuple_element<1, eagine::oalp::basic_alut_api<ApiTraits>> {
    using type = eagine::oalp::basic_alut_constants<ApiTraits>;
};
//------------------------------------------------------------------------------
} // namespace std

#endif // OALPLUS_ALUT_API_HPP

