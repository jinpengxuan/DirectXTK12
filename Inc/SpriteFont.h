//--------------------------------------------------------------------------------------
// File: SpriteFont.h
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved.
//
// http://go.microsoft.com/fwlink/?LinkId=248929
//--------------------------------------------------------------------------------------

#pragma once

#include "SpriteBatch.h"


namespace DirectX
{
    class SpriteFont
    {
    public:
        struct Glyph;

        SpriteFont(_In_ ID3D12Device* device, _In_ ResourceUploadBatch& upload, _In_z_ wchar_t const* fileName, _In_ D3D12_CPU_DESCRIPTOR_HANDLE cpuDescriptorDest, _In_ D3D12_GPU_DESCRIPTOR_HANDLE gpuDescriptor);
        SpriteFont(_In_ ID3D12Device* device, _In_ ResourceUploadBatch& upload, _In_reads_bytes_(dataSize) uint8_t const* dataBlob, _In_ size_t dataSize, _In_ D3D12_CPU_DESCRIPTOR_HANDLE cpuDescriptorDest, _In_ D3D12_GPU_DESCRIPTOR_HANDLE gpuDescriptor);
        SpriteFont(_In_ D3D12_GPU_DESCRIPTOR_HANDLE texture, _In_ XMUINT2 textureSize, _In_reads_(glyphCount) Glyph const* glyphs, _In_ size_t glyphCount, _In_ float lineSpacing);

        SpriteFont(SpriteFont&& moveFrom);
        SpriteFont& operator= (SpriteFont&& moveFrom);

        SpriteFont(SpriteFont const&) = delete;
        SpriteFont& operator= (SpriteFont const&) = delete;

        virtual ~SpriteFont();

        void XM_CALLCONV DrawString(_In_ SpriteBatch* spriteBatch, _In_z_ wchar_t const* text, XMFLOAT2 const& position, FXMVECTOR color = Colors::White, float rotation = 0, XMFLOAT2 const& origin = Float2Zero, float scale = 1, SpriteEffects effects = SpriteEffects_None, float layerDepth = 0) const;
        void XM_CALLCONV DrawString(_In_ SpriteBatch* spriteBatch, _In_z_ wchar_t const* text, XMFLOAT2 const& position, FXMVECTOR color, float rotation, XMFLOAT2 const& origin, XMFLOAT2 const& scale, SpriteEffects effects = SpriteEffects_None, float layerDepth = 0) const;
        void XM_CALLCONV DrawString(_In_ SpriteBatch* spriteBatch, _In_z_ wchar_t const* text, FXMVECTOR position, FXMVECTOR color = Colors::White, float rotation = 0, FXMVECTOR origin = g_XMZero, float scale = 1, SpriteEffects effects = SpriteEffects_None, float layerDepth = 0) const;
        void XM_CALLCONV DrawString(_In_ SpriteBatch* spriteBatch, _In_z_ wchar_t const* text, FXMVECTOR position, FXMVECTOR color, float rotation, FXMVECTOR origin, GXMVECTOR scale, SpriteEffects effects = SpriteEffects_None, float layerDepth = 0) const;

        XMVECTOR XM_CALLCONV MeasureString(_In_z_ wchar_t const* text) const;

        RECT __cdecl MeasureDrawBounds(_In_z_ wchar_t const* text, XMFLOAT2 const& position) const;
        RECT XM_CALLCONV MeasureDrawBounds(_In_z_ wchar_t const* text, FXMVECTOR position) const;

        // Spacing properties
        float __cdecl GetLineSpacing() const;
        void __cdecl SetLineSpacing(float spacing);

        // Font properties
        wchar_t __cdecl GetDefaultCharacter() const;
        void __cdecl SetDefaultCharacter(wchar_t character);

        bool __cdecl ContainsCharacter(wchar_t character) const;

        // Custom layout/rendering
        Glyph const* __cdecl FindGlyph(wchar_t character) const;
        D3D12_GPU_DESCRIPTOR_HANDLE __cdecl GetSpriteSheet() const;
        XMUINT2 __cdecl GetSpriteSheetSize() const;

        // Describes a single character glyph.
        struct Glyph
        {
            uint32_t Character;
            RECT Subrect;
            float XOffset;
            float YOffset;
            float XAdvance;
        };

    private:
        // Private implementation.
        class Impl;

        std::unique_ptr<Impl> pImpl;

        static const XMFLOAT2 Float2Zero;
    };
}
