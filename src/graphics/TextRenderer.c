/*
 * TextRenderer.c
 *
 *  Created on: Apr 5, 2014
 *      Author: Jacob61
 */


#include "graphics/Background.h"
#include "graphics/TextRenderer.h"
#include "graphics/ColorPalette.h"

#include "logic/Game.h"

void initializeCharacterLayer() {
	Background bkg;
	bkg.screenBaseBlock = 10;
	bkg.colorMode = 1;

	loadBackground(BKG2, &bkg);

	clearCharacterLayer();
}

void clearCharacterLayer() {
	for(unsigned int x=0; x<GRID_WIDTH; x++) {
		for(unsigned int y=0; y<GRID_HEIGHT; y++) {
			Position p = { x, y };

			setScreenEntry(BKG2, p, 0);
		}
	}
}

void printStr(Position at, char *str) {
	if(at.x >= GRID_WIDTH || at.y >= GRID_HEIGHT) {
		return;
	}
	while(*str && at.x < GRID_WIDTH) {
		signed int offset = -1;
		if( *str >= 'A' && *str <= 'Z' ) {
			offset = *str - 'A';
		}
		else if( *str >= 'a' && *str <= 'z' ) {
			offset = *str - 'a';
		}
		else if( *str >= '0' && *str <= '9' ) {
			offset = *str - '0' + 26;
		}
		if(offset != -1) {
			setScreenEntry(BKG2, at, FIRST_CHARACTER_INDEX + offset);
		}

		str++;
		at.x++;
	}
}

void printInt(Position at, int val) {
	char buf[34];
	int right = 0;
	int left = 0;

	for(right = 0; val != 0; val /= 10, right++) {
		buf[right] = ( val % 10 ) + '0';
	}
	buf[right + 1] = '\0';

	while(left < right) {
		char t = buf[left];
		buf[left] = buf[right];
		buf[right] = t;

		left++;
		right--;
	}

	printStr(at, buf);
}
