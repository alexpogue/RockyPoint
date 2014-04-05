#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include "logic/Game.h"
#include "logic/EntityPool.h"

unsigned int NumSurvivors = 0;
GameState CurState = GAME_OVER;

Entity grid[GRID_WIDTH][GRID_HEIGHT];
unsigned int calculateDistance(Position, Position);
void moveZombie(Entity);
Entity createZombie(Position p);
Entity createSurvivor(Position p);
bool addNewZombie();
bool addNewSurvivor();
signed int score;
GameState getGameState() {
	return CurState;
}

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

	score = 0;

	grid[15][10] = createSurvivor((Position) { 15 ,10 });
	CurState = GAME_RUNNING;

}
Entity getEntityAt(Position p){
	return grid[p.x][p.y];
}
bool move(Entity c, Position p){
	unsigned int numMoves = calculateDistance(c->position, p);
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

unsigned int calculateDistance(Position c, Position p){
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
	unsigned int spawns = (score * .5);
	for(i = 0; i < 1+spawns ; i++){
		addNewZombie();
	}
	if(rand()%100 > 90){
		addNewSurvivor();
	}
	if(NumSurvivors == 0) {
		CurState = GAME_OVER;
	}
}
void moveZombie(Entity z){
	int r = rand()%4;
	Position p = z->position;

	Entity target = NULL;
	for(signed int x = ( (signed int) p.x ) - 5; x <= ( (signed int) p.x ) + 5; x++) {
		if(x < 0 || x >= GRID_WIDTH) {
			continue;
		}
		for(signed int y = ( (signed int) p.y ) - 5; y <= ( (signed int) p.y ) + 5; y++) {
			if(y < 0 || y >=  GRID_HEIGHT) {
				continue;
			}

			Entity e = getEntityAt((Position) { (unsigned int) x, (unsigned int) y });
			if(e && e->type == ET_SURVIVOR) {
				if(target) {
					Position o = getPosition(target);
					Position u = getPosition(e);

					if(calculateDistance(p, u) < calculateDistance(p, o)) {
						target = e;
					}
				}
				else {
					target = e;
				}
			}
		}
	}
	if(target) {
		Position o = getPosition(target);
		if(calculateDistance(p, o) == 1) {
			// Attack
			target->remainingHealth--;
			if(target->remainingHealth == 0) {
				// Convert the heretics
				NumSurvivors--;
				score -= 3;
				target->type = ET_ZOMBIE;
			}
		}
		else if(o.y < p.y) {
			p.y--;
		}
		else if(o.y > p.y) {
			p.y++;
		}
		else if(o.x < p.x) {
			p.x--;
		}
		else if(o.x > p.x) {
			p.x++;
		}
	}
	else {
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


		if(p.x >= GRID_WIDTH){
			p.x = z->position.x;;
		}

		if(p.y >= GRID_HEIGHT){
			p.y = z->position.y;
		}
	}

	if(z->position.x != p.x || z->position.y != p.y) {
		move(z,p);
	}
}
bool shoot(Entity shooter, Position shotAt){
	if(getEntityAt(shotAt)->type == ET_ZOMBIE){
		if(shooter->remainingPoints > 0){

			//if the random number is greater than the number of moves, the shot hits
			unsigned int distance = calculateDistance(shooter->position, shotAt);
			if((rand()%50) > distance + score*.1){
				//hit
				Entity e = grid[shotAt.x][shotAt.y];
				grid[shotAt.x][shotAt.y] = NULL;
				score++;
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
	unsigned int wall = rand()%4;
	Position p;

	if(wall == 0){
		p = (Position){ GRID_WIDTH-1, rand()%20 };
	}

	else if(wall== 1){
		p = (Position){ rand()%30, 0 };
	}
	else if(wall == 2){
		p = (Position){ rand()%30, GRID_HEIGHT-1};
	}
	else{
		p = (Position){ 0, rand()%20 };
	}



	if(getEntityAt(p) == NULL){
		grid[p.x][p.y] = createZombie(p);
		return true;
	}
	else{
		return false;
	}
}
bool addNewSurvivor(){
	unsigned int wall = rand()%4;
	Position p;

	if(wall == 0){
		p = (Position){ GRID_WIDTH-1, rand()%20 };
	}

	else if(wall== 1){
		p = (Position){ rand()%30, 0 };
	}
	else if(wall == 2){
		p = (Position){ rand()%30, GRID_HEIGHT-1};
	}
	else{
		p = (Position){ 0, rand()%20 };
	}



	if(getEntityAt(p) == NULL){
		grid[p.x][p.y] = createSurvivor(p);
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

		NumSurvivors++;

		return survivor;
}
