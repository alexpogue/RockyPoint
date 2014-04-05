/*
 * Background.c
 *
 *  Created on: Apr 5, 2014
 *      Author: Jacob61
 */


#include "graphics/Background.h"
#include <stddef.h>

typedef Tile CBB[1024 * 16 / sizeof(Tile)];
typedef unsigned short SBB[2 * 1024 / sizeof(unsigned short)];

#define SBB_OFFSET(pos) ( (pos).x + ( (pos).y * 32 ) )

#define COLOR_PALETTE_ADDR ( (volatile unsigned short *) 0x5000000 )
#define COLOR_PALETTE_SIZE 256

#define BKG_CNT_REG ( (volatile unsigned short *) 0x04000008)
#define BKG_BIT(b)  ( 1 << ( 8 + ( b ) ) )

#define REG_DISPCNT *(unsigned int*)0x4000000

CBB *CharacterBaseBlocks = (CBB *) 0x06000000;
SBB *ScreenBaseBlocks    = (SBB *) 0x06000000;

Background Backgrounds[4];

unsigned short DisplayControlRegister = 0;

void loadColorPalette(ColorPalette palette) {
	for(int i=0; i<COLOR_PALETTE_SIZE; i++) {
		COLOR_PALETTE_ADDR[i] = palette[i];
	}
}

void loadBackground(BkgId bkgId, Background *bkg) {
	if(bkgId >= 4) {
		return;
	}
	if(bkg != NULL) {
		DisplayControlRegister |= BKG_BIT(bkgId);
		REG_DISPCNT = DisplayControlRegister;

		Backgrounds[bkgId] = *bkg;

		union {
			Background BITS;
			unsigned short RAW;
		} BKG_BITS;

		BKG_BITS.BITS = *bkg;
		BKG_CNT_REG[bkgId] = BKG_BITS.RAW;

		// Clear the screen
		for(int x=0; x<32; x++) {
			for(int y=0; y<32; y++) {
				Position p = { x, y };
				setScreenEntry(bkgId, p, 0);
			}
		}
	}
	else {
		DisplayControlRegister &= ~BKG_BIT(bkgId);
		REG_DISPCNT = DisplayControlRegister;
	}
}

void loadTileMap(BkgId bkgId, TileMap map) {
	if(bkgId >= 4) {
		return;
	}
	for(int i=0; i<255; i++) {
			setTileData(bkgId, i, map[i]);
	}
}

void setTileData(BkgId bkgId, TileId tileId, Tile src) {
	if(bkgId >= 4) {
		return;
	}

	Background *bkg = &Backgrounds[bkgId];

	Tile *dest = &(CharacterBaseBlocks[bkg->characterBaseBlock][tileId]);
	for(int i=0; i<sizeof(Tile); i++) {
		(*dest)[i] = src[i];
	}
}

void setScreenEntry(BkgId bkgId, Position pos, TileId tileId) {
	if(bkgId >= 4) {
		return;
	}

	Background *bkg = &Backgrounds[bkgId];
	ScreenBaseBlocks[bkg->screenBaseBlock][SBB_OFFSET(pos)] = tileId;
}

TileId getScreenEntry(BkgId bkgId, Position pos) {
	if(bkgId >= 4) {
		return 0;
	}

	Background *bkg = &Backgrounds[bkgId];
	return ScreenBaseBlocks[bkg->screenBaseBlock][SBB_OFFSET(pos)];
}
