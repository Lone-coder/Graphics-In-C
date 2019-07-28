#ifndef _GEOMETRY_H_
#define _GEOMETRY_H_

#include<math.h>
#include "Vector3D.h"

double xtheta = 0,ytheta = 0,ztheta = 0;
double dx = 0,dy = 0,dz = 0;

typedef struct TRIS
{
	Vector3 vertex1;
	Vector3 vertex2;
	Vector3 vertex3;

} Triangle;

typedef struct OBJECT
{
	Triangle *triangles;
	Vector3 *normals;
	Vector3 position;
	int nVertices;
	int nTriangles;
} Object;



#endif
