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

void setKeyHandler(Key key, KeyHandler handler) {
	if(key > MAX_KEY) {
		return;
	}

	handlers[key] = handler;
}

void processKeys() {
	unsigned short curKeyState = ~(KEY_REG);

	unsigned short cur = curKeyState;
	unsigned short prev = prevKeyState;

	for(Key i=0; i<=MAX_KEY; i++, cur >>= 1, prev >>= 1) {
		KeyHandler handler = handlers[i];
		if(!handler) {
			continue;
		}

		KeyEvent event;
		event.key = i;

		if(cur & 1) {
			if(prev & 1) {
				event.state = KEY_STATE_REPEAT;
			}
			else {
				event.state = KEY_STATE_PRESS;
			}
		}
		else if(prev & 1) {
			event.state = KEY_STATE_RELEASE;
		}
		else {
			continue;
		}

		handler(event);
	}

	prevKeyState = curKeyState;
}
