#include "Headers/3DGC.h"

enum VIEWMODE
{
    wireFrame,
    solid,
    shaded,
    infraRed
} viewmode;

char *ViewModeString[4]=
{
	"WIREFRAME",
	"SOLID",
	"SHADED",
	"INFRARED"
};

//x-axis
Vector3 axisCoordinates[6] = { {5,0,0},{-5,0,0},{0,5,0},{0,-5,0},{0,0,5},{0,0,-5} };

void DrawAxis(double xtheta,double ytheta,double ztheta)
{
	Vector3 axisRotated[6];
	Vector3 axisProjected[6];
	int i;
	
	for(i=0; i<6; i++)
	{
		axisRotated[i] = UpdateRotationZ(axisCoordinates[i],ztheta);
		axisRotated[i] = UpdateRotationX(axisRotated[i],xtheta);
		axisRotated[i] = UpdateRotationY(axisRotated[i],ytheta);
		
		axisProjected[i] = ProjectPoint(axisRotated[i]);
		
		if(i==0)
		{
			DrawLine(axisProjected[i].x,axisProjected[i].y,axisProjected[i+1].x,axisProjected[i+1].y,RED,defaultChar);
		}
		else if(i==2)
		{
			DrawLine(axisProjected[i].x,axisProjected[i].y,axisProjected[i+1].x,axisProjected[i+1].y,GREEN,defaultChar);
		}
		else if(i==4)
		{
			DrawLine(axisProjected[i].x,axisProjected[i].y,axisProjected[i+1].x,axisProjected[i+1].y,BLUE,defaultChar);
		}		  
	}
}

//Preocedural Mesh Generation
Object GenerateMesh(int width,int height)
{
	Object mesh;
	
	mesh.nVertices = (width+1) * (height+1);
	mesh.nTriangles = 2 * width * height;
	
	Vector3 *vertices = (Vector3*)malloc(sizeof(Vector3)*mesh.nVertices);
	mesh.triangles = (Triangle*)malloc(sizeof(Triangle)*mesh.nTriangles);
	
	int i,j;
	float x,z;
	int vertexIndex = 0;
	
	x =- 1.0;
	
	for(i = 0; i < height+1; i++)
	{
		z =- 1.0;
		
		for(j = 0; j < width+1; j++)
		{
			
			vertices[vertexIndex].x = x;
			vertices[vertexIndex].y = z;
			vertices[vertexIndex].z = sin(x + z);
			vertices[vertexIndex].w = 1;
			
			vertexIndex++;
			
			z += 0.1;
		}
		
		x += 0.1;
	}
	
	int k;
	int triangleIndex = 0;
	vertexIndex = 0;
	
	for(i = 0; i < height; i++)
	{
		for(j = 0; j < width+1; j++)
		{
				if(j == 0)
				{
					mesh.triangles[triangleIndex].vertex1 =	vertices[vertexIndex];
					mesh.triangles[triangleIndex].vertex2 = vertices[vertexIndex+width+2];
					mesh.triangles[triangleIndex].vertex3 = vertices[vertexIndex+width+1];
					
					triangleIndex++; 
				}
				else if(j == width)
				{
					mesh.triangles[triangleIndex].vertex1 =	vertices[vertexIndex];
					mesh.triangles[triangleIndex].vertex2 = vertices[vertexIndex+width+1];
					mesh.triangles[triangleIndex].vertex3 = vertices[vertexIndex-1];
					
					triangleIndex++;				
				}
				else
				{
					for(k = 0; k < 2; k++)
					{	
						if(k == 0)
						{
							mesh.triangles[triangleIndex].vertex1 =	vertices[vertexIndex];
							mesh.triangles[triangleIndex].vertex2 = vertices[vertexIndex+width+1];
							mesh.triangles[triangleIndex].vertex3 = vertices[vertexIndex-1];
						}		
						else
						{
							mesh.triangles[triangleIndex].vertex1 =	vertices[vertexIndex];
							mesh.triangles[triangleIndex].vertex2 = vertices[vertexIndex+width+2];
							mesh.triangles[triangleIndex].vertex3 = vertices[vertexIndex+width+1];
						}
						
						triangleIndex++;
					}
				}
				
			vertexIndex++;
		}
	}
	
	free(vertices);
	
	return mesh;
}

