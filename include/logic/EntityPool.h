/*
 * EntityInternal.h
 *
 *  Created on: Apr 4, 2014
 *      Author: Jacob61
 */

#ifndef ENTITYPOOL_H_
#define ENTITYPOOL_H_

#include "logic/Entity.h"

struct Entity_t {
	EntityType type;
	Position p;
	int health;
};

Entity allocEntity();

void freeEntity(Entity);

void initializePool();

#endif /* ENTITYPOOL_H_ */
