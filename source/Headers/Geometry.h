#ifndef _GEOMETRY_H_
#define _GEOMETRY_H_

#include<math.h>
#include "Vector3D.h"

double xtheta,ytheta,ztheta;

typedef struct TRIS
{

	Vector3 vertex1;
	Vector3 vertex2;
	Vector3 vertex3;

} Triangle;

typedef struct OBJECT
{
	Vector3 *vertices;
	Triangle *triangles;
	int nVertices;
	int nTriangles;

} Object;


#endif
