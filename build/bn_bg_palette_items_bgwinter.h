#ifndef BN_BG_PALETTE_ITEMS_BGWINTER_H
#define BN_BG_PALETTE_ITEMS_BGWINTER_H

#include "bn_bg_palette_item.h"

//{{BLOCK(bgwinter_bn_gfx)

//======================================================================
//
//	bgwinter_bn_gfx, 8x8@4, 
//	+ palette 16 entries, not compressed
//	Total size: 32 = 32
//
//	Time-stamp: 2023-02-03, 22:26:47
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BGWINTER_BN_GFX_H
#define GRIT_BGWINTER_BN_GFX_H

#define bgwinter_bn_gfxPalLen 32
extern const bn::color bgwinter_bn_gfxPal[16];

#endif // GRIT_BGWINTER_BN_GFX_H

//}}BLOCK(bgwinter_bn_gfx)

namespace bn::bg_palette_items
{
    constexpr inline bg_palette_item bgwinter(span<const color>(bgwinter_bn_gfxPal, 16), 
            bpp_mode::BPP_4, compression_type::NONE);
}

#endif

