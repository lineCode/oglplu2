/**
 *  @file oalplus/alut_api/api.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_ALUT_API_API_HPP
#define OALPLUS_ALUT_API_API_HPP

#include "../al_api/object_name.hpp"
#include "c_api.hpp"
#include "enum_types.hpp"
#include <eagine/scope_exit.hpp>
#include <eagine/string_list.hpp>

namespace eagine {
namespace oalp {
//------------------------------------------------------------------------------
#define OALPAFP(FUNC) decltype(c_api::FUNC), &c_api::FUNC
//------------------------------------------------------------------------------
template <typename ApiTraits>
class basic_alut_api : public basic_alut_c_api<ApiTraits> {

public:
    using api_traits = ApiTraits;
    using c_api = basic_alut_c_api<ApiTraits>;

    using enum_type = typename alut_types::enum_type;
    using char_type = typename alut_types::char_type;

    struct derived_func : derived_c_api_function<c_api, api_traits, nothing_t> {
        using base = derived_c_api_function<c_api, api_traits, nothing_t>;
        using base::base;

        template <typename Res>
        constexpr auto _check(Res&& res) const noexcept {
            res.error_code(this->api().GetError());
            return std::forward<Res>(res);
        }
    };

    template <typename W, W c_api::*F>
    class func
      : public wrapped_c_api_function<c_api, api_traits, nothing_t, W, F> {
        using base = wrapped_c_api_function<c_api, api_traits, nothing_t, W, F>;

    private:
        template <typename Res>
        constexpr auto _check(Res&& res) const noexcept {
            res.error_code(this->api().GetError());
            return std::forward<Res>(res);
        }

    protected:
        template <typename... Args>
        constexpr auto _chkcall(Args&&... args) const noexcept {
            return this->_check(this->call(std::forward<Args>(args)...));
        }

    public:
        using base::base;
    };

    // init
    struct : func<OALPAFP(Init)> {
        using func<OALPAFP(Init)>::func;

        constexpr auto operator()(int* argcp, char** argvp) const noexcept {
            return this->_chkcall(argcp, argvp);
        }
    } init;

    // create_buffer_hello_world
    struct : func<OALPAFP(CreateBufferHelloWorld)> {
        using func<OALPAFP(CreateBufferHelloWorld)>::func;

        constexpr auto operator()() const noexcept {
            return this->_chkcall().cast_to(identity<owned_buffer_name>{});
        }
    } create_buffer_hello_world;

    // exit
    struct : func<OALPAFP(Exit)> {
        using func<OALPAFP(Exit)>::func;

        constexpr auto operator()() const noexcept {
            return this->_chkcall();
        }

        auto raii() noexcept {
            return eagine::finally([=]() { (*this)(); });
        }
    } exit;

    constexpr basic_alut_api(api_traits& traits)
      : c_api{traits}
      , init("init", traits, *this)
      , create_buffer_hello_world("create_buffer_hello_world", traits, *this)
      , exit("exit", traits, *this) {
    }
};
//------------------------------------------------------------------------------
#undef OALPAFP
//------------------------------------------------------------------------------
} // namespace oalp
} // namespace eagine

#endif // OALPLUS_ALUT_API_API_HPP

