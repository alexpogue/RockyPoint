/*
 * Entity.c
 *
 *  Created on: Apr 4, 2014
 *      Author: Jacob61
 */


#include "logic/EntityPool.h"

Position getPosition(Entity e) {
	return e->position;
}

EntityType getType(Entity e) {
	return e->type;
}

ActionPoint getRemainingActionPoints(Entity e) {
	return e->remainingPoints;
}

EntityHealth getRemainingHealth(Entity e) {
	return e->remainingHealth;
}
