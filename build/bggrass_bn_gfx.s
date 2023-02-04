
@{{BLOCK(bggrass_bn_gfx)

@=======================================================================
@
@	bggrass_bn_gfx, 8x8@4, 
@	+ palette 16 entries, not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2023-02-03, 22:26:47
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global bggrass_bn_gfxPal		@ 32 unsigned chars
	.hidden bggrass_bn_gfxPal
bggrass_bn_gfxPal:
	.hword 0x03E0,0x0380,0x02A0,0x0210,0x02A0,0x0380,0x4200,0x6318
	.hword 0x4210,0x001F,0x03E0,0x03FF,0x7C00,0x7C1F,0x7FE0,0x7FFF

@}}BLOCK(bggrass_bn_gfx)
