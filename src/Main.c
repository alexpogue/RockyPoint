#define TRUE  1
#define FALSE 0

#define NUM_ROWS 160
#define NUM_COLS 240

#define VIDMEM_OFF(x, y) ( ( x ) + ( ( y ) * NUM_COLS ) )
#define RGB16(r, g, b) ( ( r ) + ( ( g ) << 5 ) + ( ( b ) << 10 ) )

#define TILE_SIZE 1

typedef unsigned short PIXEL;
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
PIXEL *vidMem = ( PIXEL * ) 0x6000000;

void setPixel(int, int, char, char, char);
void clearScreen();

void pollKeys();
void sleep(int);

int main();

void setPixel(int x, int y, char r, char g, char b) {
	vidMem[ VIDMEM_OFF(x, y) ] = RGB16(r, g, b);
}

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
	*( ( unsigned long * ) 0x4000000 ) = 0x403;

	clearScreen();

	x = NUM_COLS / 2;
	y = NUM_ROWS / 2;

	prevX = -1;
	prevY = -1;

	while(TRUE) {
		pollKeys();

		if(KEYS.UP) {
			y--;
		}
		if(KEYS.DOWN) {
			y++;
		}

		if( ( y - TILE_SIZE ) < 0) {
			y = TILE_SIZE;
		}
		else if( ( y + TILE_SIZE ) >= NUM_ROWS) {
			y = NUM_ROWS - 1 - TILE_SIZE;
		}

		if(KEYS.LEFT) {
			x--;
		}
		if(KEYS.RIGHT) {
			x++;
		}

		if( ( x - TILE_SIZE ) < 0) {
			x = TILE_SIZE;
		}
		else if( ( x + TILE_SIZE ) >= NUM_COLS) {
			x = NUM_COLS - 1 - TILE_SIZE;
		}

		if(KEYS.SELECT) {
			clearScreen();

			prevX = -1;
			prevY = -1;
		}
		else if(prevX != x || prevY != y) {
			int i, j;

			if(prevX != -1 && prevY != -1) {
				for(i = -TILE_SIZE; i <= TILE_SIZE; i++) {
					for(j = -TILE_SIZE; j <= TILE_SIZE; j++) {
						setPixel(prevX + i, prevY + j, 31, 31, 31);
					}
				}
			}

			for(i = -TILE_SIZE; i <= TILE_SIZE; i++) {
				for(j = -TILE_SIZE; j <= TILE_SIZE; j++) {
					setPixel(x + i, y + j, 0, 31, 0);
				}
			}

			prevX = x;
			prevY = y;
		}
		sleep(1);
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
