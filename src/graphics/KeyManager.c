/*
 * KeyManager.c
 *
 *  Created on: Apr 5, 2014
 *      Author: Jacob61
 */


#include "graphics/KeyManager.h"

#define KEY_REG *((unsigned short *) 0x04000130)

KeyHandler handlers[MAX_KEY + 1];
unsigned short prevKeyState = 0;

void setKeyHandler(KEY key, KeyHandler *handler) {
	if(key > MAX_KEY) {
		return;
	}

	handlers[key] = *handler;
}

void processKeys() {
	unsigned short curKeyState = ~(KEY_REG);

	unsigned short cur = curKeyState;
	unsigned short prev = prevKeyState;

	for(KEY i=0; i<=MAX_KEY; i++, cur >>= 1, prev >>= 1) {
		KeyHandler *handler = &handlers[i];
		if(cur & 1) {
			if(prev & 1) {
				if(handler->onKeyRepeat) {
					handler->onKeyRepeat(i);
				}
			}
			else {
				if(handler->onKeyPressed) {
					handler->onKeyPressed(i);
				}
			}
		}
		else if(prev & 1) {
			if(handler->onKeyReleased) {
				handler->onKeyReleased(i);
			}
		}
	}

	prevKeyState = curKeyState;
}
