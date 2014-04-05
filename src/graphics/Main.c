#include <stdbool.h>

#include "logic/Game.h"

#include "graphics/ColorPalette.h"
#include "graphics/Background.h"
#include "graphics/KeyManager.h"

bool IsScreenDirty = true;

Position PrevCursorPosition = { 0, 0 };
Position CurrCursorPosition = { 0, 0 };

void sleep(int);

int main();

void handleDPADEvents(KeyEvent);


void validateCursor();

void drawScreen();



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

	for(Key i = KEY_RIGHT; i <= KEY_DOWN; i++) {
		setKeyHandler(i, handleDPADEvents);
	}

	setScreenEntry(BKG0, PrevCursorPosition, 2);
	while(true) {
		processKeys();

		if(IsScreenDirty) {
			drawScreen();
			IsScreenDirty = false;
		}

		sleep(10);
	}
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

void handleDPADEvents(KeyEvent event) {
	if(event.state == KEY_STATE_PRESS || event.state == KEY_STATE_REPEAT) {
		switch(event.key) {
		case KEY_UP:
			CurrCursorPosition.y--;
			break;
		case KEY_DOWN:
			CurrCursorPosition.y++;
			break;
		case KEY_LEFT:
			CurrCursorPosition.x--;
			break;
		case KEY_RIGHT:
			CurrCursorPosition.x++;
			break;
		}
		IsScreenDirty = true;
	}
}

void validateCursor() {
	if(CurrCursorPosition.x >= GRID_WIDTH) {
		CurrCursorPosition.x = PrevCursorPosition.x;
	}

	if(CurrCursorPosition.y >= GRID_HEIGHT) {
		CurrCursorPosition.y = PrevCursorPosition.y;
	}
}

void drawScreen() {
	validateCursor();

	setScreenEntry(BKG0, PrevCursorPosition, getScreenEntry(BKG0, PrevCursorPosition) - 1);
	setScreenEntry(BKG0, CurrCursorPosition, getScreenEntry(BKG0, CurrCursorPosition) + 1);
	PrevCursorPosition = CurrCursorPosition;
}
