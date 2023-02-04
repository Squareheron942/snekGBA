
@{{BLOCK(bg_bn_gfx)

@=======================================================================
@
@	bg_bn_gfx, 16x16@4, 
@	+ palette 16 entries, not compressed
@	+ 4 tiles not compressed
@	Total size: 32 + 128 = 160
@
@	Time-stamp: 2023-01-28, 11:25:21
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global bg_bn_gfxTiles		@ 128 unsigned chars
	.hidden bg_bn_gfxTiles
bg_bn_gfxTiles:
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111

	.section .rodata
	.align	2
	.global bg_bn_gfxPal		@ 32 unsigned chars
	.hidden bg_bn_gfxPal
bg_bn_gfxPal:
	.hword 0x02C0,0x0300,0x0200,0x0210,0x4000,0x4010,0x4200,0x6318
	.hword 0x4210,0x001F,0x03E0,0x03FF,0x7C00,0x7C1F,0x7FE0,0x7FFF

@}}BLOCK(bg_bn_gfx)
