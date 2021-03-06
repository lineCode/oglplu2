/**
 *  .file oglplus/example/wrapper.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include "wrapper.hpp"
#include "state.hpp"
#include <eagine/span.hpp>
#include <oglplus/gl.hpp>
#include <cassert>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>

namespace eagine {
//------------------------------------------------------------------------------
example_wrapper::example_wrapper(example_run_context& erc)
  : _context(erc)
  , _example(make_example(erc.args, _context))
  , _screenshot_done(false) {

    if(_example) {
        _context.log().debug("checking example requirements");
        if(_example->check_requirements(_context)) {
            _context.log().debug("initializing example");
            _example->init(_context);

            erc.state.sync_size();
            _example->resize(_context);
            _context.log()
              .debug("initial surface resize to ${width}x${height}")
              .arg(EAGINE_ID(width), _context.state().width())
              .arg(EAGINE_ID(height), _context.state().height());

            erc.state.center_mouse();
            _example->pointer_motion(_context);
            _context.log()
              .trace("initial pointer centering to ${x},${y}")
              .arg(EAGINE_ID(x), _context.state().mouse_x())
              .arg(EAGINE_ID(y), _context.state().mouse_y());

            if(erc.params.doing_framedump()) {
                textbuf(1024);
                std::cin.getline(
                  _textbuf.data(), std::streamsize(_textbuf.size()));

                if(
                  std::strncmp(
                    c_str(erc.params.framedump_prefix()),
                    _textbuf.data(),
                    _textbuf.size()) != 0) {
                    throw std::runtime_error(
                      "Expected frame-dump prefix on stdin");
                }
            }

            if(erc.state.multiple_tiles() && erc.params.auto_tiles()) {
                glEnable(GL_SCISSOR_TEST);
            }
        } else {
            _context.log().warning(
              "example requirement check failed; cleaning up");
            _example.reset();
        }
    }
    _start = clock_type::now();
    _now = _start;
    _context.log().trace("example wrapper initialized");
}
//------------------------------------------------------------------------------
bool example_wrapper::is_ready() const {
    return bool(_example);
}
//------------------------------------------------------------------------------
void example_wrapper::destroy() {
    if(_example) {
        _context.log().debug("cleaning-up example");
        _example->cleanup(_context);
        EAGINE_ASSERT(_context.cleanup().is_empty());
        _example.reset();
    }
    _context.log().trace("example wrapper destroyed");
}
//------------------------------------------------------------------------------
std::vector<char>& example_wrapper::pixels() {
    auto& state = _context.state();

    const auto size = std_size(state.height().get() * state.width().get() * 4);

    if(_pixel_data.size() < size) {
        _pixel_data.resize(size);
    }

    return _pixel_data;
}
//------------------------------------------------------------------------------
std::vector<char>& example_wrapper::textbuf(std::size_t size) {
    if(_textbuf.size() < size) {
        _textbuf.resize(size);
    }

    return _textbuf;
}
//------------------------------------------------------------------------------
bool example_wrapper::next_frame() {

    auto& state = _context.state();
    auto& params = _context.params();

    state.advance_frame();
    if(params.fixed_framerate()) {
        state.advance_time(params.frame_time());
    } else {
        static const float period =
          float(clock_type::period::num) / float(clock_type::period::den);
        _now = clock_type::now();
        state.set_time((_now - _start).count() * period);
    }

    if(params.doing_screenshot()) {
        return !_screenshot_done;
    } else {
        return params.demo_mode() || _example->continue_running(_context);
    }
}
//------------------------------------------------------------------------------
void example_wrapper::update() {

    if(_context.state().user_idle()) {
        _example->user_idle(_context);
    }
}
//------------------------------------------------------------------------------
void example_wrapper::render() {

    auto& state = _context.state();
    auto& params = _context.params();

    bool save_frame = params.doing_framedump();
    save_frame |= params.doing_screenshot() &&
                  (state.exec_time() >= params.screenshot_time());

    if(state.multiple_tiles()) {
        EAGINE_ASSERT(state.first_tile());
        do {
            if(params.auto_tiles()) {
                glScissor(
                  state.tile_x(),
                  state.tile_y(),
                  state.tile_w(),
                  state.tile_h());
            }
            _example->render(_context);
            glFlush();

        } while(!state.next_tile());
    } else {
        _example->render(_context);
    }

    if(save_frame) {
        glReadPixels(
          0,
          0,
          GLsizei(state.width()),
          GLsizei(state.height()),
          GL_RGBA,
          GL_UNSIGNED_BYTE,
          pixels().data());

        std::stringstream filename;

        if(params.doing_framedump()) {
            filename << params.framedump_prefix() << std::setfill('0')
                     << std::setw(6) << state.frame_number() << ".rgba";
        } else if(params.doing_screenshot()) {
            filename << params.screenshot_path();
        }

        std::ofstream file(filename.str());
        file.write(pixels().data(), std::streamsize(pixels().size()));
        file.flush();

        if(params.doing_framedump()) {
            std::cout << filename.str() << std::endl;
            textbuf(filename.str().size() + 1);

            std::cin.getline(_textbuf.data(), std::streamsize(_textbuf.size()));

            if(
              std::strncmp(
                filename.str().c_str(), _textbuf.data(), _textbuf.size()) !=
              0) {
                throw std::runtime_error(
                  "Expected frame-dump filepath on stdin.");
            }
        } else if(params.doing_screenshot()) {
            _screenshot_done = true;
        }
    }
}
//------------------------------------------------------------------------------
void example_wrapper::set_size(int width, int height) {

    auto& state = _context.state();

    if(width < 1) {
        width = 1;
    }
    if(height < 1) {
        height = 1;
    }

    if(state.set_size(width, height)) {
        _example->resize(_context);
    }
}
//------------------------------------------------------------------------------
void example_wrapper::set_mouse_btn(int i, bool pressed) {

    auto& state = _context.state();

    if(state.set_mouse_btn(i, pressed)) {
        // TODO
        //_example->mouse_button(_context);
    }
}
//------------------------------------------------------------------------------
void example_wrapper::set_mouse_pos(int x, int y) {

    auto& state = _context.state();

    if(state.set_mouse_pos(x, y)) {
        _example->pointer_motion(_context);
    }
}
//------------------------------------------------------------------------------
void example_wrapper::set_mouse_wheel(int w) {

    auto& state = _context.state();

    if(state.set_mouse_wheel(w)) {
        _example->pointer_scrolling(_context);
    }
}
//------------------------------------------------------------------------------
} // namespace eagine
