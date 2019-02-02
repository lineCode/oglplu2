/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/memory/span_algo.hpp>
#include <vector>

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
span_size_t to_quads_gen::index_count() {

    span_size_t count{0};

    std::vector<draw_operation> ops;
    ops.resize(std_size(delegated_gen::operation_count()));
    delegated_gen::instructions(cover(ops));

    std::vector<std::uint32_t> idx;
    idx.resize(std_size(delegated_gen::index_count()));
    delegated_gen::indices(cover(idx));

    for(const auto& op : ops) {
        if(op.mode == primitive_type::triangle_strip) {
            if(op.idx_type == index_data_type::none) {
                count += span_size(((op.count / 2) - 1) * 4);
            } else {
                span_size_t prev{0};
                span_size_t curr{0};
                while(curr < op.count) {
                    if(
                      delegated_gen::primitive_restart() &&
                      (idx[std_size(op.first + curr)] ==
                       op.primitive_restart_index)) {
                        count += span_size((((curr - prev) / 2) - 1) * 4);
                        prev = curr + 1;
                    }
                    ++curr;
                }
                count += span_size((((curr - prev) / 2) - 1) * 4);
            }
        } else {
            count += op.count;
        }
    }

    return count;
}
//------------------------------------------------------------------------------
template <typename T>
void to_quads_gen::_indices(span<T> dest) noexcept {

    assert(dest.size() >= index_count());

    span_size_t i = 0;

    std::vector<draw_operation> ops;
    ops.resize(std_size(delegated_gen::operation_count()));
    delegated_gen::instructions(cover(ops));

    std::vector<std::uint32_t> del_idx;
    del_idx.resize(std_size(delegated_gen::index_count()));
    delegated_gen::indices(cover(del_idx));

    for(const auto& op : ops) {
        if(op.mode == primitive_type::triangle_strip) {
            if(op.idx_type == index_data_type::none) {
                for(span_size_t p = 1; p < op.count / 2; ++p) {
                    dest[i++] = limit_cast<T>(op.first + p * 2 - 2);
                    dest[i++] = limit_cast<T>(op.first + p * 2 - 1);
                    dest[i++] = limit_cast<T>(op.first + p * 2 + 0);
                    dest[i++] = limit_cast<T>(op.first + p * 2 + 1);
                }
            } else {
                span_size_t curr{0};

                while(curr + 4 <= op.count) {
                    for(span_size_t t = 0; t < 4; ++t) {
                        if(
                          delegated_gen::primitive_restart() &&
                          (del_idx[std_size(op.first + curr + t)] ==
                           op.primitive_restart_index)) {
                            curr += t + 1;
                            break;
                        }
                    }
                    if(curr + 4 <= op.count) {
                        dest[i++] =
                          limit_cast<T>(del_idx[std_size(op.first + curr + 0)]);
                        dest[i++] =
                          limit_cast<T>(del_idx[std_size(op.first + curr + 1)]);
                        dest[i++] =
                          limit_cast<T>(del_idx[std_size(op.first + curr + 2)]);
                        dest[i++] =
                          limit_cast<T>(del_idx[std_size(op.first + curr + 3)]);
                        curr += 2;
                    } else {
                        break;
                    }
                }
            }
        } else {
            if(op.idx_type == index_data_type::none) {
                for(span_size_t p = 0; p < op.count; ++p) {
                    dest[i++] = limit_cast<T>(op.first + p);
                }
            } else {
                for(span_size_t p = 0; p < op.count; ++p) {
                    dest[i++] = limit_cast<T>(del_idx[op.first + p]);
                }
            }
        }
    }

    assert(i == index_count());
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void to_quads_gen::indices(span<std::uint8_t> dest) {
    _indices(dest);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void to_quads_gen::indices(span<std::uint16_t> dest) {
    _indices(dest);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void to_quads_gen::indices(span<std::uint32_t> dest) {
    _indices(dest);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
span_size_t to_quads_gen::operation_count() {
    return delegated_gen::operation_count();
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void to_quads_gen::instructions(span<draw_operation> ops) {

    delegated_gen::instructions(ops);

    std::vector<std::uint32_t> idx;
    idx.resize(std_size(delegated_gen::index_count()));
    delegated_gen::indices(cover(idx));

    const auto it = index_type();

    span_size_t offs{0};

    for(auto& op : ops) {
        if(op.mode == primitive_type::triangle_strip) {
            op.mode = primitive_type::quads;
            span_size_t count{0};
            span_size_t prev{0};
            span_size_t curr{0};
            while(curr < op.count) {
                if(
                  delegated_gen::primitive_restart() &&
                  (idx[std_size(op.first + curr)] ==
                   op.primitive_restart_index)) {
                    count += span_size((((curr - prev) / 2) - 1) * 4);
                    prev = curr + 1;
                }
                ++curr;
            }
            count += span_size((((curr - prev) / 2) - 1) * 4);
            op.count = count;
        }
        op.idx_type = it;
        op.first = offs;
        offs += op.count;
    }
}
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine
