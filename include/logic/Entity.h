#ifndef ENTITY_H
#define ENTITY_H


typedef struct Entity_t* Entity;

typedef unsigned char EntityType;

#define SURVIVOR 0
#define ZOMBIE 1
#define INVALID 255

typedef struct {
	unsigned int x;
	unsigned int y;
} Position;

Position getPosition(Entity c);

EntityType getType(Entity c);

#endif
