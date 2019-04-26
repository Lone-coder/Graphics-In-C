#include "3DGC.h"

Object LoadOBJFile(const char *fileName)
{
	Object object;
	object.nVertices=0;
	object.nTriangles=0;
	
	FILE *objFile=fopen(fileName,"r");
	
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
				object.vertices=(vector3*)malloc(sizeof(vector3)*object.nVertices);
			else
				object.vertices=realloc(object.vertices,sizeof(vector3)*object.nVertices);
			
			fscanf(objFile,"%lf",&object.vertices[object.nVertices-1].x);
			fscanf(objFile,"%lf",&object.vertices[object.nVertices-1].y);
			fscanf(objFile,"%lf",&object.vertices[object.nVertices-1].z);
			
		}
		
		if(c=='f' && fgetc(objFile)==' ')
		{
			object.nTriangles++;
			
			if(object.nTriangles==1)
				object.triangles=(triangle*)malloc(sizeof(triangle)*object.nTriangles);
			else
				object.triangles=realloc(object.triangles,sizeof(triangle)*object.nTriangles);
			
			fscanf(objFile,"%d",&x);
			fscanf(objFile,"%d",&y);
			fscanf(objFile,"%d",&z);
			
			object.triangles[object.nTriangles-1].vertex1=object.vertices[x-1];
			object.triangles[object.nTriangles-1].vertex2=object.vertices[y-1];
			object.triangles[object.nTriangles-1].vertex3=object.vertices[z-1];
						
		}
	}
	
	fclose(objFile);
	
	return object;
}

void UpdateRotationZ(vector3 toRotate,vector3 *rotated,double ang)
{
    double angle=(ang*M_PI)/180;

    Mat3x3 rotZ=
    {
        cos(angle),-sin(angle),0,
        sin(angle),cos(angle),0,
        0,0,1
    };

    matmul(rotZ,toRotate,rotated);

}

void main()
{
	CreateConsole("3DEngine",300,200,2,2);
	Projection=Ortho;
	Object cube=LoadOBJFile("spaceship.obj");
	
	int i=0;
	
	triangle trisRotated[cube.nTriangles];
	triangle trisProj[cube.nTriangles];
	
	
	OnUpdate()
	{
	
		for(i=0;i<cube.nTriangles;i++)
		{
			UpdateRotationZ(cube.triangles[i].vertex1,&trisRotated[i].vertex1,ztheta);
			UpdateRotationZ(cube.triangles[i].vertex2,&trisRotated[i].vertex2,ztheta);
			UpdateRotationZ(cube.triangles[i].vertex3,&trisRotated[i].vertex3,ztheta);
			
			
					
			ProjectPoint(trisRotated[i].vertex1,&trisProj[i].vertex1);
			ProjectPoint(trisRotated[i].vertex2,&trisProj[i].vertex2);
			ProjectPoint(trisRotated[i].vertex3,&trisProj[i].vertex3);
			
			DrawTriangle(trisProj[i]);
		}
		
		ztheta++;
		DrawFrame(TRUE);
	}
	
	return;
}
