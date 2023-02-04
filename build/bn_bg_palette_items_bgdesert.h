#ifndef BN_BG_PALETTE_ITEMS_BGDESERT_H
#define BN_BG_PALETTE_ITEMS_BGDESERT_H

#include "bn_bg_palette_item.h"

//{{BLOCK(bgdesert_bn_gfx)

//======================================================================
//
//	bgdesert_bn_gfx, 8x8@4, 
//	+ palette 16 entries, not compressed
//	Total size: 32 = 32
//
//	Time-stamp: 2023-02-03, 22:26:47
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BGDESERT_BN_GFX_H
#define GRIT_BGDESERT_BN_GFX_H

#define bgdesert_bn_gfxPalLen 32
extern const bn::color bgdesert_bn_gfxPal[16];

#endif // GRIT_BGDESERT_BN_GFX_H

//}}BLOCK(bgdesert_bn_gfx)

namespace bn::bg_palette_items
{
    constexpr inline bg_palette_item bgdesert(span<const color>(bgdesert_bn_gfxPal, 16), 
            bpp_mode::BPP_4, compression_type::NONE);
}

#endif

