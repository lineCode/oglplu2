/**
 *  @file eagine/memory_block.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MEMORY_BLOCK_1509260923_HPP
#define EAGINE_MEMORY_BLOCK_1509260923_HPP

#include "memory/block.hpp"

namespace eagine {

// TODO: remove this
template <bool IsConst>
using basic_memory_block = memory::basic_block<IsConst>;

using memory_block = memory::block;
using const_memory_block = memory::const_block;

using owned_memory_block = memory::owned_block;

} // namespace eagine

#endif // include guard
