/**
 *  @file oalplus/al_api.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_AL_API_HPP
#define OALPLUS_AL_API_HPP

#include "al_api/api.hpp"
#include "al_api/api_traits.hpp"
#include "al_api/constants.hpp"

namespace eagine {
namespace oalp {
//------------------------------------------------------------------------------
struct al_api
  : basic_al_api<al_api_traits>
  , basic_al_constants<al_api_traits> {
    al_api(al_api_traits& traits)
      : basic_al_api<al_api_traits>(traits)
      , basic_al_constants<al_api_traits>(traits, *this) {
    }
};
//------------------------------------------------------------------------------
} // namespace oalp
} // namespace eagine

#endif // OALPLUS_AL_API_HPP

