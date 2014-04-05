#ifndef GAME_H
#define GAME_H

#include "logic/Entity.h"

Entity getEntityAt(Position);
void move(Entity, Position);
int getWidth();
int getHeight();
void endTurn();


#endif
