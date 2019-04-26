#ifndef VECTOR3D_H
#define VECTOR3D_H

#include<math.h>

typedef double FLOAT;

typedef struct VECTOR3D
{
	FLOAT x,y,z;
} Vector3;

Vector3 NewVector3(FLOAT x,FLOAT y,FLOAT z)
{
	Vector3 v;
	v.x=x;
	v.y=y;
	v.z=z;
	
	return v;
}

FLOAT Vector3Mag(Vector3 v)
{
	return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
}

FLOAT Vector3Length(Vector3 v1,Vector3 v2)
{
	return sqrt(pow((v1.x-v2.x),2) + pow((v1.y-v2.y),2) + pow((v1.z-v2.z),2));	
}

FLOAT Vector3SqrMag(Vector3 v)
{
	return (v.x*v.x + v.y*v.y + v.z*v.z);
}

void Vector3Normalize(Vector3 *v)
{
	FLOAT mag=Vector3Mag(*v);

	v->x/=mag;
	v->y/=mag;
	v->z/=mag;
}

Vector3 Vector3Add(Vector3 v1,Vector3 v2)
{
	Vector3 v;
	
	v.x=v1.x+v2.x;
	v.y=v1.y+v2.y;
	v.z=v1.z+v2.z;

	return v;
}

Vector3 Vector3Subtract(Vector3 v1,Vector3 v2)
{
	Vector3 v;
	
	v.x=v1.x-v2.x;
	v.y=v1.y-v2.y;
	v.z=v1.z-v2.z;

	return v;
}

FLOAT Vector3Dot(Vector3 v1,Vector3 v2)
{
	return (v1.x*v2.x + v1.y*v2.y + v1.z*v2.z);
}

void Vector3Scale(Vector3 *v,FLOAT scale)
{
	v->x*=scale;
	v->y*=scale;
	v->z*=scale;
}

//Debug
void PrintVector3(Vector3 v,const char *label)
{
	printf("\n");
	printf(label);
	printf(" : ( %lf , %lf , %lf )\n",v.x,v.y,v.z);
}
#endif
