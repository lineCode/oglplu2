/**
 *  @file oglplus/context.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_CONTEXT_1509260923_HPP
#define OGLPLUS_CONTEXT_1509260923_HPP

#include "ctxt/capabilities.hpp"
#include "ctxt/viewport.hpp"
#include "ctxt/buffer_clearing.hpp"
#include "ctxt/prog_var_location.hpp"
#include "ctxt/drawing.hpp"
#include "ctxt/synchronization.hpp"

#include "ctxt/object_lifetime.hpp"
#include "ctxt/vertex_array.hpp"
#include "ctxt/buffer.hpp"
#include "ctxt/texture.hpp"
#include "ctxt/shader.hpp"
#include "ctxt/program.hpp"

#include "ctxt/vertex_attrib.hpp"
#include "ctxt/uniform.hpp"

#ifdef GL_ARB_compatibility
#include "ctxt/compatibility.hpp"
#endif

namespace oglplus {

class context
 : public ctxt::capability_state
 , public ctxt::viewport_state
 , public ctxt::buffer_clearing_state
 , public ctxt::buffer_clearing_ops
 , public ctxt::drawing_ops
 , public ctxt::synchronization

 , public ctxt::object_lifetime_ops
 , public ctxt::vertex_array_ops
 , public ctxt::buffer_ops
 , public ctxt::texture_ops
 , public ctxt::shader_ops
 , public ctxt::program_ops

 , public ctxt::prog_var_location_ops
 , public ctxt::vertex_attrib_ops
 , public ctxt::uniform_ops

#ifdef GL_ARB_compatibility
 , public ctxt::compatibility
#endif
{
public:
	using ctxt::vertex_array_ops::bind;
	using ctxt::buffer_ops::bind;
	using ctxt::texture_ops::bind;
};

} // namespace oglplus

#endif // include guard
