#include <stdbool.h>
#include <stddef.h>

#include "logic/Game.h"

#include "graphics/ColorPalette.h"
#include "graphics/Background.h"
#include "graphics/KeyManager.h"

bool IsScreenDirty = false;

Position PrevCursorPosition = { 0, 0 };
Position CurrCursorPosition = { 0, 0 };

Entity SelectedEntity = NULL;

void sleep(int);

int main();

void handleDPADEvents(KeyEvent);
void handleKeyA(KeyEvent);

void validateCursor();

void drawScreen();

int main() {
	Background bkgCnt;
	// for background layer
	bkgCnt.priority = 1;
	bkgCnt.colorMode = 1;
	bkgCnt.characterBaseBlock = 0;
	bkgCnt.screenBaseBlock = 8;
	loadBackground(BKG0, &bkgCnt);

	// for sprite layer
	bkgCnt.priority = 0;
	bkgCnt.screenBaseBlock = 9;
	loadBackground(BKG1, &bkgCnt);

	loadColorPalette(COLOR_PALETTE);
	loadTileMap(BKG0, CHARACTER_BASE_BLOCK);

	for (Key i = KEY_RIGHT; i <= KEY_DOWN; i++) {
		setKeyHandler(i, handleDPADEvents);
	}
	setKeyHandler(KEY_A, handleKeyA);

	initializeGame();


	drawScreen();
	setScreenEntry(BKG0, PrevCursorPosition, 2);
	while (true) {
		processKeys();
		validateCursor();
		if(PrevCursorPosition.x != CurrCursorPosition.x || PrevCursorPosition.y != CurrCursorPosition.y) {
			setScreenEntry(BKG0, PrevCursorPosition, getScreenEntry(BKG0, PrevCursorPosition) - 1);
			setScreenEntry(BKG0, CurrCursorPosition, getScreenEntry(BKG0, CurrCursorPosition) + 1);
			PrevCursorPosition = CurrCursorPosition;
		}

		if (IsScreenDirty) {
			drawScreen();
			IsScreenDirty = false;
		}

		sleep(8);
	}
}

void sleep(int i) {
	int x, y;
	int c;
	for (y = 0; y < i; y++) {
		for (x = 0; x < 3750; x++)
			c = c + 2; // do something to slow things down
	}
}

void handleDPADEvents(KeyEvent event) {
	if (event.state == KEY_STATE_PRESS || event.state == KEY_STATE_REPEAT) {
		switch (event.key) {
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
	}
}

void handleKeyA(KeyEvent event) {
	if (event.state != KEY_STATE_PRESS) {
		return;
	}
	Entity e = getEntityAt(PrevCursorPosition);
	if (e != NULL) {
		if (getType(e) == ET_SURVIVOR) {
			SelectedEntity = e;
			IsScreenDirty = true;
		} else {

		}
	}
	else if (SelectedEntity) {
		IsScreenDirty = move(SelectedEntity, PrevCursorPosition);
	}
}

void validateCursor() {
	if (CurrCursorPosition.x >= GRID_WIDTH) {
		CurrCursorPosition.x = PrevCursorPosition.x;
	}

	if (CurrCursorPosition.y >= GRID_HEIGHT) {
		CurrCursorPosition.y = PrevCursorPosition.y;
	}
}

void drawScreen() {
	vsync();
	for (int x = 0; x < GRID_WIDTH; x++) {
		for (int y = 0; y < GRID_HEIGHT; y++) {
			Position p = { x, y };
			Entity e = getEntityAt(p);
			if (e != NULL) {
				setScreenEntry(BKG1, p, getType(e) + FIRST_ENTITY_INDEX);

			} else {
				setScreenEntry(BKG1, p, 0);
			}

			if(p.x != PrevCursorPosition.x || p.y != PrevCursorPosition.y) {
				setScreenEntry(BKG0, p, 1);
			}
		}
	}

	if (SelectedEntity) {
		ActionPoint remPoints = getRemainingActionPoints(SelectedEntity);
		Position ePosition = getPosition(SelectedEntity);
		Position p;
		for (signed int y = -remPoints; y <= remPoints; y++) {
			p.y = ePosition.y + y;
			if(p.y >= ( GRID_HEIGHT - 1 )) {
				continue;
			}

			signed int width = remPoints - abs(y);
			for (signed int x = -width; x <= width; x++) {
				p.x = ePosition.x + x;
				if(p.x >= ( GRID_WIDTH - 1 )) {
					continue;
				}

				if(p.x != ePosition.x || p.y != ePosition.y) {
					setScreenEntry(BKG0, p, getScreenEntry(BKG0, p) + 2);
				}
			}
		}
		setScreenEntry(BKG0, ePosition, getScreenEntry(BKG0, ePosition) + 2);
	}
}
