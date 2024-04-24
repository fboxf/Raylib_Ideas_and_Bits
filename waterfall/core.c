#include <stdio.h>
#include <stdlib.h>
#include "core.h"
#include "raylib.h"
#include "raymath.h"

typedef struct Object_structure{
	Vector2 position;
	Vector2 size;

	float magnitude;
	Vector2 normal;

	Vector2 velocity;		// measure at one instant
	Vector2 acceleration; 	// rate of which velocity changes (+ / -)
	Vector2 speed;			// magnitude of velocity vector;
} Object_structure;

Object createObject(void){
	Object a = malloc(sizeof(Object_structure));
	if (a == NULL){
		exit(EXIT_FAILURE);
	} else {
		a->position.x = 0;
		a->position.y = 0;
		a->size = (Vector2){20,20};
	}

	return a;	
}

/* supply data */

void setPos(Object o, float x, float y){
	o->position.x = x; o->position.y = y;

	calcMagnitude(o);
	calcObjectNormal(o);
}

void setSize(Object o, int x, int y){
	
	o->size = (Vector2){x,y};

}

void setVelocity(Object o, float x ,float y){
	o->velocity = (Vector2) {x,y};
}

void setAcceleration(Object o, float x, float y){
	o->acceleration = (Vector2) {x, y};
}

/* calculate object data */

void calcMagnitude(Object o){
	float a = Vector2Length(o->position);
	o->magnitude = a;
}

void calcObjectNormal(Object o){
	o->normal = Vector2Normalize(o->position);
}

void calcScaled(Object o, float x){
	o->position = Vector2Scale(o->position, x);
}

Vector2 calcAdded(Object o, Object p){
	Vector2 v = Vector2Add(o->position, p->position);
	return v;
}

Vector2 calcSubtracted(Object o, Object p){
	Vector2 v = Vector2Add(o->position, p->position);

	return v;
}

Vector2 calcComponentProduct(Object o, Object p){
	Vector2 v = Vector2Multiply(o->position, p->position);

	return v;
}

float calcScalarProduct(Vector2 v1, Vector2 v2){
	float value = Vector2DotProduct(v1, v2);

	return value;
}

void calcSpeed(Object o){
	o->speed = Vector2Scale(Vector2Normalize(o->velocity), Vector2Length(o->velocity));
}

/* Return values to client */

Vector2 getPos(Object o){
	return o->position;
}

Vector2 getSize(Object o){
	return o->size;
}

Vector2 getVelocity(Object o){
	return o->velocity;
}

Vector2 getAcceleration(Object o){
	return o->acceleration;
}

Vector2 getSpeed(Object o){
	return o->speed;
}

float getMagnitude(Object o){
	return o->magnitude;
}

Vector2 getNormal(Object o){
	return o->normal;
}


