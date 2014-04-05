#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

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
void handleKeyB(KeyEvent);
void handleKeyStart(KeyEvent);

void handleAllKeys(KeyEvent);

void validateCursor();

void drawScreen();

int main() {
	initializeGame();
	while(true) {
		Background bkgCnt;
		// for background layer
		bkgCnt.priority = 3;
		bkgCnt.colorMode = 1;
		bkgCnt.characterBaseBlock = 0;
		bkgCnt.screenBaseBlock = 8;
		loadBackground(BKG0, &bkgCnt);

		// for sprite layer
		bkgCnt.priority = 2;
		bkgCnt.screenBaseBlock = 9;
		loadBackground(BKG1, &bkgCnt);

		loadColorPalette(COLOR_PALETTE);
		for(int i=0; i < ( sizeof(TILE_MAP) / sizeof(Tile) ); i++) {
			setTileData(BKG0, i, TILE_MAP[i]);
		}

		for (Key i = KEY_RIGHT; i <= KEY_DOWN; i++) {
			setKeyHandler(i, handleDPADEvents);
		}
		setKeyHandler(KEY_A, handleKeyA);
		setKeyHandler(KEY_B, handleKeyB);
		setKeyHandler(KEY_START, handleKeyStart);


		drawScreen();
		setScreenEntry(BKG0, PrevCursorPosition, 2);
		while (getGameState() == GAME_RUNNING) {
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

			rand();
			sleep(7);
		}

		for(Key k = KEY_A; k <= MAX_KEY; k++) {
			setKeyHandler(k, handleAllKeys);
		}

		loadBackground(BKG1, NULL); // Unload front background

		while(getGameState() == GAME_OVER) {
			processKeys();

			rand();
			sleep(7);
		}

		for(Key k = KEY_A; k <= MAX_KEY; k++) {
			setKeyHandler(k, NULL);
		}
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
		EntityType type = getType(e);
		if (type == ET_SURVIVOR) {
			SelectedEntity = e;
			IsScreenDirty = true;
		} else if(type == ET_ZOMBIE){
			if(SelectedEntity) {
				IsScreenDirty = shoot(SelectedEntity, PrevCursorPosition);
			}
		}
	}
	else if (SelectedEntity) {
		IsScreenDirty = move(SelectedEntity, PrevCursorPosition);
	}
}

void handleKeyB(KeyEvent event) {
	if(event.state != KEY_STATE_PRESS) {
		return;
	}

	if(SelectedEntity) {
		SelectedEntity = NULL;
		IsScreenDirty = getGameState() == GAME_RUNNING;
	}
}

void handleKeyStart(KeyEvent event) {
	if(event.state != KEY_STATE_PRESS) {
		return;
	}

	endTurn();
	if(getType(SelectedEntity) != ET_SURVIVOR) {
		SelectedEntity = NULL;
	}
	IsScreenDirty = true;
}

void handleAllKeys(KeyEvent event) {
	if(event.state != KEY_STATE_PRESS) {
		return;
	}

	initializeGame();
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
			setScreenEntry(BKG0, p, 1);
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

				setScreenEntry(BKG0, p, 3);
			}
		}
	}

	setScreenEntry(BKG0, PrevCursorPosition, getScreenEntry(BKG0, PrevCursorPosition) + 1);
}
