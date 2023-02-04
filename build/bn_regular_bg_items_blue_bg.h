#ifndef BN_REGULAR_BG_ITEMS_BLUE_BG_H
#define BN_REGULAR_BG_ITEMS_BLUE_BG_H

#include "bn_regular_bg_item.h"

//{{BLOCK(blue_bg_bn_gfx)

//======================================================================
//
//	blue_bg_bn_gfx, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 93 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 2976 + 2048 = 5056
//
//	Time-stamp: 2023-01-28, 10:27:08
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BLUE_BG_BN_GFX_H
#define GRIT_BLUE_BG_BN_GFX_H

#define blue_bg_bn_gfxTilesLen 2976
extern const bn::tile blue_bg_bn_gfxTiles[93];

#define blue_bg_bn_gfxMapLen 2048
extern const bn::regular_bg_map_cell blue_bg_bn_gfxMap[1024];

#define blue_bg_bn_gfxPalLen 32
extern const bn::color blue_bg_bn_gfxPal[16];

#endif // GRIT_BLUE_BG_BN_GFX_H

//}}BLOCK(blue_bg_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item blue_bg(
            regular_bg_tiles_item(span<const tile>(blue_bg_bn_gfxTiles, 93), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(blue_bg_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(blue_bg_bn_gfxMap[0], size(32, 32), compression_type::NONE));
}

#endif

