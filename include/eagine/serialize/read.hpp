/**
 *  @file eagine/serialize/read.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SERIALIZE_READ_HPP
#define EAGINE_SERIALIZE_READ_HPP

#include "../memory/span_algo.hpp"
#include "read_backend.hpp"
#include <array>
#include <string>
#include <tuple>
#include <type_traits>
#include <vector>

namespace eagine {
//------------------------------------------------------------------------------
template <typename T>
struct deserializer;
//------------------------------------------------------------------------------
template <typename T>
struct deserializer<T&> : deserializer<T> {};
//------------------------------------------------------------------------------
template <typename T>
struct plain_deserializer {

    template <typename Backend>
    static deserialization_result read(T& value, Backend& backend) {
        return backend.read(cover_one(value));
    }

    template <typename Backend>
    static deserialization_result read(span<T> values, Backend& backend) {
        return backend.read(values);
    }
};
//------------------------------------------------------------------------------
template <>
struct deserializer<bool> : plain_deserializer<bool> {};
template <>
struct deserializer<char> : plain_deserializer<char> {};
template <>
struct deserializer<std::int16_t> : plain_deserializer<std::int16_t> {};
template <>
struct deserializer<std::int32_t> : plain_deserializer<std::int32_t> {};
template <>
struct deserializer<std::int64_t> : plain_deserializer<std::int64_t> {};
template <>
struct deserializer<std::uint8_t> : plain_deserializer<std::uint8_t> {};
template <>
struct deserializer<std::uint16_t> : plain_deserializer<std::uint16_t> {};
template <>
struct deserializer<std::uint32_t> : plain_deserializer<std::uint32_t> {};
template <>
struct deserializer<std::uint64_t> : plain_deserializer<std::uint64_t> {};
template <>
struct deserializer<float> : plain_deserializer<float> {};
template <>
struct deserializer<double> : plain_deserializer<double> {};
template <>
struct deserializer<std::string> : plain_deserializer<std::string> {};
//------------------------------------------------------------------------------
template <typename T>
struct common_deserializer {

    template <typename Backend>
    deserialization_result read(span<T> values, Backend& backend) const {
        using ec = deserialization_error_code;
        deserialization_result result{};
        for(auto& elem : values) {
            result |=
              static_cast<const deserializer<T>*>(this)->read(elem, backend);
            if(
              result.has(ec::not_enough_data) ||
              result.has(ec::backend_error)) {
                break;
            }
        }
        return result;
    }
};
//------------------------------------------------------------------------------
template <typename... T>
struct deserializer<std::tuple<T...>> : common_deserializer<std::tuple<T...>> {

    template <typename Backend>
    deserialization_result read(std::tuple<T...>& values, Backend& backend) {
        deserialization_result errors{};
        span_size_t elem_count{0};
        errors |= backend.begin_list(elem_count);
        if(elem_count < span_size_t(sizeof...(T))) {
            errors |= deserialization_error_code::missing_element;
        } else if(elem_count > span_size_t(sizeof...(T))) {
            errors |= deserialization_error_code::excess_element;
        }
        if(errors.has_at_most(deserialization_error_code::excess_element)) {
            _read_members(
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
    void _read_members(
      deserialization_result& errors,
      Tuple& values,
      Backend& backend,
      std::index_sequence<I...>) {
        (...,
         _read_member(
           errors,
           I,
           std::get<I>(values),
           backend,
           std::get<I>(_deserializers)));
    }

    template <typename Elem, typename Backend, typename Serializer>
    static void _read_member(
      deserialization_result& errors,
      std::size_t index,
      Elem& elem,
      Backend& backend,
      Serializer& serial) {
        if(!errors) {
            errors |= backend.begin_element(span_size_t(index));
            if(!errors) {
                errors |= serial.read(elem, backend);
                errors |= backend.finish_element(span_size_t(index));
            }
        }
    }

    std::tuple<deserializer<T>...> _deserializers{};
};
//------------------------------------------------------------------------------
template <typename T, std::size_t N>
struct deserializer<std::array<T, N>> : common_deserializer<std::array<T, N>> {
    template <typename Backend>
    deserialization_result read(
      std::array<T, N>& values, Backend& backend) const {
        deserialization_result errors{};
        span_size_t elem_count{0};
        errors |= backend.begin_list(elem_count);
        if(elem_count < span_size_t(N)) {
            errors |= deserialization_error_code::missing_element;
        } else if(elem_count > span_size_t(N)) {
            errors |= deserialization_error_code::excess_element;
        }
        if(errors.has_at_most(deserialization_error_code::excess_element)) {
            errors |= _elem_deserializer.read(cover(values), backend);
            errors |= backend.finish_list();
        }
        return errors;
    }

private:
    deserializer<T> _elem_deserializer{};
};
//------------------------------------------------------------------------------
template <typename T, typename A>
struct deserializer<std::vector<T, A>>
  : common_deserializer<std::vector<T, A>> {
    template <typename Backend>
    deserialization_result read(
      std::vector<T, A>& values, Backend& backend) const {
        deserialization_result errors{};
        span_size_t elem_count{0};
        errors |= backend.begin_list(elem_count);
        if(!errors) {
            values.resize(std::size_t(elem_count));
            errors |= _elem_deserializer.read(cover(values), backend);
            errors |= backend.finish_list();
        }
        return errors;
    }

private:
    deserializer<T> _elem_deserializer{};
};
//------------------------------------------------------------------------------
template <typename T, typename Backend>
std::enable_if_t<
  std::is_base_of_v<deserializer_backend, Backend>,
  deserialization_result>
deserialize(T& value, Backend& backend) {
    deserialization_result errors{};
    errors |= backend.start();
    if(!errors) {
        deserializer<T> reader;
        errors |= reader.read(value, backend);
        errors |= backend.finish();
    }
    return errors;
}
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_SERIALIZE_READ_HPP
