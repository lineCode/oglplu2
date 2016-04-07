/**
 *  @file oglplus/texgen/render_node.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_TEXGEN_RENDER_NODE_1509260923_HPP
#define OGLPLUS_TEXGEN_RENDER_NODE_1509260923_HPP

#include "fallback_input.hpp"
#include "base_node.hpp"
#include "../program.hpp"
#include "../buffer.hpp"
#include "../vertex_array.hpp"
#include "../uniform.hpp"
#include <oglplus/utils/valid_if.hpp>

namespace oglplus {
namespace texgen {

class render_node
 : public base_node
{
private:
	input_with_const_default<float[4]> _input;

	owned<program_name> _prog;
	owned<buffer_name> _data;
	owned<vertex_array_name> _vao;

	uniform_location _voxel_size;

	void _init_screen(void);
	void _update_program(void);

	int _xdiv, _ydiv, _tile;

	unsigned _render_version;
	render_params _render_params;
public:
	render_node(void);
	render_node(const render_node&) = delete;
	~render_node(void);

	std::ostream&
	make_fragment_shader_source(std::ostream&, compile_context&);

	void draw_screen(void);

	cstr_ref type_name(void)
	override;

	std::size_t input_count(void)
	override;

	input_intf& input(std::size_t index)
	override;

	void update_needed(void)
	override;

	bool render(const render_params&)
	override;

	bool render(void);

	void set_size(
		valid_if_positive<int> width,
		valid_if_positive<int> height
	);
};

} // namespace texgen
} // namespace oglplus

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/texgen/render_node.inl>
#endif

#endif // include guard