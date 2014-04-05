/*
 * Keyboard.h
 *
 *  Created on: Apr 5, 2014
 *      Author: Jacob61
 */

#ifndef KEYMANAGER_H_
#define KEYMANAGER_H_

typedef unsigned char KEY;

#define KEY_A      0
#define KEY_B      1
#define KEY_SELECT 2
#define KEY_START  3
#define KEY_RIGHT  4
#define KEY_LEFT   5
#define KEY_UP     6
#define KEY_DOWN   7
#define KEY_R      8
#define KEY_L      9

#define MAX_KEY    KEY_L

typedef void (* KeyPressedFunc)(KEY key);
typedef void (* KeyReleasedFunc)(KEY key);
typedef void (* KeyRepeatFunc)(KEY key);

typedef struct {
	KeyPressedFunc onKeyPressed;
	KeyReleasedFunc onKeyReleased;
	KeyRepeatFunc onKeyRepeat;
} KeyHandler;

void processKeys();

void setKeyHandler(KEY key, KeyHandler *handler);

#endif /* KEYMANAGER_H_ */
