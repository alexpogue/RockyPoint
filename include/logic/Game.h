#ifndef GAME_H
#define GAME_H

#include <stdbool.h>
#include "logic/Entity.h"

#define GRID_WIDTH 30
#define GRID_HEIGHT 20

void initializeGame();

int getWidth();
int getHeight();

Entity getEntityAt(Position);

 move(Entity, Position);
void endTurn();


#endif
