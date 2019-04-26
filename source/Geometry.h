#ifndef _GEOMETRY_H_
#define _GEOMETRY_H_

#include<math.h>

double xtheta,ytheta,ztheta;

typedef struct VECTOR3{

    double x,y,z;

}vector3;

typedef struct TRIS{

    vector3 vertex1;
    vector3 vertex2;
    vector3 vertex3;

}triangle;

typedef struct OBJECT
{
	vector3 *vertices;
	triangle *triangles;
	int nVertices;
	int nTriangles;
		
}Object;

void initVector3(vector3 *p,double x,double y,double z)
{
    p->x=x;
    p->y=y;
    p->z=z;
}


vector3 p[8];
vector3 pr[8];
vector3 pp[8];

#endif
