/**
 *  @file eagine/shapes/cube.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SHAPES_CUBE_HPP
#define EAGINE_SHAPES_CUBE_HPP

#include "gen_base.hpp"
#include <eagine/config/basic.hpp>
#include <cassert>
#include <memory>

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
class unit_cube_gen : public centered_unit_shape_generator_base {
private:
    using _base = centered_unit_shape_generator_base;

    static vertex_attrib_bits _attr_mask() noexcept;

    static vertex_attrib_bits _shared_attrs() noexcept;

    bool _only_shared_attribs() noexcept;

    static int _coord_c(span_size_t v, span_size_t c) noexcept;

    static int _normal_c(span_size_t f, span_size_t c) noexcept;

    static int _tangential_c(span_size_t f, span_size_t c) noexcept;

    static int _bitangential_c(span_size_t f, span_size_t c) noexcept;

    template <typename T>
    void _indices(drawing_variant, span<T> dest) noexcept;

    static span_size_t _face_vert(
      span_size_t f, span_size_t t, span_size_t v) noexcept;

public:
    unit_cube_gen(vertex_attrib_bits attr_bits) noexcept;

    span_size_t vertex_count() override;

    void positions(span<float> dest) noexcept;

    void normals(span<float> dest) noexcept;

    void tangentials(span<float> dest) noexcept;

    void bitangentials(span<float> dest) noexcept;

    void face_coords(span<float> dest) noexcept;

    void attrib_values(vertex_attrib_variant, span<float>) override;

    span_size_t draw_variant_count() override;

    index_data_type index_type(drawing_variant) override;

    span_size_t index_count(drawing_variant) override;

    void indices(drawing_variant, span<std::uint8_t> dest) override;

    void indices(drawing_variant, span<std::uint16_t> dest) override;

    void indices(drawing_variant, span<std::uint32_t> dest) override;

    span_size_t operation_count(drawing_variant) override;

    void instructions(drawing_variant, span<draw_operation> ops) override;

    math::sphere<float, true> bounding_sphere() override;
};
//------------------------------------------------------------------------------
static inline auto unit_cube(vertex_attrib_bits attr_bits) {
    return std::make_unique<unit_cube_gen>(attr_bits);
}
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/shapes/cube.inl>
#endif

#endif // EAGINE_SHAPES_CUBE_HPP
