#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
macro(eagine_add_boost_test TEST_NAME)
	do_add_boost_test(eagine ${TEST_NAME})
endmacro()

eagine_add_boost_test(all_are_same)
eagine_add_boost_test(any_iterator)
eagine_add_boost_test(array_size)
eagine_add_boost_test(base64)
eagine_add_boost_test(bindump)
eagine_add_boost_test(bit_density)
eagine_add_boost_test(biteset)
eagine_add_boost_test(bitfield)
eagine_add_boost_test(buffer_data)
eagine_add_boost_test(buffer_size)
eagine_add_boost_test(byteset)
eagine_add_boost_test(callable_composer)
eagine_add_boost_test(callable_ref)
eagine_add_boost_test(deep_copy_ptr)
eagine_add_boost_test(ecs_integration)
eagine_add_boost_test(enum_bitfield)
eagine_add_boost_test(enum_class)
eagine_add_boost_test(enum_map)
eagine_add_boost_test(fixed_size_str)
eagine_add_boost_test(flat_map)
eagine_add_boost_test(hexdump)
eagine_add_boost_test(identifier)
eagine_add_boost_test(identity)
eagine_add_boost_test(interleaved_call)
eagine_add_boost_test(iterator)
eagine_add_boost_test(key_val_list)
eagine_add_boost_test(make_array)
eagine_add_boost_test(make_span)
eagine_add_boost_test(math_coordinates)
eagine_add_boost_test(math_functions)
eagine_add_boost_test(math_matrix_1)
eagine_add_boost_test(math_matrix_2)
eagine_add_boost_test(math_matrix_3)
eagine_add_boost_test(math_matrix_ctrs)
eagine_add_boost_test(math_scalar)
eagine_add_boost_test(math_tvec)
eagine_add_boost_test(math_vector)
eagine_add_boost_test(math_vector_ops)
eagine_add_boost_test(mem_func_const)
eagine_add_boost_test(memoized)
eagine_add_boost_test(memory_address)
eagine_add_boost_test(memory_align_alloc)
eagine_add_boost_test(memory_alloc_arena)
eagine_add_boost_test(memory_block)
eagine_add_boost_test(memory_buffer)
eagine_add_boost_test(memory_c_realloc)
eagine_add_boost_test(memory_fallback_alloc)
eagine_add_boost_test(memory_null_alloc)
eagine_add_boost_test(memory_shared_alloc)
eagine_add_boost_test(memory_stack_alloc)
eagine_add_boost_test(memory_std_alloc)
eagine_add_boost_test(mp_list)
eagine_add_boost_test(mp_string)
eagine_add_boost_test(mp_strings)
eagine_add_boost_test(msgbus_blobs)
eagine_add_boost_test(multi_byte_seq)
eagine_add_boost_test(network_sorter)
eagine_add_boost_test(offset_ptr)
eagine_add_boost_test(offset_span)
eagine_add_boost_test(optional_expr)
eagine_add_boost_test(program_args)
eagine_add_boost_test(protected_member)
eagine_add_boost_test(quantities_1)
eagine_add_boost_test(quantities_2)
eagine_add_boost_test(random_bytes)
eagine_add_boost_test(scope_exit)
eagine_add_boost_test(span_algo)
eagine_add_boost_test(string_list)
eagine_add_boost_test(string_path)
eagine_add_boost_test(struct_memory_block)
eagine_add_boost_test(str_var_subst)
eagine_add_boost_test(tribool)
eagine_add_boost_test(type_to_value)
eagine_add_boost_test(units_base_dim)
eagine_add_boost_test(units_dimension_1)
eagine_add_boost_test(units_dimension_2)
eagine_add_boost_test(units_scaled_unit)
eagine_add_boost_test(units_si_1)
eagine_add_boost_test(units_si_2)
eagine_add_boost_test(units_unit)
eagine_add_boost_test(valid_if)
eagine_add_boost_test(vararray)
eagine_add_boost_test(vect_abs)
eagine_add_boost_test(vect_axis)
eagine_add_boost_test(vect_compare)
eagine_add_boost_test(vect_data)
eagine_add_boost_test(vect_diff)
eagine_add_boost_test(vect_fill)
eagine_add_boost_test(vect_from)
eagine_add_boost_test(vect_hsum)
eagine_add_boost_test(vect_shuffle)
eagine_add_boost_test(vect_view)
eagine_add_boost_test(zip_iterator)
