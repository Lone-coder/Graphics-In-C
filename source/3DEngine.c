#include "Headers/3DGC.h"

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
				object.vertices=(Vector3*)malloc(sizeof(Vector3)*object.nVertices);
			else
				object.vertices=realloc(object.vertices,sizeof(Vector3)*object.nVertices);

			fscanf(objFile,"%lf",&object.vertices[object.nVertices-1].x);
			fscanf(objFile,"%lf",&object.vertices[object.nVertices-1].y);
			fscanf(objFile,"%lf",&object.vertices[object.nVertices-1].z);
			object.vertices[object.nVertices-1].w=1;
		}

		if(c=='f' && fgetc(objFile)==' ')
		{
			object.nTriangles++;

			if(object.nTriangles==1)
				object.triangles=(Triangle*)malloc(sizeof(Triangle)*object.nTriangles);
			else
				object.triangles=realloc(object.triangles,sizeof(Triangle)*object.nTriangles);

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

void main()
{

	char fileName[25];
	char path[]="E:\\C Projects\\Graphics\\Console-Graphics\\source\\3d_models\\";

	printf("Enter name of the OBJ file : ");

	scanf("%s",&fileName);
	
	strcat(fileName,".obj");
	strcat(path,fileName);

	Object cube=LoadOBJFile(path);

	CreateConsole("3DEngine",400,300,2,2);
	SetBgColor(DARK_GREY);

	int i=0;

	Triangle trisRotated[cube.nTriangles];
	Triangle trisTranslated[cube.nTriangles];
	Triangle trisProj[cube.nTriangles];

	scale=40;

	Vector3 lightPosition= {10,10,10};

	OnUpdate()
	{

		if(GetAsyncKeyState(VK_UP))
			xtheta++;

		if(GetAsyncKeyState(VK_DOWN))
			xtheta--;

		if(GetAsyncKeyState(VK_LEFT))
			ytheta++;

		if(GetAsyncKeyState(VK_RIGHT))
			ytheta--;

		if(GetAsyncKeyState(VK_HOME))
			scale++;

		if(GetAsyncKeyState(VK_END))
			scale--;

		//transformations
		for(i=0; i<cube.nTriangles; i++)
		{
			trisRotated[i].vertex1=UpdateRotationZ(cube.triangles[i].vertex1,ztheta);
			trisRotated[i].vertex2=UpdateRotationZ(cube.triangles[i].vertex2,ztheta);
			trisRotated[i].vertex3=UpdateRotationZ(cube.triangles[i].vertex3,ztheta);

			trisRotated[i].vertex1=UpdateRotationX(trisRotated[i].vertex1,xtheta);
			trisRotated[i].vertex2=UpdateRotationX(trisRotated[i].vertex2,xtheta);
			trisRotated[i].vertex3=UpdateRotationX(trisRotated[i].vertex3,xtheta);

			trisRotated[i].vertex1=UpdateRotationY(trisRotated[i].vertex1,ytheta);
			trisRotated[i].vertex2=UpdateRotationY(trisRotated[i].vertex2,ytheta);
			trisRotated[i].vertex3=UpdateRotationY(trisRotated[i].vertex3,ytheta);

			trisTranslated[i].vertex1=TranslateObject(trisRotated[i].vertex1,0,0,0);
			trisTranslated[i].vertex2=TranslateObject(trisRotated[i].vertex2,0,0,0);
			trisTranslated[i].vertex3=TranslateObject(trisRotated[i].vertex3,0,0,0);

			trisProj[i].vertex1=ProjectPoint(trisTranslated[i].vertex1);
			trisProj[i].vertex2=ProjectPoint(trisTranslated[i].vertex2);
			trisProj[i].vertex3=ProjectPoint(trisTranslated[i].vertex3);

		}
		
		//reordering triangles
		int n,m;
		
		for(n=0;n<cube.nTriangles;n++)
		{
			for(m=n+1;m<cube.nTriangles;m++)
			{
				Vector3 midVert1=Vector3ScalarMul(Vector3Add(Vector3Add(trisProj[n].vertex1,trisProj[n].vertex2),trisProj[n].vertex3),0.5);
				Vector3 midVert2=Vector3ScalarMul(Vector3Add(Vector3Add(trisProj[m].vertex1,trisProj[m].vertex2),trisProj[m].vertex3),0.5);
				
				if(midVert1.z > midVert2.z)
				{
					Triangle temp=trisProj[n];
					trisProj[n]=trisProj[m];
					trisProj[m]=temp;
				}
			}
		} 
		
		//rendering
		for(i=0; i<cube.nTriangles; i++)
		{
			Vector3 v31=Vector3Subtract(trisRotated[i].vertex1,trisRotated[i].vertex3);
			Vector3 v32=Vector3Subtract(trisRotated[i].vertex2,trisRotated[i].vertex3);

			Vector3 normal=Vector3Cross(v31,v32);

			Vector3Normalize(&normal);

			Vector3 PL=Vector3Subtract(lightPosition,NewVector3(0,0,0));

			Vector3Normalize(&PL);

			FLOATPOINT cosTheta=MAX(0,Vector3Dot(normal,PL));

//			if(cosTheta >0.2)
//				Filltriangle(trisProj[i],DARK_GREY);
//			if(cosTheta >0.6)
//				Filltriangle(trisProj[i],GREY);
//			if(cosTheta > 0.8)
				Filltriangle(trisProj[i],WHITE);
				DrawTriangle(trisProj[i],BLACK);
				
		}
		
		ytheta+=2;
		DrawFrame(TRUE);
	}

	return;
}
