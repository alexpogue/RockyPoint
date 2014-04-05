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
	unsigned int numMoves = calculateNumMoves(c->position,p, c->remainingPoints);
	if(c->remainingPoints >= numMoves){
		if(NULL == grid[p.x][p.y]){
			grid[p.x][p.y] = c;
			grid[c->position.x][c->position.y] = NULL;
			c->position = p;
			c->remainingPoints-=numMoves;
			return true;
		}
		else{
			return false;
		}
	}
	else{
		return false;
	}
}
void endTurn(){

}
unsigned int calculateNumMoves(Position c, Position p, ActionPoint a){
	unsigned int i = 0;
	while((c.x != p.x && c.y != p.y)|| i > a){
		if(c.x < p.x){
			c.x++;
			i++;
		}
		else if(c.x > p.x){
			c.x--;
			i++;
		}
		else if(c.y < p.y){
			c.y++;
			i++;
		}
		else if(c.y > p.y){
			c.y--;
			i++;
		}
		else{
			//Not supposed to happen
		}
	}
	return i;
}

//;)
