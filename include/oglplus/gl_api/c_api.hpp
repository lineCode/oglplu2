/**
 *  @file oglplus/gl_api/c_api.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_GL_API_C_API_HPP
#define OGLPLUS_GL_API_C_API_HPP

#include "api_traits.hpp"
#include "config.hpp"
#include <eagine/nothing.hpp>
#include <eagine/preprocessor.hpp>

#ifndef OGLPLUS_GL_STATIC_FUNC
#if OGLPLUS_HAS_GL
#if defined(__GLEW_H__)
#define OGLPLUS_GL_STATIC_FUNC(NAME) nullptr
#else
#define OGLPLUS_GL_STATIC_FUNC(NAME) &EAGINE_JOIN(gl, NAME)
#endif
#else
#define OGLPLUS_GL_STATIC_FUNC(NAME) nullptr
#endif
#endif

namespace eagine::oglp {
//------------------------------------------------------------------------------
template <typename Traits>
struct basic_gl_c_api {

    using this_api = basic_gl_c_api;
    using api_traits = Traits;

    using void_ptr_type = typename gl_types::void_ptr_type;
    using const_void_ptr_type = typename gl_types::const_void_ptr_type;
    using sizei_type = typename gl_types::sizei_type;
    using sizeiptr_type = typename gl_types::sizeiptr_type;
    using intptr_type = typename gl_types::intptr_type;
    using bool_type = typename gl_types::bool_type;
    using char_type = typename gl_types::char_type;
    using byte_type = typename gl_types::byte_type;
    using ubyte_type = typename gl_types::ubyte_type;
    using short_type = typename gl_types::short_type;
    using ushort_type = typename gl_types::ushort_type;
    using int_type = typename gl_types::int_type;
    using uint_type = typename gl_types::uint_type;
    using int64_type = typename gl_types::int64_type;
    using uint64_type = typename gl_types::uint64_type;
    using enum_type = typename gl_types::enum_type;
    using float_type = typename gl_types::float_type;
    using double_type = typename gl_types::double_type;
    using bitfield_type = typename gl_types::bitfield_type;
    using sync_type = typename gl_types::sync_type;

    using debug_callback_type = void(
      enum_type,
      enum_type,
      uint_type,
      enum_type,
      sizei_type,
      const char_type*,
      const_void_ptr_type);

    template <
      typename Signature,
      c_api_function_ptr<api_traits, nothing_t, Signature> Function>
    using gl_api_function = eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      Signature,
      Function,
      gl_types::has_api,
      gl_types::has_static_api>;

    gl_api_function<enum_type(), OGLPLUS_GL_STATIC_FUNC(GetError)> GetError;

    gl_api_function<enum_type(), OGLPLUS_GL_STATIC_FUNC(GetGraphicsResetStatus)>
      GetGraphicsResetStatus;

    gl_api_function<void(enum_type), OGLPLUS_GL_STATIC_FUNC(Enable)> Enable;

    gl_api_function<void(enum_type, uint_type), OGLPLUS_GL_STATIC_FUNC(Enablei)>
      Enablei;

    gl_api_function<void(enum_type), OGLPLUS_GL_STATIC_FUNC(Disable)> Disable;

    gl_api_function<
      void(enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(Disablei)>
      Disablei;

    gl_api_function<bool_type(enum_type), OGLPLUS_GL_STATIC_FUNC(IsEnabled)>
      IsEnabled;

    gl_api_function<
      bool_type(enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(IsEnabledi)>
      IsEnabledi;

    gl_api_function<void(bitfield_type), OGLPLUS_GL_STATIC_FUNC(MemoryBarrier)>
      MemoryBarrier;

    gl_api_function<
      void(bitfield_type),
      OGLPLUS_GL_STATIC_FUNC(MemoryBarrierByRegion)>
      MemoryBarrierByRegion;

    // object ops
    gl_api_function<
      sync_type(enum_type, bitfield_type),
      OGLPLUS_GL_STATIC_FUNC(FenceSync)>
      FenceSync;

    gl_api_function<void(sync_type), OGLPLUS_GL_STATIC_FUNC(DeleteSync)>
      DeleteSync;

    gl_api_function<bool_type(sync_type), OGLPLUS_GL_STATIC_FUNC(IsSync)>
      IsSync;

    gl_api_function<
      void(sync_type, enum_type, sizei_type, sizei_type*, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetSynciv)>
      GetSynciv;

    gl_api_function<
      void(sync_type, bitfield_type, uint64_type),
      OGLPLUS_GL_STATIC_FUNC(WaitSync)>
      WaitSync;

    gl_api_function<
      enum_type(sync_type, bitfield_type, uint64_type),
      OGLPLUS_GL_STATIC_FUNC(ClientWaitSync)>
      ClientWaitSync;

    gl_api_function<
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GenVertexArrays)>
      GenVertexArrays;

    gl_api_function<
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(CreateVertexArrays)>
      CreateVertexArrays;

    gl_api_function<
      void(sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(DeleteVertexArrays)>
      DeleteVertexArrays;

    gl_api_function<bool_type(uint_type), OGLPLUS_GL_STATIC_FUNC(IsVertexArray)>
      IsVertexArray;

    gl_api_function<void(uint_type), OGLPLUS_GL_STATIC_FUNC(BindVertexArray)>
      BindVertexArray;

    gl_api_function<
      void(uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexArrayElementBuffer)>
      VertexArrayElementBuffer;

    gl_api_function<
      void(uint_type, uint_type, intptr_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(BindVertexBuffer)>
      BindVertexBuffer;

    gl_api_function<
      void(uint_type, uint_type, uint_type, intptr_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(VertexArrayVertexBuffer)>
      VertexArrayVertexBuffer;

    gl_api_function<
      void(
        uint_type,
        sizei_type,
        const uint_type*,
        const intptr_type*,
        const sizei_type*),
      OGLPLUS_GL_STATIC_FUNC(BindVertexBuffers)>
      BindVertexBuffers;

    gl_api_function<
      void(
        uint_type,
        uint_type,
        sizei_type,
        const uint_type*,
        const intptr_type*,
        const sizei_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexArrayVertexBuffers)>
      VertexArrayVertexBuffers;

    gl_api_function<
      void(uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribBinding)>
      VertexAttribBinding;

    gl_api_function<
      void(uint_type, uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexArrayAttribBinding)>
      VertexArrayAttribBinding;

    gl_api_function<
      void(uint_type),
      OGLPLUS_GL_STATIC_FUNC(EnableVertexAttribArray)>
      EnableVertexAttribArray;

    gl_api_function<
      void(uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(EnableVertexArrayAttrib)>
      EnableVertexArrayAttrib;

    gl_api_function<
      void(uint_type),
      OGLPLUS_GL_STATIC_FUNC(DisableVertexAttribArray)>
      DisableVertexAttribArray;

    gl_api_function<
      void(uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(DisableVertexArrayAttrib)>
      DisableVertexArrayAttrib;

    gl_api_function<
      void(uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexBindingDivisor)>
      VertexBindingDivisor;

    gl_api_function<
      void(uint_type, uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexArrayBindingDivisor)>
      VertexArrayBindingDivisor;

    gl_api_function<
      void(uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribDivisor)>
      VertexAttribDivisor;

    gl_api_function<
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GenBuffers)>
      GenBuffers;

    gl_api_function<
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(CreateBuffers)>
      CreateBuffers;

    gl_api_function<
      void(sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(DeleteBuffers)>
      DeleteBuffers;

    gl_api_function<bool_type(uint_type), OGLPLUS_GL_STATIC_FUNC(IsBuffer)>
      IsBuffer;

    gl_api_function<
      void(enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(BindBuffer)>
      BindBuffer;

    gl_api_function<
      void(enum_type, uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(BindBufferBase)>
      BindBufferBase;

    gl_api_function<
      void(enum_type, uint_type, uint_type, intptr_type, sizeiptr_type),
      OGLPLUS_GL_STATIC_FUNC(BindBufferRange)>
      BindBufferRange;

    gl_api_function<
      void(enum_type, sizeiptr_type, const_void_ptr_type, bitfield_type),
      OGLPLUS_GL_STATIC_FUNC(BufferStorage)>
      BufferStorage;

    gl_api_function<
      void(uint_type, sizeiptr_type, const_void_ptr_type, bitfield_type),
      OGLPLUS_GL_STATIC_FUNC(BufferStorage)>
      NamedBufferStorage;

    gl_api_function<
      void(enum_type, sizeiptr_type, const_void_ptr_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(BufferData)>
      BufferData;

    gl_api_function<
      void(uint_type, sizeiptr_type, const_void_ptr_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(NamedBufferData)>
      NamedBufferData;

    gl_api_function<
      void(enum_type, intptr_type, sizeiptr_type, const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(BufferSubData)>
      BufferSubData;

    gl_api_function<
      void(uint_type, intptr_type, sizeiptr_type, const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(NamedBufferSubData)>
      NamedBufferSubData;

    gl_api_function<
      void(enum_type, enum_type, enum_type, enum_type, const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(ClearBufferData)>
      ClearBufferData;

    gl_api_function<
      void(uint_type, enum_type, enum_type, enum_type, const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(ClearNamedBufferData)>
      ClearNamedBufferData;

    gl_api_function<
      void(
        enum_type,
        enum_type,
        intptr_type,
        sizeiptr_type,
        enum_type,
        enum_type,
        const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(ClearBufferSubData)>
      ClearBufferSubData;

    gl_api_function<
      void(
        uint_type,
        enum_type,
        intptr_type,
        sizeiptr_type,
        enum_type,
        enum_type,
        const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(ClearNamedBufferSubData)>
      ClearNamedBufferSubData;

    gl_api_function<
      void_ptr_type(enum_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(MapBuffer)>
      MapBuffer;

    gl_api_function<
      void_ptr_type(uint_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(MapNamedBuffer)>
      MapNamedBuffer;

    gl_api_function<
      void_ptr_type(enum_type, intptr_type, sizeiptr_type, bitfield_type),
      OGLPLUS_GL_STATIC_FUNC(MapBufferRange)>
      MapBufferRange;

    gl_api_function<
      void_ptr_type(uint_type, intptr_type, sizeiptr_type, bitfield_type),
      OGLPLUS_GL_STATIC_FUNC(MapNamedBufferRange)>
      MapNamedBufferRange;

    gl_api_function<
      void(enum_type, intptr_type, sizeiptr_type),
      OGLPLUS_GL_STATIC_FUNC(FlushMappedBufferRange)>
      FlushMappedBufferRange;

    gl_api_function<
      void(uint_type, intptr_type, sizeiptr_type),
      OGLPLUS_GL_STATIC_FUNC(FlushMappedNamedBufferRange)>
      FlushMappedNamedBufferRange;

    gl_api_function<bool_type(enum_type), OGLPLUS_GL_STATIC_FUNC(UnmapBuffer)>
      UnmapBuffer;

    gl_api_function<
      bool_type(uint_type),
      OGLPLUS_GL_STATIC_FUNC(UnmapNamedBuffer)>
      UnmapNamedBuffer;

    gl_api_function<
      void(uint_type),
      OGLPLUS_GL_STATIC_FUNC(InvalidateBufferData)>
      InvalidateBufferData;

    gl_api_function<
      void(uint_type, intptr_type, sizeiptr_type),
      OGLPLUS_GL_STATIC_FUNC(InvalidateBufferSubData)>
      InvalidateBufferSubData;

    gl_api_function<
      void(enum_type, enum_type, intptr_type, intptr_type, sizeiptr_type),
      OGLPLUS_GL_STATIC_FUNC(CopyBufferSubData)>
      CopyBufferSubData;

    gl_api_function<
      void(uint_type, uint_type, intptr_type, intptr_type, sizeiptr_type),
      OGLPLUS_GL_STATIC_FUNC(CopyNamedBufferSubData)>
      CopyNamedBufferSubData;

    gl_api_function<
      void(enum_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetBufferParameteriv)>
      GetBufferParameteriv;

    gl_api_function<
      void(enum_type, enum_type, int64_type*),
      OGLPLUS_GL_STATIC_FUNC(GetBufferParameteri64v)>
      GetBufferParameteri64v;

    gl_api_function<
      void(uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetNamedBufferParameteriv)>
      GetNamedBufferParameteriv;

    gl_api_function<
      void(uint_type, enum_type, int64_type*),
      OGLPLUS_GL_STATIC_FUNC(GetNamedBufferParameteri64v)>
      GetNamedBufferParameteri64v;

    gl_api_function<
      void(enum_type, intptr_type, sizeiptr_type, void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(GetBufferSubData)>
      GetBufferSubData;

    gl_api_function<
      void(uint_type, intptr_type, sizeiptr_type, void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(GetNamedBufferSubData)>
      GetNamedBufferSubData;

    // texture
    gl_api_function<
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GenTextures)>
      GenTextures;

    gl_api_function<
      void(enum_type, sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(CreateTextures)>
      CreateTextures;

    gl_api_function<
      void(sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(DeleteTextures)>
      DeleteTextures;

    gl_api_function<bool_type(uint_type), OGLPLUS_GL_STATIC_FUNC(IsTexture)>
      IsTexture;

    gl_api_function<void(enum_type), OGLPLUS_GL_STATIC_FUNC(ActiveTexture)>
      ActiveTexture;

    gl_api_function<
      void(enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(BindTexture)>
      BindTexture;

    gl_api_function<
      void(uint_type, sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(BindTextures)>
      BindTextures;

    gl_api_function<
      void(uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(BindTextureUnit)>
      BindTextureUnit;

    gl_api_function<
      void(
        uint_type,
        uint_type,
        int_type,
        bool_type,
        int_type,
        enum_type,
        enum_type),
      OGLPLUS_GL_STATIC_FUNC(BindImageTexture)>
      BindImageTexture;

    gl_api_function<
      void(uint_type, sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(BindImageTextures)>
      BindImageTextures;

    gl_api_function<
      void(
        enum_type, sizei_type, enum_type, sizei_type, sizei_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(TexStorage3D)>
      TexStorage3D;

    gl_api_function<
      void(enum_type, sizei_type, enum_type, sizei_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(TexStorage2D)>
      TexStorage2D;

    gl_api_function<
      void(enum_type, sizei_type, enum_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(TexStorage1D)>
      TexStorage1D;

    gl_api_function<
      void(
        enum_type,
        sizei_type,
        enum_type,
        sizei_type,
        sizei_type,
        sizei_type,
        bool_type),
      OGLPLUS_GL_STATIC_FUNC(TexStorage3DMultisample)>
      TexStorage3DMultisample;

    gl_api_function<
      void(enum_type, sizei_type, enum_type, sizei_type, sizei_type, bool_type),
      OGLPLUS_GL_STATIC_FUNC(TexStorage2DMultisample)>
      TexStorage2DMultisample;

    gl_api_function<
      void(
        enum_type,
        int_type,
        int_type,
        sizei_type,
        sizei_type,
        sizei_type,
        int_type,
        enum_type,
        enum_type,
        const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(TexImage3D)>
      TexImage3D;

    gl_api_function<
      void(
        enum_type,
        int_type,
        int_type,
        sizei_type,
        sizei_type,
        int_type,
        enum_type,
        enum_type,
        const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(TexImage2D)>
      TexImage2D;

    gl_api_function<
      void(
        enum_type,
        int_type,
        int_type,
        sizei_type,
        int_type,
        enum_type,
        enum_type,
        const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(TexImage1D)>
      TexImage1D;

    gl_api_function<
      void(
        enum_type,
        int_type,
        enum_type,
        int_type,
        int_type,
        sizei_type,
        sizei_type,
        int_type),
      OGLPLUS_GL_STATIC_FUNC(CopyTexImage2D)>
      CopyTexImage2D;

    gl_api_function<
      void(
        enum_type,
        int_type,
        enum_type,
        int_type,
        int_type,
        sizei_type,
        int_type),
      OGLPLUS_GL_STATIC_FUNC(CopyTexImage1D)>
      CopyTexImage1D;

    gl_api_function<
      void(
        enum_type,
        int_type,
        int_type,
        int_type,
        int_type,
        sizei_type,
        sizei_type,
        sizei_type,
        enum_type,
        enum_type,
        const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(TexSubImage3D)>
      TexSubImage3D;

    gl_api_function<
      void(
        enum_type,
        int_type,
        int_type,
        int_type,
        sizei_type,
        sizei_type,
        enum_type,
        enum_type,
        const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(TexSubImage2D)>
      TexSubImage2D;

    gl_api_function<
      void(
        enum_type,
        int_type,
        int_type,
        sizei_type,
        enum_type,
        enum_type,
        const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(TexSubImage1D)>
      TexSubImage1D;

    gl_api_function<
      void(
        enum_type,
        int_type,
        int_type,
        int_type,
        int_type,
        int_type,
        int_type,
        sizei_type,
        sizei_type),
      OGLPLUS_GL_STATIC_FUNC(CopyTexSubImage3D)>
      CopyTexSubImage3D;

    gl_api_function<
      void(
        enum_type,
        int_type,
        int_type,
        int_type,
        int_type,
        int_type,
        sizei_type,
        sizei_type),
      OGLPLUS_GL_STATIC_FUNC(CopyTexSubImage2D)>
      CopyTexSubImage2D;

    gl_api_function<
      void(enum_type, int_type, int_type, int_type, int_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(CopyTexSubImage1D)>
      CopyTexSubImage1D;

    // dsa texture
    gl_api_function<
      void(
        uint_type, sizei_type, enum_type, sizei_type, sizei_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(TextureStorage3D)>
      TextureStorage3D;

    gl_api_function<
      void(uint_type, sizei_type, enum_type, sizei_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(TextureStorage2D)>
      TextureStorage2D;

    gl_api_function<
      void(uint_type, sizei_type, enum_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(TextureStorage1D)>
      TextureStorage1D;

    gl_api_function<
      void(
        uint_type,
        sizei_type,
        enum_type,
        sizei_type,
        sizei_type,
        sizei_type,
        bool_type),
      OGLPLUS_GL_STATIC_FUNC(TextureStorage3DMultisample)>
      TextureStorage3DMultisample;

    gl_api_function<
      void(uint_type, sizei_type, enum_type, sizei_type, sizei_type, bool_type),
      OGLPLUS_GL_STATIC_FUNC(TextureStorage2DMultisample)>
      TextureStorage2DMultisample;

    gl_api_function<
      void(
        uint_type,
        int_type,
        int_type,
        int_type,
        int_type,
        sizei_type,
        sizei_type,
        sizei_type,
        enum_type,
        enum_type,
        const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(TextureSubImage3D)>
      TextureSubImage3D;

    gl_api_function<
      void(
        uint_type,
        int_type,
        int_type,
        int_type,
        sizei_type,
        sizei_type,
        enum_type,
        enum_type,
        const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(TextureSubImage2D)>
      TextureSubImage2D;

    gl_api_function<
      void(
        uint_type,
        int_type,
        int_type,
        sizei_type,
        enum_type,
        enum_type,
        const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(TextureSubImage1D)>
      TextureSubImage1D;

    gl_api_function<
      void(
        uint_type,
        int_type,
        int_type,
        int_type,
        int_type,
        int_type,
        int_type,
        sizei_type,
        sizei_type),
      OGLPLUS_GL_STATIC_FUNC(CopyTextureSubImage3D)>
      CopyTextureSubImage3D;

    gl_api_function<
      void(
        uint_type,
        int_type,
        int_type,
        int_type,
        int_type,
        int_type,
        sizei_type,
        sizei_type),
      OGLPLUS_GL_STATIC_FUNC(CopyTextureSubImage2D)>
      CopyTextureSubImage2D;

    gl_api_function<
      void(uint_type, int_type, int_type, int_type, int_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(CopyTextureSubImage1D)>
      CopyTextureSubImage1D;

    gl_api_function<
      void(
        enum_type,
        int_type,
        enum_type,
        sizei_type,
        sizei_type,
        sizei_type,
        int_type,
        sizei_type,
        const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(CompressedTexImage3D)>
      CompressedTexImage3D;

    gl_api_function<
      void(
        enum_type,
        int_type,
        enum_type,
        sizei_type,
        sizei_type,
        int_type,
        sizei_type,
        const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(CompressedTexImage2D)>
      CompressedTexImage2D;

    gl_api_function<
      void(
        enum_type,
        int_type,
        enum_type,
        sizei_type,
        int_type,
        sizei_type,
        const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(CompressedTexImage1D)>
      CompressedTexImage1D;

    gl_api_function<
      void(
        enum_type,
        int_type,
        int_type,
        int_type,
        int_type,
        sizei_type,
        sizei_type,
        sizei_type,
        enum_type,
        sizei_type,
        const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(CompressedTexSubImage3D)>
      CompressedTexSubImage3D;

    gl_api_function<
      void(
        enum_type,
        int_type,
        int_type,
        int_type,
        sizei_type,
        sizei_type,
        enum_type,
        sizei_type,
        const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(CompressedTexSubImage2D)>
      CompressedTexSubImage2D;

    gl_api_function<
      void(
        enum_type,
        int_type,
        int_type,
        sizei_type,
        enum_type,
        sizei_type,
        const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(CompressedTexSubImage1D)>
      CompressedTexSubImage1D;

    gl_api_function<
      void(
        uint_type,
        int_type,
        int_type,
        int_type,
        int_type,
        sizei_type,
        sizei_type,
        sizei_type,
        enum_type,
        sizei_type,
        const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(CompressedTextureSubImage3D)>
      CompressedTextureSubImage3D;

    gl_api_function<
      void(
        uint_type,
        int_type,
        int_type,
        int_type,
        sizei_type,
        sizei_type,
        enum_type,
        sizei_type,
        const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(CompressedTextureSubImage2D)>
      CompressedTextureSubImage2D;

    gl_api_function<
      void(
        uint_type,
        int_type,
        int_type,
        sizei_type,
        enum_type,
        sizei_type,
        const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(CompressedTextureSubImage1D)>
      CompressedTextureSubImage1D;

    gl_api_function<
      void(
        enum_type,
        sizei_type,
        enum_type,
        sizei_type,
        sizei_type,
        sizei_type,
        bool_type),
      OGLPLUS_GL_STATIC_FUNC(TexImage3DMultisample)>
      TexImage3DMultisample;

    gl_api_function<
      void(enum_type, sizei_type, enum_type, sizei_type, sizei_type, bool_type),
      OGLPLUS_GL_STATIC_FUNC(TexImage2DMultisample)>
      TexImage2DMultisample;

    gl_api_function<
      void(enum_type, enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(TexBuffer)>
      TexBuffer;

    gl_api_function<
      void(enum_type, enum_type, uint_type, intptr_type, sizeiptr_type),
      OGLPLUS_GL_STATIC_FUNC(TexBufferRange)>
      TexBufferRange;

    gl_api_function<
      void(uint_type, enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(TextureBuffer)>
      TextureBuffer;

    gl_api_function<
      void(uint_type, enum_type, uint_type, intptr_type, sizeiptr_type),
      OGLPLUS_GL_STATIC_FUNC(TextureBufferRange)>
      TextureBufferRange;

    gl_api_function<
      void(enum_type, enum_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(TexParameterf)>
      TexParameterf;

    gl_api_function<
      void(enum_type, enum_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(TexParameteri)>
      TexParameteri;

    gl_api_function<
      void(enum_type, enum_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(TexParameterfv)>
      TexParameterfv;

    gl_api_function<
      void(enum_type, enum_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(TexParameteriv)>
      TexParameteriv;

    gl_api_function<
      void(enum_type, enum_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(TexParameterIiv)>
      TexParameterIiv;

    gl_api_function<
      void(enum_type, enum_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(TexParameterIuiv)>
      TexParameterIuiv;

    gl_api_function<
      void(uint_type, enum_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(TextureParameterf)>
      TextureParameterf;

    gl_api_function<
      void(uint_type, enum_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(TextureParameteri)>
      TextureParameteri;

    gl_api_function<
      void(uint_type, enum_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(TextureParameterfv)>
      TextureParameterfv;

    gl_api_function<
      void(uint_type, enum_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(TextureParameteriv)>
      TextureParameteriv;

    gl_api_function<
      void(uint_type, enum_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(TextureParameterIiv)>
      TextureParameterIiv;

    gl_api_function<
      void(uint_type, enum_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(TextureParameterIuiv)>
      TextureParameterIuiv;

    gl_api_function<
      void(enum_type, enum_type, float_type*),
      OGLPLUS_GL_STATIC_FUNC(GetTexParameterfv)>
      GetTexParameterfv;

    gl_api_function<
      void(enum_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetTexParameteriv)>
      GetTexParameteriv;

    gl_api_function<
      void(enum_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetTexParameterIiv)>
      GetTexParameterIiv;

    gl_api_function<
      void(enum_type, enum_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GetTexParameterIuiv)>
      GetTexParameterIuiv;

    gl_api_function<
      void(enum_type, int_type, enum_type, float_type*),
      OGLPLUS_GL_STATIC_FUNC(GetTexLevelParameterfv)>
      GetTexLevelParameterfv;

    gl_api_function<
      void(enum_type, int_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetTexLevelParameteriv)>
      GetTexLevelParameteriv;

    gl_api_function<
      void(enum_type, int_type, enum_type, enum_type, void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(GetTexImage)>
      GetTexImage;

    gl_api_function<
      void(
        enum_type, int_type, enum_type, enum_type, sizei_type, void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(GetnTexImage)>
      GetnTexImage;

    gl_api_function<
      void(enum_type, int_type, void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(GetCompressedTexImage)>
      GetCompressedTexImage;

    gl_api_function<
      void(enum_type, int_type, sizei_type, void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(GetnCompressedTexImage)>
      GetnCompressedTexImage;

    gl_api_function<
      void(uint_type, enum_type, float_type*),
      OGLPLUS_GL_STATIC_FUNC(GetTextureParameterfv)>
      GetTextureParameterfv;

    gl_api_function<
      void(uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetTextureParameteriv)>
      GetTextureParameteriv;

    gl_api_function<
      void(uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetTextureParameterIiv)>
      GetTextureParameterIiv;

    gl_api_function<
      void(uint_type, enum_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GetTextureParameterIuiv)>
      GetTextureParameterIuiv;

    gl_api_function<
      void(uint_type, int_type, enum_type, float_type*),
      OGLPLUS_GL_STATIC_FUNC(GetTextureLevelParameterfv)>
      GetTextureLevelParameterfv;

    gl_api_function<
      void(uint_type, int_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetTextureLevelParameteriv)>
      GetTextureLevelParameteriv;

    gl_api_function<
      void(
        uint_type, int_type, enum_type, enum_type, sizei_type, void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(GetTextureImage)>
      GetTextureImage;

    gl_api_function<
      void(
        uint_type,
        int_type,
        int_type,
        int_type,
        int_type,
        sizei_type,
        sizei_type,
        sizei_type,
        enum_type,
        enum_type,
        sizei_type,
        void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(GetTextureSubImage)>
      GetTextureSubImage;

    gl_api_function<
      void(uint_type, int_type, sizei_type, void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(GetCompressedTextureImage)>
      GetCompressedTextureImage;

    gl_api_function<
      void(
        uint_type,
        int_type,
        int_type,
        int_type,
        int_type,
        sizei_type,
        sizei_type,
        sizei_type,
        sizei_type,
        void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(GetCompressedTextureSubImage)>
      GetCompressedTextureSubImage;

    gl_api_function<void(enum_type), OGLPLUS_GL_STATIC_FUNC(GenerateMipmap)>
      GenerateMipmap;

    gl_api_function<
      void(uint_type),
      OGLPLUS_GL_STATIC_FUNC(GenerateTextureMipmap)>
      GenerateTextureMipmap;

    gl_api_function<
      void(
        uint_type,
        enum_type,
        uint_type,
        enum_type,
        uint_type,
        uint_type,
        uint_type,
        uint_type),
      OGLPLUS_GL_STATIC_FUNC(TextureView)>
      TextureView;

    gl_api_function<
      void(
        uint_type,
        int_type,
        int_type,
        int_type,
        int_type,
        sizei_type,
        sizei_type,
        sizei_type),
      OGLPLUS_GL_STATIC_FUNC(InvalidateTexSubImage)>
      InvalidateTexSubImage;

    gl_api_function<
      void(uint_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(InvalidateTexImage)>
      InvalidateTexImage;

    gl_api_function<
      void(
        uint_type,
        int_type,
        int_type,
        int_type,
        int_type,
        sizei_type,
        sizei_type,
        sizei_type,
        enum_type,
        enum_type,
        const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(ClearTexSubImage)>
      ClearTexSubImage;

    gl_api_function<
      void(uint_type, int_type, enum_type, enum_type, const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(ClearTexImage)>
      ClearTexImage;

    gl_api_function<void(), OGLPLUS_GL_STATIC_FUNC(TextureBarrier)>
      TextureBarrier;

    // samplers
    gl_api_function<
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GenSamplers)>
      GenSamplers;

    gl_api_function<
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(CreateSamplers)>
      CreateSamplers;

    gl_api_function<
      void(sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(DeleteSamplers)>
      DeleteSamplers;

    gl_api_function<bool_type(uint_type), OGLPLUS_GL_STATIC_FUNC(IsSampler)>
      IsSampler;

    gl_api_function<
      void(uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(BindSampler)>
      BindSampler;

    gl_api_function<
      void(uint_type, sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(BindSamplers)>
      BindSamplers;

    gl_api_function<
      void(uint_type, enum_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(SamplerParameterf)>
      SamplerParameterf;

    gl_api_function<
      void(uint_type, enum_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(SamplerParameteri)>
      SamplerParameteri;

    gl_api_function<
      void(uint_type, enum_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(SamplerParameterfv)>
      SamplerParameterfv;

    gl_api_function<
      void(uint_type, enum_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(SamplerParameteriv)>
      SamplerParameteriv;

    gl_api_function<
      void(uint_type, enum_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(SamplerParameterIiv)>
      SamplerParameterIiv;

    gl_api_function<
      void(uint_type, enum_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(SamplerParameterIuiv)>
      SamplerParameterIuiv;

    gl_api_function<
      void(uint_type, enum_type, float_type*),
      OGLPLUS_GL_STATIC_FUNC(GetSamplerParameterfv)>
      GetSamplerParameterfv;

    gl_api_function<
      void(uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetSamplerParameteriv)>
      GetSamplerParameteriv;

    gl_api_function<
      void(uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetSamplerParameterIiv)>
      GetSamplerParameterIiv;

    gl_api_function<
      void(uint_type, enum_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GetSamplerParameterIuiv)>
      GetSamplerParameterIuiv;

    // renderbuffer object
    gl_api_function<
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GenRenderbuffers)>
      GenRenderbuffers;

    gl_api_function<
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(CreateRenderbuffers)>
      CreateRenderbuffers;

    gl_api_function<
      void(sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(DeleteRenderbuffers)>
      DeleteRenderbuffers;

    gl_api_function<
      bool_type(uint_type),
      OGLPLUS_GL_STATIC_FUNC(IsRenderbuffer)>
      IsRenderbuffer;

    gl_api_function<
      void(enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(BindRenderbuffer)>
      BindRenderbuffer;

    gl_api_function<
      void(enum_type, enum_type, sizei_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(RenderbufferStorage)>
      RenderbufferStorage;

    gl_api_function<
      void(uint_type, enum_type, sizei_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(NamedRenderbufferStorage)>
      NamedRenderbufferStorage;

    gl_api_function<
      void(enum_type, sizei_type, enum_type, sizei_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(RenderbufferStorageMultisample)>
      RenderbufferStorageMultisample;

    gl_api_function<
      void(uint_type, sizei_type, enum_type, sizei_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(NamedRenderbufferStorageMultisample)>
      NamedRenderbufferStorageMultisample;

    gl_api_function<
      void(enum_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetRenderbufferParameteriv)>
      GetRenderbufferParameteriv;

    gl_api_function<
      void(uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetNamedRenderbufferParameteriv)>
      GetNamedRenderbufferParameteriv;

    // framebuffer objects
    gl_api_function<
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GenFramebuffers)>
      GenFramebuffers;

    gl_api_function<
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(CreateFramebuffers)>
      CreateFramebuffers;

    gl_api_function<
      void(sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(DeleteFramebuffers)>
      DeleteFramebuffers;

    gl_api_function<bool_type(uint_type), OGLPLUS_GL_STATIC_FUNC(IsFramebuffer)>
      IsFramebuffer;

    gl_api_function<
      void(enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(BindFramebuffer)>
      BindFramebuffer;

    gl_api_function<void(enum_type), OGLPLUS_GL_STATIC_FUNC(DrawBuffer)>
      DrawBuffer;

    gl_api_function<
      void(uint_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(NamedFramebufferDrawBuffer)>
      NamedFramebufferDrawBuffer;

    gl_api_function<
      void(sizei_type, const enum_type*),
      OGLPLUS_GL_STATIC_FUNC(DrawBuffers)>
      DrawBuffers;

    gl_api_function<
      void(uint_type, sizei_type, const enum_type*),
      OGLPLUS_GL_STATIC_FUNC(NamedFramebufferDrawBuffers)>
      NamedFramebufferDrawBuffers;

    gl_api_function<
      void(enum_type, int_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(ClearBufferfv)>
      ClearBufferfv;

    gl_api_function<
      void(enum_type, int_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(ClearBufferiv)>
      ClearBufferiv;

    gl_api_function<
      void(enum_type, int_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(ClearBufferuiv)>
      ClearBufferuiv;

    gl_api_function<
      void(enum_type, int_type, float_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(ClearBufferfi)>
      ClearBufferfi;

    gl_api_function<
      void(uint_type, enum_type, int_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(ClearNamedFramebufferfv)>
      ClearNamedFramebufferfv;

    gl_api_function<
      void(uint_type, enum_type, int_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(ClearNamedFramebufferiv)>
      ClearNamedFramebufferiv;

    gl_api_function<
      void(uint_type, enum_type, int_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(ClearNamedFramebufferuiv)>
      ClearNamedFramebufferuiv;

    gl_api_function<
      void(uint_type, enum_type, int_type, float_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(ClearNamedFramebufferfi)>
      ClearNamedFramebufferfi;

    gl_api_function<
      void(enum_type, sizei_type, const enum_type*),
      OGLPLUS_GL_STATIC_FUNC(InvalidateFramebuffer)>
      InvalidateFramebuffer;

    gl_api_function<
      void(
        enum_type,
        sizei_type,
        const enum_type*,
        int_type,
        int_type,
        sizei_type,
        sizei_type),
      OGLPLUS_GL_STATIC_FUNC(InvalidateSubFramebuffer)>
      InvalidateSubFramebuffer;

    gl_api_function<
      void(uint_type, sizei_type, const enum_type*),
      OGLPLUS_GL_STATIC_FUNC(InvalidateFramebuffer)>
      InvalidateNamedFramebufferData;

    gl_api_function<
      void(
        uint_type,
        sizei_type,
        const enum_type*,
        int_type,
        int_type,
        sizei_type,
        sizei_type),
      OGLPLUS_GL_STATIC_FUNC(InvalidateNamedFramebufferSubData)>
      InvalidateNamedFramebufferSubData;

    gl_api_function<
      void(enum_type, enum_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(FramebufferParameteri)>
      FramebufferParameteri;

    gl_api_function<
      void(uint_type, enum_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(NamedFramebufferParameteri)>
      NamedFramebufferParameteri;

    gl_api_function<
      void(enum_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetFramebufferParameteriv)>
      GetFramebufferParameteriv;

    gl_api_function<
      void(uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetNamedFramebufferParameteriv)>
      GetNamedFramebufferParameteriv;

    gl_api_function<
      void(enum_type, enum_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetFramebufferAttachmentParameteriv)>
      GetFramebufferAttachmentParameteriv;

    gl_api_function<
      void(uint_type, enum_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetNamedFramebufferAttachmentParameteriv)>
      GetNamedFramebufferAttachmentParameteriv;

    gl_api_function<
      void(enum_type, enum_type, enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(FramebufferRenderbuffer)>
      FramebufferRenderbuffer;

    gl_api_function<
      void(uint_type, enum_type, enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(NamedFramebufferRenderbuffer)>
      NamedFramebufferRenderbuffer;

    gl_api_function<
      void(enum_type, enum_type, uint_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(FramebufferTexture)>
      FramebufferTexture;

    gl_api_function<
      void(uint_type, enum_type, uint_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(NamedFramebufferTexture)>
      NamedFramebufferTexture;

    gl_api_function<
      void(enum_type, enum_type, enum_type, uint_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(FramebufferTexture1D)>
      FramebufferTexture1D;

    gl_api_function<
      void(enum_type, enum_type, enum_type, uint_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(FramebufferTexture2D)>
      FramebufferTexture2D;

    gl_api_function<
      void(enum_type, enum_type, enum_type, uint_type, int_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(FramebufferTexture3D)>
      FramebufferTexture3D;

    gl_api_function<
      void(enum_type, enum_type, uint_type, int_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(FramebufferTextureLayer)>
      FramebufferTextureLayer;

    gl_api_function<
      void(uint_type, enum_type, uint_type, int_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(NamedFramebufferTextureLayer)>
      NamedFramebufferTextureLayer;

    gl_api_function<
      enum_type(enum_type),
      OGLPLUS_GL_STATIC_FUNC(CheckFramebufferStatus)>
      CheckFramebufferStatus;

    gl_api_function<
      enum_type(uint_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(CheckNamedFramebufferStatus)>
      CheckNamedFramebufferStatus;

    gl_api_function<void(enum_type), OGLPLUS_GL_STATIC_FUNC(ReadBuffer)>
      ReadBuffer;

    gl_api_function<
      void(uint_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(NamedFramebufferReadBuffer)>
      NamedFramebufferReadBuffer;

    gl_api_function<
      void(
        int_type,
        int_type,
        int_type,
        int_type,
        int_type,
        int_type,
        int_type,
        int_type,
        bitfield_type,
        enum_type),
      OGLPLUS_GL_STATIC_FUNC(BlitFramebuffer)>
      BlitFramebuffer;

    gl_api_function<
      void(
        uint_type,
        uint_type,
        int_type,
        int_type,
        int_type,
        int_type,
        int_type,
        int_type,
        int_type,
        int_type,
        bitfield_type,
        enum_type),
      OGLPLUS_GL_STATIC_FUNC(BlitNamedFramebuffer)>
      BlitNamedFramebuffer;

    gl_api_function<
      void(
        uint_type,
        enum_type,
        int_type,
        int_type,
        int_type,
        int_type,
        uint_type,
        enum_type,
        int_type,
        int_type,
        int_type,
        int_type,
        sizei_type,
        sizei_type,
        sizei_type),
      OGLPLUS_GL_STATIC_FUNC(CopyImageSubData)>
      CopyImageSubData;

    // transform feedback objects
    gl_api_function<
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GenTransformFeedbacks)>
      GenTransformFeedbacks;

    gl_api_function<
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(CreateTransformFeedbacks)>
      CreateTransformFeedbacks;

    gl_api_function<
      void(sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(DeleteTransformFeedbacks)>
      DeleteTransformFeedbacks;

    gl_api_function<
      bool_type(uint_type),
      OGLPLUS_GL_STATIC_FUNC(IsTransformFeedback)>
      IsTransformFeedback;

    gl_api_function<
      void(enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(BindTransformFeedback)>
      BindTransformFeedback;

    gl_api_function<
      void(enum_type),
      OGLPLUS_GL_STATIC_FUNC(BeginTransformFeedback)>
      BeginTransformFeedback;

    gl_api_function<void(), OGLPLUS_GL_STATIC_FUNC(PauseTransformFeedback)>
      PauseTransformFeedback;

    gl_api_function<void(), OGLPLUS_GL_STATIC_FUNC(ResumeTransformFeedback)>
      ResumeTransformFeedback;

    gl_api_function<void(), OGLPLUS_GL_STATIC_FUNC(EndTransformFeedback)>
      EndTransformFeedback;

    gl_api_function<
      void(uint_type, uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(TransformFeedbackBufferBase)>
      TransformFeedbackBufferBase;

    gl_api_function<
      void(uint_type, uint_type, uint_type, intptr_type, sizeiptr_type),
      OGLPLUS_GL_STATIC_FUNC(TransformFeedbackBufferRange)>
      TransformFeedbackBufferRange;

    gl_api_function<
      void(uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetTransformFeedbackiv)>
      GetTransformFeedbackiv;

    gl_api_function<
      void(uint_type, enum_type, uint_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetTransformFeedbacki_v)>
      GetTransformFeedbacki_v;

    gl_api_function<
      void(uint_type, enum_type, uint_type, int64_type*),
      OGLPLUS_GL_STATIC_FUNC(GetTransformFeedbacki64_v)>
      GetTransformFeedbacki64_v;

    // query objects
    gl_api_function<
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GenQueries)>
      GenQueries;

    gl_api_function<
      void(enum_type, sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(CreateQueries)>
      CreateQueries;

    gl_api_function<
      void(sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(DeleteQueries)>
      DeleteQueries;

    gl_api_function<bool_type(uint_type), OGLPLUS_GL_STATIC_FUNC(IsQuery)>
      IsQuery;

    gl_api_function<
      void(enum_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetQueryiv)>
      GetQueryiv;

    gl_api_function<
      void(enum_type, uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetQueryIndexediv)>
      GetQueryIndexediv;

    gl_api_function<
      void(uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetQueryObjectiv)>
      GetQueryObjectiv;

    gl_api_function<
      void(uint_type, enum_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GetQueryObjectuiv)>
      GetQueryObjectuiv;

    gl_api_function<
      void(uint_type, enum_type, int64_type*),
      OGLPLUS_GL_STATIC_FUNC(GetQueryObjecti64v)>
      GetQueryObjecti64v;

    gl_api_function<
      void(uint_type, enum_type, uint64_type*),
      OGLPLUS_GL_STATIC_FUNC(GetQueryObjectui64v)>
      GetQueryObjectui64v;

    gl_api_function<
      void(uint_type, uint_type, enum_type, intptr_type),
      OGLPLUS_GL_STATIC_FUNC(GetQueryBufferObjectiv)>
      GetQueryBufferObjectiv;

    gl_api_function<
      void(uint_type, uint_type, enum_type, intptr_type),
      OGLPLUS_GL_STATIC_FUNC(GetQueryBufferObjectuiv)>
      GetQueryBufferObjectuiv;

    gl_api_function<
      void(uint_type, uint_type, enum_type, intptr_type),
      OGLPLUS_GL_STATIC_FUNC(GetQueryBufferObjecti64v)>
      GetQueryBufferObjecti64v;

    gl_api_function<
      void(uint_type, uint_type, enum_type, intptr_type),
      OGLPLUS_GL_STATIC_FUNC(GetQueryBufferObjectui64v)>
      GetQueryBufferObjectui64v;

    gl_api_function<
      void(enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(BeginQuery)>
      BeginQuery;

    gl_api_function<
      void(enum_type, uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(BeginQueryIndexed)>
      BeginQueryIndexed;

    gl_api_function<void(enum_type), OGLPLUS_GL_STATIC_FUNC(EndQuery)> EndQuery;

    gl_api_function<
      void(enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(EndQueryIndexed)>
      EndQueryIndexed;

    gl_api_function<
      void(uint_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(QueryCounter)>
      QueryCounter;

    // conditional rendering
    gl_api_function<
      void(uint_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(BeginConditionalRender)>
      BeginConditionalRender;

    gl_api_function<void(), OGLPLUS_GL_STATIC_FUNC(EndConditionalRender)>
      EndConditionalRender;

    // program pipelines
    gl_api_function<
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GenProgramPipelines)>
      GenProgramPipelines;

    gl_api_function<
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(CreateProgramPipelines)>
      CreateProgramPipelines;

    gl_api_function<
      void(sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(DeleteProgramPipelines)>
      DeleteProgramPipelines;

    gl_api_function<
      bool_type(uint_type),
      OGLPLUS_GL_STATIC_FUNC(IsProgramPipeline)>
      IsProgramPipeline;

    gl_api_function<
      void(uint_type),
      OGLPLUS_GL_STATIC_FUNC(BindProgramPipeline)>
      BindProgramPipeline;

    gl_api_function<
      void(uint_type),
      OGLPLUS_GL_STATIC_FUNC(ValidateProgramPipeline)>
      ValidateProgramPipeline;

    gl_api_function<
      void(uint_type, bitfield_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(UseProgramStages)>
      UseProgramStages;

    gl_api_function<
      void(uint_type, enum_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetProgramStageiv)>
      GetProgramStageiv;

    gl_api_function<
      void(uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetProgramPipelineiv)>
      GetProgramPipelineiv;

    gl_api_function<
      void(uint_type, sizei_type, sizei_type*, char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetProgramPipelineInfoLog)>
      GetProgramPipelineInfoLog;

    gl_api_function<
      void(uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(ActiveShaderProgram)>
      ActiveShaderProgram;

    //
    gl_api_function<uint_type(enum_type), OGLPLUS_GL_STATIC_FUNC(CreateShader)>
      CreateShader;

    gl_api_function<void(uint_type), OGLPLUS_GL_STATIC_FUNC(DeleteShader)>
      DeleteShader;

    gl_api_function<bool_type(uint_type), OGLPLUS_GL_STATIC_FUNC(IsShader)>
      IsShader;

    gl_api_function<
      void(uint_type, sizei_type, const char_type* const*, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(ShaderSource)>
      ShaderSource;

    gl_api_function<void(uint_type), OGLPLUS_GL_STATIC_FUNC(CompileShader)>
      CompileShader;

    gl_api_function<
      void(
        sizei_type,
        const uint_type*,
        enum_type,
        const_void_ptr_type,
        sizei_type),
      OGLPLUS_GL_STATIC_FUNC(ShaderBinary)>
      ShaderBinary;

    gl_api_function<
      void(
        uint_type,
        const char_type*,
        uint_type,
        const uint_type*,
        const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(SpecializeShader)>
      SpecializeShader;

    gl_api_function<
      void(uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetShaderiv)>
      GetShaderiv;

    gl_api_function<
      void(uint_type, sizei_type, sizei_type*, char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetShaderInfoLog)>
      GetShaderInfoLog;

    gl_api_function<
      void(uint_type, sizei_type, sizei_type*, char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetShaderSource)>
      GetShaderSource;

    gl_api_function<
      void(enum_type, enum_type, int_type*, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetShaderPrecisionFormat)>
      GetShaderPrecisionFormat;

    gl_api_function<void(), OGLPLUS_GL_STATIC_FUNC(ReleaseShaderCompiler)>
      ReleaseShaderCompiler;

    //
    gl_api_function<uint_type(), OGLPLUS_GL_STATIC_FUNC(CreateProgram)>
      CreateProgram;

    gl_api_function<
      uint_type(enum_type, sizei_type, const char_type* const*),
      OGLPLUS_GL_STATIC_FUNC(CreateShaderProgramv)>
      CreateShaderProgramv;

    gl_api_function<void(uint_type), OGLPLUS_GL_STATIC_FUNC(DeleteProgram)>
      DeleteProgram;

    gl_api_function<bool_type(uint_type), OGLPLUS_GL_STATIC_FUNC(IsProgram)>
      IsProgram;

    gl_api_function<
      void(uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(AttachShader)>
      AttachShader;

    gl_api_function<
      void(uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(DetachShader)>
      DetachShader;

    gl_api_function<
      void(uint_type, sizei_type, sizei_type*, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GetAttachedShaders)>
      GetAttachedShaders;

    gl_api_function<void(uint_type), OGLPLUS_GL_STATIC_FUNC(ValidateProgram)>
      ValidateProgram;

    gl_api_function<void(uint_type), OGLPLUS_GL_STATIC_FUNC(LinkProgram)>
      LinkProgram;

    gl_api_function<void(uint_type), OGLPLUS_GL_STATIC_FUNC(UseProgram)>
      UseProgram;

    gl_api_function<
      void(uint_type, enum_type, const_void_ptr_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(ProgramBinary)>
      ProgramBinary;

    gl_api_function<
      void(uint_type, sizei_type, sizei_type*, enum_type*, void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(GetProgramBinary)>
      GetProgramBinary;

    gl_api_function<
      void(uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetProgramiv)>
      GetProgramiv;

    gl_api_function<
      void(uint_type, sizei_type, sizei_type*, char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetProgramInfoLog)>
      GetProgramInfoLog;

    gl_api_function<
      void(uint_type, enum_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetProgramInterfaceiv)>
      GetProgramInterfaceiv;

    gl_api_function<
      uint_type(uint_type, enum_type, const char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetProgramResourceIndex)>
      GetProgramResourceIndex;

    gl_api_function<
      void(
        uint_type, enum_type, uint_type, sizei_type, sizei_type*, char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetProgramResourceName)>
      GetProgramResourceName;

    gl_api_function<
      int_type(uint_type, enum_type, const char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetProgramResourceLocation)>
      GetProgramResourceLocation;

    gl_api_function<
      int_type(uint_type, enum_type, const char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetProgramResourceLocationIndex)>
      GetProgramResourceLocationIndex;

    gl_api_function<
      void(
        uint_type,
        enum_type,
        uint_type,
        sizei_type,
        const enum_type*,
        sizei_type,
        sizei_type*,
        int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetProgramResourceiv)>
      GetProgramResourceiv;

    gl_api_function<
      void(
        uint_type,
        enum_type,
        uint_type,
        sizei_type,
        const enum_type*,
        sizei_type,
        sizei_type*,
        float_type*),
      OGLPLUS_GL_STATIC_FUNC(GetProgramResourcefvNV)>
      GetProgramResourcefvNV;

    gl_api_function<
      void(uint_type, uint_type, const char_type*),
      OGLPLUS_GL_STATIC_FUNC(BindAttribLocation)>
      BindAttribLocation;

    gl_api_function<
      int_type(uint_type, const char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetAttribLocation)>
      GetAttribLocation;

    gl_api_function<
      void(
        uint_type,
        uint_type,
        sizei_type,
        sizei_type*,
        int_type*,
        enum_type*,
        char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetActiveAttrib)>
      GetActiveAttrib;

    gl_api_function<
      int_type(uint_type, const char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetUniformLocation)>
      GetUniformLocation;

    gl_api_function<
      void(uint_type, uint_type, sizei_type, sizei_type*, char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetActiveUniformName)>
      GetActiveUniformName;

    gl_api_function<
      uint_type(uint_type, enum_type, const char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetSubroutineIndex)>
      GetSubroutineIndex;

    gl_api_function<
      void(
        uint_type, enum_type, uint_type, sizei_type, sizei_type*, char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetActiveSubroutineName)>
      GetActiveSubroutineName;

    gl_api_function<
      void(
        uint_type, enum_type, uint_type, sizei_type, sizei_type*, char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetActiveSubroutineUniformName)>
      GetActiveSubroutineUniformName;

    gl_api_function<
      int_type(uint_type, enum_type, const char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetSubroutineUniformLocation)>
      GetSubroutineUniformLocation;

    gl_api_function<
      void(uint_type, enum_type, uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetActiveSubroutineUniformiv)>
      GetActiveSubroutineUniformiv;

    gl_api_function<
      void(uint_type, sizei_type, const char_type* const*, enum_type),
      OGLPLUS_GL_STATIC_FUNC(TransformFeedbackVaryings)>
      TransformFeedbackVaryings;

    gl_api_function<
      void(
        uint_type,
        uint_type,
        sizei_type,
        sizei_type*,
        sizei_type*,
        enum_type*,
        char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetTransformFeedbackVarying)>
      GetTransformFeedbackVarying;

    gl_api_function<
      void(uint_type, uint_type, const char_type*),
      OGLPLUS_GL_STATIC_FUNC(BindFragDataLocation)>
      BindFragDataLocation;

    gl_api_function<
      void(uint_type, uint_type, uint_type, const char_type*),
      OGLPLUS_GL_STATIC_FUNC(BindFragDataLocationIndexed)>
      BindFragDataLocationIndexed;

    gl_api_function<
      int_type(uint_type, const char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetFragDataLocation)>
      GetFragDataLocation;

    gl_api_function<
      int_type(uint_type, const char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetFragDataIndex)>
      GetFragDataIndex;

    // uniform subroutine
    gl_api_function<
      void(enum_type, sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(UniformSubroutinesuiv)>
      UniformSubroutinesuiv;

    gl_api_function<
      void(enum_type, int_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GetUniformSubroutineuiv)>
      GetUniformSubroutineuiv;

    // uniform
    gl_api_function<void(int_type, int_type), OGLPLUS_GL_STATIC_FUNC(Uniform1i)>
      Uniform1i;

    gl_api_function<
      void(int_type, int_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(Uniform2i)>
      Uniform2i;

    gl_api_function<
      void(int_type, int_type, int_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(Uniform3i)>
      Uniform3i;

    gl_api_function<
      void(int_type, int_type, int_type, int_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(Uniform4i)>
      Uniform4i;

    gl_api_function<
      void(int_type, sizei_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(Uniform1iv)>
      Uniform1iv;

    gl_api_function<
      void(int_type, sizei_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(Uniform2iv)>
      Uniform2iv;

    gl_api_function<
      void(int_type, sizei_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(Uniform3iv)>
      Uniform3iv;

    gl_api_function<
      void(int_type, sizei_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(Uniform4iv)>
      Uniform4iv;

    gl_api_function<
      void(int_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(Uniform1ui)>
      Uniform1ui;

    gl_api_function<
      void(int_type, uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(Uniform2ui)>
      Uniform2ui;

    gl_api_function<
      void(int_type, uint_type, uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(Uniform3ui)>
      Uniform3ui;

    gl_api_function<
      void(int_type, uint_type, uint_type, uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(Uniform4ui)>
      Uniform4ui;

    gl_api_function<
      void(int_type, sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(Uniform1uiv)>
      Uniform1uiv;

    gl_api_function<
      void(int_type, sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(Uniform2uiv)>
      Uniform2uiv;

    gl_api_function<
      void(int_type, sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(Uniform3uiv)>
      Uniform3uiv;

    gl_api_function<
      void(int_type, sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(Uniform4uiv)>
      Uniform4uiv;

    gl_api_function<
      void(int_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(Uniform1f)>
      Uniform1f;

    gl_api_function<
      void(int_type, float_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(Uniform2f)>
      Uniform2f;

    gl_api_function<
      void(int_type, float_type, float_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(Uniform3f)>
      Uniform3f;

    gl_api_function<
      void(int_type, float_type, float_type, float_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(Uniform4f)>
      Uniform4f;

    gl_api_function<
      void(int_type, sizei_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(Uniform1fv)>
      Uniform1fv;

    gl_api_function<
      void(int_type, sizei_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(Uniform2fv)>
      Uniform2fv;

    gl_api_function<
      void(int_type, sizei_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(Uniform3fv)>
      Uniform3fv;

    gl_api_function<
      void(int_type, sizei_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(Uniform4fv)>
      Uniform4fv;

    gl_api_function<
      void(int_type, sizei_type, bool_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(UniformMatrix2fv)>
      UniformMatrix2fv;

    gl_api_function<
      void(int_type, sizei_type, bool_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(UniformMatrix3fv)>
      UniformMatrix3fv;

    gl_api_function<
      void(int_type, sizei_type, bool_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(UniformMatrix4fv)>
      UniformMatrix4fv;

    gl_api_function<
      void(int_type, sizei_type, bool_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(UniformMatrix2x3fv)>
      UniformMatrix2x3fv;

    gl_api_function<
      void(int_type, sizei_type, bool_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(UniformMatrix3x2fv)>
      UniformMatrix3x2fv;

    gl_api_function<
      void(int_type, sizei_type, bool_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(UniformMatrix2x4fv)>
      UniformMatrix2x4fv;

    gl_api_function<
      void(int_type, sizei_type, bool_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(UniformMatrix4x2fv)>
      UniformMatrix4x2fv;

    gl_api_function<
      void(int_type, sizei_type, bool_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(UniformMatrix3x4fv)>
      UniformMatrix3x4fv;

    gl_api_function<
      void(int_type, sizei_type, bool_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(UniformMatrix4x3fv)>
      UniformMatrix4x3fv;

    gl_api_function<
      void(uint_type, int_type, float_type*),
      OGLPLUS_GL_STATIC_FUNC(GetUniformfv)>
      GetUniformfv;

    gl_api_function<
      void(uint_type, int_type, double_type*),
      OGLPLUS_GL_STATIC_FUNC(GetUniformdv)>
      GetUniformdv;

    gl_api_function<
      void(uint_type, int_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetUniformiv)>
      GetUniformiv;

    gl_api_function<
      void(uint_type, int_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GetUniformuiv)>
      GetUniformuiv;

    gl_api_function<
      void(uint_type, int_type, sizei_type, float_type*),
      OGLPLUS_GL_STATIC_FUNC(GetnUniformfv)>
      GetnUniformfv;

    gl_api_function<
      void(uint_type, int_type, sizei_type, double_type*),
      OGLPLUS_GL_STATIC_FUNC(GetnUniformdv)>
      GetnUniformdv;

    gl_api_function<
      void(uint_type, int_type, sizei_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetnUniformiv)>
      GetnUniformiv;

    gl_api_function<
      void(uint_type, int_type, sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GetnUniformuiv)>
      GetnUniformuiv;

    // program uniform
    gl_api_function<
      void(uint_type, int_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform1i)>
      ProgramUniform1i;

    gl_api_function<
      void(uint_type, int_type, int_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform2i)>
      ProgramUniform2i;

    gl_api_function<
      void(uint_type, int_type, int_type, int_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform3i)>
      ProgramUniform3i;

    gl_api_function<
      void(uint_type, int_type, int_type, int_type, int_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform4i)>
      ProgramUniform4i;

    gl_api_function<
      void(uint_type, int_type, sizei_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform1iv)>
      ProgramUniform1iv;

    gl_api_function<
      void(uint_type, int_type, sizei_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform2iv)>
      ProgramUniform2iv;

    gl_api_function<
      void(uint_type, int_type, sizei_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform3iv)>
      ProgramUniform3iv;

    gl_api_function<
      void(uint_type, int_type, sizei_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform4iv)>
      ProgramUniform4iv;

    gl_api_function<
      void(uint_type, int_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform1ui)>
      ProgramUniform1ui;

    gl_api_function<
      void(uint_type, int_type, uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform2ui)>
      ProgramUniform2ui;

    gl_api_function<
      void(uint_type, int_type, uint_type, uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform3ui)>
      ProgramUniform3ui;

    gl_api_function<
      void(uint_type, int_type, uint_type, uint_type, uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform4ui)>
      ProgramUniform4ui;

    gl_api_function<
      void(uint_type, int_type, sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform1uiv)>
      ProgramUniform1uiv;

    gl_api_function<
      void(uint_type, int_type, sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform2uiv)>
      ProgramUniform2uiv;

    gl_api_function<
      void(uint_type, int_type, sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform3uiv)>
      ProgramUniform3uiv;

    gl_api_function<
      void(uint_type, int_type, sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform4uiv)>
      ProgramUniform4uiv;

    gl_api_function<
      void(uint_type, int_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform1f)>
      ProgramUniform1f;

    gl_api_function<
      void(uint_type, int_type, float_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform2f)>
      ProgramUniform2f;

    gl_api_function<
      void(uint_type, int_type, float_type, float_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform3f)>
      ProgramUniform3f;

    gl_api_function<
      void(uint_type, int_type, float_type, float_type, float_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform4f)>
      ProgramUniform4f;

    gl_api_function<
      void(uint_type, int_type, sizei_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform1fv)>
      ProgramUniform1fv;

    gl_api_function<
      void(uint_type, int_type, sizei_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform2fv)>
      ProgramUniform2fv;

    gl_api_function<
      void(uint_type, int_type, sizei_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform3fv)>
      ProgramUniform3fv;

    gl_api_function<
      void(uint_type, int_type, sizei_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform4fv)>
      ProgramUniform4fv;

    gl_api_function<
      void(uint_type, int_type, sizei_type, bool_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniformMatrix2fv)>
      ProgramUniformMatrix2fv;

    gl_api_function<
      void(uint_type, int_type, sizei_type, bool_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniformMatrix3fv)>
      ProgramUniformMatrix3fv;

    gl_api_function<
      void(uint_type, int_type, sizei_type, bool_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniformMatrix4fv)>
      ProgramUniformMatrix4fv;

    gl_api_function<
      void(uint_type, int_type, sizei_type, bool_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniformMatrix2x3fv)>
      ProgramUniformMatrix2x3fv;

    gl_api_function<
      void(uint_type, int_type, sizei_type, bool_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniformMatrix3x2fv)>
      ProgramUniformMatrix3x2fv;

    gl_api_function<
      void(uint_type, int_type, sizei_type, bool_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniformMatrix2x4fv)>
      ProgramUniformMatrix2x4fv;

    gl_api_function<
      void(uint_type, int_type, sizei_type, bool_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniformMatrix4x2fv)>
      ProgramUniformMatrix4x2fv;

    gl_api_function<
      void(uint_type, int_type, sizei_type, bool_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniformMatrix3x4fv)>
      ProgramUniformMatrix3x4fv;

    gl_api_function<
      void(uint_type, int_type, sizei_type, bool_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniformMatrix4x3fv)>
      ProgramUniformMatrix4x3fv;

    // uniform blocks
    gl_api_function<
      void(uint_type, uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(UniformBlockBinding)>
      UniformBlockBinding;

    gl_api_function<
      void(uint_type, uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(ShaderStorageBlockBinding)>
      ShaderStorageBlockBinding;

    // vertex attrib
    gl_api_function<
      void(uint_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib1f)>
      VertexAttrib1f;

    gl_api_function<
      void(uint_type, float_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib2f)>
      VertexAttrib2f;

    gl_api_function<
      void(uint_type, float_type, float_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib3f)>
      VertexAttrib3f;

    gl_api_function<
      void(uint_type, float_type, float_type, float_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib4f)>
      VertexAttrib4f;

    gl_api_function<
      void(uint_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib1fv)>
      VertexAttrib1fv;

    gl_api_function<
      void(uint_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib2fv)>
      VertexAttrib2fv;

    gl_api_function<
      void(uint_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib3fv)>
      VertexAttrib3fv;

    gl_api_function<
      void(uint_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib4fv)>
      VertexAttrib4fv;

    gl_api_function<
      void(uint_type, double_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib1d)>
      VertexAttrib1d;

    gl_api_function<
      void(uint_type, double_type, double_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib2d)>
      VertexAttrib2d;

    gl_api_function<
      void(uint_type, double_type, double_type, double_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib3d)>
      VertexAttrib3d;

    gl_api_function<
      void(uint_type, double_type, double_type, double_type, double_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib4d)>
      VertexAttrib4d;

    gl_api_function<
      void(uint_type, const double_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib1dv)>
      VertexAttrib1dv;

    gl_api_function<
      void(uint_type, const double_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib2dv)>
      VertexAttrib2dv;

    gl_api_function<
      void(uint_type, const double_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib3dv)>
      VertexAttrib3dv;

    gl_api_function<
      void(uint_type, const double_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib4dv)>
      VertexAttrib4dv;

    gl_api_function<
      void(uint_type, short_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib1s)>
      VertexAttrib1s;

    gl_api_function<
      void(uint_type, short_type, short_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib2s)>
      VertexAttrib2s;

    gl_api_function<
      void(uint_type, short_type, short_type, short_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib3s)>
      VertexAttrib3s;

    gl_api_function<
      void(uint_type, short_type, short_type, short_type, short_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib4s)>
      VertexAttrib4s;

    gl_api_function<
      void(uint_type, const short_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib1sv)>
      VertexAttrib1sv;

    gl_api_function<
      void(uint_type, const short_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib2sv)>
      VertexAttrib2sv;

    gl_api_function<
      void(uint_type, const short_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib3sv)>
      VertexAttrib3sv;

    gl_api_function<
      void(uint_type, const short_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib4sv)>
      VertexAttrib4sv;

    gl_api_function<
      void(uint_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI1i)>
      VertexAttribI1i;

    gl_api_function<
      void(uint_type, int_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI2i)>
      VertexAttribI2i;

    gl_api_function<
      void(uint_type, int_type, int_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI3i)>
      VertexAttribI3i;

    gl_api_function<
      void(uint_type, int_type, int_type, int_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI4i)>
      VertexAttribI4i;

    gl_api_function<
      void(uint_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI1iv)>
      VertexAttribI1iv;

    gl_api_function<
      void(uint_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI2iv)>
      VertexAttribI2iv;

    gl_api_function<
      void(uint_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI3iv)>
      VertexAttribI3iv;

    gl_api_function<
      void(uint_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI4iv)>
      VertexAttribI4iv;

    gl_api_function<
      void(uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI1ui)>
      VertexAttribI1ui;

    gl_api_function<
      void(uint_type, uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI2ui)>
      VertexAttribI2ui;

    gl_api_function<
      void(uint_type, uint_type, uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI3ui)>
      VertexAttribI3ui;

    gl_api_function<
      void(uint_type, uint_type, uint_type, uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI4ui)>
      VertexAttribI4ui;

    gl_api_function<
      void(uint_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI1uiv)>
      VertexAttribI1uiv;

    gl_api_function<
      void(uint_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI2uiv)>
      VertexAttribI2uiv;

    gl_api_function<
      void(uint_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI3uiv)>
      VertexAttribI3uiv;

    gl_api_function<
      void(uint_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI4uiv)>
      VertexAttribI4uiv;

    gl_api_function<
      void(uint_type, const byte_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI4bv)>
      VertexAttribI4bv;

    gl_api_function<
      void(uint_type, const ubyte_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI4ubv)>
      VertexAttribI4ubv;

    gl_api_function<
      void(uint_type, const short_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI4sv)>
      VertexAttribI4sv;

    gl_api_function<
      void(uint_type, const ushort_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI4usv)>
      VertexAttribI4usv;

    gl_api_function<
      void(uint_type, const byte_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib4bv)>
      VertexAttrib4bv;

    gl_api_function<
      void(uint_type, const ubyte_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib4ubv)>
      VertexAttrib4ubv;

    gl_api_function<
      void(uint_type, const ushort_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib4usv)>
      VertexAttrib4usv;

    gl_api_function<
      void(uint_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib4iv)>
      VertexAttrib4iv;

    gl_api_function<
      void(uint_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib4uiv)>
      VertexAttrib4uiv;

    gl_api_function<
      void(uint_type, ubyte_type, ubyte_type, ubyte_type, ubyte_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib4Nub)>
      VertexAttrib4Nub;

    gl_api_function<
      void(uint_type, const byte_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib4Nbv)>
      VertexAttrib4Nbv;

    gl_api_function<
      void(uint_type, const ubyte_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib4Nubv)>
      VertexAttrib4Nubv;

    gl_api_function<
      void(uint_type, const short_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib4Nsv)>
      VertexAttrib4Nsv;

    gl_api_function<
      void(uint_type, const ushort_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib4Nusv)>
      VertexAttrib4Nusv;

    gl_api_function<
      void(uint_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib4Niv)>
      VertexAttrib4Niv;

    gl_api_function<
      void(uint_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib4Nuiv)>
      VertexAttrib4Nuiv;

    gl_api_function<
      void(uint_type, double_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribL1d)>
      VertexAttribL1d;

    gl_api_function<
      void(uint_type, double_type, double_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribL2d)>
      VertexAttribL2d;

    gl_api_function<
      void(uint_type, double_type, double_type, double_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribL3d)>
      VertexAttribL3d;

    gl_api_function<
      void(uint_type, double_type, double_type, double_type, double_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribL4d)>
      VertexAttribL4d;

    gl_api_function<
      void(uint_type, const double_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribL1dv)>
      VertexAttribL1dv;

    gl_api_function<
      void(uint_type, const double_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribL2dv)>
      VertexAttribL2dv;

    gl_api_function<
      void(uint_type, const double_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribL3dv)>
      VertexAttribL3dv;

    gl_api_function<
      void(uint_type, const double_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribL4dv)>
      VertexAttribL4dv;

    gl_api_function<
      void(uint_type, enum_type, bool_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribP1ui)>
      VertexAttribP1ui;

    gl_api_function<
      void(uint_type, enum_type, bool_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribP2ui)>
      VertexAttribP2ui;

    gl_api_function<
      void(uint_type, enum_type, bool_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribP3ui)>
      VertexAttribP3ui;

    gl_api_function<
      void(uint_type, enum_type, bool_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribP4ui)>
      VertexAttribP4ui;

    gl_api_function<
      void(uint_type, enum_type, bool_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribP1uiv)>
      VertexAttribP1uiv;

    gl_api_function<
      void(uint_type, enum_type, bool_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribP2uiv)>
      VertexAttribP2uiv;

    gl_api_function<
      void(uint_type, enum_type, bool_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribP3uiv)>
      VertexAttribP3uiv;

    gl_api_function<
      void(uint_type, enum_type, bool_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribP4uiv)>
      VertexAttribP4uiv;

    // vertex attrib format
    gl_api_function<
      void(uint_type, int_type, enum_type, bool_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribFormat)>
      VertexAttribFormat;

    gl_api_function<
      void(uint_type, int_type, enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribIFormat)>
      VertexAttribIFormat;

    gl_api_function<
      void(uint_type, int_type, enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribLFormat)>
      VertexAttribLFormat;

    gl_api_function<
      void(uint_type, uint_type, int_type, enum_type, bool_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexArrayAttribFormat)>
      VertexArrayAttribFormat;

    gl_api_function<
      void(uint_type, uint_type, int_type, enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexArrayAttribIFormat)>
      VertexArrayAttribIFormat;

    gl_api_function<
      void(uint_type, uint_type, int_type, enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexArrayAttribLFormat)>
      VertexArrayAttribLFormat;

    gl_api_function<
      void(
        uint_type,
        int_type,
        enum_type,
        bool_type,
        sizei_type,
        const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribPointer)>
      VertexAttribPointer;

    gl_api_function<
      void(uint_type, int_type, enum_type, sizei_type, const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribIPointer)>
      VertexAttribIPointer;

    gl_api_function<
      void(uint_type, int_type, enum_type, sizei_type, const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribLPointer)>
      VertexAttribLPointer;

    gl_api_function<
      void(uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetVertexArrayiv)>
      GetVertexArrayiv;

    gl_api_function<
      void(uint_type, uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetVertexArrayIndexediv)>
      GetVertexArrayIndexediv;

    gl_api_function<
      void(uint_type, uint_type, enum_type, int64_type*),
      OGLPLUS_GL_STATIC_FUNC(GetVertexArrayIndexed64iv)>
      GetVertexArrayIndexed64iv;

    gl_api_function<
      void(uint_type, enum_type, double_type*),
      OGLPLUS_GL_STATIC_FUNC(GetVertexAttribdv)>
      GetVertexAttribdv;

    gl_api_function<
      void(uint_type, enum_type, float_type*),
      OGLPLUS_GL_STATIC_FUNC(GetVertexAttribfv)>
      GetVertexAttribfv;

    gl_api_function<
      void(uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetVertexAttribiv)>
      GetVertexAttribiv;

    gl_api_function<
      void(uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetVertexAttribIiv)>
      GetVertexAttribIiv;

    gl_api_function<
      void(uint_type, enum_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GetVertexAttribIuiv)>
      GetVertexAttribIuiv;

    gl_api_function<
      void(uint_type, enum_type, double_type*),
      OGLPLUS_GL_STATIC_FUNC(GetVertexAttribLdv)>
      GetVertexAttribLdv;

    gl_api_function<
      void(uint_type, enum_type, void_ptr_type*),
      OGLPLUS_GL_STATIC_FUNC(GetVertexAttribPointerv)>
      GetVertexAttribPointerv;

    // viewport
    gl_api_function<
      void(enum_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(ClipControl)>
      ClipControl;

    gl_api_function<
      void(double_type, double_type),
      OGLPLUS_GL_STATIC_FUNC(DepthRange)>
      DepthRange;

    gl_api_function<
      void(float_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(DepthRangef)>
      DepthRangef;

    gl_api_function<
      void(uint_type, sizei_type, const double_type*),
      OGLPLUS_GL_STATIC_FUNC(DepthRangeArrayv)>
      DepthRangeArrayv;

    gl_api_function<
      void(uint_type, double_type, double_type),
      OGLPLUS_GL_STATIC_FUNC(DepthRangeIndexed)>
      DepthRangeIndexed;

    gl_api_function<
      void(int_type, int_type, sizei_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(Viewport)>
      Viewport;

    gl_api_function<
      void(uint_type, sizei_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(ViewportArrayv)>
      ViewportArrayv;

    gl_api_function<
      void(uint_type, float_type, float_type, float_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(ViewportIndexedf)>
      ViewportIndexedf;

    gl_api_function<
      void(uint_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(ViewportIndexedfv)>
      ViewportIndexedfv;

    // scissor test
    gl_api_function<
      void(int_type, int_type, sizei_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(Scissor)>
      Scissor;

    gl_api_function<
      void(uint_type, sizei_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(ScissorArrayv)>
      ScissorArrayv;

    gl_api_function<
      void(uint_type, int_type, int_type, sizei_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(ScissorIndexed)>
      ScissorIndexed;

    gl_api_function<
      void(uint_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(ScissorIndexedv)>
      ScissorIndexedv;

    // stencil test
    gl_api_function<
      void(enum_type, int_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(StencilFunc)>
      StencilFunc;

    gl_api_function<
      void(enum_type, enum_type, int_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(StencilFuncSeparate)>
      StencilFuncSeparate;

    gl_api_function<
      void(enum_type, enum_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(StencilOp)>
      StencilOp;

    gl_api_function<
      void(enum_type, enum_type, enum_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(StencilOpSeparate)>
      StencilOpSeparate;

    // depth test
    gl_api_function<void(enum_type), OGLPLUS_GL_STATIC_FUNC(DepthFunc)>
      DepthFunc;

    // buffer masking
    gl_api_function<
      void(bool_type, bool_type, bool_type, bool_type),
      OGLPLUS_GL_STATIC_FUNC(ColorMask)>
      ColorMask;

    gl_api_function<
      void(uint_type, bool_type, bool_type, bool_type, bool_type),
      OGLPLUS_GL_STATIC_FUNC(ColorMaski)>
      ColorMaski;

    gl_api_function<void(bool_type), OGLPLUS_GL_STATIC_FUNC(DepthMask)>
      DepthMask;

    gl_api_function<void(uint_type), OGLPLUS_GL_STATIC_FUNC(StencilMask)>
      StencilMask;

    gl_api_function<
      void(enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(StencilMaskSeparate)>
      StencilMaskSeparate;

    // draw buffer clearing
    gl_api_function<
      void(float_type, float_type, float_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(ClearColor)>
      ClearColor;

    gl_api_function<void(float_type), OGLPLUS_GL_STATIC_FUNC(ClearDepthf)>
      ClearDepthf;

    gl_api_function<void(double_type), OGLPLUS_GL_STATIC_FUNC(ClearDepth)>
      ClearDepth;

    gl_api_function<void(int_type), OGLPLUS_GL_STATIC_FUNC(ClearStencil)>
      ClearStencil;

    gl_api_function<void(bitfield_type), OGLPLUS_GL_STATIC_FUNC(Clear)> Clear;

    // draw parameters
    gl_api_function<
      void(uint_type),
      OGLPLUS_GL_STATIC_FUNC(PrimitiveRestartIndex)>
      PrimitiveRestartIndex;

    gl_api_function<void(enum_type), OGLPLUS_GL_STATIC_FUNC(ProvokingVertex)>
      ProvokingVertex;

    gl_api_function<void(float_type), OGLPLUS_GL_STATIC_FUNC(LineWidth)>
      LineWidth;

    gl_api_function<void(float_type), OGLPLUS_GL_STATIC_FUNC(PointSize)>
      PointSize;

    gl_api_function<
      void(enum_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(PointParameteri)>
      PointParameteri;

    gl_api_function<
      void(enum_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(PointParameterf)>
      PointParameterf;

    gl_api_function<
      void(enum_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(PointParameteriv)>
      PointParameteriv;

    gl_api_function<
      void(enum_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(PointParameterfv)>
      PointParameterfv;

    gl_api_function<
      void(enum_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(PatchParameteri)>
      PatchParameteri;

    gl_api_function<
      void(enum_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(PatchParameterfv)>
      PatchParameterfv;

    gl_api_function<void(enum_type), OGLPLUS_GL_STATIC_FUNC(FrontFace)>
      FrontFace;

    gl_api_function<void(enum_type), OGLPLUS_GL_STATIC_FUNC(CullFace)> CullFace;

    gl_api_function<
      void(enum_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(PolygonMode)>
      PolygonMode;

    gl_api_function<
      void(float_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(PolygonOffset)>
      PolygonOffset;

    gl_api_function<
      void(float_type, float_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(PolygonOffsetClamp)>
      PolygonOffsetClamp;

    gl_api_function<
      void(float_type, bool_type),
      OGLPLUS_GL_STATIC_FUNC(SampleCoverage)>
      SampleCoverage;

    gl_api_function<
      void(uint_type, bitfield_type),
      OGLPLUS_GL_STATIC_FUNC(SampleMaski)>
      SampleMaski;

    gl_api_function<void(float_type), OGLPLUS_GL_STATIC_FUNC(MinSampleShading)>
      MinSampleShading;

    gl_api_function<
      void(enum_type, uint_type, float_type*),
      OGLPLUS_GL_STATIC_FUNC(GetMultisamplefv)>
      GetMultisamplefv;

    // blending
    gl_api_function<void(enum_type), OGLPLUS_GL_STATIC_FUNC(BlendEquation)>
      BlendEquation;

    gl_api_function<
      void(enum_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(BlendEquationSeparate)>
      BlendEquationSeparate;

    gl_api_function<
      void(uint_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(BlendEquationi)>
      BlendEquationi;

    gl_api_function<
      void(uint_type, enum_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(BlendEquationSeparatei)>
      BlendEquationSeparatei;

    gl_api_function<
      void(enum_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(BlendFunc)>
      BlendFunc;

    gl_api_function<
      void(enum_type, enum_type, enum_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(BlendFuncSeparate)>
      BlendFuncSeparate;

    gl_api_function<
      void(uint_type, enum_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(BlendFunci)>
      BlendFunci;

    gl_api_function<
      void(uint_type, enum_type, enum_type, enum_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(BlendFuncSeparatei)>
      BlendFuncSeparatei;

    gl_api_function<
      void(float_type, float_type, float_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(BlendColor)>
      BlendColor;

    // logic operation
    gl_api_function<void(enum_type), OGLPLUS_GL_STATIC_FUNC(LogicOp)> LogicOp;

    // draw arrays
    gl_api_function<
      void(enum_type, int_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(DrawArrays)>
      DrawArrays;

    gl_api_function<
      void(enum_type, int_type, sizei_type, sizei_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(DrawArraysInstancedBaseInstance)>
      DrawArraysInstancedBaseInstance;

    gl_api_function<
      void(enum_type, int_type, sizei_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(DrawArraysInstanced)>
      DrawArraysInstanced;

    gl_api_function<
      void(enum_type, const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(DrawArraysIndirect)>
      DrawArraysIndirect;

    gl_api_function<
      void(enum_type, const int_type*, const sizei_type*, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(MultiDrawArrays)>
      MultiDrawArrays;

    gl_api_function<
      void(enum_type, const_void_ptr_type, sizei_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(MultiDrawArraysIndirect)>
      MultiDrawArraysIndirect;

    gl_api_function<
      void(enum_type, const_void_ptr_type, intptr_type, sizei_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(MultiDrawArraysIndirectCount)>
      MultiDrawArraysIndirectCount;

    // draw elements
    gl_api_function<
      void(enum_type, sizei_type, enum_type, const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(DrawElements)>
      DrawElements;

    gl_api_function<
      void(
        enum_type,
        uint_type,
        uint_type,
        sizei_type,
        enum_type,
        const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(DrawRangeElements)>
      DrawRangeElements;

    gl_api_function<
      void(
        enum_type,
        sizei_type,
        enum_type,
        const_void_ptr_type,
        sizei_type,
        uint_type),
      OGLPLUS_GL_STATIC_FUNC(DrawElementsInstancedBaseInstance)>
      DrawElementsInstancedBaseInstance;

    gl_api_function<
      void(enum_type, sizei_type, enum_type, const_void_ptr_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(DrawElementsInstanced)>
      DrawElementsInstanced;

    gl_api_function<
      void(enum_type, sizei_type, enum_type, const_void_ptr_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(DrawElementsBaseVertex)>
      DrawElementsBaseVertex;

    gl_api_function<
      void(
        enum_type,
        uint_type,
        uint_type,
        sizei_type,
        enum_type,
        const_void_ptr_type,
        int_type),
      OGLPLUS_GL_STATIC_FUNC(DrawRangeElementsBaseVertex)>
      DrawRangeElementsBaseVertex;

    gl_api_function<
      void(
        enum_type,
        sizei_type,
        enum_type,
        const_void_ptr_type,
        sizei_type,
        int_type),
      OGLPLUS_GL_STATIC_FUNC(DrawElementsInstancedBaseVertex)>
      DrawElementsInstancedBaseVertex;

    gl_api_function<
      void(
        enum_type,
        sizei_type,
        enum_type,
        const_void_ptr_type,
        sizei_type,
        int_type,
        uint_type),
      OGLPLUS_GL_STATIC_FUNC(DrawElementsInstancedBaseVertexBaseInstance)>
      DrawElementsInstancedBaseVertexBaseInstance;

    gl_api_function<
      void(enum_type, enum_type, const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(DrawElementsIndirect)>
      DrawElementsIndirect;

    gl_api_function<
      void(
        enum_type,
        const sizei_type*,
        enum_type,
        const const_void_ptr_type*,
        sizei_type),
      OGLPLUS_GL_STATIC_FUNC(MultiDrawElements)>
      MultiDrawElements;

    gl_api_function<
      void(enum_type, enum_type, const_void_ptr_type, sizei_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(MultiDrawElementsIndirect)>
      MultiDrawElementsIndirect;

    gl_api_function<
      void(
        enum_type,
        enum_type,
        const_void_ptr_type,
        intptr_type,
        sizei_type,
        sizei_type),
      OGLPLUS_GL_STATIC_FUNC(MultiDrawElementsIndirectCount)>
      MultiDrawElementsIndirectCount;

    gl_api_function<
      void(
        enum_type,
        const sizei_type*,
        enum_type,
        const const_void_ptr_type*,
        sizei_type,
        const int_type*),
      OGLPLUS_GL_STATIC_FUNC(MultiDrawElementsBaseVertex)>
      MultiDrawElementsBaseVertex;

    // draw transform feedback
    gl_api_function<
      void(enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(DrawTransformFeedback)>
      DrawTransformFeedback;

    gl_api_function<
      void(enum_type, uint_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(DrawTransformFeedbackInstanced)>
      DrawTransformFeedbackInstanced;

    gl_api_function<
      void(enum_type, uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(DrawTransformFeedbackStream)>
      DrawTransformFeedbackStream;

    gl_api_function<
      void(enum_type, uint_type, uint_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(DrawTransformFeedbackStreamInstanced)>
      DrawTransformFeedbackStreamInstanced;

    // compute
    gl_api_function<
      void(uint_type, uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(DispatchCompute)>
      DispatchCompute;

    gl_api_function<
      void(intptr_type),
      OGLPLUS_GL_STATIC_FUNC(DispatchComputeIndirect)>
      DispatchComputeIndirect;

    // framebufer reads/writes
    gl_api_function<
      void(enum_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(ClampColor)>
      ClampColor;

    gl_api_function<
      void(
        int_type,
        int_type,
        sizei_type,
        sizei_type,
        enum_type,
        enum_type,
        void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(ReadPixels)>
      ReadPixels;

    gl_api_function<
      void(
        int_type,
        int_type,
        sizei_type,
        sizei_type,
        enum_type,
        enum_type,
        sizei_type,
        void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(ReadnPixels)>
      ReadnPixels;

    // state queries
    gl_api_function<
      void(enum_type, bool_type*),
      OGLPLUS_GL_STATIC_FUNC(GetBooleanv)>
      GetBooleanv;

    gl_api_function<
      void(enum_type, uint_type, bool_type*),
      OGLPLUS_GL_STATIC_FUNC(GetBooleani_v)>
      GetBooleani_v;

    gl_api_function<
      void(enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetIntegerv)>
      GetIntegerv;

    gl_api_function<
      void(enum_type, uint_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetIntegeri_v)>
      GetIntegeri_v;

    gl_api_function<
      void(enum_type, int64_type*),
      OGLPLUS_GL_STATIC_FUNC(GetInteger64v)>
      GetInteger64v;

    gl_api_function<
      void(enum_type, uint_type, int64_type*),
      OGLPLUS_GL_STATIC_FUNC(GetInteger64i_v)>
      GetInteger64i_v;

    gl_api_function<
      void(enum_type, float_type*),
      OGLPLUS_GL_STATIC_FUNC(GetFloatv)>
      GetFloatv;

    gl_api_function<
      void(enum_type, uint_type, float_type*),
      OGLPLUS_GL_STATIC_FUNC(GetFloati_v)>
      GetFloati_v;

    gl_api_function<
      void(enum_type, double_type*),
      OGLPLUS_GL_STATIC_FUNC(GetDoublev)>
      GetDoublev;

    gl_api_function<
      void(enum_type, uint_type, double_type*),
      OGLPLUS_GL_STATIC_FUNC(GetDoublei_v)>
      GetDoublei_v;

    gl_api_function<
      void(enum_type, enum_type, enum_type, sizei_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetInternalformativ)>
      GetInternalformativ;

    gl_api_function<
      void(enum_type, enum_type, enum_type, sizei_type, int64_type*),
      OGLPLUS_GL_STATIC_FUNC(GetInternalformati64v)>
      GetInternalformati64v;

    gl_api_function<
      void(enum_type, void_ptr_type*),
      OGLPLUS_GL_STATIC_FUNC(GetPointerv)>
      GetPointerv;

    gl_api_function<
      const ubyte_type*(enum_type),
      OGLPLUS_GL_STATIC_FUNC(GetString)>
      GetString;

    gl_api_function<
      const ubyte_type*(enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(GetStringi)>
      GetStringi;

    gl_api_function<
      void(debug_callback_type*, const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(DebugMessageCallback)>
      DebugMessageCallback;

    gl_api_function<
      void(
        enum_type,
        enum_type,
        enum_type,
        sizei_type,
        const uint_type*,
        bool_type),
      OGLPLUS_GL_STATIC_FUNC(DebugMessageControl)>
      DebugMessageControl;

    gl_api_function<
      void(
        enum_type, enum_type, uint_type, enum_type, int_type, const char_type*),
      OGLPLUS_GL_STATIC_FUNC(DebugMessageInsert)>
      DebugMessageInsert;

    gl_api_function<
      void(enum_type, uint_type, sizei_type, const char_type*),
      OGLPLUS_GL_STATIC_FUNC(PushDebugGroup)>
      PushDebugGroup;

    gl_api_function<void(), OGLPLUS_GL_STATIC_FUNC(PopDebugGroup)>
      PopDebugGroup;

    gl_api_function<
      void(enum_type, uint_type, sizei_type, const char_type*),
      OGLPLUS_GL_STATIC_FUNC(ObjectLabel)>
      ObjectLabel;

    gl_api_function<
      void(const_void_ptr_type, sizei_type, const char_type*),
      OGLPLUS_GL_STATIC_FUNC(ObjectPtrLabel)>
      ObjectPtrLabel;

    gl_api_function<
      void(enum_type, uint_type, sizei_type, sizei_type*, char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetObjectLabel)>
      GetObjectLabel;

    gl_api_function<
      void(const_void_ptr_type, sizei_type, sizei_type*, char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetObjectPtrLabel)>
      GetObjectPtrLabel;

    gl_api_function<
      uint_type(
        uint_type,
        sizei_type,
        enum_type*,
        enum_type*,
        uint_type*,
        enum_type*,
        sizei_type*,
        char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetDebugMessageLog)>
      GetDebugMessageLog;

    // arb compatibility
    gl_api_function<void(enum_type), nullptr> Begin;
    gl_api_function<void(), nullptr> End;

    // vertex position
    gl_api_function<void(int_type, int_type), nullptr> Vertex2i;
    gl_api_function<void(int_type, int_type, int_type), nullptr> Vertex3i;
    gl_api_function<void(int_type, int_type, int_type, int_type), nullptr>
      Vertex4i;

    gl_api_function<void(float_type, float_type), nullptr> Vertex2f;
    gl_api_function<void(float_type, float_type, float_type), nullptr> Vertex3f;
    gl_api_function<
      void(float_type, float_type, float_type, float_type),
      nullptr>
      Vertex4f;

    // vertex color
    gl_api_function<void(int_type, int_type, int_type), nullptr> Color3i;
    gl_api_function<void(int_type, int_type, int_type, int_type), nullptr>
      Color4i;

    gl_api_function<void(float_type, float_type, float_type), nullptr> Color3f;
    gl_api_function<
      void(float_type, float_type, float_type, float_type),
      nullptr>
      Color4f;

    gl_api_function<void(int_type, int_type, int_type), nullptr>
      SecondaryColor3i;
    gl_api_function<void(int_type, int_type, int_type, int_type), nullptr>
      SecondaryColor4i;

    gl_api_function<void(float_type, float_type, float_type), nullptr>
      SecondaryColor3f;
    gl_api_function<
      void(float_type, float_type, float_type, float_type),
      nullptr>
      SecondaryColor4f;

    // vertex texture coord
    gl_api_function<void(int_type), nullptr> TexCoord1i;
    gl_api_function<void(int_type, int_type), nullptr> TexCoord2i;
    gl_api_function<void(int_type, int_type, int_type), nullptr> TexCoord3i;
    gl_api_function<void(int_type, int_type, int_type, int_type), nullptr>
      TexCoord4i;

    gl_api_function<void(float_type), nullptr> TexCoord1f;
    gl_api_function<void(float_type, float_type), nullptr> TexCoord2f;
    gl_api_function<void(float_type, float_type, float_type), nullptr>
      TexCoord3f;
    gl_api_function<
      void(float_type, float_type, float_type, float_type),
      nullptr>
      TexCoord4f;

    // vertex multi texture coord
    gl_api_function<void(enum_type, int_type), nullptr> MultiTexCoord1i;
    gl_api_function<void(enum_type, int_type, int_type), nullptr>
      MultiTexCoord2i;
    gl_api_function<void(enum_type, int_type, int_type, int_type), nullptr>
      MultiTexCoord3i;
    gl_api_function<
      void(enum_type, int_type, int_type, int_type, int_type),
      nullptr>
      MultiTexCoord4i;

    gl_api_function<void(enum_type, float_type), nullptr> MultiTexCoord1f;
    gl_api_function<void(enum_type, float_type, float_type), nullptr>
      MultiTexCoord2f;
    gl_api_function<
      void(enum_type, float_type, float_type, float_type),
      nullptr>
      MultiTexCoord3f;
    gl_api_function<
      void(enum_type, float_type, float_type, float_type, float_type),
      nullptr>
      MultiTexCoord4f;

    // matrix compatibility
    gl_api_function<void(enum_type), nullptr> MatrixMode;

    gl_api_function<void(void), nullptr> PushMatrix;
    gl_api_function<void(void), nullptr> PopMatrix;

    gl_api_function<void(enum_type), nullptr> MatrixPushEXT;
    gl_api_function<void(enum_type), nullptr> MatrixPopEXT;

    gl_api_function<void(), nullptr> LoadIdentity;
    gl_api_function<void(enum_type), nullptr> MatrixLoadIdentityEXT;

    gl_api_function<void(float_type, float_type, float_type), nullptr>
      Translatef;

    gl_api_function<void(double_type, double_type, double_type), nullptr>
      Translated;

    gl_api_function<
      void(enum_type, float_type, float_type, float_type),
      nullptr>
      MatrixTranslatefEXT;

    gl_api_function<
      void(enum_type, double_type, double_type, double_type),
      nullptr>
      MatrixTranslatedEXT;

    gl_api_function<
      void(float_type, float_type, float_type, float_type),
      nullptr>
      Rotatef;

    gl_api_function<
      void(double_type, double_type, double_type, double_type),
      nullptr>
      Rotated;

    gl_api_function<
      void(enum_type, float_type, float_type, float_type, float_type),
      nullptr>
      MatrixRotatefEXT;

    gl_api_function<
      void(enum_type, double_type, double_type, double_type, double_type),
      nullptr>
      MatrixRotatedEXT;

    gl_api_function<void(float_type, float_type, float_type), nullptr> Scalef;

    gl_api_function<void(double_type, double_type, double_type), nullptr>
      Scaled;

    gl_api_function<
      void(enum_type, float_type, float_type, float_type),
      nullptr>
      MatrixScalefEXT;

    gl_api_function<
      void(enum_type, double_type, double_type, double_type),
      nullptr>
      MatrixScaledEXT;

    gl_api_function<
      void(
        double_type,
        double_type,
        double_type,
        double_type,
        double_type,
        double_type),
      nullptr>
      Frustum;

    gl_api_function<
      void(
        double_type,
        double_type,
        double_type,
        double_type,
        double_type,
        double_type),
      nullptr>
      Ortho;

    gl_api_function<
      void(
        enum_type,
        double_type,
        double_type,
        double_type,
        double_type,
        double_type),
      nullptr>
      MatrixFrustumEXT;

    gl_api_function<
      void(
        enum_type,
        double_type,
        double_type,
        double_type,
        double_type,
        double_type),
      nullptr>
      MatrixOrthoEXT;

    gl_api_function<void(const float_type[16]), nullptr> LoadMatrixf;
    gl_api_function<void(const double_type[16]), nullptr> LoadMatrixd;

    gl_api_function<void(enum_type, const float_type[16]), nullptr>
      MatrixLoadfEXT;
    gl_api_function<void(enum_type, const double_type[16]), nullptr>
      MatrixLoaddEXT;

    gl_api_function<void(const float_type[16]), nullptr> MultMatrixf;
    gl_api_function<void(const double_type[16]), nullptr> MultMatrixd;

    gl_api_function<void(enum_type, const float_type[16]), nullptr>
      MatrixMultfEXT;
    gl_api_function<void(enum_type, const double_type[16]), nullptr>
      MatrixMultdEXT;

    gl_api_function<void(const float_type[16]), nullptr> LoadTransposeMatrixf;
    gl_api_function<void(const double_type[16]), nullptr> LoadTransposeMatrixd;

    gl_api_function<void(enum_type, const float_type[16]), nullptr>
      MatrixLoadTransposefEXT;
    gl_api_function<void(enum_type, const double_type[16]), nullptr>
      MatrixLoadTransposedEXT;

    gl_api_function<void(const float_type[16]), nullptr> MultTransposeMatrixf;
    gl_api_function<void(const double_type[16]), nullptr> MultTransposeMatrixd;

    gl_api_function<void(enum_type, const float_type[16]), nullptr>
      MatrixMultTransposefEXT;
    gl_api_function<void(enum_type, const double_type[16]), nullptr>
      MatrixMultTransposedEXT;

    // nv path rendering
    gl_api_function<
      void(enum_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(MatrixLoad3x2fNV)>
      MatrixLoad3x2fNV;

    gl_api_function<
      void(enum_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(MatrixLoad3x3fNV)>
      MatrixLoad3x3fNV;

    gl_api_function<
      void(enum_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(MatrixLoadTranspose3x3fNV)>
      MatrixLoadTranspose3x3fNV;

    gl_api_function<
      void(enum_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(MatrixMult3x2fNV)>
      MatrixMult3x2fNV;

    gl_api_function<
      void(enum_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(MatrixMult3x3fNV)>
      MatrixMult3x3fNV;

    gl_api_function<
      void(enum_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(MatrixMultTranspose3x3fNV)>
      MatrixMultTranspose3x3fNV;

    gl_api_function<uint_type(sizei_type), OGLPLUS_GL_STATIC_FUNC(GenPathsNV)>
      GenPathsNV;

    gl_api_function<
      void(uint_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(DeletePathsNV)>
      DeletePathsNV;

    gl_api_function<bool_type(uint_type), OGLPLUS_GL_STATIC_FUNC(IsPathNV)>
      IsPathNV;

    gl_api_function<
      void(uint_type, enum_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(PathParameterivNV)>
      PathParameterivNV;

    gl_api_function<
      void(uint_type, enum_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(PathParameteriNV)>
      PathParameteriNV;

    gl_api_function<
      void(uint_type, enum_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(PathParameterfvNV)>
      PathParameterfvNV;

    gl_api_function<
      void(uint_type, enum_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(PathParameterfNV)>
      PathParameterfNV;

    gl_api_function<
      void(
        uint_type,
        sizei_type,
        const ubyte_type*,
        sizei_type,
        enum_type,
        const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(PathCommandsNV)>
      PathCommandsNV;

    gl_api_function<
      void(
        uint_type,
        sizei_type,
        sizei_type,
        sizei_type,
        const ubyte_type*,
        sizei_type,
        enum_type,
        const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(PathSubCommandsNV)>
      PathSubCommandsNV;

    gl_api_function<
      void(uint_type, sizei_type, enum_type, const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(PathCoordsNV)>
      PathCoordsNV;

    gl_api_function<
      void(uint_type, sizei_type, sizei_type, enum_type, const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(PathSubCoordsNV)>
      PathSubCoordsNV;

    gl_api_function<
      void(uint_type, enum_type, sizei_type, const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(PathStringNV)>
      PathStringNV;

    gl_api_function<
      void(
        uint_type,
        enum_type,
        const_void_ptr_type,
        bitfield_type,
        sizei_type,
        enum_type,
        const_void_ptr_type,
        enum_type,
        uint_type,
        float_type),
      OGLPLUS_GL_STATIC_FUNC(PathGlyphsNV)>
      PathGlyphsNV;

    gl_api_function<
      void(
        uint_type,
        enum_type,
        const_void_ptr_type,
        bitfield_type,
        uint_type,
        sizei_type,
        enum_type,
        uint_type,
        float_type),
      OGLPLUS_GL_STATIC_FUNC(PathGlyphRangeNV)>
      PathGlyphRangeNV;

    gl_api_function<
      enum_type(
        uint_type,
        enum_type,
        const_void_ptr_type,
        bitfield_type,
        uint_type,
        sizei_type,
        uint_type,
        float_type),
      OGLPLUS_GL_STATIC_FUNC(PathGlyphIndexArrayNV)>
      PathGlyphIndexArrayNV;

    gl_api_function<
      enum_type(
        uint_type,
        enum_type,
        sizeiptr_type,
        const_void_ptr_type,
        sizei_type,
        uint_type,
        sizei_type,
        uint_type,
        float_type),
      OGLPLUS_GL_STATIC_FUNC(PathMemoryGlyphIndexArrayNV)>
      PathMemoryGlyphIndexArrayNV;

    gl_api_function<
      enum_type(
        enum_type,
        const_void_ptr_type,
        bitfield_type,
        uint_type,
        float_type,
        uint_type[2]),
      OGLPLUS_GL_STATIC_FUNC(PathGlyphIndexRangeNV)>
      PathGlyphIndexRangeNV;

    gl_api_function<
      void(uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(CopyPathNV)>
      CopyPathNV;

    gl_api_function<
      void(uint_type, uint_type, uint_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(InterpolatePathsNV)>
      InterpolatePathsNV;

    gl_api_function<
      void(uint_type, sizei_type, const uint_type[], const float_type[]),
      OGLPLUS_GL_STATIC_FUNC(WeightPathsNV)>
      WeightPathsNV;

    gl_api_function<
      void(uint_type, uint_type, enum_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(TransformPathNV)>
      TransformPathNV;

    gl_api_function<
      void(enum_type, int_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(PathStencilFuncNV)>
      PathStencilFuncNV;

    gl_api_function<
      void(float_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(PathStencilDepthOffsetNV)>
      PathStencilDepthOffsetNV;

    gl_api_function<
      void(uint_type, enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(StencilFillPathNV)>
      StencilFillPathNV;

    gl_api_function<
      void(uint_type, int_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(StencilStrokePathNV)>
      StencilStrokePathNV;

    gl_api_function<
      void(
        sizei_type,
        enum_type,
        const_void_ptr_type,
        uint_type,
        enum_type,
        uint_type,
        enum_type,
        const float_type*),
      OGLPLUS_GL_STATIC_FUNC(StencilFillPathInstancedNV)>
      StencilFillPathInstancedNV;

    gl_api_function<
      void(
        sizei_type,
        enum_type,
        const_void_ptr_type,
        uint_type,
        int_type,
        uint_type,
        enum_type,
        const float_type*),
      OGLPLUS_GL_STATIC_FUNC(StencilStrokePathInstancedNV)>
      StencilStrokePathInstancedNV;

    gl_api_function<
      void(enum_type),
      OGLPLUS_GL_STATIC_FUNC(PathCoverDepthFuncNV)>
      PathCoverDepthFuncNV;

    gl_api_function<
      void(enum_type, enum_type, enum_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(PathColorGenNV)>
      PathColorGenNV;

    gl_api_function<
      void(enum_type, enum_type, int_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(PathTexGenNV)>
      PathTexGenNV;

    gl_api_function<void(enum_type), OGLPLUS_GL_STATIC_FUNC(PathFogGenNV)>
      PathFogGenNV;

    gl_api_function<
      void(uint_type, int_type, enum_type, int_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramPathFragmentInputGenNV)>
      ProgramPathFragmentInputGenNV;

    gl_api_function<
      void(uint_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(CoverFillPathNV)>
      CoverFillPathNV;

    gl_api_function<
      void(uint_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(CoverStrokePathNV)>
      CoverStrokePathNV;

    gl_api_function<
      void(
        sizei_type,
        enum_type,
        const_void_ptr_type,
        uint_type,
        enum_type,
        enum_type,
        const float_type*),
      OGLPLUS_GL_STATIC_FUNC(CoverFillPathInstancedNV)>
      CoverFillPathInstancedNV;

    gl_api_function<
      void(
        sizei_type,
        enum_type,
        const_void_ptr_type,
        uint_type,
        enum_type,
        enum_type,
        const float_type*),
      OGLPLUS_GL_STATIC_FUNC(CoverStrokePathInstancedNV)>
      CoverStrokePathInstancedNV;

    gl_api_function<
      void(uint_type, enum_type, uint_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(StencilThenCoverFillPathNV)>
      StencilThenCoverFillPathNV;

    gl_api_function<
      void(uint_type, int_type, uint_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(StencilThenCoverStrokePathNV)>
      StencilThenCoverStrokePathNV;

    gl_api_function<
      void(
        sizei_type,
        enum_type,
        const_void_ptr_type,
        uint_type,
        enum_type,
        uint_type,
        enum_type,
        enum_type,
        const float_type*),
      OGLPLUS_GL_STATIC_FUNC(StencilThenCoverFillPathInstancedNV)>
      StencilThenCoverFillPathInstancedNV;

    gl_api_function<
      void(
        sizei_type,
        enum_type,
        const_void_ptr_type,
        uint_type,
        int_type,
        uint_type,
        enum_type,
        enum_type,
        const float_type*),
      OGLPLUS_GL_STATIC_FUNC(StencilThenCoverStrokePathInstancedNV)>
      StencilThenCoverStrokePathInstancedNV;

    gl_api_function<
      void(uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetPathParameterivNV)>
      GetPathParameterivNV;

    gl_api_function<
      void(uint_type, enum_type, float_type*),
      OGLPLUS_GL_STATIC_FUNC(GetPathParameterfvNV)>
      GetPathParameterfvNV;

    gl_api_function<
      void(uint_type, ubyte_type*),
      OGLPLUS_GL_STATIC_FUNC(GetPathCommandsNV)>
      GetPathCommandsNV;

    gl_api_function<
      void(uint_type, float_type*),
      OGLPLUS_GL_STATIC_FUNC(GetPathCoordsNV)>
      GetPathCoordsNV;

    gl_api_function<
      void(uint_type, float_type*),
      OGLPLUS_GL_STATIC_FUNC(GetPathDashArrayNV)>
      GetPathDashArrayNV;

    gl_api_function<
      void(
        bitfield_type,
        sizei_type,
        enum_type,
        const_void_ptr_type,
        uint_type,
        sizei_type,
        float_type*),
      OGLPLUS_GL_STATIC_FUNC(GetPathMetricsNV)>
      GetPathMetricsNV;

    gl_api_function<
      void(bitfield_type, uint_type, sizei_type, sizei_type, float_type*),
      OGLPLUS_GL_STATIC_FUNC(GetPathMetricRangeNV)>
      GetPathMetricRangeNV;

    gl_api_function<
      void(
        enum_type,
        sizei_type,
        enum_type,
        const_void_ptr_type,
        uint_type,
        float_type,
        float_type,
        enum_type,
        float_type*),
      OGLPLUS_GL_STATIC_FUNC(GetPathSpacingNV)>
      GetPathSpacingNV;

    gl_api_function<
      void(enum_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetPathColorGenivNV)>
      GetPathColorGenivNV;

    gl_api_function<
      void(enum_type, enum_type, float_type*),
      OGLPLUS_GL_STATIC_FUNC(GetPathColorGenfvNV)>
      GetPathColorGenfvNV;

    gl_api_function<
      void(enum_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetPathTexGenivNV)>
      GetPathTexGenivNV;

    gl_api_function<
      void(enum_type, enum_type, float_type*),
      OGLPLUS_GL_STATIC_FUNC(GetPathTexGenfvNV)>
      GetPathTexGenfvNV;

    gl_api_function<
      float_type(uint_type, sizei_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(GetPathLengthNV)>
      GetPathLengthNV;

    gl_api_function<
      bool_type(uint_type, uint_type, float_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(IsPointInFillPathNV)>
      IsPointInFillPathNV;

    gl_api_function<
      bool_type(uint_type, float_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(IsPointInStrokePathNV)>
      IsPointInStrokePathNV;

    gl_api_function<
      bool_type(
        uint_type,
        sizei_type,
        sizei_type,
        float_type,
        float_type*,
        float_type*,
        float_type*,
        float_type*),
      OGLPLUS_GL_STATIC_FUNC(PointAlongPathNV)>
      PointAlongPathNV;

    // hints
    gl_api_function<
      void(uint_type),
      OGLPLUS_GL_STATIC_FUNC(MaxShaderCompilerThreadsARB)>
      MaxShaderCompilerThreadsARB;

    gl_api_function<void(enum_type, enum_type), OGLPLUS_GL_STATIC_FUNC(Hint)>
      Hint;

    // flush/finish
    gl_api_function<void(), OGLPLUS_GL_STATIC_FUNC(Flush)> Flush;
    gl_api_function<void(), OGLPLUS_GL_STATIC_FUNC(Finish)> Finish;

    constexpr basic_gl_c_api(api_traits& traits)
      : GetError("GetError", traits, *this)
      , GetGraphicsResetStatus("GetGraphicsResetStatus", traits, *this)
      , Enable("Enable", traits, *this)
      , Enablei("Enablei", traits, *this)
      , Disable("Disable", traits, *this)
      , Disablei("Disablei", traits, *this)
      , IsEnabled("IsEnabled", traits, *this)
      , IsEnabledi("IsEnabledi", traits, *this)
      , MemoryBarrier("MemoryBarrier", traits, *this)
      , MemoryBarrierByRegion("MemoryBarrierByRegion", traits, *this)
      , FenceSync("FenceSync", traits, *this)
      , DeleteSync("DeleteSync", traits, *this)
      , IsSync("IsSync", traits, *this)
      , GetSynciv("GetSynciv", traits, *this)
      , WaitSync("WaitSync", traits, *this)
      , ClientWaitSync("ClientWaitSync", traits, *this)
      , GenVertexArrays("GenVertexArrays", traits, *this)
      , CreateVertexArrays("CreateVertexArrays", traits, *this)
      , DeleteVertexArrays("DeleteVertexArrays", traits, *this)
      , IsVertexArray("IsVertexArray", traits, *this)
      , BindVertexArray("BindVertexArray", traits, *this)
      , VertexArrayElementBuffer("VertexArrayElementBuffer", traits, *this)
      , BindVertexBuffer("BindVertexBuffer", traits, *this)
      , VertexArrayVertexBuffer("VertexArrayVertexBuffer", traits, *this)
      , BindVertexBuffers("BindVertexBuffers", traits, *this)
      , VertexArrayVertexBuffers("VertexArrayVertexBuffers", traits, *this)
      , VertexAttribBinding("VertexAttribBinding", traits, *this)
      , VertexArrayAttribBinding("VertexArrayAttribBinding", traits, *this)
      , EnableVertexAttribArray("EnableVertexAttribArray", traits, *this)
      , EnableVertexArrayAttrib("EnableVertexArrayAttrib", traits, *this)
      , DisableVertexAttribArray("DisableVertexAttribArray", traits, *this)
      , DisableVertexArrayAttrib("DisableVertexArrayAttrib", traits, *this)
      , VertexBindingDivisor("VertexBindingDivisor", traits, *this)
      , VertexArrayBindingDivisor("VertexArrayBindingDivisor", traits, *this)
      , VertexAttribDivisor("VertexAttribDivisor", traits, *this)
      , GenBuffers("GenBuffers", traits, *this)
      , CreateBuffers("CreateBuffers", traits, *this)
      , DeleteBuffers("DeleteBuffers", traits, *this)
      , IsBuffer("IsBuffer", traits, *this)
      , BindBuffer("BindBuffer", traits, *this)
      , BindBufferBase("BindBufferBase", traits, *this)
      , BindBufferRange("BindBufferRange", traits, *this)
      , BufferStorage("BufferStorage", traits, *this)
      , NamedBufferStorage("NamedBufferStorage", traits, *this)
      , BufferData("BufferData", traits, *this)
      , NamedBufferData("NamedBufferData", traits, *this)
      , BufferSubData("BufferSubData", traits, *this)
      , NamedBufferSubData("NamedBufferSubData", traits, *this)
      , ClearBufferData("ClearBufferData", traits, *this)
      , ClearNamedBufferData("ClearNamedBufferData", traits, *this)
      , ClearBufferSubData("ClearBufferSubData", traits, *this)
      , ClearNamedBufferSubData("ClearNamedBufferSubData", traits, *this)
      , MapBuffer("MapBuffer", traits, *this)
      , MapNamedBuffer("MapNamedBuffer", traits, *this)
      , MapBufferRange("MapBufferRange", traits, *this)
      , MapNamedBufferRange("MapNamedBufferRange", traits, *this)
      , FlushMappedBufferRange("FlushMappedBufferRange", traits, *this)
      , FlushMappedNamedBufferRange(
          "FlushMappedNamedBufferRange", traits, *this)
      , UnmapBuffer("UnmapBuffer", traits, *this)
      , UnmapNamedBuffer("UnmapNamedBuffer", traits, *this)
      , InvalidateBufferData("InvalidateBufferData", traits, *this)
      , InvalidateBufferSubData("InvalidateBufferSubData", traits, *this)
      , CopyBufferSubData("CopyBufferSubData", traits, *this)
      , CopyNamedBufferSubData("CopyNamedBufferSubData", traits, *this)
      , GetBufferParameteriv("GetBufferParameteriv", traits, *this)
      , GetBufferParameteri64v("GetBufferParameteri64v", traits, *this)
      , GetNamedBufferParameteriv("GetNamedBufferParameteriv", traits, *this)
      , GetNamedBufferParameteri64v(
          "GetNamedBufferParameteri64v", traits, *this)
      , GetBufferSubData("GetBufferSubData", traits, *this)
      , GetNamedBufferSubData("GetNamedBufferSubData", traits, *this)
      , GenTextures("GenTextures", traits, *this)
      , CreateTextures("CreateTextures", traits, *this)
      , DeleteTextures("DeleteTextures", traits, *this)
      , IsTexture("IsTexture", traits, *this)
      , ActiveTexture("ActiveTexture", traits, *this)
      , BindTexture("BindTexture", traits, *this)
      , BindTextures("BindTextures", traits, *this)
      , BindTextureUnit("BindTextureUnit", traits, *this)
      , BindImageTexture("BindImageTexture", traits, *this)
      , BindImageTextures("BindImageTextures", traits, *this)
      , TexStorage3D("TexStorage3D", traits, *this)
      , TexStorage2D("TexStorage2D", traits, *this)
      , TexStorage1D("TexStorage1D", traits, *this)
      , TexStorage3DMultisample("TexStorage3DMultisample", traits, *this)
      , TexStorage2DMultisample("TexStorage2DMultisample", traits, *this)
      , TexImage3D("TexImage3D", traits, *this)
      , TexImage2D("TexImage2D", traits, *this)
      , TexImage1D("TexImage1D", traits, *this)
      , CopyTexImage2D("CopyTexImage2D", traits, *this)
      , CopyTexImage1D("CopyTexImage1D", traits, *this)
      , TexSubImage3D("TexSubImage3D", traits, *this)
      , TexSubImage2D("TexSubImage2D", traits, *this)
      , TexSubImage1D("TexSubImage1D", traits, *this)
      , CopyTexSubImage3D("CopyTexSubImage3D", traits, *this)
      , CopyTexSubImage2D("CopyTexSubImage2D", traits, *this)
      , CopyTexSubImage1D("CopyTexSubImage1D", traits, *this)
      , TextureStorage3D("TextureStorage3D", traits, *this)
      , TextureStorage2D("TextureStorage2D", traits, *this)
      , TextureStorage1D("TextureStorage1D", traits, *this)
      , TextureStorage3DMultisample(
          "TextureStorage3DMultisample", traits, *this)
      , TextureStorage2DMultisample(
          "TextureStorage2DMultisample", traits, *this)
      , TextureSubImage3D("TextureSubImage3D", traits, *this)
      , TextureSubImage2D("TextureSubImage2D", traits, *this)
      , TextureSubImage1D("TextureSubImage1D", traits, *this)
      , CopyTextureSubImage3D("CopyTextureSubImage3D", traits, *this)
      , CopyTextureSubImage2D("CopyTextureSubImage2D", traits, *this)
      , CopyTextureSubImage1D("CopyTextureSubImage1D", traits, *this)
      , CompressedTexImage3D("CompressedTexImage3D", traits, *this)
      , CompressedTexImage2D("CompressedTexImage2D", traits, *this)
      , CompressedTexImage1D("CompressedTexImage1D", traits, *this)
      , CompressedTexSubImage3D("CompressedTexSubImage3D", traits, *this)
      , CompressedTexSubImage2D("CompressedTexSubImage2D", traits, *this)
      , CompressedTexSubImage1D("CompressedTexSubImage1D", traits, *this)
      , CompressedTextureSubImage3D(
          "CompressedTextureSubImage3D", traits, *this)
      , CompressedTextureSubImage2D(
          "CompressedTextureSubImage2D", traits, *this)
      , CompressedTextureSubImage1D(
          "CompressedTextureSubImage1D", traits, *this)
      , TexImage3DMultisample("TexImage3DMultisample", traits, *this)
      , TexImage2DMultisample("TexImage2DMultisample", traits, *this)
      , TexBuffer("TexBuffer", traits, *this)
      , TexBufferRange("TexBufferRange", traits, *this)
      , TextureBuffer("TextureBuffer", traits, *this)
      , TextureBufferRange("TextureBufferRange", traits, *this)
      , TexParameterf("TexParameterf", traits, *this)
      , TexParameteri("TexParameteri", traits, *this)
      , TexParameterfv("TexParameterfv", traits, *this)
      , TexParameteriv("TexParameteriv", traits, *this)
      , TexParameterIiv("TexParameterIiv", traits, *this)
      , TexParameterIuiv("TexParameterIuiv", traits, *this)
      , TextureParameterf("TextureParameterf", traits, *this)
      , TextureParameteri("TextureParameteri", traits, *this)
      , TextureParameterfv("TextureParameterfv", traits, *this)
      , TextureParameteriv("TextureParameteriv", traits, *this)
      , TextureParameterIiv("TextureParameterIiv", traits, *this)
      , TextureParameterIuiv("TextureParameterIuiv", traits, *this)
      , GetTexParameterfv("GetTexParameterfv", traits, *this)
      , GetTexParameteriv("GetTexParameteriv", traits, *this)
      , GetTexParameterIiv("GetTexParameterIiv", traits, *this)
      , GetTexParameterIuiv("GetTexParameterIuiv", traits, *this)
      , GetTexLevelParameterfv("GetTexLevelParameterfv", traits, *this)
      , GetTexLevelParameteriv("GetTexLevelParameteriv", traits, *this)
      , GetTexImage("GetTexImage", traits, *this)
      , GetnTexImage("GetnTexImage", traits, *this)
      , GetCompressedTexImage("GetCompressedTexImage", traits, *this)
      , GetnCompressedTexImage("GetnCompressedTexImage", traits, *this)
      , GetTextureParameterfv("GetTextureParameterfv", traits, *this)
      , GetTextureParameteriv("GetTextureParameteriv", traits, *this)
      , GetTextureParameterIiv("GetTextureParameterIiv", traits, *this)
      , GetTextureParameterIuiv("GetTextureParameterIuiv", traits, *this)
      , GetTextureLevelParameterfv("GetTextureLevelParameterfv", traits, *this)
      , GetTextureLevelParameteriv("GetTextureLevelParameteriv", traits, *this)
      , GetTextureImage("GetTextureImage", traits, *this)
      , GetTextureSubImage("GetTextureSubImage", traits, *this)
      , GetCompressedTextureImage("GetCompressedTextureImage", traits, *this)
      , GetCompressedTextureSubImage(
          "GetCompressedTextureSubImage", traits, *this)
      , GenerateMipmap("GenerateMipmap", traits, *this)
      , GenerateTextureMipmap("GenerateTextureMipmap", traits, *this)
      , TextureView("TextureView", traits, *this)
      , InvalidateTexSubImage("InvalidateTexSubImage", traits, *this)
      , InvalidateTexImage("InvalidateTexImage", traits, *this)
      , ClearTexSubImage("ClearTexSubImage", traits, *this)
      , ClearTexImage("ClearTexImage", traits, *this)
      , TextureBarrier("TextureBarrier", traits, *this)
      , GenSamplers("GenSamplers", traits, *this)
      , CreateSamplers("CreateSamplers", traits, *this)
      , DeleteSamplers("DeleteSamplers", traits, *this)
      , IsSampler("IsSampler", traits, *this)
      , BindSampler("BindSampler", traits, *this)
      , BindSamplers("BindSamplers", traits, *this)
      , SamplerParameterf("SamplerParameterf", traits, *this)
      , SamplerParameteri("SamplerParameteri", traits, *this)
      , SamplerParameterfv("SamplerParameterfv", traits, *this)
      , SamplerParameteriv("SamplerParameteriv", traits, *this)
      , SamplerParameterIiv("SamplerParameterIiv", traits, *this)
      , SamplerParameterIuiv("SamplerParameterIuiv", traits, *this)
      , GetSamplerParameterfv("GetSamplerParameterfv", traits, *this)
      , GetSamplerParameteriv("GetSamplerParameteriv", traits, *this)
      , GetSamplerParameterIiv("GetSamplerParameterIiv", traits, *this)
      , GetSamplerParameterIuiv("GetSamplerParameterIuiv", traits, *this)
      , GenRenderbuffers("GenRenderbuffers", traits, *this)
      , CreateRenderbuffers("CreateRenderbuffers", traits, *this)
      , DeleteRenderbuffers("DeleteRenderbuffers", traits, *this)
      , IsRenderbuffer("IsRenderbuffer", traits, *this)
      , BindRenderbuffer("BindRenderbuffer", traits, *this)
      , RenderbufferStorage("RenderbufferStorage", traits, *this)
      , NamedRenderbufferStorage("NamedRenderbufferStorage", traits, *this)
      , RenderbufferStorageMultisample(
          "RenderbufferStorageMultisample", traits, *this)
      , NamedRenderbufferStorageMultisample(
          "NamedRenderbufferStorageMultisample", traits, *this)
      , GetRenderbufferParameteriv("GetRenderbufferParameteriv", traits, *this)
      , GetNamedRenderbufferParameteriv(
          "GetNamedRenderbufferParameteriv", traits, *this)
      , GenFramebuffers("GenFramebuffers", traits, *this)
      , CreateFramebuffers("CreateFramebuffers", traits, *this)
      , DeleteFramebuffers("DeleteFramebuffers", traits, *this)
      , IsFramebuffer("IsFramebuffer", traits, *this)
      , BindFramebuffer("BindFramebuffer", traits, *this)
      , DrawBuffer("DrawBuffer", traits, *this)
      , NamedFramebufferDrawBuffer("NamedFramebufferDrawBuffer", traits, *this)
      , DrawBuffers("DrawBuffers", traits, *this)
      , NamedFramebufferDrawBuffers(
          "NamedFramebufferDrawBuffers", traits, *this)
      , ClearBufferfv("ClearBufferfv", traits, *this)
      , ClearBufferiv("ClearBufferiv", traits, *this)
      , ClearBufferuiv("ClearBufferuiv", traits, *this)
      , ClearBufferfi("ClearBufferfi", traits, *this)
      , ClearNamedFramebufferfv("ClearNamedFramebufferfv", traits, *this)
      , ClearNamedFramebufferiv("ClearNamedFramebufferiv", traits, *this)
      , ClearNamedFramebufferuiv("ClearNamedFramebufferuiv", traits, *this)
      , ClearNamedFramebufferfi("ClearNamedFramebufferfi", traits, *this)
      , InvalidateFramebuffer("InvalidateFramebuffer", traits, *this)
      , InvalidateSubFramebuffer("InvalidateSubFramebuffer", traits, *this)
      , InvalidateNamedFramebufferData(
          "InvalidateNamedFramebufferData", traits, *this)
      , InvalidateNamedFramebufferSubData(
          "InvalidateNamedFramebufferSubData", traits, *this)
      , FramebufferParameteri("FramebufferParameteri", traits, *this)
      , NamedFramebufferParameteri("NamedFramebufferParameteri", traits, *this)
      , GetFramebufferParameteriv("GetFramebufferParameteriv", traits, *this)
      , GetNamedFramebufferParameteriv(
          "GetNamedFramebufferParameteriv", traits, *this)
      , GetFramebufferAttachmentParameteriv(
          "GetFramebufferAttachmentParameteriv", traits, *this)
      , GetNamedFramebufferAttachmentParameteriv(
          "GetNamedFramebufferAttachmentParameteriv", traits, *this)
      , FramebufferRenderbuffer("FramebufferRenderbuffer", traits, *this)
      , NamedFramebufferRenderbuffer(
          "NamedFramebufferRenderbuffer", traits, *this)
      , FramebufferTexture("FramebufferTexture", traits, *this)
      , NamedFramebufferTexture("NamedFramebufferTexture", traits, *this)
      , FramebufferTexture1D("FramebufferTexture1D", traits, *this)
      , FramebufferTexture2D("FramebufferTexture2D", traits, *this)
      , FramebufferTexture3D("FramebufferTexture3D", traits, *this)
      , FramebufferTextureLayer("FramebufferTextureLayer", traits, *this)
      , NamedFramebufferTextureLayer(
          "NamedFramebufferTextureLayer", traits, *this)
      , CheckFramebufferStatus("CheckFramebufferStatus", traits, *this)
      , CheckNamedFramebufferStatus(
          "CheckNamedFramebufferStatus", traits, *this)
      , ReadBuffer("ReadBuffer", traits, *this)
      , NamedFramebufferReadBuffer("NamedFramebufferReadBuffer", traits, *this)
      , BlitFramebuffer("BlitFramebuffer", traits, *this)
      , BlitNamedFramebuffer("BlitNamedFramebuffer", traits, *this)
      , CopyImageSubData("CopyImageSubData", traits, *this)
      , GenTransformFeedbacks("GenTransformFeedbacks", traits, *this)
      , CreateTransformFeedbacks("CreateTransformFeedbacks", traits, *this)
      , DeleteTransformFeedbacks("DeleteTransformFeedbacks", traits, *this)
      , IsTransformFeedback("IsTransformFeedback", traits, *this)
      , BindTransformFeedback("BindTransformFeedback", traits, *this)
      , BeginTransformFeedback("BeginTransformFeedback", traits, *this)
      , PauseTransformFeedback("PauseTransformFeedback", traits, *this)
      , ResumeTransformFeedback("ResumeTransformFeedback", traits, *this)
      , EndTransformFeedback("EndTransformFeedback", traits, *this)
      , TransformFeedbackBufferBase(
          "TransformFeedbackBufferBase", traits, *this)
      , TransformFeedbackBufferRange(
          "TransformFeedbackBufferRange", traits, *this)
      , GetTransformFeedbackiv("GetTransformFeedbackiv", traits, *this)
      , GetTransformFeedbacki_v("GetTransformFeedbacki_v", traits, *this)
      , GetTransformFeedbacki64_v("GetTransformFeedbacki64_v", traits, *this)
      , GenQueries("GenQueries", traits, *this)
      , CreateQueries("CreateQueries", traits, *this)
      , DeleteQueries("DeleteQueries", traits, *this)
      , IsQuery("IsQuery", traits, *this)
      , GetQueryiv("GetQueryiv", traits, *this)
      , GetQueryIndexediv("GetQueryIndexediv", traits, *this)
      , GetQueryObjectiv("GetQueryObjectiv", traits, *this)
      , GetQueryObjectuiv("GetQueryObjectuiv", traits, *this)
      , GetQueryObjecti64v("GetQueryObjecti64v", traits, *this)
      , GetQueryObjectui64v("GetQueryObjectui64v", traits, *this)
      , GetQueryBufferObjectiv("GetQueryBufferObjectiv", traits, *this)
      , GetQueryBufferObjectuiv("GetQueryBufferObjectuiv", traits, *this)
      , GetQueryBufferObjecti64v("GetQueryBufferObjecti64v", traits, *this)
      , GetQueryBufferObjectui64v("GetQueryBufferObjectui64v", traits, *this)
      , BeginQuery("BeginQuery", traits, *this)
      , BeginQueryIndexed("BeginQueryIndexed", traits, *this)
      , EndQuery("EndQuery", traits, *this)
      , EndQueryIndexed("EndQueryIndexed", traits, *this)
      , QueryCounter("QueryCounter", traits, *this)
      , BeginConditionalRender("BeginConditionalRender", traits, *this)
      , EndConditionalRender("EndConditionalRender", traits, *this)
      , GenProgramPipelines("GenProgramPipelines", traits, *this)
      , CreateProgramPipelines("CreateProgramPipelines", traits, *this)
      , DeleteProgramPipelines("DeleteProgramPipelines", traits, *this)
      , IsProgramPipeline("IsProgramPipeline", traits, *this)
      , BindProgramPipeline("BindProgramPipeline", traits, *this)
      , ValidateProgramPipeline("ValidateProgramPipeline", traits, *this)
      , UseProgramStages("UseProgramStages", traits, *this)
      , GetProgramStageiv("GetProgramStageiv", traits, *this)
      , GetProgramPipelineiv("GetProgramPipelineiv", traits, *this)
      , GetProgramPipelineInfoLog("GetProgramPipelineInfoLog", traits, *this)
      , ActiveShaderProgram("ActiveShaderProgram", traits, *this)
      , CreateShader("CreateShader", traits, *this)
      , DeleteShader("DeleteShader", traits, *this)
      , IsShader("IsShader", traits, *this)
      , ShaderSource("ShaderSource", traits, *this)
      , CompileShader("CompileShader", traits, *this)
      , ShaderBinary("ShaderBinary", traits, *this)
      , SpecializeShader("SpecializeShader", traits, *this)
      , GetShaderiv("GetShaderiv", traits, *this)
      , GetShaderInfoLog("GetShaderInfoLog", traits, *this)
      , GetShaderSource("GetShaderSource", traits, *this)
      , GetShaderPrecisionFormat("GetShaderPrecisionFormat", traits, *this)
      , ReleaseShaderCompiler("ReleaseShaderCompiler", traits, *this)
      , CreateProgram("CreateProgram", traits, *this)
      , CreateShaderProgramv("CreateShaderProgramv", traits, *this)
      , DeleteProgram("DeleteProgram", traits, *this)
      , IsProgram("IsProgram", traits, *this)
      , AttachShader("AttachShader", traits, *this)
      , DetachShader("DetachShader", traits, *this)
      , GetAttachedShaders("GetAttachedShaders", traits, *this)
      , ValidateProgram("ValidateProgram", traits, *this)
      , LinkProgram("LinkProgram", traits, *this)
      , UseProgram("UseProgram", traits, *this)
      , ProgramBinary("ProgramBinary", traits, *this)
      , GetProgramBinary("GetProgramBinary", traits, *this)
      , GetProgramiv("GetProgramiv", traits, *this)
      , GetProgramInfoLog("GetProgramInfoLog", traits, *this)
      , GetProgramInterfaceiv("GetProgramInterfaceiv", traits, *this)
      , GetProgramResourceIndex("GetProgramResourceIndex", traits, *this)
      , GetProgramResourceName("GetProgramResourceName", traits, *this)
      , GetProgramResourceLocation("GetProgramResourceLocation", traits, *this)
      , GetProgramResourceLocationIndex(
          "GetProgramResourceLocationIndex", traits, *this)
      , GetProgramResourceiv("GetProgramResourceiv", traits, *this)
      , GetProgramResourcefvNV("GetProgramResourcefvNV", traits, *this)
      , BindAttribLocation("BindAttribLocation", traits, *this)
      , GetAttribLocation("GetAttribLocation", traits, *this)
      , GetActiveAttrib("GetActiveAttrib", traits, *this)
      , GetUniformLocation("GetUniformLocation", traits, *this)
      , GetActiveUniformName("GetActiveUniformName", traits, *this)
      , GetSubroutineIndex("GetSubroutineIndex", traits, *this)
      , GetActiveSubroutineName("GetActiveSubroutineName", traits, *this)
      , GetActiveSubroutineUniformName(
          "GetActiveSubroutineUniformName", traits, *this)
      , GetSubroutineUniformLocation(
          "GetSubroutineUniformLocation", traits, *this)
      , GetActiveSubroutineUniformiv(
          "GetActiveSubroutineUniformiv", traits, *this)
      , TransformFeedbackVaryings("TransformFeedbackVaryings", traits, *this)
      , GetTransformFeedbackVarying(
          "GetTransformFeedbackVarying", traits, *this)
      , BindFragDataLocation("BindFragDataLocation", traits, *this)
      , BindFragDataLocationIndexed(
          "BindFragDataLocationIndexed", traits, *this)
      , GetFragDataLocation("GetFragDataLocation", traits, *this)
      , GetFragDataIndex("GetFragDataIndex", traits, *this)
      , UniformSubroutinesuiv("UniformSubroutinesuiv", traits, *this)
      , GetUniformSubroutineuiv("GetUniformSubroutineuiv", traits, *this)
      , Uniform1i("Uniform1i", traits, *this)
      , Uniform2i("Uniform2i", traits, *this)
      , Uniform3i("Uniform3i", traits, *this)
      , Uniform4i("Uniform4i", traits, *this)
      , Uniform1iv("Uniform1iv", traits, *this)
      , Uniform2iv("Uniform2iv", traits, *this)
      , Uniform3iv("Uniform3iv", traits, *this)
      , Uniform4iv("Uniform4iv", traits, *this)
      , Uniform1ui("Uniform1ui", traits, *this)
      , Uniform2ui("Uniform2ui", traits, *this)
      , Uniform3ui("Uniform3ui", traits, *this)
      , Uniform4ui("Uniform4ui", traits, *this)
      , Uniform1uiv("Uniform1uiv", traits, *this)
      , Uniform2uiv("Uniform2uiv", traits, *this)
      , Uniform3uiv("Uniform3uiv", traits, *this)
      , Uniform4uiv("Uniform4uiv", traits, *this)
      , Uniform1f("Uniform1f", traits, *this)
      , Uniform2f("Uniform2f", traits, *this)
      , Uniform3f("Uniform3f", traits, *this)
      , Uniform4f("Uniform4f", traits, *this)
      , Uniform1fv("Uniform1fv", traits, *this)
      , Uniform2fv("Uniform2fv", traits, *this)
      , Uniform3fv("Uniform3fv", traits, *this)
      , Uniform4fv("Uniform4fv", traits, *this)
      , UniformMatrix2fv("UniformMatrix2fv", traits, *this)
      , UniformMatrix3fv("UniformMatrix3fv", traits, *this)
      , UniformMatrix4fv("UniformMatrix4fv", traits, *this)
      , UniformMatrix2x3fv("UniformMatrix2x3fv", traits, *this)
      , UniformMatrix3x2fv("UniformMatrix3x2fv", traits, *this)
      , UniformMatrix2x4fv("UniformMatrix2x4fv", traits, *this)
      , UniformMatrix4x2fv("UniformMatrix4x2fv", traits, *this)
      , UniformMatrix3x4fv("UniformMatrix3x4fv", traits, *this)
      , UniformMatrix4x3fv("UniformMatrix4x3fv", traits, *this)
      , GetUniformfv("GetUniformfv", traits, *this)
      , GetUniformdv("GetUniformdv", traits, *this)
      , GetUniformiv("GetUniformiv", traits, *this)
      , GetUniformuiv("GetUniformuiv", traits, *this)
      , GetnUniformfv("GetnUniformfv", traits, *this)
      , GetnUniformdv("GetnUniformdv", traits, *this)
      , GetnUniformiv("GetnUniformiv", traits, *this)
      , GetnUniformuiv("GetnUniformuiv", traits, *this)
      , ProgramUniform1i("ProgramUniform1i", traits, *this)
      , ProgramUniform2i("ProgramUniform2i", traits, *this)
      , ProgramUniform3i("ProgramUniform3i", traits, *this)
      , ProgramUniform4i("ProgramUniform4i", traits, *this)
      , ProgramUniform1iv("ProgramUniform1iv", traits, *this)
      , ProgramUniform2iv("ProgramUniform2iv", traits, *this)
      , ProgramUniform3iv("ProgramUniform3iv", traits, *this)
      , ProgramUniform4iv("ProgramUniform4iv", traits, *this)
      , ProgramUniform1ui("ProgramUniform1ui", traits, *this)
      , ProgramUniform2ui("ProgramUniform2ui", traits, *this)
      , ProgramUniform3ui("ProgramUniform3ui", traits, *this)
      , ProgramUniform4ui("ProgramUniform4ui", traits, *this)
      , ProgramUniform1uiv("ProgramUniform1uiv", traits, *this)
      , ProgramUniform2uiv("ProgramUniform2uiv", traits, *this)
      , ProgramUniform3uiv("ProgramUniform3uiv", traits, *this)
      , ProgramUniform4uiv("ProgramUniform4uiv", traits, *this)
      , ProgramUniform1f("ProgramUniform1f", traits, *this)
      , ProgramUniform2f("ProgramUniform2f", traits, *this)
      , ProgramUniform3f("ProgramUniform3f", traits, *this)
      , ProgramUniform4f("ProgramUniform4f", traits, *this)
      , ProgramUniform1fv("ProgramUniform1fv", traits, *this)
      , ProgramUniform2fv("ProgramUniform2fv", traits, *this)
      , ProgramUniform3fv("ProgramUniform3fv", traits, *this)
      , ProgramUniform4fv("ProgramUniform4fv", traits, *this)
      , ProgramUniformMatrix2fv("ProgramUniformMatrix2fv", traits, *this)
      , ProgramUniformMatrix3fv("ProgramUniformMatrix3fv", traits, *this)
      , ProgramUniformMatrix4fv("ProgramUniformMatrix4fv", traits, *this)
      , ProgramUniformMatrix2x3fv("ProgramUniformMatrix2x3fv", traits, *this)
      , ProgramUniformMatrix3x2fv("ProgramUniformMatrix3x2fv", traits, *this)
      , ProgramUniformMatrix2x4fv("ProgramUniformMatrix2x4fv", traits, *this)
      , ProgramUniformMatrix4x2fv("ProgramUniformMatrix4x2fv", traits, *this)
      , ProgramUniformMatrix3x4fv("ProgramUniformMatrix3x4fv", traits, *this)
      , ProgramUniformMatrix4x3fv("ProgramUniformMatrix4x3fv", traits, *this)
      , UniformBlockBinding("UniformBlockBinding", traits, *this)
      , ShaderStorageBlockBinding("ShaderStorageBlockBinding", traits, *this)
      , VertexAttrib1f("VertexAttrib1f", traits, *this)
      , VertexAttrib2f("VertexAttrib2f", traits, *this)
      , VertexAttrib3f("VertexAttrib3f", traits, *this)
      , VertexAttrib4f("VertexAttrib4f", traits, *this)
      , VertexAttrib1fv("VertexAttrib1fv", traits, *this)
      , VertexAttrib2fv("VertexAttrib2fv", traits, *this)
      , VertexAttrib3fv("VertexAttrib3fv", traits, *this)
      , VertexAttrib4fv("VertexAttrib4fv", traits, *this)
      , VertexAttrib1d("VertexAttrib1d", traits, *this)
      , VertexAttrib2d("VertexAttrib2d", traits, *this)
      , VertexAttrib3d("VertexAttrib3d", traits, *this)
      , VertexAttrib4d("VertexAttrib4d", traits, *this)
      , VertexAttrib1dv("VertexAttrib1dv", traits, *this)
      , VertexAttrib2dv("VertexAttrib2dv", traits, *this)
      , VertexAttrib3dv("VertexAttrib3dv", traits, *this)
      , VertexAttrib4dv("VertexAttrib4dv", traits, *this)
      , VertexAttrib1s("VertexAttrib1s", traits, *this)
      , VertexAttrib2s("VertexAttrib2s", traits, *this)
      , VertexAttrib3s("VertexAttrib3s", traits, *this)
      , VertexAttrib4s("VertexAttrib4s", traits, *this)
      , VertexAttrib1sv("VertexAttrib1sv", traits, *this)
      , VertexAttrib2sv("VertexAttrib2sv", traits, *this)
      , VertexAttrib3sv("VertexAttrib3sv", traits, *this)
      , VertexAttrib4sv("VertexAttrib4sv", traits, *this)
      , VertexAttribI1i("VertexAttribI1i", traits, *this)
      , VertexAttribI2i("VertexAttribI2i", traits, *this)
      , VertexAttribI3i("VertexAttribI3i", traits, *this)
      , VertexAttribI4i("VertexAttribI4i", traits, *this)
      , VertexAttribI1iv("VertexAttribI1iv", traits, *this)
      , VertexAttribI2iv("VertexAttribI2iv", traits, *this)
      , VertexAttribI3iv("VertexAttribI3iv", traits, *this)
      , VertexAttribI4iv("VertexAttribI4iv", traits, *this)
      , VertexAttribI1ui("VertexAttribI1ui", traits, *this)
      , VertexAttribI2ui("VertexAttribI2ui", traits, *this)
      , VertexAttribI3ui("VertexAttribI3ui", traits, *this)
      , VertexAttribI4ui("VertexAttribI4ui", traits, *this)
      , VertexAttribI1uiv("VertexAttribI1uiv", traits, *this)
      , VertexAttribI2uiv("VertexAttribI2uiv", traits, *this)
      , VertexAttribI3uiv("VertexAttribI3uiv", traits, *this)
      , VertexAttribI4uiv("VertexAttribI4uiv", traits, *this)
      , VertexAttribI4bv("VertexAttribI4bv", traits, *this)
      , VertexAttribI4ubv("VertexAttribI4ubv", traits, *this)
      , VertexAttribI4sv("VertexAttribI4sv", traits, *this)
      , VertexAttribI4usv("VertexAttribI4usv", traits, *this)
      , VertexAttrib4bv("VertexAttrib4bv", traits, *this)
      , VertexAttrib4ubv("VertexAttrib4ubv", traits, *this)
      , VertexAttrib4usv("VertexAttrib4usv", traits, *this)
      , VertexAttrib4iv("VertexAttrib4iv", traits, *this)
      , VertexAttrib4uiv("VertexAttrib4uiv", traits, *this)
      , VertexAttrib4Nub("VertexAttrib4Nub", traits, *this)
      , VertexAttrib4Nbv("VertexAttrib4Nbv", traits, *this)
      , VertexAttrib4Nubv("VertexAttrib4Nubv", traits, *this)
      , VertexAttrib4Nsv("VertexAttrib4Nsv", traits, *this)
      , VertexAttrib4Nusv("VertexAttrib4Nusv", traits, *this)
      , VertexAttrib4Niv("VertexAttrib4Niv", traits, *this)
      , VertexAttrib4Nuiv("VertexAttrib4Nuiv", traits, *this)
      , VertexAttribL1d("VertexAttribL1d", traits, *this)
      , VertexAttribL2d("VertexAttribL2d", traits, *this)
      , VertexAttribL3d("VertexAttribL3d", traits, *this)
      , VertexAttribL4d("VertexAttribL4d", traits, *this)
      , VertexAttribL1dv("VertexAttribL1dv", traits, *this)
      , VertexAttribL2dv("VertexAttribL2dv", traits, *this)
      , VertexAttribL3dv("VertexAttribL3dv", traits, *this)
      , VertexAttribL4dv("VertexAttribL4dv", traits, *this)
      , VertexAttribP1ui("VertexAttribP1ui", traits, *this)
      , VertexAttribP2ui("VertexAttribP2ui", traits, *this)
      , VertexAttribP3ui("VertexAttribP3ui", traits, *this)
      , VertexAttribP4ui("VertexAttribP4ui", traits, *this)
      , VertexAttribP1uiv("VertexAttribP1uiv", traits, *this)
      , VertexAttribP2uiv("VertexAttribP2uiv", traits, *this)
      , VertexAttribP3uiv("VertexAttribP3uiv", traits, *this)
      , VertexAttribP4uiv("VertexAttribP4uiv", traits, *this)
      , VertexAttribFormat("VertexAttribFormat", traits, *this)
      , VertexAttribIFormat("VertexAttribIFormat", traits, *this)
      , VertexAttribLFormat("VertexAttribLFormat", traits, *this)
      , VertexArrayAttribFormat("VertexArrayAttribFormat", traits, *this)
      , VertexArrayAttribIFormat("VertexArrayAttribIFormat", traits, *this)
      , VertexArrayAttribLFormat("VertexArrayAttribLFormat", traits, *this)
      , VertexAttribPointer("VertexAttribPointer", traits, *this)
      , VertexAttribIPointer("VertexAttribIPointer", traits, *this)
      , VertexAttribLPointer("VertexAttribLPointer", traits, *this)
      , GetVertexArrayiv("GetVertexArrayiv", traits, *this)
      , GetVertexArrayIndexediv("GetVertexArrayIndexediv", traits, *this)
      , GetVertexArrayIndexed64iv("GetVertexArrayIndexed64iv", traits, *this)
      , GetVertexAttribdv("GetVertexAttribdv", traits, *this)
      , GetVertexAttribfv("GetVertexAttribfv", traits, *this)
      , GetVertexAttribiv("GetVertexAttribiv", traits, *this)
      , GetVertexAttribIiv("GetVertexAttribIiv", traits, *this)
      , GetVertexAttribIuiv("GetVertexAttribIuiv", traits, *this)
      , GetVertexAttribLdv("GetVertexAttribLdv", traits, *this)
      , GetVertexAttribPointerv("GetVertexAttribPointerv", traits, *this)
      , ClipControl("ClipControl", traits, *this)
      , DepthRange("DepthRange", traits, *this)
      , DepthRangef("DepthRangef", traits, *this)
      , DepthRangeArrayv("DepthRangeArrayv", traits, *this)
      , DepthRangeIndexed("DepthRangeIndexed", traits, *this)
      , Viewport("Viewport", traits, *this)
      , ViewportArrayv("ViewportArrayv", traits, *this)
      , ViewportIndexedf("ViewportIndexedf", traits, *this)
      , ViewportIndexedfv("ViewportIndexedfv", traits, *this)
      , Scissor("Scissor", traits, *this)
      , ScissorArrayv("ScissorArrayv", traits, *this)
      , ScissorIndexed("ScissorIndexed", traits, *this)
      , ScissorIndexedv("ScissorIndexedv", traits, *this)
      , StencilFunc("StencilFunc", traits, *this)
      , StencilFuncSeparate("StencilFuncSeparate", traits, *this)
      , StencilOp("StencilOp", traits, *this)
      , StencilOpSeparate("StencilOpSeparate", traits, *this)
      , DepthFunc("DepthFunc", traits, *this)
      , ColorMask("ColorMask", traits, *this)
      , ColorMaski("ColorMaski", traits, *this)
      , DepthMask("DepthMask", traits, *this)
      , StencilMask("StencilMask", traits, *this)
      , StencilMaskSeparate("StencilMaskSeparate", traits, *this)
      , ClearColor("ClearColor", traits, *this)
      , ClearDepthf("ClearDepthf", traits, *this)
      , ClearDepth("ClearDepth", traits, *this)
      , ClearStencil("ClearStencil", traits, *this)
      , Clear("Clear", traits, *this)
      , PrimitiveRestartIndex("PrimitiveRestartIndex", traits, *this)
      , ProvokingVertex("ProvokingVertex", traits, *this)
      , LineWidth("LineWidth", traits, *this)
      , PointSize("PointSize", traits, *this)
      , PointParameteri("PointParameteri", traits, *this)
      , PointParameterf("PointParameterf", traits, *this)
      , PointParameteriv("PointParameteriv", traits, *this)
      , PointParameterfv("PointParameterfv", traits, *this)
      , PatchParameteri("PatchParameteri", traits, *this)
      , PatchParameterfv("PatchParameterfv", traits, *this)
      , FrontFace("FrontFace", traits, *this)
      , CullFace("CullFace", traits, *this)
      , PolygonMode("PolygonMode", traits, *this)
      , PolygonOffset("PolygonOffset", traits, *this)
      , PolygonOffsetClamp("PolygonOffsetClamp", traits, *this)
      , SampleCoverage("SampleCoverage", traits, *this)
      , SampleMaski("SampleMaski", traits, *this)
      , MinSampleShading("MinSampleShading", traits, *this)
      , GetMultisamplefv("GetMultisamplefv", traits, *this)
      , BlendEquation("BlendEquation", traits, *this)
      , BlendEquationSeparate("BlendEquationSeparate", traits, *this)
      , BlendEquationi("BlendEquationi", traits, *this)
      , BlendEquationSeparatei("BlendEquationSeparatei", traits, *this)
      , BlendFunc("BlendFunc", traits, *this)
      , BlendFuncSeparate("BlendFuncSeparate", traits, *this)
      , BlendFunci("BlendFunci", traits, *this)
      , BlendFuncSeparatei("BlendFuncSeparatei", traits, *this)
      , BlendColor("BlendColor", traits, *this)
      , LogicOp("LogicOp", traits, *this)
      , DrawArrays("DrawArrays", traits, *this)
      , DrawArraysInstancedBaseInstance(
          "DrawArraysInstancedBaseInstance", traits, *this)
      , DrawArraysInstanced("DrawArraysInstanced", traits, *this)
      , DrawArraysIndirect("DrawArraysIndirect", traits, *this)
      , MultiDrawArrays("MultiDrawArrays", traits, *this)
      , MultiDrawArraysIndirect("MultiDrawArraysIndirect", traits, *this)
      , MultiDrawArraysIndirectCount(
          "MultiDrawArraysIndirectCount", traits, *this)
      , DrawElements("DrawElements", traits, *this)
      , DrawRangeElements("DrawRangeElements", traits, *this)
      , DrawElementsInstancedBaseInstance(
          "DrawElementsInstancedBaseInstance", traits, *this)
      , DrawElementsInstanced("DrawElementsInstanced", traits, *this)
      , DrawElementsBaseVertex("DrawElementsBaseVertex", traits, *this)
      , DrawRangeElementsBaseVertex(
          "DrawRangeElementsBaseVertex", traits, *this)
      , DrawElementsInstancedBaseVertex(
          "DrawElementsInstancedBaseVertex", traits, *this)
      , DrawElementsInstancedBaseVertexBaseInstance(
          "DrawElementsInstancedBaseVertexBaseInstance", traits, *this)
      , DrawElementsIndirect("DrawElementsIndirect", traits, *this)
      , MultiDrawElements("MultiDrawElements", traits, *this)
      , MultiDrawElementsIndirect("MultiDrawElementsIndirect", traits, *this)
      , MultiDrawElementsIndirectCount(
          "MultiDrawElementsIndirectCount", traits, *this)
      , MultiDrawElementsBaseVertex(
          "MultiDrawElementsBaseVertex", traits, *this)
      , DrawTransformFeedback("DrawTransformFeedback", traits, *this)
      , DrawTransformFeedbackInstanced(
          "DrawTransformFeedbackInstanced", traits, *this)
      , DrawTransformFeedbackStream(
          "DrawTransformFeedbackStream", traits, *this)
      , DrawTransformFeedbackStreamInstanced(
          "DrawTransformFeedbackStreamInstanced", traits, *this)
      , DispatchCompute("DispatchCompute", traits, *this)
      , DispatchComputeIndirect("DispatchComputeIndirect", traits, *this)
      , ClampColor("ClampColor", traits, *this)
      , ReadPixels("ReadPixels", traits, *this)
      , ReadnPixels("ReadnPixels", traits, *this)
      , GetBooleanv("GetBooleanv", traits, *this)
      , GetBooleani_v("GetBooleani_v", traits, *this)
      , GetIntegerv("GetIntegerv", traits, *this)
      , GetIntegeri_v("GetIntegeri_v", traits, *this)
      , GetInteger64v("GetInteger64v", traits, *this)
      , GetInteger64i_v("GetInteger64i_v", traits, *this)
      , GetFloatv("GetFloatv", traits, *this)
      , GetFloati_v("GetFloati_v", traits, *this)
      , GetDoublev("GetDoublev", traits, *this)
      , GetDoublei_v("GetDoublei_v", traits, *this)
      , GetInternalformativ("GetInternalformativ", traits, *this)
      , GetInternalformati64v("GetInternalformati64v", traits, *this)
      , GetPointerv("GetPointerv", traits, *this)
      , GetString("GetString", traits, *this)
      , GetStringi("GetStringi", traits, *this)
      , DebugMessageCallback("DebugMessageCallback", traits, *this)
      , DebugMessageControl("DebugMessageControl", traits, *this)
      , DebugMessageInsert("DebugMessageInsert", traits, *this)
      , PushDebugGroup("PushDebugGroup", traits, *this)
      , PopDebugGroup("PopDebugGroup", traits, *this)
      , ObjectLabel("ObjectLabel", traits, *this)
      , ObjectPtrLabel("ObjectPtrLabel", traits, *this)
      , GetObjectLabel("GetObjectLabel", traits, *this)
      , GetObjectPtrLabel("GetObjectPtrLabel", traits, *this)
      , GetDebugMessageLog("GetDebugMessageLog", traits, *this)
      , Begin("Begin", traits, *this)
      , End("End", traits, *this)
      , Vertex2i("Vertex2i", traits, *this)
      , Vertex3i("Vertex3i", traits, *this)
      , Vertex4i("Vertex4i", traits, *this)
      , Vertex2f("Vertex2f", traits, *this)
      , Vertex3f("Vertex3f", traits, *this)
      , Vertex4f("Vertex4f", traits, *this)
      , Color3i("Color3i", traits, *this)
      , Color4i("Color4i", traits, *this)
      , Color3f("Color3f", traits, *this)
      , Color4f("Color4f", traits, *this)
      , SecondaryColor3i("SecondaryColor3i", traits, *this)
      , SecondaryColor4i("SecondaryColor4i", traits, *this)
      , SecondaryColor3f("SecondaryColor3f", traits, *this)
      , SecondaryColor4f("SecondaryColor4f", traits, *this)
      , TexCoord1i("TexCoord1i", traits, *this)
      , TexCoord2i("TexCoord2i", traits, *this)
      , TexCoord3i("TexCoord3i", traits, *this)
      , TexCoord4i("TexCoord4i", traits, *this)
      , TexCoord1f("TexCoord1f", traits, *this)
      , TexCoord2f("TexCoord2f", traits, *this)
      , TexCoord3f("TexCoord3f", traits, *this)
      , TexCoord4f("TexCoord4f", traits, *this)
      , MultiTexCoord1i("MultiTexCoord1i", traits, *this)
      , MultiTexCoord2i("MultiTexCoord2i", traits, *this)
      , MultiTexCoord3i("MultiTexCoord3i", traits, *this)
      , MultiTexCoord4i("MultiTexCoord4i", traits, *this)
      , MultiTexCoord1f("MultiTexCoord1f", traits, *this)
      , MultiTexCoord2f("MultiTexCoord2f", traits, *this)
      , MultiTexCoord3f("MultiTexCoord3f", traits, *this)
      , MultiTexCoord4f("MultiTexCoord4f", traits, *this)
      , MatrixMode("MatrixMode", traits, *this)
      , PushMatrix("PushMatrix", traits, *this)
      , PopMatrix("PopMatrix", traits, *this)
      , MatrixPushEXT("MatrixPushEXT", traits, *this)
      , MatrixPopEXT("MatrixPopEXT", traits, *this)
      , LoadIdentity("LoadIdentity", traits, *this)
      , MatrixLoadIdentityEXT("MatrixLoadIdentityEXT", traits, *this)
      , Translatef("Translatef", traits, *this)
      , Translated("Translated", traits, *this)
      , MatrixTranslatefEXT("MatrixTranslatefEXT", traits, *this)
      , MatrixTranslatedEXT("MatrixTranslatedEXT", traits, *this)
      , Rotatef("Rotatef", traits, *this)
      , Rotated("Rotated", traits, *this)
      , MatrixRotatefEXT("MatrixRotatefEXT", traits, *this)
      , MatrixRotatedEXT("MatrixRotatedEXT", traits, *this)
      , Scalef("Scalef", traits, *this)
      , Scaled("Scaled", traits, *this)
      , MatrixScalefEXT("MatrixScalefEXT", traits, *this)
      , MatrixScaledEXT("MatrixScaledEXT", traits, *this)
      , Frustum("Frustum", traits, *this)
      , Ortho("Ortho", traits, *this)
      , MatrixFrustumEXT("MatrixFrustumEXT", traits, *this)
      , MatrixOrthoEXT("MatrixOrthoEXT", traits, *this)
      , LoadMatrixf("LoadMatrixf", traits, *this)
      , LoadMatrixd("LoadMatrixd", traits, *this)
      , MatrixLoadfEXT("MatrixLoadfEXT", traits, *this)
      , MatrixLoaddEXT("MatrixLoaddEXT", traits, *this)
      , MultMatrixf("MultMatrixf", traits, *this)
      , MultMatrixd("MultMatrixd", traits, *this)
      , MatrixMultfEXT("MatrixMultfEXT", traits, *this)
      , MatrixMultdEXT("MatrixMultdEXT", traits, *this)
      , LoadTransposeMatrixf("LoadTransposeMatrixf", traits, *this)
      , LoadTransposeMatrixd("LoadTransposeMatrixd", traits, *this)
      , MatrixLoadTransposefEXT("MatrixLoadTransposefEXT", traits, *this)
      , MatrixLoadTransposedEXT("MatrixLoadTransposedEXT", traits, *this)
      , MultTransposeMatrixf("MultTransposeMatrixf", traits, *this)
      , MultTransposeMatrixd("MultTransposeMatrixd", traits, *this)
      , MatrixMultTransposefEXT("MatrixMultTransposefEXT", traits, *this)
      , MatrixMultTransposedEXT("MatrixMultTransposedEXT", traits, *this)
      , MatrixLoad3x2fNV("MatrixLoad3x2fNV", traits, *this)
      , MatrixLoad3x3fNV("MatrixLoad3x3fNV", traits, *this)
      , MatrixLoadTranspose3x3fNV("MatrixLoadTranspose3x3fNV", traits, *this)
      , MatrixMult3x2fNV("MatrixMult3x2fNV", traits, *this)
      , MatrixMult3x3fNV("MatrixMult3x3fNV", traits, *this)
      , MatrixMultTranspose3x3fNV("MatrixMultTranspose3x3fNV", traits, *this)
      , GenPathsNV("GenPathsNV", traits, *this)
      , DeletePathsNV("DeletePathsNV", traits, *this)
      , IsPathNV("IsPathNV", traits, *this)
      , PathParameterivNV("PathParameterivNV", traits, *this)
      , PathParameteriNV("PathParameteriNV", traits, *this)
      , PathParameterfvNV("PathParameterfvNV", traits, *this)
      , PathParameterfNV("PathParameterfNV", traits, *this)
      , PathCommandsNV("PathCommandsNV", traits, *this)
      , PathSubCommandsNV("PathSubCommandsNV", traits, *this)
      , PathCoordsNV("PathCoordsNV", traits, *this)
      , PathSubCoordsNV("PathSubCoordsNV", traits, *this)
      , PathStringNV("PathStringNV", traits, *this)
      , PathGlyphsNV("PathGlyphsNV", traits, *this)
      , PathGlyphRangeNV("PathGlyphRangeNV", traits, *this)
      , PathGlyphIndexArrayNV("PathGlyphIndexArrayNV", traits, *this)
      , PathMemoryGlyphIndexArrayNV(
          "PathMemoryGlyphIndexArrayNV", traits, *this)
      , PathGlyphIndexRangeNV("PathGlyphIndexRangeNV", traits, *this)
      , CopyPathNV("CopyPathNV", traits, *this)
      , InterpolatePathsNV("InterpolatePaths", traits, *this)
      , WeightPathsNV("WeightPathsNV", traits, *this)
      , TransformPathNV("TransformPathNV", traits, *this)
      , PathStencilFuncNV("PathStencilFuncNV", traits, *this)
      , PathStencilDepthOffsetNV("PathStencilDepthOffsetNV", traits, *this)
      , StencilFillPathNV("StencilFillPathNV", traits, *this)
      , StencilStrokePathNV("StencilStrokePathNV", traits, *this)
      , StencilFillPathInstancedNV("StencilFillPathInstancedNV", traits, *this)
      , StencilStrokePathInstancedNV(
          "StencilStrokePathInstancedNV", traits, *this)
      , PathCoverDepthFuncNV("PathCoverDepthFuncNV", traits, *this)
      , PathColorGenNV("PathColorGenNV", traits, *this)
      , PathTexGenNV("PathTexGenNV", traits, *this)
      , PathFogGenNV("PathFogGenNV", traits, *this)
      , ProgramPathFragmentInputGenNV(
          "ProgramPathFragmentInputGenNV", traits, *this)
      , CoverFillPathNV("CoverFillPathNV", traits, *this)
      , CoverStrokePathNV("CoverStrokePathNV", traits, *this)
      , CoverFillPathInstancedNV("CoverFillPathInstancedNV", traits, *this)
      , CoverStrokePathInstancedNV("CoverStrokePathInstancedNV", traits, *this)
      , StencilThenCoverFillPathNV("StencilThenCoverFillPathNV", traits, *this)
      , StencilThenCoverStrokePathNV(
          "StencilThenCoverStrokePathNV", traits, *this)
      , StencilThenCoverFillPathInstancedNV(
          "StencilThenCoverFillPathInstancedNV", traits, *this)
      , StencilThenCoverStrokePathInstancedNV(
          "StencilThenCoverStrokePathInstancedNV", traits, *this)
      , GetPathParameterivNV("GetPathParameterivNV", traits, *this)
      , GetPathParameterfvNV("GetPathParameterfvNV", traits, *this)
      , GetPathCommandsNV("GetPathCommandsNV", traits, *this)
      , GetPathCoordsNV("GetPathCoordsNV", traits, *this)
      , GetPathDashArrayNV("GetPathDashArrayNV", traits, *this)
      , GetPathMetricsNV("GetPathMetricsNV", traits, *this)
      , GetPathMetricRangeNV("GetPathMetricRangeNV", traits, *this)
      , GetPathSpacingNV("GetPathSpacingNV", traits, *this)
      , GetPathColorGenivNV("GetPathColorGenivNV", traits, *this)
      , GetPathColorGenfvNV("GetPathColorGenfvNV", traits, *this)
      , GetPathTexGenivNV("GetPathTexGenivNV", traits, *this)
      , GetPathTexGenfvNV("GetPathTexGenfvNV", traits, *this)
      , GetPathLengthNV("GetPathLengthNV", traits, *this)
      , IsPointInFillPathNV("IsPointInFillPathNV", traits, *this)
      , IsPointInStrokePathNV("IsPointInStrokePathNV", traits, *this)
      , PointAlongPathNV("PointAlongPathNV", traits, *this)
      , MaxShaderCompilerThreadsARB(
          "MaxShaderCompilerThreadsARB", traits, *this)
      , Hint("Hint", traits, *this)
      , Flush("Flush", traits, *this)
      , Finish("Finish", traits, *this) {
    }
};
//------------------------------------------------------------------------------
using gl_c_api = basic_gl_c_api<gl_api_traits>;
//------------------------------------------------------------------------------
} // namespace eagine::oglp

#endif // OGLPLUS_GL_API_C_API_HPP

