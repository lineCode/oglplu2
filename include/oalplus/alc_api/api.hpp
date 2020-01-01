/**
 *  @file oalplus/alc_api/api.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_ALC_API_API_HPP
#define OALPLUS_ALC_API_API_HPP

#include "c_api.hpp"
#include "enum_types.hpp"
#include <eagine/scope_exit.hpp>
#include <eagine/span.hpp>
#include <eagine/string_list.hpp>

namespace eagine {
namespace oalp {
//------------------------------------------------------------------------------
template <typename ApiTraits>
class basic_alc_api : public basic_alc_c_api<ApiTraits> {

public:
    using api_traits = ApiTraits;
    using c_api = basic_alc_c_api<ApiTraits>;

    using device_handle = typename alc_types::device_type*;
    using context_handle = typename alc_types::context_type*;
    using enum_type = typename alc_types::enum_type;
    using size_type = typename alc_types::size_type;
    using char_type = typename alc_types::char_type;
    using int_type = typename alc_types::int_type;

    struct derived_func : derived_c_api_function<c_api, api_traits, nothing_t> {
        using base = derived_c_api_function<c_api, api_traits, nothing_t>;
        using base::base;

        template <typename Res>
        constexpr auto _check(Res&& res, device_handle dev = nullptr) const
          noexcept {
            res.error_code(this->api().GetError(dev));
            return std::forward<Res>(res);
        }
    };

    // open_device
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().OpenDevice);
        }

        constexpr auto operator()() const noexcept {
            return this->_check(this->call(this->api().OpenDevice, nullptr));
        }

        auto operator()(string_view name) const noexcept {
            return this->_check(
              this->call(this->api().OpenDevice, c_str(name)));
        }
    } open_device;

    // close_device
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().CloseDevice);
        }

        constexpr auto operator()(device_handle dev) const noexcept {
            return this->_check(this->call(this->api().CloseDevice, dev), dev);
        }

        auto raii(device_handle dev) noexcept {
            return eagine::finally([=]() { (*this)(dev); });
        }
    } close_device;

    // create_context
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().CreateContext);
        }

        constexpr auto operator()(device_handle dev) const noexcept {
            return this->_check(
              this->call(this->api().CreateContext, dev, nullptr), dev);
        }

        constexpr auto operator()(
          device_handle dev, span<const int_type> attributes) const noexcept {
            return this->_check(
              this->call(this->api().CreateContext, dev, attributes.data()),
              dev);
        }
    } create_context;

    // destroy_context
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().DestroyContext);
        }

        constexpr auto operator()(device_handle dev, context_handle ctx) const
          noexcept {
            return this->_check(
              this->call(this->api().DestroyContext, ctx), dev);
        }

        auto raii(device_handle dev, context_handle ctx) noexcept {
            return eagine::finally([=]() { (*this)(dev, ctx); });
        }
    } destroy_context;

    // make_context_current
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().MakeContextCurrent);
        }

        constexpr auto operator()(device_handle dev, context_handle ctx) const
          noexcept {
            return this->_check(
              this->call(this->api().MakeContextCurrent, ctx), dev);
        }

        constexpr auto operator()(device_handle dev) const noexcept {
            return this->_check(
              this->call(this->api().MakeContextCurrent, nullptr), dev);
        }

        constexpr auto operator()(context_handle ctx) const noexcept {
            return this->_check(
              this->call(this->api().MakeContextCurrent, ctx), nullptr);
        }

        constexpr auto operator()() const noexcept {
            return this->_check(
              this->call(this->api().MakeContextCurrent, nullptr), nullptr);
        }

        auto raii(device_handle dev) noexcept {
            return eagine::finally([=]() { (*this)(dev); });
        }

        auto raii() noexcept {
            return eagine::finally([=]() { (*this)(); });
        }
    } make_context_current;

    // get_current_context
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().GetCurrentContext);
        }

        constexpr auto operator()(device_handle dev) const noexcept {
            return this->_check(this->call(this->api().GetCurrentContext), dev);
        }

        constexpr auto operator()() const noexcept {
            return this->_check(
              this->call(this->api().GetCurrentContext), nullptr);
        }
    } get_current_context;

    // get_integer
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().GetIntegerv);
        }

        constexpr auto operator()(
          device_handle dev, alc_integer_query query) const noexcept {
            int_type result{};
            return this
              ->_check(
                this->call(
                  this->api().GetIntegerv,
                  dev,
                  enum_type(query),
                  size_type(1),
                  &result),
                dev)
              .transformed([&result]() { return result; });
        }

        constexpr auto operator()(alc_integer_query query) const noexcept {
            return (*this)(nullptr, query);
        }
    } get_integer;

    // get_integerv
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().GetIntegerv);
        }

        constexpr auto operator()(
          device_handle dev, alc_integer_query query, span<int_type> dst) const
          noexcept {
            return this->_check(
              this->call(
                this->api().GetIntegerv,
                dev,
                enum_type(query),
                size_type(dst.size()),
                dst.data()),
              dev);
        }

        constexpr auto operator()(
          alc_integer_query query, span<int_type> dst) const noexcept {
            return (*this)(nullptr, query, dst);
        }
    } get_integerv;

    // get_string
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().GetString);
        }

        constexpr auto operator()(
          device_handle dev, alc_string_query query) const noexcept {
            return this->_check(
              this->call(this->api().GetString, dev, enum_type(query)), dev);
        }

        constexpr auto operator()(alc_string_query query) const noexcept {
            return (*this)(nullptr, query);
        }

        constexpr auto operator()(device_handle) const noexcept {
            return this->fake(this->api().GetString, "");
        }
    } get_string;

    // get_strings
    auto get_strings(
      device_handle dev, alc_string_query query, char separator) noexcept {
        return get_string(dev, query).transformed([separator](auto src) {
            return split_c_str_into_string_list(src, separator);
        });
    }

    // get_extensions
    auto get_extensions(device_handle dev) noexcept {
#ifdef ALC_EXTENSIONS
        return get_string(dev, alc_string_query(ALC_EXTENSIONS))
#else
        return get_string(dev)
#endif
          .transformed(
            [](auto src) { return split_c_str_into_string_list(src, ' '); });
    }

    // get_default_device_specifier
    auto get_default_device_specifier() noexcept {
#ifdef ALC_DEFAULT_DEVICE_SPECIFIER
        return get_string(
                 nullptr, alc_string_query(ALC_DEFAULT_DEVICE_SPECIFIER))
#else
        return get_string(nullptr)
#endif
          .transformed([](auto src) { return string_view(src); });
    }

    // get_device_specifiers
    auto get_device_specifiers() noexcept {
#ifdef ALC_DEVICE_SPECIFIER
        return get_string(nullptr, alc_string_query(ALC_DEVICE_SPECIFIER))
#else
        return get_string(nullptr)
#endif
          .transformed(
            [](auto src) { return split_c_str_into_string_list(src, '\0'); });
    }

    // get_capture_default_device_specifier
    auto get_capture_default_device_specifier() noexcept {
#ifdef ALC_CAPTURE_DEFAULT_DEVICE_SPECIFIER
        return get_string(
                 nullptr,
                 alc_string_query(ALC_CAPTURE_DEFAULT_DEVICE_SPECIFIER))
#else
        return get_string(nullptr)
#endif
          .transformed([](auto src) { return string_view(src); });
    }

    // get_capture_device_specifiers
    auto get_capture_device_specifiers() noexcept {
#ifdef ALC_CAPTURE_DEVICE_SPECIFIER
        return get_string(
                 nullptr, alc_string_query(ALC_CAPTURE_DEVICE_SPECIFIER))
#else
        return get_string(nullptr)
#endif
          .transformed(
            [](auto src) { return split_c_str_into_string_list(src, '\0'); });
    }

    constexpr basic_alc_api(api_traits& traits)
      : c_api{traits}
      , open_device("open_device", traits, *this)
      , close_device("close_device", traits, *this)
      , create_context("create_context", traits, *this)
      , destroy_context("destroy_context", traits, *this)
      , make_context_current("make_context_current", traits, *this)
      , get_current_context("get_current_context", traits, *this)
      , get_integer("get_integer", traits, *this)
      , get_integerv("get_integerv", traits, *this)
      , get_string("get_string", traits, *this) {
    }
};
//------------------------------------------------------------------------------
} // namespace oalp
} // namespace eagine

#endif // OALPLUS_ALC_API_API_HPP
