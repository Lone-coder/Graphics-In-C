#ifndef _VECTOR3D_H_
#define _VECTOR3D_H_

#include<math.h>

typedef double FLOATPOINT;

typedef struct VECTOR3D
{
	FLOATPOINT x,y,z,w;
} Vector3;

Vector3 NewVector3(FLOATPOINT x,FLOATPOINT y,FLOATPOINT z)
{
	Vector3 v;
	v.x = x;
	v.y = y;
	v.z = z;
	v.w = 1;

	return v;
}

FLOATPOINT Vector3Mag(Vector3 v)
{
	return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
}

FLOATPOINT Vector3Length(Vector3 v1,Vector3 v2)
{
	return sqrt(pow((v1.x-v2.x),2) + pow((v1.y-v2.y),2) + pow((v1.z-v2.z),2));
}

FLOATPOINT Vector3SqrMag(Vector3 v)
{
	return (v.x*v.x + v.y*v.y + v.z*v.z);
}

void Vector3Normalize(Vector3 *v)
{
	FLOATPOINT mag=Vector3Mag(*v);

	v->x /= mag;
	v->y /= mag;
	v->z /= mag;
}

Vector3 Vector3Add(Vector3 v1,Vector3 v2)
{
	Vector3 v;

	v.x = v1.x+v2.x;
	v.y = v1.y+v2.y;
	v.z = v1.z+v2.z;

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

FLOATPOINT Vector3Dot(Vector3 v1,Vector3 v2)
{
	return (v1.x*v2.x + v1.y*v2.y + v1.z*v2.z);
}

void Vector3Scale(Vector3 *v,FLOATPOINT scale)
{
	v->x *= scale;
	v->y *= scale;
	v->z *= scale;
}

Vector3 Vector3ScalarMul(Vector3 v,FLOATPOINT scale)
{
	Vector3 scaled;
	
	scaled.x = v.x * scale;
	scaled.y = v.y * scale;
	scaled.z = v.z * scale;
	
	return scaled;
}

Vector3 Vector3Cross(Vector3 v1,Vector3 v2)
{
	Vector3 vComputed;

	vComputed.x = (v1.y * v2.z) - (v1.z * v2.y);
	vComputed.y = (v1.x * v2.z) - (v1.z * v2.x);
	vComputed.z = (v1.x * v2.y) - (v1.y * v2.x);

	return vComputed;
}

//Debug
void PrintVector3(Vector3 v,const char *label)
{
	printf("\n");
	printf(label);
	printf(" : ( %lf , %lf , %lf )\n",v.x,v.y,v.z);
}
#endif
