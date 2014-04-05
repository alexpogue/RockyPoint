#include "logic/Game.h"

#define TRUE  1
#define FALSE 0

#define NUM_ROWS 160
#define NUM_COLS 240

#define VIDMEM_OFF(x, y) ( ( x ) + ( ( y ) * NUM_COLS ) )
#define RGB16(r, g, b) ( ( r ) + ( ( g ) << 5 ) + ( ( b ) << 10 ) )
#define REG_DISPCNT *(unsigned int*)0x4000000
#define MODE_1 0x1
#define BG1_ENABLE 0x200
#define BG2_ENABLE 0x400
#define SPRITES_ENABLE 0x1000

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

void clearScreen() {
	int x, y;
	for(x = 0; x < NUM_COLS; x++) {
		for(y = 0; y < NUM_ROWS; y++) {
			setPixel(x, y, 0, 0, 0);
		}
	}
}

int main() {
	int x, y, prevX, prevY;
	REG_DISPCNT = MODE_1 | BG1_ENABLE | BG2_ENABLE | SPRITES_ENABLE;
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
