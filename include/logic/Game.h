#ifndef GAME_H
#define GAME_H

#include "logic/Entity.h"

void initializeGame();

int getWidth();
int getHeight();

Entity getEntityAt(Position);

void move(Entity, Position);
void endTurn();


#endif
