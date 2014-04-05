#ifndef GAME_H
#define GAME_H

#include <stdbool.h>
#include "logic/Entity.h"

#define GRID_WIDTH 30
#define GRID_HEIGHT 20
#define MAX_ENTITIES ( GRID_WIDTH * GRID_HEIGHT )

typedef unsigned char GameState;

#define GAME_OVER    0
#define GAME_RUNNING 1

GameState getGameState();

void initializeGame();

Entity getEntityAt(Position);

bool move(Entity, Position);
bool shoot(Entity shooter, Position target);

void endTurn();

#endif
