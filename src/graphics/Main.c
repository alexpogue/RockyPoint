#include <string.h>

#include "logic/Game.h"
#include "graphics/ColorPalette.h"

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

typedef union {
	struct {
		char PR    : 2;
		char CBB   : 2;
		char       : 2;
		char MOS   : 1;
		char CM    : 1;
		char SBB   : 5;
		char WR    : 1;
		char SZ    : 2;
	} REGISTER_BITS __attribute__((packed));
	unsigned short REGISTER_VAL;
} BKG_CNT;

KEY_MAP KEYS;

unsigned short *KEY_REG = ( unsigned short * ) 0x04000130;

void clearScreen();

void pollKeys();
void sleep(int);

int main();

void clearScreen() {
	int x, y;
	for(x = 0; x < NUM_COLS; x++) {
		for(y = 0; y < NUM_ROWS; y++) {
			//setPixel(x, y, 0, 0, 0);
		}
	}
}
#define RGB16(r, g, b) ( ( r ) + ( ( g ) << 5 ) + ( ( b ) << 10 ) )
int main() {
	//int x, y, prevX, prevY;
	REG_DISPCNT = MODE_0 | BG0_ENABLE | BG1_ENABLE;

	BKG_CNT bkgCnt;
	// for background layer
	bkgCnt.REGISTER_VAL = 0;
	bkgCnt.REGISTER_BITS.CM = 1;
	bkgCnt.REGISTER_BITS.SBB = 8;
	REG_BG0CNT = bkgCnt.REGISTER_VAL;

	// for sprite layer
	bkgCnt.REGISTER_VAL = 0;
	bkgCnt.REGISTER_BITS.PR = 1;
	bkgCnt.REGISTER_BITS.CM = 1;
	bkgCnt.REGISTER_BITS.SBB = 9;
	REG_BG1CNT = bkgCnt.REGISTER_VAL;

	memcpy(COLOR_PALETTE_ADDR, COLOR_PALETTE, sizeof(COLOR_PALETTE));
	for(int i=0; i<16 * 1024 / 2; i++) {
		((volatile unsigned short *) 0x06000000)[i] = ((unsigned short *) CHARACTER_BASE_BLOCK)[i];
	}
	for(int i=0; i<1024; i++) { // SBB
		((volatile unsigned short *) 0x06004000)[i] = 0x000;
	}
	while(true) {};
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
