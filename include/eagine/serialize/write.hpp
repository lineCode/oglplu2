/**
 *  @file eagine/serialize/write.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SERIALIZE_WRITE_HPP
#define EAGINE_SERIALIZE_WRITE_HPP

#include "../assert.hpp"
#include "../bitfield.hpp"
#include "../nothing.hpp"
#include "../reflect/enumerators.hpp"
#include "write_backend.hpp"
#include <array>
#include <string>
#include <tuple>
#include <type_traits>
#include <vector>

namespace eagine {
//------------------------------------------------------------------------------
template <typename T>
class fragment_serialize_wrapper;
//------------------------------------------------------------------------------
template <typename T>
class fragment_serialize_wrapper<span<const T>> {
public:
    constexpr fragment_serialize_wrapper() noexcept = default;

    fragment_serialize_wrapper(span<const T> src) noexcept
      : _src{src} {
    }

    auto remaining() const noexcept {
        return skip(_src, _offset);
    }

    span_size_t offset() const noexcept {
        return _offset;
    }

    void advance(span_size_t inc) noexcept {
        _offset += inc;
    }

    bool is_done() const noexcept {
        return !remaining();
    }

private:
    span<const T> _src{};
    span_size_t _offset{0};
};
//------------------------------------------------------------------------------
template <typename T>
struct serializer;
//------------------------------------------------------------------------------
template <typename T>
struct serializer<T&> : serializer<T> {};
//------------------------------------------------------------------------------
template <typename T>
struct serializer<const T&> : serializer<T> {};
//------------------------------------------------------------------------------
template <typename T>
struct plain_serializer {
    template <typename Backend>
    static serialization_errors write(T value, Backend& backend) {
        span_size_t written{0};
        auto errors = backend.write(view_one(value), written);
        if(written < 1) {
            EAGINE_ASSERT(errors.has(serialization_error_code::too_much_data));
        }
        return errors;
    }

    template <typename Backend>
    static serialization_errors write(span<const T> values, Backend& backend) {
        span_size_t written{0};
        auto errors = backend.write(values, written);
        if(written < 1) {
            EAGINE_ASSERT(errors.has(serialization_error_code::too_much_data));
        } else if(written < values.size()) {
            EAGINE_ASSERT(
              errors.has(serialization_error_code::incomplete_write) ||
              errors.has(serialization_error_code::too_much_data));
        }
        return errors;
    }
};

//------------------------------------------------------------------------------
template <>
struct serializer<bool> : plain_serializer<bool> {};
template <>
struct serializer<char> : plain_serializer<char> {};
template <>
struct serializer<std::int8_t> : plain_serializer<std::int8_t> {};
template <>
struct serializer<short> : plain_serializer<short> {};
template <>
struct serializer<int> : plain_serializer<int> {};
template <>
struct serializer<long> : plain_serializer<long> {};
template <>
struct serializer<long long> : plain_serializer<long long> {};
template <>
struct serializer<std::uint8_t> : plain_serializer<std::uint8_t> {};
template <>
struct serializer<unsigned short> : plain_serializer<unsigned short> {};
template <>
struct serializer<unsigned> : plain_serializer<unsigned> {};
template <>
struct serializer<unsigned long> : plain_serializer<unsigned long> {};
template <>
struct serializer<unsigned long long> : plain_serializer<unsigned long long> {};
template <>
struct serializer<float> : plain_serializer<float> {};
template <>
struct serializer<double> : plain_serializer<double> {};
template <>
struct serializer<identifier> : plain_serializer<identifier> {};
template <>
struct serializer<decl_name> : plain_serializer<decl_name> {};
template <>
struct serializer<string_view> : plain_serializer<string_view> {};
//------------------------------------------------------------------------------
template <typename T>
struct common_serializer {

    template <typename Backend>
    serialization_errors write(span<const T> values, Backend& backend) {
        const auto tmd = serialization_error_code::too_much_data;
        const auto icw = serialization_error_code::incomplete_write;
        auto& sink = extract(backend.sink());
        serialization_errors errors{};
        span_size_t i = 0;
        for(auto& elem : values) {
            auto th = sink.begin_work();
            errors |= backend.begin_element(i);
            if(!errors) {
                errors |=
                  static_cast<serializer<T>*>(this)->write(elem, backend);
                errors |= backend.finish_element(i++);
                if(!errors) {
                    sink.commit(th);
                } else if(errors.has_at_most(tmd)) {
                    errors.clear(tmd);
                    errors |= icw;
                    sink.rollback(th);
                    break;
                } else {
                    break;
                }
            } else if(errors.has_only(tmd)) {
                errors.clear(tmd);
                errors |= icw;
                sink.rollback(th);
                break;
            } else {
                break;
            }
        }
        return errors;
    }
};
//------------------------------------------------------------------------------
template <typename... T>
struct serializer<std::tuple<T...>> : common_serializer<std::tuple<T...>> {

    using common_serializer<std::tuple<T...>>::write;

    template <typename Backend>
    serialization_errors write(
      const std::tuple<T...>& values, Backend& backend) {
        serialization_errors errors{};
        errors |= backend.begin_list(span_size(sizeof...(T)));
        if(!errors) {
            _write_elements(
              errors,
              values,
              backend,
              std::make_index_sequence<sizeof...(T)>());
            errors |= backend.finish_list();
        }
        return errors;
    }

private:
    template <typename Tuple, typename Backend, std::size_t... I>
    void _write_elements(
      serialization_errors& errors,
      Tuple& values,
      Backend& backend,
      std::index_sequence<I...>) {
        (...,
         _write_element(
           errors, I, std::get<I>(values), backend, std::get<I>(_serializers)));
    }

    template <typename Elem, typename Backend, typename Serializer>
    static void _write_element(
      serialization_errors& errors,
      std::size_t index,
      Elem& elem,
      Backend& backend,
      Serializer& serial) {
        if(!errors) {
            errors |= backend.begin_element(span_size(index));
            if(!errors) {
                errors |= serial.write(elem, backend);
                errors |= backend.finish_element(span_size(index));
            }
        }
    }

    std::tuple<serializer<T>...> _serializers{};
};
//------------------------------------------------------------------------------
template <typename... T>
struct serializer<std::tuple<std::pair<string_view, T>...>>
  : common_serializer<std::tuple<std::pair<string_view, T>...>> {

    template <typename Backend>
    serialization_errors write(
      const std::tuple<std::pair<string_view, T>...>& members,
      Backend& backend) {
        serialization_errors errors{};
        errors |= backend.begin_struct(span_size(sizeof...(T)));
        if(!errors) {
            _write_members(
              errors,
              members,
              backend,
              std::make_index_sequence<sizeof...(T)>());
            errors |= backend.finish_struct();
        }
        return errors;
    }

private:
    template <typename Tuple, typename Backend, std::size_t... I>
    void _write_members(
      serialization_errors& errors,
      Tuple& members,
      Backend& backend,
      std::index_sequence<I...>) {
        (...,
         _write_member(
           errors,
           std::get<0>(std::get<I>(members)),
           std::get<1>(std::get<I>(members)),
           backend,
           std::get<I>(_serializers)));
    }

    template <typename Memb, typename Backend, typename Serializer>
    static void _write_member(
      serialization_errors& errors,
      string_view name,
      Memb& value,
      Backend& backend,
      Serializer& serial) {
        if(!errors) {
            errors |= backend.begin_member(name);
            if(!errors) {
                errors |= serial.write(value, backend);
                errors |= backend.finish_member(name);
            }
        }
    }

    std::tuple<serializer<T>...> _serializers{};
};
//------------------------------------------------------------------------------
template <typename Bit>
struct serializer<bitfield<Bit>> : common_serializer<bitfield<Bit>> {

    template <typename Backend>
    serialization_errors write(bitfield<Bit> value, Backend& backend) {
        return _serializer.write(value.bits(), backend);
    }

private:
    serializer<typename bitfield<Bit>::value_type> _serializer{};
};
//------------------------------------------------------------------------------
template <std::size_t N>
struct serializer<char[N]> : serializer<string_view> {};
//------------------------------------------------------------------------------
template <typename Char, typename Traits, typename Alloc>
struct serializer<std::basic_string<Char, Traits, Alloc>>
  : common_serializer<std::basic_string<Char, Traits, Alloc>> {

    using common_serializer<std::basic_string<Char, Traits, Alloc>>::write;

    template <typename Backend>
    serialization_errors write(
      const std::basic_string<Char, Traits, Alloc>& value, Backend& backend) {
        return _serializer.write(value, backend);
    }

private:
    serializer<string_view> _serializer{};
};
//------------------------------------------------------------------------------
template <typename T>
struct serializer<span<const T>> : common_serializer<span<const T>> {

    using common_serializer<span<const T>>::write;

    template <typename Backend>
    serialization_errors write(span<const T> values, Backend& backend) {
        serialization_errors errors{};
        errors |= backend.begin_list(values.size());
        if(!errors) {
            errors |= _elem_serializer.write(values, backend);
            errors |= backend.finish_list();
        }
        return errors;
    }

private:
    serializer<T> _elem_serializer{};
};
//------------------------------------------------------------------------------
template <typename T>
struct serializer<span<T>> : serializer<span<const T>> {};
//------------------------------------------------------------------------------
template <typename T>
struct serializer<fragment_serialize_wrapper<span<const T>>>
  : common_serializer<fragment_serialize_wrapper<span<const T>>> {

    using common_serializer<fragment_serialize_wrapper<span<const T>>>::write;

    template <typename Backend>
    serialization_errors write(
      fragment_serialize_wrapper<span<const T>>& frag, Backend& backend) {
        serialization_errors errors{};
        errors |= _size_serializer.write(frag.offset(), backend);
        if(!errors) {
            auto todo = frag.remaining();
            errors |= _size_serializer.write(todo.size(), backend);
            if(!errors) {
                span_size_t written{0};
                errors |= backend.write(todo, written);
                if(errors.has_at_most(
                     serialization_error_code::incomplete_write)) {
                    frag.advance(written);
                }
            }
        }
        return errors;
    }

    serializer<span_size_t> _size_serializer{};
};
//------------------------------------------------------------------------------
template <typename T, std::size_t N>
struct serializer<std::array<T, N>> : common_serializer<std::array<T, N>> {

    using common_serializer<std::array<T, N>>::write;

    template <typename Backend>
    serialization_errors write(
      const std::array<T, N>& values, Backend& backend) {
        serialization_errors errors{};
        errors |= backend.begin_list(span_size(N));
        if(!errors) {
            errors |= _elem_serializer.write(view(values), backend);
            errors |= backend.finish_list();
        }
        return errors;
    }

private:
    serializer<T> _elem_serializer{};
};
//------------------------------------------------------------------------------
template <typename T, typename A>
struct serializer<std::vector<T, A>> : common_serializer<std::vector<T, A>> {

    using common_serializer<std::vector<T, A>>::write;

    template <typename Backend>
    serialization_errors write(
      const std::vector<T, A>& values, Backend& backend) {
        serialization_errors errors{};
        errors |= backend.begin_list(values.size());
        if(!errors) {
            errors |= _elem_serializer.write(view(values), backend);
            errors |= backend.finish_list();
        }
        return errors;
    }

private:
    serializer<T> _elem_serializer{};
};
//------------------------------------------------------------------------------
template <typename T>
struct enum_serializer {
    template <typename Backend>
    serialization_errors write(T enumerator, Backend& backend) {
        serialization_errors errors{};
        if(backend.enum_as_string()) {
            errors |=
              _name_serializer.write(enumerator_name(enumerator), backend);
        } else {
            errors |=
              _value_serializer.write(enumerator_value(enumerator), backend);
        }
        return errors;
    }

private:
    serializer<std::underlying_type_t<T>> _value_serializer{};
    serializer<decl_name> _name_serializer{};
};
//------------------------------------------------------------------------------
template <typename T>
struct serializer
  : std::conditional_t<
      has_enumerator_mapping_v<T>,
      enum_serializer<T>,
      nothing_t> {};
//------------------------------------------------------------------------------
template <typename T, typename Backend>
std::enable_if_t<
  std::is_base_of_v<serializer_backend, Backend>,
  serialization_errors>
serialize(T& value, Backend& backend) {
    serialization_errors errors{};
    errors |= backend.begin();
    if(!errors) {
        serializer<std::remove_cv_t<T>> writer;
        errors |= writer.write(value, backend);
        errors |= backend.finish();
    }
    return errors;
}
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_SERIALIZE_WRITE_HPP

