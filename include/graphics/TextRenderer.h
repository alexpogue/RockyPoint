/*
 * StringRenderer.h
 *
 *  Created on: Apr 5, 2014
 *      Author: Jacob61
 */

#ifndef TEXTRENDERER_H_
#define TEXTRENDERER_H_

#include "logic/Entity.h"

void printStr(Position at, char *str);

void printInt(Position at, signed int val);

void clearCharacterLayer();

void initializeCharacterLayer();

#endif /* TEXTRENDERER_H_ */
