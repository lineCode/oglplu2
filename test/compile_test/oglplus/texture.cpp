/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oglplus/gl_fixed.hpp>
#include <oglplus/texture.hpp>
#include "helper/object_c.hpp"

using namespace oglplus;

void oglplus_texture_test_1(void)
{
	oglplus_object_name_test<texture_name>();
	oglplus_object_test<texture>();
}

void oglplus_texture_test_ops1(void)
{
	using namespace oglplus;

	oper::texture_ops gl;
	texture tex;
	texture_array<4> texs;
	texture_target tgt(GL_TEXTURE_2D);
	texture_name_and_target tnt(tex,tgt);
	bound_texture curtex(tgt);

	pixel_data_internal_format ifmt(GL_RGBA);
	pixel_data_format fmt(GL_RGBA);
	pixel_data_type typ(GL_UNSIGNED_BYTE);
	texture_wrap_coord wrap_s(GL_TEXTURE_WRAP_S);
	texture_swizzle_coord swizzle_r(GL_TEXTURE_SWIZZLE_R);
	const_memory_block blk;

	gl.bind_texture(tgt, tex);
	gl.texture_binding(tgt);
	gl.bind_texture(tgt, texs[0]);

#if defined(GL_VERSION_4_2) || defined(GL_ARB_texture_storage)
	gl.texture_image_1d(tgt, 0, ifmt, 64, 0, fmt, typ, blk);
	gl.texture_image_3d(tgt, 0, ifmt, 64, 64, 64, 0, fmt, typ, blk);
#endif
	gl.texture_image_2d(tgt, 0, ifmt, 64, 64, 0, fmt, typ, blk);

#if defined(GL_EXT_direct_state_access)
#if defined(GL_VERSION_4_2) || defined(GL_ARB_texture_storage)
	gl.texture_image_1d(tnt, 0, ifmt, 64, 0, fmt, typ, blk);
	gl.texture_image_3d(tnt, 0, ifmt, 64, 64, 64, 0, fmt, typ, blk);
#endif
	gl.texture_image_2d(tnt, 0, ifmt, 64, 64, 0, fmt, typ, blk);
#endif

#if defined(GL_VERSION_4_2) || defined(GL_ARB_texture_storage)
	gl.texture_storage_1d(tgt, 1, ifmt, 64);
	gl.texture_storage_2d(tgt, 1, ifmt, 64, 64);
	gl.texture_storage_3d(tgt, 1, ifmt, 64, 64, 64);
#endif

#if defined(GL_VERSION_4_5) || defined(GL_ARB_direct_state_access)
	gl.texture_storage_1d(tex, 1, ifmt, 64);
	gl.texture_storage_2d(tex, 1, ifmt, 64, 64);
	gl.texture_storage_3d(tex, 1, ifmt, 64, 64, 64);
#endif

#if defined(GL_VERSION_3_0) || defined(GL_ES_VERSION_3_1)
	gl.get_texture_width(tgt);
	gl.get_texture_height(tgt);
	gl.get_texture_depth(tgt);

	gl.get_texture_red_type(tgt);
	gl.get_texture_red_size(tgt);
	gl.get_texture_green_type(tgt);
	gl.get_texture_green_size(tgt);
	gl.get_texture_blue_type(tgt);
	gl.get_texture_blue_size(tgt);
	gl.get_texture_alpha_type(tgt);
	gl.get_texture_alpha_size(tgt);
	gl.get_texture_depth_type(tgt);
	gl.get_texture_depth_size(tgt);
	gl.get_texture_stencil_size(tgt);
	gl.get_texture_shared_size(tgt);
	gl.is_texture_compressed(tgt);
#if defined(GL_TEXTURE_COMPRESSED_IMAGE_SIZE)
	gl.get_texture_compressed_image_size(tgt);
#endif
	gl.get_texture_internal_format(tgt);

	gl.texture_min_filter(tgt, texture_min_filter(GL_LINEAR));
	gl.get_texture_min_filter(tgt);
	gl.texture_mag_filter(tgt, texture_mag_filter(GL_LINEAR));
	gl.get_texture_mag_filter(tgt);
	gl.texture_compare_mode(tgt, texture_compare_mode(GL_NONE));
	gl.get_texture_compare_mode(tgt);
	gl.texture_compare_func(tgt, compare_function(GL_EQUAL));
	gl.get_texture_compare_func(tgt);
	gl.texture_wrap(tgt, wrap_s, texture_wrap_mode(GL_REPEAT));
	gl.get_texture_wrap(tgt, wrap_s);
	gl.texture_swizzle(tgt, swizzle_r, texture_swizzle_mode(GL_ONE));
	gl.get_texture_swizzle(tgt, swizzle_r);

#if defined(GL_TEXTURE_LOD_BIAS)
	gl.texture_lod_bias(tgt, 1.0f);
	gl.get_texture_lod_bias(tgt);
#endif
	gl.texture_min_lod(tgt,-1000.0f);
	gl.get_texture_min_lod(tgt);
	gl.texture_max_lod(tgt, 1000.0f);
	gl.get_texture_max_lod(tgt);

#if defined(GL_EXT_direct_state_access)
	gl.get_texture_width(tnt);
	gl.get_texture_height(tnt);
	gl.get_texture_depth(tnt);

	gl.get_texture_red_type(tnt);
	gl.get_texture_red_size(tnt);
	gl.get_texture_green_type(tnt);
	gl.get_texture_green_size(tnt);
	gl.get_texture_blue_type(tnt);
	gl.get_texture_blue_size(tnt);
	gl.get_texture_alpha_type(tnt);
	gl.get_texture_alpha_size(tnt);
	gl.get_texture_depth_type(tnt);
	gl.get_texture_depth_size(tnt);
	gl.get_texture_stencil_size(tnt);
	gl.get_texture_shared_size(tnt);
	gl.is_texture_compressed(tnt);
#if defined(GL_TEXTURE_COMPRESSED_IMAGE_SIZE)
	gl.get_texture_compressed_image_size(tnt);
#endif
	gl.get_texture_internal_format(tnt);

	gl.texture_min_filter(tnt, texture_min_filter(GL_LINEAR));
	gl.get_texture_min_filter(tnt);
	gl.texture_mag_filter(tnt, texture_mag_filter(GL_LINEAR));
	gl.get_texture_mag_filter(tnt);
	gl.texture_compare_mode(tnt, texture_compare_mode(GL_NONE));
	gl.get_texture_compare_mode(tnt);
	gl.texture_compare_func(tnt, compare_function(GL_EQUAL));
	gl.get_texture_compare_func(tnt);
	gl.texture_wrap(tnt, wrap_s, texture_wrap_mode(GL_REPEAT));
	gl.get_texture_wrap(tnt, wrap_s);
	gl.texture_swizzle(tnt, swizzle_r, texture_swizzle_mode(GL_ONE));
	gl.get_texture_swizzle(tnt, swizzle_r);

#if defined(GL_TEXTURE_LOD_BIAS)
	gl.texture_lod_bias(tnt, 1.0f);
	gl.get_texture_lod_bias(tnt);
#endif
	gl.texture_min_lod(tnt,-1000.0f);
	gl.get_texture_min_lod(tnt);
	gl.texture_max_lod(tnt, 1000.0f);
	gl.get_texture_max_lod(tnt);
#endif
#endif // GL_VERSION_3_0

#if defined(GL_VERSION_4_5) || defined(GL_ARB_direct_state_access)
	gl.get_texture_width(tex);
	gl.get_texture_height(tex);
	gl.get_texture_depth(tex);

	gl.get_texture_red_type(tex);
	gl.get_texture_red_size(tex);
	gl.get_texture_green_type(tex);
	gl.get_texture_green_size(tex);
	gl.get_texture_blue_type(tex);
	gl.get_texture_blue_size(tex);
	gl.get_texture_alpha_type(tex);
	gl.get_texture_alpha_size(tex);
	gl.get_texture_depth_type(tex);
	gl.get_texture_depth_size(tex);
	gl.get_texture_stencil_size(tex);
	gl.get_texture_shared_size(tex);
	gl.is_texture_compressed(tex);
#if defined(GL_TEXTURE_COMPRESSED_IMAGE_SIZE)
	gl.get_texture_compressed_image_size(tex);
#endif
	gl.get_texture_internal_format(tex);

	gl.texture_min_filter(tex, texture_min_filter(GL_LINEAR));
	gl.get_texture_min_filter(tex);
	gl.texture_mag_filter(tex, texture_mag_filter(GL_LINEAR));
	gl.get_texture_mag_filter(tex);
	gl.texture_compare_mode(tex, texture_compare_mode(GL_NONE));
	gl.get_texture_compare_mode(tex);
	gl.texture_compare_func(tex, compare_function(GL_EQUAL));
	gl.get_texture_compare_func(tex);
	gl.texture_wrap(tex, wrap_s, texture_wrap_mode(GL_REPEAT));
	gl.get_texture_wrap(tex, wrap_s);
	gl.texture_swizzle(tex, swizzle_r, texture_swizzle_mode(GL_ONE));
	gl.get_texture_swizzle(tex, swizzle_r);

#if defined(GL_TEXTURE_LOD_BIAS)
	gl.texture_lod_bias(tex, 1.0f);
	gl.get_texture_lod_bias(tex);
#endif
	gl.texture_min_lod(tex,-1000.0f);
	gl.get_texture_min_lod(tex);
	gl.texture_max_lod(tex, 1000.0f);
	gl.get_texture_max_lod(tex);
#endif

#if defined(GL_VERSION_3_0) || defined(GL_ES_VERSION_3_1)
	curtex.get_width();
	curtex.get_height();
	curtex.get_depth();

	curtex.get_red_type();
	curtex.get_red_size();
	curtex.get_green_type();
	curtex.get_green_size();
	curtex.get_blue_type();
	curtex.get_blue_size();
	curtex.get_alpha_type();
	curtex.get_alpha_size();
	curtex.get_depth_type();
	curtex.get_depth_size();
	curtex.get_stencil_size();
	curtex.get_shared_size();

	curtex.min_filter(texture_min_filter(GL_NEAREST));
	curtex.get_min_filter();
	curtex.mag_filter(texture_mag_filter(GL_NEAREST));
	curtex.get_mag_filter();

	curtex.compare_mode(texture_compare_mode(GL_NONE));
	curtex.get_compare_mode();
	curtex.compare_func(compare_function(GL_LESS));
	curtex.get_compare_func();
	curtex.wrap(wrap_s, texture_wrap_mode(GL_REPEAT));
	curtex.get_wrap(wrap_s);
	curtex.swizzle(swizzle_r, texture_swizzle_mode(GL_ONE));
	curtex.get_swizzle(swizzle_r);

#if defined(GL_TEXTURE_LOD_BIAS)
	curtex.lod_bias(1.0f);
	curtex.get_lod_bias();
#endif
#endif
	curtex.min_lod(-1000.0f);
	curtex.get_min_lod();
	curtex.max_lod(1000.0f);
	curtex.get_max_lod();

#if defined(GL_VERSION_4_5) ||\
	defined(GL_ARB_direct_state_access) ||\
	defined(GL_EXT_direct_state_access)

	tex.get_width();
	tex.get_height();
	tex.get_depth();

	tex.get_red_type();
	tex.get_red_size();
	tex.get_green_type();
	tex.get_green_size();
	tex.get_blue_type();
	tex.get_blue_size();
	tex.get_alpha_type();
	tex.get_alpha_size();
	tex.get_depth_type();
	tex.get_depth_size();
	tex.get_stencil_size();
	tex.get_shared_size();

	tex.min_filter(texture_min_filter(GL_NEAREST));
	tex.get_min_filter();
	tex.mag_filter(texture_mag_filter(GL_NEAREST));
	tex.get_mag_filter();

	tex.compare_mode(texture_compare_mode(GL_NONE));
	tex.get_compare_mode();
	tex.compare_func(compare_function(GL_LESS));
	tex.get_compare_func();
	tex.wrap(wrap_s, texture_wrap_mode(GL_REPEAT));
	tex.get_wrap(wrap_s);
	tex.swizzle(swizzle_r, texture_swizzle_mode(GL_ONE));
	tex.get_swizzle(swizzle_r);

	tex.lod_bias(1.0f);
	tex.get_lod_bias();
	tex.min_lod(-1000.0f);
	tex.get_min_lod();
	tex.max_lod(1000.0f);
	tex.get_max_lod();
#endif
}

// TODO
