#ifndef ENTITY_H
#define ENTITY_H


typedef struct Entity_t* Entity;

typedef unsigned char EntityType;
typedef unsigned char ActionPoint;
typedef unsigned int  EntityHealth;

#define MAX_ENTITY_TYPE 255

#define ET_SURVIVOR 0
#define ET_ZOMBIE 1
#define ET_INVALID MAX_ENTITY_TYPE

typedef struct {
	unsigned int x;
	unsigned int y;
} Position;

Position getPosition(Entity e);

EntityType getType(Entity e);

ActionPoint getRemainingActionPoints(Entity e);

EntityHealth getRemainingHealth(Entity e);


#endif
