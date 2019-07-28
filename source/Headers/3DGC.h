#ifndef _3DGC_H_
#define _3DGC_H_

#include<windows.h>
#include<math.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<stdlib.h>

#include "Matrix3D.h"
#include "Geometry.h"
#include "PixelText.h"

#define MAX(x,y)  x > y ? x : y
#define MIN(x,y)  x < y ? x : y

#define OnUpdate() while(1)
#define OnStart() if(1)

short i,j;
short scale;

Vector3 ProjectPoint(Vector3 v)
{
	Vector3 projected;
	double d = 6;
	double z = d - v.z;

	Mat4x4 OrthoProj =
	{
		scale,0,0,0,
		0,scale,0,0,
		0,0,1,0,
		0,0,0,1
	};

	projected = matmul(OrthoProj,v);

	return projected;
}

Vector3 UpdateRotationZ(Vector3 toRotate,double ang)
{
	double angle = (ang*M_PI)/180;

	Vector3 rotated;

	Mat4x4 rotZ =
	{
		cos(angle),-sin(angle),0,0,
		sin(angle),cos(angle),0,0,
		0,0,1,0,
		0,0,0,1
	};

	rotated=matmul(rotZ,toRotate);

	return rotated;

}

Vector3 UpdateRotationY(Vector3 toRotate,double ang)
{
	double angle = (ang*M_PI)/180;

	Vector3 rotated;

	Mat4x4 rotY =
	{
		cos(angle),0,sin(angle),0,
		0,1,0,0,
		-sin(angle),0,cos(angle),0,
		0,0,0,1
	};

	rotated = matmul(rotY,toRotate);

	return rotated;

}

Vector3 UpdateRotationX(Vector3 toRotate,double ang)
{
	double angle = (ang*M_PI)/180;

	Vector3 rotated;

	Mat4x4 rotX =
	{
		1,0,0,0,
		0,cos(angle),-sin(angle),0,
		0,sin(angle),cos(angle),0,
		0,0,0,1
	};

	rotated = matmul(rotX,toRotate);

	return rotated;

}

Vector3 TranslateObject(Vector3 v,FLOATPOINT x,FLOATPOINT y,FLOATPOINT z)
{
	Vector3 translated;

	Mat4x4 translate =
	{
		1,0,0,x,
		0,1,0,y,
		0,0,1,z,
		0,0,0,1
	};

	translated = matmul(translate,v);

	return translated;
}

Object LoadOBJFile(const char *fileName)
{
	Object object;
	object.nVertices = 0;
	object.nTriangles = 0;
	
	Vector3 *vertices;

	FILE *objFile = fopen(fileName,"r");

	if(objFile==NULL)
		return object;

	char c;

	int x,y,z;

	while(c!=EOF)
	{
		c=fgetc(objFile);

		if(c=='v' && fgetc(objFile)==' ')
		{
			object.nVertices++;

			if(object.nVertices==1)
				vertices = (Vector3*)malloc(sizeof(Vector3)*object.nVertices);
			else
				vertices = realloc(vertices,sizeof(Vector3)*object.nVertices);

			fscanf(objFile,"%lf",&vertices[object.nVertices-1].x);
			fscanf(objFile,"%lf",&vertices[object.nVertices-1].y);
			fscanf(objFile,"%lf",&vertices[object.nVertices-1].z);
			
			vertices[object.nVertices-1].x += object.position.x;
			vertices[object.nVertices-1].y += object.position.y;
			vertices[object.nVertices-1].z += object.position.z;
			
			vertices[object.nVertices-1].w = 1;
		}

		if(c=='f' && fgetc(objFile)==' ')
		{
			object.nTriangles++;

			if(object.nTriangles==1)
				object.triangles = (Triangle*)malloc(sizeof(Triangle)*object.nTriangles);
			else
				object.triangles = realloc(object.triangles,sizeof(Triangle)*object.nTriangles);

			fscanf(objFile,"%d",&x);
			fscanf(objFile,"%d",&y);
			fscanf(objFile,"%d",&z);

			object.triangles[object.nTriangles-1].vertex1 = vertices[x-1];
			object.triangles[object.nTriangles-1].vertex2 = vertices[y-1];
			object.triangles[object.nTriangles-1].vertex3 = vertices[z-1];

		}
	}
	
	free(vertices);

	fclose(objFile);

	return object;
}
