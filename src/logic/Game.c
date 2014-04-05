#include <stddef.h>
#include <stdlib.h>
#include "logic/Game.h"
#include "logic/EntityPool.h"
#include "logic/Random.h"

Entity grid[GRID_WIDTH][GRID_HEIGHT];
unsigned int calculateNumMoves(Position, Position, ActionPoint);
void moveZombie(Entity);
Entity createZombie(Position p);
Entity createSurvivor(Position p);
bool addNewZombie();


void initializeGame(){
	initializePool();
	int unsigned i, j;

	//initialize grid
	for(i = 0; i < GRID_WIDTH;i++){
		for(j =0; j < GRID_HEIGHT;j++){
			grid[i][j] = NULL;
		}
	}

	//put some zombies in
	for(i=0; i < 15; i++){
		addNewZombie();
	}

	grid[15][15] = createZombie((Position) { 15, 15 });


	grid[0][0] = createSurvivor((Position) { 0 ,0 });

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

unsigned int calculateNumMoves(Position c, Position p, ActionPoint a){
	return abs(c.x - p.x) + abs(c.y - p.y);
}


void endTurn(){
	unsigned int i, j;
	for(i = 0; i < GRID_WIDTH; i++){
		for(j=0; j<GRID_HEIGHT;j++){
			if(grid[i][j] != NULL){
				if(grid[i][j]->type == ET_ZOMBIE){
					moveZombie(grid[i][j]);

				}
				grid[i][j]->remainingPoints = MAX_ACTION_POINTS[grid[i][j]->type];

			}
		}
	}

}
void moveZombie(Entity z){
	int r = rand()%4;
	Position p = z->position;
	if(r == 0){
		p.x--;
	}
	else if(r==1){
		p.y++;
	}
	else if(r==2){
		p.x++;
	}
	else{
		p.y--;
	}

	if(p.x < 0){
		p.x = 0;
	}
	else if(p.x > GRID_WIDTH){
		p.x = GRID_WIDTH;
	}
	if(p.y < 0){
		p.y = 0;
	}
	else if(p.y > GRID_HEIGHT){
		p.y = GRID_HEIGHT;
	}
	move(z,p);
}
bool shoot(Entity shooter, Position shotAt){
	if(getEntityAt(shotAt)->type == ET_ZOMBIE){
		if(shooter->remainingPoints > 0){

			//if the random number is greater than the number of moves, the shot hits
			if(rand()%50 > calculateNumMoves(shooter->position, shotAt, 50)){
				//hit
				Entity e = grid[shotAt.x][shotAt.y];
				grid[shotAt.x][shotAt.y] = NULL;

				freeEntity(e);
			}
			else{
				//miss
			}

			shooter->remainingPoints -= 1;
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
bool addNewZombie(){
	Position p = { rand()%30, rand()%20 };

	if(getEntityAt(p) == NULL){
		grid[p.x][p.y] = createZombie(p);
		return true;
	}
	else{
		return false;
	}
}
Entity createZombie(Position p){
	Entity zombie = allocEntity();
	zombie->remainingHealth = 1;
	zombie->type = ET_ZOMBIE;
	zombie->remainingPoints = MAX_ACTION_POINTS[zombie->type];
	zombie->position = p;
	return zombie;
}
Entity createSurvivor(Position p){
		Entity survivor = allocEntity();
		survivor->remainingHealth = 1;
		survivor->type = ET_SURVIVOR;
		survivor->remainingPoints = MAX_ACTION_POINTS[survivor->type];
		survivor->position = p;
		return survivor;
}
