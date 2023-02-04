#ifndef BN_SPRITE_ITEMS_BG_H
#define BN_SPRITE_ITEMS_BG_H

#include "bn_sprite_item.h"

//{{BLOCK(bg_bn_gfx)

//======================================================================
//
//	bg_bn_gfx, 16x16@4, 
//	+ palette 16 entries, not compressed
//	+ 4 tiles not compressed
//	Total size: 32 + 128 = 160
//
//	Time-stamp: 2023-01-28, 11:25:21
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BG_BN_GFX_H
#define GRIT_BG_BN_GFX_H

#define bg_bn_gfxTilesLen 128
extern const bn::tile bg_bn_gfxTiles[4];

#define bg_bn_gfxPalLen 32
extern const bn::color bg_bn_gfxPal[16];

#endif // GRIT_BG_BN_GFX_H

//}}BLOCK(bg_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item bg(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(bg_bn_gfxTiles, 4), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(bg_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

