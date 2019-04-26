#ifndef VECTOR2D_H
#define VECTOR2D_H

#include<math.h>

typedef struct VECTOR2D
{
	float x,y;

} Vector2;

void InitVector2(Vector2* v,float x,float y)
{
	v->x=x;
	v->x=y;
}

float Vector2Mag(Vector2 v)
{
	return sqrt(v.x * v.x + v.y * v.y);
}

float Vector2SqrMag(Vector2 v)
{
	return (v.x * v.x + v.y * v.y);
}

float Vector2Dot(Vector2 v1,Vector2 v2)
{
	return (v1.x * v2.x + v1.y * v2.y);
}

void Vector2Normalize(Vector2 *v)
{
	float mag=Vector2Mag(*v);
	v->x/mag;
	v->y/mag;
}

void Vector2DotScalar(Vector2 *v,float scalar)
{
	v->x*=scalar;
	v->y*=scalar;
}
#endif
