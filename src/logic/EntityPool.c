/*
 * EntityPool.c
 *
 *  Created on: Apr 4, 2014
 *      Author: Jacob61
 */

#include <stddef.h>

#include "logic/EntityPool.h"
#include "logic/Game.h"


union Node_t {
	struct Entity_t USED;
	struct {
		EntityType type;
		union Node_t *next;
	} FREE;
};

typedef union Node_t Node;

Node pool[MAX_ENTITIES];
Node *head = NULL;

void initializePool() {
	for(int i=0; i<MAX_ENTITIES; i++) {
		freeEntity(&pool[i].USED);
	}
}

void freeEntity(Entity entity) {
	Node *node = (Node *) entity;
	node->FREE.type = ET_INVALID;

	node->FREE.next = head;
	head = node;
}

Entity allocEntity() {
	if(head == NULL) {
		return NULL;
	}

	Node *node = head;
	head = head->FREE.next;

	return &node->USED;
}
