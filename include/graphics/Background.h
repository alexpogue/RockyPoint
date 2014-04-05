/*
 * Background.h
 *
 *  Created on: Apr 5, 2014
 *      Author: Jacob61
 */

#ifndef BACKGROUND_H_
#define BACKGROUND_H_

#include "logic/Entity.h"

typedef unsigned short ColorPalette[256];

typedef unsigned short Tile[32];
typedef Tile TileMap[256];

typedef unsigned char BkgId;
typedef unsigned short TileId;

#define REG_BKG_SIZE_32x32 0x00
#define REG_BKG_SIZE_64x32 0x01
#define REG_BKG_SIZE_32x64 0x10
#define REG_BKG_SIZE_64x64 0x11

#define BKG0 0
#define BKG1 1
#define BKG2 2
#define BKG3 3

typedef struct {
	unsigned char priority           : 2;
	unsigned char characterBaseBlock : 2;
	unsigned char                    : 2;
	unsigned char mosaic             : 1;
	unsigned char colorMode          : 1;
	unsigned char screenBaseBlock    : 5;
	unsigned char affine             : 1;
	unsigned char size               : 2;
} __attribute__((packed)) Background;


void loadColorPalette(ColorPalette palette);

void loadBackground(BkgId id, Background *bkg);

void loadTileMap(BkgId bkg, TileMap map);

void setTileData(BkgId bkg, TileId id, Tile tile);

void setScreenEntry(BkgId bkg, Position pos, TileId tile);

TileId getScreenEntry(BkgId bkg, Position pos);

void vsync();

#endif /* BACKGROUND_H_ */