void main(int argc,char *argv[])
{
	viewmode = solid;

	char fileName[25];
	char path[] = "E:\\C Projects\\Graphics\\Console-Graphics\\source\\3d_models\\";
	
	printf("Enter name of the OBJ file : ");
	
	scanf("%s",fileName);

	strcat(fileName,".obj");
	strcat(path,fileName);

	Object cube = LoadOBJFile(path);
//	Object cube = GenerateMesh(10,10);	

	CreateConsole("3DEngine",400,300,2,2);
	SetBgColor(DARK_GREY);

	int i = 0;

	Triangle trisRotated[cube.nTriangles];
	Triangle trisTranslated[cube.nTriangles];
	Triangle trisProj[cube.nTriangles];

	scale = 40;

	Vector3 lightPosition = {0,0,0};

	OnUpdate()
	{
		DrawAxis(xtheta,ytheta,ztheta);
		//control rotation
		if(GetAsyncKeyState(VK_INSERT))
			xtheta++;

		if(GetAsyncKeyState(VK_DELETE))
			xtheta--;

		if(GetAsyncKeyState(VK_HOME))
			ytheta++;

		if(GetAsyncKeyState(VK_END))
			ytheta--;
		
		//control light position
		if(GetAsyncKeyState(VK_F1))
			lightPosition.x++;
		
		if(GetAsyncKeyState(VK_F2))
			lightPosition.x--;
			
		if(GetAsyncKeyState(VK_F3))
			lightPosition.y++;
		
		if(GetAsyncKeyState(VK_F4))
			lightPosition.y--;
			
		if(GetAsyncKeyState(VK_F5))
			lightPosition.z++;
		
		if(GetAsyncKeyState(VK_F6))
			lightPosition.z--;
		
		//control scaling of the model
		if(GetAsyncKeyState(VK_ADD))
			scale+=5;

		if(GetAsyncKeyState(VK_SUBTRACT))
			scale-=5;

		//control viewmode
		if(GetAsyncKeyState(VK_TAB))
		{
			Sleep(200);
			
			if(viewmode == solid)
				viewmode = wireFrame;
			else if(viewmode == wireFrame)
				viewmode = shaded;
			else if(viewmode == shaded)
				viewmode = infraRed;
			else
				viewmode = solid;					
		}
		
		//Text GUI		
		PrintString("VIEWMODE :",35,20,GREEN);
		PrintString(ViewModeString[viewmode],100,20,WHITE);
		
		PrintString("SCALE :",170,20,GREEN);
		PrintString(strcat(ToString(scale),"x"),210,20,WHITE);
		
		PrintString("VERTICES :",35,40,GREEN);
		PrintString(ToString(cube.nVertices),100,40,WHITE);
		
		PrintString("TRIANGLES :",35,60,GREEN);
		PrintString(ToString(cube.nTriangles),100,60,WHITE);
		
		
		//3D transformations
		for(i = 0; i < cube.nTriangles; i++)
		{
			trisRotated[i].vertex1 = UpdateRotationZ(cube.triangles[i].vertex1,ztheta);
			trisRotated[i].vertex2 = UpdateRotationZ(cube.triangles[i].vertex2,ztheta);
			trisRotated[i].vertex3 = UpdateRotationZ(cube.triangles[i].vertex3,ztheta);

			trisRotated[i].vertex1 = UpdateRotationX(trisRotated[i].vertex1,xtheta);
			trisRotated[i].vertex2 = UpdateRotationX(trisRotated[i].vertex2,xtheta);
			trisRotated[i].vertex3 = UpdateRotationX(trisRotated[i].vertex3,xtheta);

			trisRotated[i].vertex1 = UpdateRotationY(trisRotated[i].vertex1,ytheta);
			trisRotated[i].vertex2 = UpdateRotationY(trisRotated[i].vertex2,ytheta);
			trisRotated[i].vertex3 = UpdateRotationY(trisRotated[i].vertex3,ytheta);

			trisTranslated[i].vertex1 = TranslateObject(trisRotated[i].vertex1,dx,dy,dz);
			trisTranslated[i].vertex2 = TranslateObject(trisRotated[i].vertex2,dx,dy,dz);
			trisTranslated[i].vertex3 = TranslateObject(trisRotated[i].vertex3,dx,dy,dz);

			trisProj[i].vertex1 = ProjectPoint(trisTranslated[i].vertex1);
			trisProj[i].vertex2 = ProjectPoint(trisTranslated[i].vertex2);
			trisProj[i].vertex3 = ProjectPoint(trisTranslated[i].vertex3);

		}

		//rearranging triangles according to the distance of midpoint
		int n = 0,m = 0;

//		for(n = 0; n < cube.nTriangles; n++)
//		{
//			for(m = n+1; m < cube.nTriangles; m++)
//			{
//				Vector3 midVert1 = Vector3ScalarMul(Vector3Add(Vector3Add(trisProj[n].vertex1,trisProj[n].vertex2),trisProj[n].vertex3),0.33);
//				Vector3 midVert2 = Vector3ScalarMul(Vector3Add(Vector3Add(trisProj[m].vertex1,trisProj[m].vertex2),trisProj[m].vertex3),0.33);
//
//				if(midVert1.z > midVert2.z)
//				{
//					Triangle temp = trisProj[n];
//					trisProj[n] = trisProj[m];
//					trisProj[m] = temp;
//				}
//			}
//		}

		//rendering
		int objColor = RandomColor();
		int lColor = RandomColor();
		
		for(i = 0; i < cube.nTriangles; i++)
		{
			if(viewmode == solid)
			{	
				Filltriangle(trisProj[i],GREY,defaultChar);
				DrawTriangle(trisProj[i],BLACK,defaultChar);
			}
			else if(viewmode == wireFrame)
			{				
				DrawTriangle(trisProj[i],GREEN,defaultChar);
			}
			else if(viewmode == shaded)
			{				
				//lighting calculation
				Vector3 v31 = Vector3Subtract(trisRotated[i].vertex1,trisRotated[i].vertex3);
				Vector3 v32 = Vector3Subtract(trisRotated[i].vertex2,trisRotated[i].vertex3);

				Vector3 normal = Vector3Cross(v31,v32);

				Vector3Normalize(&normal);

				Vector3 PL = Vector3Subtract(lightPosition,trisRotated[i].vertex1);
				
				Vector3Normalize(&PL);

				FLOATPOINT cosTheta = MAX(0,Vector3Dot(normal,PL));
				
				if(cosTheta >-1)
					Filltriangle(trisProj[i],DARK_GREY,defaultChar);
				if(cosTheta >0.4)
					Filltriangle(trisProj[i],GREY,defaultChar);
				if(cosTheta > 0.9)
					Filltriangle(trisProj[i],WHITE,defaultChar);
			}
			else
			{
				Vector3 v31 = Vector3Subtract(trisRotated[i].vertex1,trisRotated[i].vertex3);
				Vector3 v32 = Vector3Subtract(trisRotated[i].vertex2,trisRotated[i].vertex3);

				Vector3 normal = Vector3Cross(v31,v32);

				Vector3Normalize(&normal);

				Vector3 PL = Vector3Subtract(lightPosition,trisRotated[i].vertex1);
				
				Vector3Normalize(&PL);

				FLOATPOINT cosTheta = MAX(0,Vector3Dot(normal,PL));
				
				if(cosTheta >-1)
					Filltriangle(trisProj[i],DARK_BLUE,defaultChar);
				if(cosTheta >0.2)
					Filltriangle(trisProj[i],BLUE,defaultChar);
				if(cosTheta >0.3)
					Filltriangle(trisProj[i],CYAN,defaultChar);
				if(cosTheta >0.4)
					Filltriangle(trisProj[i],DARK_GREEN,defaultChar);
				if(cosTheta >0.5)
					Filltriangle(trisProj[i],GREEN,defaultChar);
				if(cosTheta >0.6)
					Filltriangle(trisProj[i],YELLOW,defaultChar);
				if(cosTheta >0.7)
					Filltriangle(trisProj[i],DARK_RED,defaultChar);
				if(cosTheta >0.8)
					Filltriangle(trisProj[i],MAGENTA,defaultChar);
				if(cosTheta >0.9)
					Filltriangle(trisProj[i],WHITE,defaultChar);	
			}
		}
		DrawFrame(FALSE);
	}

}
