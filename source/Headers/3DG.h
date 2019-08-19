#ifndef _3DG_H_
#define _3DG_H_

#include<math.h>
#include<stdio.h>
#include<stdlib.h>

#include "Vector3D.h"
#include "Matrix3D.h"
#include "Geometry.h"

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

Vector3 Translate(Vector3 v,FLOATPOINT x,FLOATPOINT y,FLOATPOINT z)
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

TranslateObject(Object *obj,FLOATPOINT x,FLOATPOINT y,FLOATPOINT z)
{
	int i;
	
	for(i=0; i<obj->nTriangles; i++)
	{
		obj->triangles[i].vertex1 = Translate(obj->triangles[i].vertex1,x,y,z);
		obj->triangles[i].vertex2 = Translate(obj->triangles[i].vertex2,x,y,z);
		obj->triangles[i].vertex3 = Translate(obj->triangles[i].vertex3,x,y,z);
	}
}

Object LoadOBJFile(const char *fileName)
{
	Object object;
	object.nVertices = 0;
	object.nTriangles = 0;
	
	Vector3 *vertices;
	Vector3 *normals;
	
	int numNormals = 0;

	FILE *objFile = fopen(fileName,"r");

	char c;
	char trash;

	int x,y,z;
	int nx,ny,nz;

	while(c!=EOF)
	{
		c = fgetc(objFile);
		
		if(c=='v')
		{
			char c1;
			fscanf(objFile,"%c",&c1);
			
			if(c1==' ')
			{
				object.nVertices++;
		
				if(object.nVertices==1)
					vertices = (Vector3*)malloc(sizeof(Vector3)*object.nVertices);
				else
					vertices = (Vector3*)realloc(vertices,sizeof(Vector3)*object.nVertices);
		
				fscanf(objFile,"%lf",&vertices[object.nVertices-1].x);
				fscanf(objFile,"%lf",&vertices[object.nVertices-1].y);
				fscanf(objFile,"%lf",&vertices[object.nVertices-1].z);
				
				vertices[object.nVertices-1].w = 1;
			}			
			else if(c1=='n')
			{
				numNormals++;
				
				if(numNormals==1)
					normals = (Vector3*)malloc(sizeof(Vector3)*numNormals);
				else
					normals = (Vector3*)realloc(normals,sizeof(Vector3)*numNormals);
					
				fscanf(objFile,"%lf",&normals[numNormals-1].x);
				fscanf(objFile,"%lf",&normals[numNormals-1].y);
				fscanf(objFile,"%lf",&normals[numNormals-1].z);
				
				normals[numNormals-1].w = 1;
			}
		}
		
		if(c=='f')
		{
			char c1;
			fscanf(objFile,"%c",&c1);
			
			if(c1==' ')
			{
				object.nTriangles++;

				if(object.nTriangles==1)
				{
					object.triangles = (Triangle*)malloc(sizeof(Triangle)*object.nTriangles);
					object.normals = (Vector3*)malloc(sizeof(Vector3)*object.nTriangles);
				}
				else
				{
					object.triangles = (Triangle*)realloc(object.triangles,sizeof(Triangle)*object.nTriangles);
					object.normals = (Vector3*)realloc(object.normals,sizeof(Vector3)*object.nTriangles);	
				}
	
				fscanf(objFile,"%d%c%c%d%d%c%c%d%d%c%c%d",&x,&trash,&trash,&nx,&y,&trash,&trash,&ny,&z,&trash,&trash,&nz);
	
				object.triangles[object.nTriangles-1].vertex1 = vertices[x-1];
				object.triangles[object.nTriangles-1].vertex2 = vertices[y-1];
				object.triangles[object.nTriangles-1].vertex3 = vertices[z-1];
				
//				Vector3 u = Vector3Subtract(vertices[y-1],vertices[x-1]);
//				Vector3 v = Vector3Subtract(vertices[z-1],vertices[x-1]);
//				
//				Vector3 normal = Vector3Cross(u,v);
//				Vector3Normalize(&normal);
				
				object.normals[object.nTriangles-1] = normals[nx-1];
			}
			
		}
	}
	
	free(vertices);

	fclose(objFile);

	return object;
}

#endif
