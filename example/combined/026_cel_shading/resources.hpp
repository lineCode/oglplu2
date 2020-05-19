/**
 *  example combined/026_cel_shading/resources.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include <oglplus/gl.hpp>
#include <oglplus/gl_api.hpp>

#include <oglplus/shapes/drawing.hpp>

namespace eagine {
class example_context;
namespace oglp {
class example_orbiting_camera;
//------------------------------------------------------------------------------
// program
//------------------------------------------------------------------------------
class cel_program {
private:
    owned_program_name prog;
    uniform_location projection_loc;
    uniform_location modelview_loc;
    float shp_turns{0.f};

public:
    void init(example_context& ctx);
    void set_projection(
      const example_context& ctx, const example_orbiting_camera& camera);
    void set_modelview(const example_context& ctx);

    void bind_position_location(
      const example_context& ctx, vertex_attrib_location loc);
};
//------------------------------------------------------------------------------
// geometry
//------------------------------------------------------------------------------
class icosahedron_geometry {
private:
    owned_vertex_array_name vao;

    owned_buffer_name positions;
    owned_buffer_name indices;

    std::vector<shape_draw_operation> ops;

public:
    void init(example_context& ctx);
    void draw(const example_context& ctx);

    static auto position_loc() noexcept {
        return vertex_attrib_location{0};
    }
};
//------------------------------------------------------------------------------
} // namespace oglp
} // namespace eagine
