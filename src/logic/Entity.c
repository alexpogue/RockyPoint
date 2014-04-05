/*
 * Entity.c
 *
 *  Created on: Apr 4, 2014
 *      Author: Jacob61
 */


#include "logic/EntityPool.h"

Position getPosition(Entity e) {
	return e->p;
}

EntityType getType(Entity e) {
	return e->type;
}
