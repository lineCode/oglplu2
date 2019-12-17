/**
 *  @file oalplus/al_api/enum_types.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_AL_API_ENUM_TYPES_HPP
#define OALPLUS_AL_API_ENUM_TYPES_HPP

#include "api_types.hpp"
#include "enum_class.hpp"

namespace eagine {
namespace oalp {
//------------------------------------------------------------------------------
struct al_error_code : al_enum_class<al_error_code, al_types::enum_type, 0> {
    using enum_class::enum_class;
};

struct al_string_query
  : al_enum_class<al_string_query, al_types::enum_type, 1> {
    using enum_class::enum_class;
};
//------------------------------------------------------------------------------
} // namespace oalp
} // namespace eagine

#endif // OALPLUS_AL_API_ENUM_TYPES_HPP

