#ifndef GEOMETRY_H
#define GEOMETRY_H

#include<math.h>

double xtheta,ytheta,ztheta;

typedef struct VECTOR2{
	
	float x,y;
		
}vect2;

typedef struct VECTOR3{

    double x,y,z;

}vector3;

typedef struct TRIS{

    vector3 tri[3];

}tris;

void initVector3(vector3 *p,double x,double y,double z)
{
    p->x=x;
    p->y=y;
    p->z=z;
}

void initVector2(vect2 *p,float x,float y)
{
    p->x=x;
    p->y=y;
}

vector3 p[8];
vector3 pr[8];
vector3 pp[8];

typedef struct rect{
	int x,y;
	int width;
	int height;
	int color;
}Rect;

typedef struct circle{
	int x,y,radius;
	int color;
}Circle;

//Vector operations

float VectMag(vect2 v)
{
	return sqrt(v.x * v.x + v.y * v.y);	
}  
float VectSqrMag(vect2 v)
{
	return v.x * v.x + v.y * v.y;
}

float VectDot(vect2 v1,vect2 v2)
{
	return v1.x * v2.x + v1.y * v2.y;
}

void NoramalizeVect2(vect2 v,vect2 *n)
{
	int mag=VectMag(v);
	n->x=v.x/mag;
	n->y=v.y/mag;
}

float AngleBwVect(vect2 v1,vect2 v2)
{
	return acos((double)VectDot(v1,v2)/(VectMag(v1)*VectMag(v2)));
}
#endif
