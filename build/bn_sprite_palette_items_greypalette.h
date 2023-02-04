#ifndef BN_SPRITE_PALETTE_ITEMS_GREYPALETTE_H
#define BN_SPRITE_PALETTE_ITEMS_GREYPALETTE_H

#include "bn_sprite_palette_item.h"

//{{BLOCK(greypalette_bn_gfx)

//======================================================================
//
//	greypalette_bn_gfx, 8x8@4, 
//	+ palette 16 entries, not compressed
//	Total size: 32 = 32
//
//	Time-stamp: 2023-02-02, 14:59:39
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_GREYPALETTE_BN_GFX_H
#define GRIT_GREYPALETTE_BN_GFX_H

#define greypalette_bn_gfxPalLen 32
extern const bn::color greypalette_bn_gfxPal[16];

#endif // GRIT_GREYPALETTE_BN_GFX_H

//}}BLOCK(greypalette_bn_gfx)

namespace bn::sprite_palette_items
{
    constexpr inline sprite_palette_item greypalette(span<const color>(greypalette_bn_gfxPal, 16), 
            bpp_mode::BPP_4, compression_type::NONE);
}

#endif

