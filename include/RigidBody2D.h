#ifndef RIGIDBODY2D_H
#define RIGIDBODY2D_H

#include "Vector2D.h"

typedef struct RIGIDBODY_2D_CIRCLE
{
	int radius;
	int mass;
	Vector2 position;
	Vector2 velocity;

} RigidBodyCircle;

RigidBodyCircle *rbCircles;

void* CreateRigidBodyCircle()
{
	return;
}

#endif
