#include <stddef.h>
#include "logic/Game.h"
#include "logic/EntityPool.h"

Entity grid[GRID_WIDTH][GRID_HEIGHT];

void initializeGame(){
	initializePool();
	int unsigned i, j;
	for(i = 0; i < GRID_WIDTH;i++){
		for(j =0; j < GRID_HEIGHT;j++){
			grid[i][j] = NULL;
		}
	}

}
Entity getEntityAt(Position p){
	return grid[p.x][p.y];
}
bool move(Entity c, Position p){
	if(NULL == grid[p.x][p.y]){
		grid[p.x][p.y] = c;
		grid[c->p.x][c->p.y] = NULL;
		c->p = p;
		return true;
	}
	else{
		return false;
	}
}
void endTurn(){

}
