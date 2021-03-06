/**
 *  file. oglplus/example/main_glfw3.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include "main.hpp"
#include <eagine/main_ctx.hpp>
#include <eagine/maybe_unused.hpp>
#include <oglplus/config/basic.hpp>
#if OGLPLUS_GLFW3_FOUND
#include "state.hpp"
#include "wrapper.hpp"
#include <oglplus/gl.hpp>

#include <eagine/program_args.hpp>
#include <eagine/scope_exit.hpp>

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"
#endif
#include <GLFW/glfw3.h>
#ifdef __clang__
#pragma clang diagnostic pop
#endif

#include <cmath>
#include <iostream>
#include <stdexcept>

static int example_scroll_y = 0;

void example_scroll_callback(GLFWwindow*, double /*x*/, double y) {
    example_scroll_y += int(std::ceil(y));
}
#endif // OGLPLUS_GLFW3_FOUND

namespace eagine {
//------------------------------------------------------------------------------
class example_main_glfw3 : public example_main_intf {
public:
    bool is_implemented() final {
        return (OGLPLUS_GLX_FOUND != 0);
    }

    string_view implementation_name() final {
        return {"GLFW3"};
    }

    int run(example_run_context& erc) final {
#if OGLPLUS_GLFW3_FOUND
        if(!glfwInit()) {
            erc.main.log().error("GLFW initialization error");
            return 2;
        } else {
            auto ensure_glfw_cleanup = eagine::finally(glfwTerminate);

            glfwWindowHint(GLFW_DOUBLEBUFFER, GL_TRUE);
            glfwWindowHint(GLFW_RED_BITS, erc.params.color_bits());
            glfwWindowHint(GLFW_BLUE_BITS, erc.params.color_bits());
            glfwWindowHint(GLFW_GREEN_BITS, erc.params.color_bits());
            glfwWindowHint(GLFW_ALPHA_BITS, erc.params.alpha_bits());
            glfwWindowHint(GLFW_DEPTH_BITS, erc.params.depth_bits());
            glfwWindowHint(GLFW_STENCIL_BITS, erc.params.stencil_bits());

            glfwWindowHint(GLFW_SAMPLES, erc.params.samples() / GLFW_DONT_CARE);

            GLFWwindow* window = glfwCreateWindow(
              erc.state.width(),
              erc.state.height(),
              "OGLplus example (GLFW3)",
              nullptr,
              nullptr);

            if(!window) {
                erc.main.log().error("Failed to create GLFW window");
                return 2;
            } else {
                glfwMakeContextCurrent(window);
                glfwSetWindowTitle(window, "OGLplus example (GLFW3)");
                glfwSetWindowPos(
                  window, erc.params.window_x_pos(), erc.params.window_y_pos());
                glfwSetScrollCallback(window, example_scroll_callback);

                oglp::api_initializer gl_api_init;

                erc.state.set_depth(16);
                example_wrapper example(erc);
                example.context().log().info("using GLFW3 context");

                if(!example.is_ready()) {
                    return 2;
                }
                _example_loop(window, erc, example);
                example.destroy();
            }
        }
        return 0;
#else
        EAGINE_MAYBE_UNUSED(args);
        EAGINE_MAYBE_UNUSED(params);
        EAGINE_MAYBE_UNUSED(state);
        return 1;
#endif
    }

#if OGLPLUS_GLFW3_FOUND
    void _example_loop(
      GLFWwindow* window, example_run_context& erc, example_wrapper& example) {
        auto& state = erc.state;
        int w = state.width();
        int h = state.height();
        double x, y;

        while(true) {
            glfwPollEvents();

            if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
                glfwSetWindowShouldClose(window, 1);
                break;
            }

            if(glfwWindowShouldClose(window)) {
                break;
            }

            glfwGetWindowSize(window, &w, &h);
            example.set_size(w, h);

            glfwGetCursorPos(window, &x, &y);
            example.set_mouse_pos(int(x), h - int(y));

            example.set_mouse_btn(
              1, glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1) == GLFW_PRESS);

            example.set_mouse_wheel(example_scroll_y);

            example.update();

            example.render();
            glfwSwapBuffers(window);

            if(!example.next_frame()) {
                break;
            }
        }
    }
#endif
};
//------------------------------------------------------------------------------
std::unique_ptr<example_main_intf> make_example_main_glfw3() {
    return {std::make_unique<example_main_glfw3>()};
}
//------------------------------------------------------------------------------
} // namespace eagine

