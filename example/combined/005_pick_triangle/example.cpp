/**
 *  example combined/005_pick_triangle/example.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include <oglplus/gl.hpp>
#include <oglplus/gl_api.hpp>

#include <eagine/math/intersection.hpp>
#include <oglplus/glsl/string_ref.hpp>
#include <oglplus/math/primitives.hpp>
#include <oglplus/math/vector.hpp>

#include "../example.hpp"

namespace eagine {
namespace oglp {
//------------------------------------------------------------------------------
class example_triangle : public example {
private:
    triangle tri{
      vec3{-0.2F, 0.5F, 0.0F},
      vec3{-0.7F, -0.6F, 0.0F},
      vec3{0.6F, 0.2F, 0.0F}};

    float hl_value{0.F};
    bool is_inside{false};

    owned_vertex_array_name vao;

    owned_buffer_name positions;

    owned_shader_name vs;
    owned_shader_name fs;

    owned_program_name prog;

    uniform_location highlight_loc;

public:
    bool check_requirements(const example_context& ctx) final;
    void init(example_context& ctx) final;
    void cleanup(example_context& ctx) final;
    void update_highlight(const example_context& ctx, float dt);
    void pointer_motion(const example_context& ctx) final;
    void user_idle(const example_context& ctx) final;
    void resize(const example_context& ctx) final;
    void render(const example_context& ctx) final;
    seconds_t<float> default_timeout() final;
};
//------------------------------------------------------------------------------
// example_triangle
//------------------------------------------------------------------------------
bool example_triangle::check_requirements(const example_context& ctx) {
    const auto& [gl, GL] = ctx.gl();
    auto r = ctx.req_mark();

    return r(gl.disable) && r(gl.clear_color) && r(gl.create_shader) &&
           r(gl.shader_source) && r(gl.compile_shader) &&
           r(gl.create_program) && r(gl.attach_shader) && r(gl.link_program) &&
           r(gl.use_program) && r(gl.gen_buffers) && r(gl.bind_buffer) &&
           r(gl.buffer_data) && r(gl.gen_vertex_arrays) &&
           r(gl.bind_vertex_array) && r(gl.get_attrib_location) &&
           r(gl.vertex_attrib_pointer) && r(gl.enable_vertex_attrib_array) &&
           r(gl.get_uniform_location) && r(gl.uniform1f) && r(gl.draw_arrays) &&
           r(GL.vertex_shader) && r(GL.fragment_shader);
}
//------------------------------------------------------------------------------
void example_triangle::init(example_context& ctx) {

    const auto& glapi = ctx.gl();
    const auto& [gl, GL] = glapi;

    gl.clear_color(0.4F, 0.4F, 0.4F, 0.0F);

    // vertex shader
    auto vs_src = embed(EAGINE_ID(VertShader), "vertex.glsl");
    gl.create_shader(GL.vertex_shader) >> vs;
    gl.shader_source(vs, glsl_string_ref(vs_src));
    gl.compile_shader(vs);

    // fragment shader
    auto fs_src = embed(EAGINE_ID(FragShader), "fragment.glsl");
    gl.create_shader(GL.fragment_shader) >> fs;
    gl.shader_source(fs, glsl_string_ref(fs_src));
    gl.compile_shader(fs);
    //
    // program
    gl.create_program() >> prog;
    gl.attach_shader(prog, vs);
    gl.attach_shader(prog, fs);
    gl.link_program(prog);
    gl.use_program(prog);

    // vao
    gl.gen_vertex_arrays() >> vao;
    gl.bind_vertex_array(vao);

    // positions
    const auto position_data = GL.float_.array(
      tri.a().x(),
      tri.a().y(),
      tri.b().x(),
      tri.b().y(),
      tri.c().x(),
      tri.c().y());

    gl.gen_buffers() >> positions;
    gl.bind_buffer(GL.array_buffer, positions);
    gl.buffer_data(GL.array_buffer, view(position_data), GL.static_draw);
    vertex_attrib_location position_loc;
    gl.get_attrib_location(prog, "Position") >> position_loc;

    gl.vertex_attrib_pointer(position_loc, 2, GL.float_, GL.false_);
    gl.enable_vertex_attrib_array(position_loc);

    // uniform
    gl.get_uniform_location(prog, "Highlight") >> highlight_loc;
    glapi.set_uniform(prog, highlight_loc, hl_value);

    gl.disable(GL.depth_test);
}
//------------------------------------------------------------------------------
void example_triangle::cleanup(example_context& ctx) {
    const auto& gl = ctx.gl();

    gl.delete_program(std::move(prog));

    gl.delete_shader(std::move(fs));
    gl.delete_shader(std::move(vs));

    gl.delete_buffers(std::move(positions));

    gl.delete_vertex_arrays(std::move(vao));
}
//------------------------------------------------------------------------------
void example_triangle::update_highlight(const example_context& ctx, float dt) {
    const auto& glapi = ctx.gl();

    if(is_inside) {
        hl_value = math::minimum(hl_value + dt * 3.0F, 1.F);
    } else {
        hl_value = math::maximum(hl_value - dt * 1.0F, 0.F);
    }
    glapi.set_uniform(prog, highlight_loc, hl_value);
}
//------------------------------------------------------------------------------
void example_triangle::pointer_motion(const example_context& ctx) {
    const auto& state = ctx.state();
    const auto x = state.ndc_pointer_x();
    const auto y = state.ndc_pointer_y();
    line ray(vec3(x, y, 1.F), vec3(0.F, 0.F, -1.F));

    is_inside = bool(eagine::math::line_triangle_intersection(ray, tri));
    update_highlight(ctx, state.frame_duration().value());
}
//------------------------------------------------------------------------------
void example_triangle::user_idle(const example_context& ctx) {
    update_highlight(ctx, ctx.state().frame_duration().value());
}
//------------------------------------------------------------------------------
void example_triangle::resize(const example_context& ctx) {
    const auto& [gl, GL] = ctx.gl();
    EAGINE_MAYBE_UNUSED(GL);
    const auto& state = ctx.state();
    gl.viewport(state.width(), state.height());
}
//------------------------------------------------------------------------------
seconds_t<float> example_triangle::default_timeout() {
    return seconds_(20);
}
//------------------------------------------------------------------------------
void example_triangle::render(const example_context& ctx) {
    const auto& [gl, GL] = ctx.gl();
    gl.draw_arrays(GL.triangles, 0, 3);
}
//------------------------------------------------------------------------------
} // namespace oglp
//------------------------------------------------------------------------------
std::unique_ptr<example> make_example(
  const example_args&, const example_context&) {
    return std::make_unique<oglp::example_triangle>();
}
//------------------------------------------------------------------------------
void adjust_params(example_params& params) {
    params.depth_buffer(false);
    params.stencil_buffer(false);
}
//------------------------------------------------------------------------------
bool is_example_param(const example_arg&) {
    return false;
}
//------------------------------------------------------------------------------
} // namespace eagine
