#include <string.h>

#include "logic/Game.h"
#include "graphics/ColorPalette.h"
#include "graphics/Background.h"
#include "graphics/KeyManager.h"

#define TRUE  1
#define FALSE 0

#define NUM_ROWS 160
#define NUM_COLS 240

#define VIDMEM_OFF(x, y) ( ( x ) + ( ( y ) * NUM_COLS ) )
#define RGB16(r, g, b) ( ( r ) + ( ( g ) << 5 ) + ( ( b ) << 10 ) )
#define REG_DISPCNT *(unsigned int*)0x4000000
#define REG_BG0CNT *(unsigned short*)0x04000008
#define REG_BG1CNT *(unsigned short*)0x0400000A
#define MODE_0 0x0
#define BG0_ENABLE ( 1 << 8 )
#define BG1_ENABLE ( 1 << 9 )
#define BG2_ENABLE 0x400
#define SPRITES_ENABLE 0x1000

#define COLOR_PALETTE_ADDR ((volatile unsigned short *) 0x5000000 )

typedef struct {
	char A      : 1;
	char B      : 1;
	char SELECT : 1;
	char START  : 1;
	char RIGHT  : 1;
	char LEFT   : 1;
	char UP     : 1;
	char DOWN   : 1;
	char R      : 1;
	char L      : 1;
} KEY_MAP __attribute__((packed));


KEY_MAP KEYS;

unsigned short *KEY_REG = ( unsigned short * ) 0x04000130;

void clearScreen();

void pollKeys();
void sleep(int);

int main();

void onKeyPress(KEY k) {
	Position p = { k, 0 };
	setScreenEntry(BKG0, p, 2);
}

void onKeyRelease(KEY k) {
	Position p = { k, 0 };
	setScreenEntry(BKG0, p, 1);
}

void clearScreen() {
	int x, y;
	for(x = 0; x < NUM_COLS; x++) {
		for(y = 0; y < NUM_ROWS; y++) {
			//setPixel(x, y, 0, 0, 0);
		}
	}
}

int main() {
	Background bkgCnt;
	// for background layer
	bkgCnt.priority = 0;
	bkgCnt.colorMode = 1;
	bkgCnt.characterBaseBlock = 0;
	bkgCnt.screenBaseBlock = 8;
	loadBackground(BKG0, &bkgCnt);

	// for sprite layer
	bkgCnt.priority = 1;
	bkgCnt.screenBaseBlock = 9;
	loadBackground(BKG1, &bkgCnt);

	loadColorPalette(COLOR_PALETTE);
	loadTileMap(BKG0, CHARACTER_BASE_BLOCK);

	KeyHandler handler;
	handler.onKeyPressed = onKeyPress;
	handler.onKeyReleased = onKeyRelease;
	handler.onKeyRepeat = 0;
	for(KEY i = 0; i <= MAX_KEY; i++) {
		setKeyHandler(i, &handler);
	}

	while(true) {
		processKeys();
	}
}

void pollKeys() {
	union {
		KEY_MAP bitmap_t;
		unsigned short bitmap_p;
	} con;

	con.bitmap_p = ~(*KEY_REG);
	KEYS = con.bitmap_t;
}

void sleep(int i)
{
	int x, y;
	int c;
	for (y = 0; y < i; y++)
	{
		for (x = 0; x < 3750; x++)
			c = c + 2; // do something to slow things down
	}
}
