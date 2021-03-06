/**
 *  @file eagine/utils/iterator.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_WRAPPING_CONTAINER_HPP
#define EAGINE_WRAPPING_CONTAINER_HPP

#include "iterator.hpp"
#include "range_types.hpp"
#include "span.hpp"
#include "types.hpp"

namespace eagine {
//------------------------------------------------------------------------------
template <
  typename Container,
  typename Wrapper,
  typename T,
  T initial = T{},
  typename Transform = typename Wrapper::transform>
class basic_wrapping_container : private Transform {
private:
    constexpr const Transform& _transf() const noexcept {
        return *this;
    }

    Container _items{};

    static constexpr void _initialize(Container& items) {
        using std::begin;
        using std::end;
        using std::fill;
        fill(begin(items), end(items), initial);
    }

    auto _release_items() noexcept {
        Container items{std::move(_items)};
        _intialize(_items);
        return items;
    }

public:
    using wrapper_type = Wrapper;

    constexpr basic_wrapping_container() noexcept {
        _initialize(_items);
    }

    constexpr basic_wrapping_container(const basic_wrapping_container&) =
      default;
    constexpr basic_wrapping_container& operator=(
      const basic_wrapping_container&) = default;

    basic_wrapping_container(basic_wrapping_container&& temp) noexcept
      : _items{temp._release_items()} {
    }

    basic_wrapping_container& operator=(
      basic_wrapping_container&& temp) noexcept {
        using std::swap;

        auto items{temp._release_items()};
        swap(items, _items);
        return *this;
    }

    ~basic_wrapping_container() noexcept = default;

    constexpr operator basic_wrapping_container<
      span<T>,
      Wrapper,
      T,
      initial,
      Transform>() noexcept {
        return {cover(_items)};
    }

    constexpr operator basic_wrapping_container<
      span<const T>,
      Wrapper,
      T,
      initial,
      Transform>() noexcept {
        return {view(_items)};
    }

    constexpr bool empty() const noexcept {
        return _items.empty();
    }

    constexpr auto size() const noexcept {
        return span_size(_items.size());
    }

    constexpr auto operator[](span_size_t index) const noexcept {
        return _transf()(_items[range_index<Container>(index)]);
    }

    constexpr auto at(span_size_t index) const {
        return _transf()(_items.at(range_index<Container>(index)));
    }

    using const_iterator = transforming_iterator<
      typename Container::const_iterator,
      Wrapper,
      T,
      Transform>;

    constexpr const_iterator begin() const noexcept {
        return {_items.begin()};
    }

    constexpr const_iterator end() const noexcept {
        return {_items.end()};
    }

    constexpr auto raw_items() noexcept {
        if constexpr(std::is_const_v<typename Container::value_type>) {
            return view(_items);
        } else {
            return cover(_items);
        }
    }

    constexpr auto raw_items() const noexcept {
        return view(_items);
    }
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_WRAPPING_CONTAINER_HPP
