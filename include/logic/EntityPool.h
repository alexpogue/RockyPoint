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
	ActionPoint remainingPoints;
	Position position;
	EntityHealth remainingHealth;
};

Entity allocEntity();

void freeEntity(Entity);

void initializePool();

extern const ActionPoint MAX_ACTION_POINTS[MAX_ENTITY_TYPE + 1];

#endif /* ENTITYPOOL_H_ */
