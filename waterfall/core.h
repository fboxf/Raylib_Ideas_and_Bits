#ifndef CORE_H
#define CORE_H

#include "raylib.h"

typedef struct Object_structure* Object;

Object createObject(void);
/* supply data */

void setPos(Object, float, float);
void setSize(Object, int, int);
void setVelocity(Object, float,float);
void setAcceleration(Object, float, float);

/* calculate object data */

void calcMagnitude(Object);
void calcObjectNormal(Object);
void calcScaled(Object, float);
Vector2 calcAdded(Object, Object);
Vector2 calcSubtracted(Object, Object);
Vector2 calcComponentProduct(Object, Object);
float calcScalarProduct(Vector2, Vector2);
void calcSpeed(Object o);

/* Return values to client */

Vector2 getPos(Object);
Vector2 getSize(Object);
Vector2 getVelocity(Object);
Vector2 getAcceleration(Object);
Vector2 getSpeed(Object);
float getMagnitude(Object);
Vector2 getNormal(Object);
#endif

