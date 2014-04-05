#ifndef ENTITY_H
#define ENTITY_H


typedef struct Entity_t* Entity;

typedef unsigned char EntityType;

#define ET_SURVIVOR 0
#define ET_ZOMBIE 1
#define ET_INVALID 255

typedef struct {
	unsigned int x;
	unsigned int y;
} Position;

Position getPosition(Entity c);

EntityType getType(Entity c);

#endif
