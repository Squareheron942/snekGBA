#ifndef BN_SPRITE_PALETTE_ITEMS_FRONKPALETTE_H
#define BN_SPRITE_PALETTE_ITEMS_FRONKPALETTE_H

#include "bn_sprite_palette_item.h"

//{{BLOCK(fronkpalette_bn_gfx)

//======================================================================
//
//	fronkpalette_bn_gfx, 8x8@4, 
//	+ palette 16 entries, not compressed
//	Total size: 32 = 32
//
//	Time-stamp: 2023-02-02, 23:29:14
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_FRONKPALETTE_BN_GFX_H
#define GRIT_FRONKPALETTE_BN_GFX_H

#define fronkpalette_bn_gfxPalLen 32
extern const bn::color fronkpalette_bn_gfxPal[16];

#endif // GRIT_FRONKPALETTE_BN_GFX_H

//}}BLOCK(fronkpalette_bn_gfx)

namespace bn::sprite_palette_items
{
    constexpr inline sprite_palette_item fronkpalette(span<const color>(fronkpalette_bn_gfxPal, 16), 
            bpp_mode::BPP_4, compression_type::NONE);
}

#endif

