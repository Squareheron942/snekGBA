
@{{BLOCK(apple_bn_gfx)

@=======================================================================
@
@	apple_bn_gfx, 16x96@4, 
@	+ palette 16 entries, not compressed
@	+ 24 tiles not compressed
@	Total size: 32 + 768 = 800
@
@	Time-stamp: 2023-02-03, 23:03:30
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global apple_bn_gfxTiles		@ 768 unsigned chars
	.hidden apple_bn_gfxTiles
apple_bn_gfxTiles:
	.word 0x00000000,0xD0000000,0x30000000,0x11100000,0x12210000,0x12221000,0x11221100,0x11111100
	.word 0x00000000,0x00000000,0x00000000,0x00000011,0x00000111,0x00001111,0x00011111,0x00041111
	.word 0x11111100,0x11111100,0x11111100,0x11111000,0x41110000,0x44400000,0x00000000,0x00000000
	.word 0x00044111,0x00044111,0x00044411,0x00004441,0x00000444,0x00000044,0x00000000,0x00000000
	.word 0x00000000,0x30300000,0x3D300000,0xD3000000,0x33000000,0x55500000,0x55550000,0x55660000
	.word 0x00000000,0x00000D30,0x000003D3,0x000000D3,0x00000033,0x00000555,0x00005555,0x00006665
	.word 0x66660000,0x65550000,0x55660000,0x66660000,0x66550000,0x55500000,0x77000000,0x00000000
	.word 0x00006666,0x00005556,0x00006665,0x00007666,0x00007756,0x00000775,0x00000077,0x00000000

	.word 0x30000000,0x30000000,0x00000000,0x30000000,0x33000000,0x03000000,0x03300000,0x00300000
	.word 0x00000300,0x00000333,0x00000033,0x00000033,0x00000030,0x00000330,0x00000300,0x00000300
	.word 0x01210000,0x11221000,0x11121000,0x44111000,0x04410000,0x00000000,0x00000000,0x00000000
	.word 0x00003300,0x00012100,0x00112210,0x00411210,0x00441110,0x00044400,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x20000000,0x22000000
	.word 0x00000000,0x00000000,0x00039000,0x00DD9200,0x00392220,0x00D98222,0x00D92282,0x00339222
	.word 0x22200000,0x22820000,0x22222000,0x92829900,0x3999D300,0xD3DD3000,0x00000000,0x00000000
	.word 0x000D9222,0x000D9228,0x00033922,0x00003D99,0x000003DD,0x00000000,0x00000000,0x00000000

	.word 0x03000000,0x03D03000,0xD3D33000,0xD33D0000,0x33D00000,0xCCCC0000,0xCBACC000,0xCAACCC00
	.word 0x000000D0,0x000030D3,0x0000D33D,0x00033D33,0x00000D3D,0x0000CCCC,0x000CCCAB,0x00CABCAC
	.word 0xAACABC00,0xACCAAC00,0xCBACC000,0xAAAC0000,0xACCC0000,0xBCC00000,0xCC000000,0x00000000
	.word 0x00CACCCB,0x00CCABCA,0x000CACCC,0x0000CBAC,0x0000CACA,0x00000CCA,0x000000CC,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x80000000,0xE8000000,0xFE888000,0xFFEEE880
	.word 0x00008000,0x00008800,0x00000880,0x000008F8,0x000088FE,0x00088E8F,0x00088F8F,0x008E8FE8
	.word 0x88FFFEE8,0xE8888880,0xEE880000,0xFEEE8800,0x8FFFEE80,0xE8888800,0xFE800000,0x88000000
	.word 0x008EE8FE,0x008FE8FE,0x008FE8FF,0x008FFE8F,0x0008FFE8,0x0008FFFE,0x000088FF,0x00000088

	.section .rodata
	.align	2
	.global apple_bn_gfxPal		@ 32 unsigned chars
	.hidden apple_bn_gfxPal
apple_bn_gfxPal:
	.hword 0x7C1F,0x001F,0x295F,0x0200,0x001A,0x27F6,0x1B58,0x12CD
	.hword 0x0002,0x739F,0x681B,0x7DBF,0x400F,0x0120,0x4FFF,0x03FF

@}}BLOCK(apple_bn_gfx)
