#include "scroll.h"

// VARIABLES SCROLL
i8 cx, cy;
///////////////////////

const u8 bloque [32] = {
	0x2F, 0x0F, 0x0F, 0x4F,
	0x1F, 0x0F, 0x0F, 0x8A,
	0x0F, 0xCF, 0xCF, 0x00,
	0x0F, 0xCF, 0xCF, 0x00,
	0x0F, 0xCF, 0xCF,	0x00,
	0x0F, 0xCF, 0xCF, 0x00,
	0x4F, 0x00, 0x00, 0x8A,
	0x8A, 0x00, 0x00, 0x45

};
void initScroll() {
  cx=0;
  cy=0;
}


void widthImageScroll(u8 tile[], u8 shadowTile[], i8 posY, u8 widthImage) {
	u8 i;
	for (i=widthImage; i>0; --i) {
			if(i==1){
				scroll(tile, shadowTile, i, posY,1);
			} else {
				scroll(tile, shadowTile, i, posY,-1);
			}
		}
}

void Road() {
	u8 i=19;
	u8 posY=5;

	scroll(g_tile_white, g_tile_pastel_blue, i, posY,-1);
	--i;
	scroll(g_tile_white, g_tile_pastel_blue, i, posY,-1);
	--i;
	scroll(g_tile_white, g_tile_pastel_blue, i, posY,-1);
	--i;
	--i;
	scroll(g_tile_white, g_tile_pastel_blue, i, posY,-1);
	--i;
	scroll(g_tile_white, g_tile_pastel_blue, i, posY,-1);
	--i;
	scroll(g_tile_white, g_tile_pastel_blue, i, posY,-1);
	--i;
	--i;
	scroll(g_tile_white, g_tile_pastel_blue, i, posY,-1);
	--i;
	scroll(g_tile_white, g_tile_pastel_blue, i, posY,-1);
	--i;
	scroll(g_tile_white, g_tile_pastel_blue, i, posY,-1);
	--i;
	--i;
	scroll(g_tile_white, g_tile_pastel_blue, i, posY,-1);
	--i;
	scroll(g_tile_white, g_tile_pastel_blue, i, posY,-1);
	--i;
	scroll(g_tile_white, g_tile_pastel_blue, i, posY,-1);
	--i;
	--i;
	scroll(g_tile_white, g_tile_pastel_blue, i, posY,-1);
	--i;
	scroll(g_tile_white, g_tile_pastel_blue, i, posY,-1);
	--i;
	scroll(g_tile_white, g_tile_pastel_blue, i, posY,1);
}

void scroll(u8 tile[], u8 shadowTile[], i8 posX, i8 posY, i8 nextLine) {
	i8 position;
	position = (posX+cx) % 20;
	cpct_drawSprite(tile, (u8*)0xc04c-(4*position) + 0x0050*posY, 4, 8);

	if (position==0) {
		cpct_drawSprite(shadowTile, (u8*)0xc000 + 0x50*posY, 4, 8);
	} else {
		cpct_drawSprite(shadowTile, (u8*)0xc04c-(4*position)+4 + 0x50*posY, 4, 8);
	}

	if (nextLine>0) { ++cx; }
	if (cx>20) { cx=0; }
}
