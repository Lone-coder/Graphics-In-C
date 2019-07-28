#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#include<Vector3D.h>
#include<Matrix3D.h>
#include<Geometry.h>
#include<3DG.h>

#define MAX_RANGE 1e6
#define MAX(X,Y)  X > Y ? X : Y
#define MIN(X,Y)  X < Y ? X : Y

#define FLOAT FLOATPOINT

const int width = 640;
const int height = 360;

typedef struct PIXEL_UNIT
{
	FLOAT r,g,b;
} Pixel,Color;

typedef struct RAY
{
	Vector3 origin;
	Vector3 direction;
} Ray;

Pixel *imageData;

typedef struct CAMERA
{
	Vector3 position;
	Vector3 lookAt;
}Camera;

Color Red = {1,0,0};
Color White = {1,1,1};
Color Green = {0,1,0};
Color Blue = {0,0,1};
Color Black = {0,0,0};

Color NewColor(char r,char g,char b)
{
	Color color;

	color.r = r;
	color.g = g;
	color.b = b;

	return color;
}

Mat4x4 CameraToWorld(Camera cam)
{
	Vector3 up = {0,1,0};
	
	Mat4x4 mat;
	
	Vector3 forwardVect = Vector3Subtract(cam.lookAt,cam.position);
	Vector3Normalize(&forwardVect);
	Vector3 rightVect = Vector3Cross(forwardVect,up);
	Vector3Normalize(&rightVect);
	Vector3 upVect = Vector3Cross(forwardVect,rightVect);
	Vector3Normalize(&upVect);
	
	mat.mat[0][0] = rightVect.x;
	mat.mat[0][1] =	upVect.x;
	mat.mat[0][2] =	forwardVect.x;
	mat.mat[0][3] = cam.position.x;
	
	mat.mat[1][0] = rightVect.y;
	mat.mat[1][1] =	upVect.y;
	mat.mat[1][2] =	forwardVect.y;
	mat.mat[1][3] = cam.position.y;
	
	mat.mat[2][0] = rightVect.z;
	mat.mat[2][1] =	upVect.z;
	mat.mat[2][2] =	forwardVect.z;
	mat.mat[2][3] = cam.position.z;
	
	mat.mat[3][0] = rightVect.w;
	mat.mat[3][1] =	upVect.w;
	mat.mat[3][2] =	forwardVect.w;
	mat.mat[3][3] = cam.position.w;
	
	return mat;
}

void WriteToImageData(Pixel *imageData,int x,int y,Color color)
{
	imageData[x+y*width].r = color.r;
	imageData[x+y*width].g = color.g;
	imageData[x+y*width].b = color.b;
}

void CreatePPMImageFile(Pixel *imageData)
{
	FILE *imageFile = fopen("image2.ppm","w");
	fprintf(imageFile,"P6 %d %d 255 ",width,height);

	int i;

	for(i=0; i<width*height; i++)
	{
		fprintf(imageFile,"%c",(char)(255*imageData[i].r));
		fprintf(imageFile,"%c",(char)(255*imageData[i].g));
		fprintf(imageFile,"%c",(char)(255*imageData[i].b));
	}

	fclose(imageFile);
}

bool IntersectWithTriangle(Ray ray,Triangle tri,Vector3 N,FLOAT *x)
{
	FLOAT DN = Vector3Dot(N,ray.direction); 
	
	if(DN==0)
		return false;
		
	FLOAT ON = Vector3Dot(N,ray.origin);
	
	FLOAT d = Vector3Dot(N,tri.vertex1);
	
	FLOAT t = (d+ON)/DN;
	
	if(t<0.0001)
		return false;
	
	Vector3Scale(&ray.direction,t);
					
	Vector3 P = Vector3Add(ray.origin,ray.direction);
	
	Vector3 edge1 = Vector3Subtract(tri.vertex2,tri.vertex1);
	Vector3 edge2 = Vector3Subtract(tri.vertex3,tri.vertex2);
	Vector3 edge3 = Vector3Subtract(tri.vertex1,tri.vertex3);
	
	Vector3 C1 = Vector3Subtract(P,tri.vertex1);
	Vector3 C2 = Vector3Subtract(P,tri.vertex2);
	Vector3 C3 = Vector3Subtract(P,tri.vertex3);
	
	if( Vector3Dot(N,Vector3Cross(edge1,C1)) >0 &&
		Vector3Dot(N,Vector3Cross(edge2,C2)) >0 &&
		Vector3Dot(N,Vector3Cross(edge3,C3)) >0)
		{
			*x = t;
			return true;
		}
	else
		return false;
}

bool IntersectWithTriangle2(Ray ray,Triangle tri,Vector3 N,FLOAT *x)
{
	const float epsilon = 0.0001;
	
	Vector3 v1v2 = Vector3Subtract(tri.vertex2,tri.vertex1);
	Vector3 v1v3 = Vector3Subtract(tri.vertex3,tri.vertex1);
	
	Vector3 pVec = Vector3Cross(ray.direction,v1v3);
	FLOAT det = Vector3Dot(v1v2,pVec);
	
	if(det > -epsilon && det < epsilon)
		return false;
		
	FLOAT invDet = 1/det;
	
	Vector3 tVec = Vector3Subtract(ray.origin,tri.vertex1);
	
	FLOAT u = Vector3Dot(pVec,tVec) * invDet;
	
	if(u < 0.0 || u > 1.0)
		return false;
	
	Vector3 qVec = Vector3Cross(tVec,v1v2);
	FLOAT v = Vector3Dot(ray.direction,qVec) * invDet;
	
	if(v < 0.0 || u+v > 1.0)
		return false;

	*x = Vector3Dot(v1v3,qVec) * invDet;
	
	if(*x > epsilon)
	{
		return true;
	}
	else
		return false;
	
}

Vector3 ReflectDir(Vector3 I,Vector3 N)
{
	FLOAT dotIN =  2* Vector3Dot(I,N);
	Vector3Scale(&N,dotIN);
	
	return Vector3Subtract(I,N);
}

void main()
{
	int i,j;
	
	float totalPixel = width * height;
	float pixelCount;
	
	imageData = (Pixel*)malloc(width*height*sizeof(Pixel));

	FLOAT FOV = M_PI/3;

	Vector3 lightPosition = {10,0,10};
	
	FLOAT lightIntensity = 3;
	Color lightColor = White;
	
	Color diffuseColor = Red;
	
	Object sphere = LoadOBJFile("man.obj");
//	TranslateObject(&sphere,0,0,0);
	
	Camera cam;
	cam.position = NewVector3(0,0,5);
	cam.lookAt = NewVector3(0,0,0);
	
	Mat4x4 camToWorld = CameraToWorld(cam);
	
	for(j=0; j<height; j++)
	{
		for(i=0; i<width; i++)
		{			
			//printf("Percentage: %f\n",pixelCount/totalPixel * 100.0);
			
			FLOAT x = (2.0*(i + 0.5)/width  - 1) * tan(FOV/2.0)*width/(FLOAT)height;
			FLOAT y = -(2.0*(j + 0.5)/height - 1) * tan(FOV/2.0);
			
			FLOAT et = MAX_RANGE;
			FLOAT t = et;
			
			Vector3 origin = NewVector3(0,0,0);
			Vector3 cImagePlane = NewVector3(x,y,-1);
			
			Ray ray;
			ray.origin = matmul(camToWorld,origin);
			Vector3 wImagePLane = matmul(camToWorld,cImagePlane);
			
			ray.direction = Vector3Subtract(wImagePLane,ray.origin);
			
			Vector3Normalize(&ray.direction);
			
			int k;
			
			Color illumColor;
			
			Vector3 N;
			
			for(k=0; k<sphere.nTriangles; k++)
			{	
				Vector3 n = sphere.normals[k];
				
				if(IntersectWithTriangle(ray,sphere.triangles[k],n,&t) && t < et)
				{	
					et = t;
					N = n;					
				}
			}
			
			if(t<MAX_RANGE)
			{
				Vector3Scale(&ray.direction,t);
						
				Vector3 P = Vector3Add(ray.origin,ray.direction);
				
				Vector3 lightDir = Vector3Subtract(lightPosition,P);
				Vector3Normalize(&lightDir);
				
				FLOAT ki = MAX(0,Vector3Dot(N,lightDir));
								
				illumColor.r = ((ki*lightColor.r*lightIntensity*diffuseColor.r)/M_PI);
				illumColor.g = ((ki*lightColor.g*lightIntensity*diffuseColor.g)/M_PI);
				illumColor.b = ((ki*lightColor.b*lightIntensity*diffuseColor.b)/M_PI);	
			}
			else
			{
				illumColor = NewColor(0,0,0);
			}
			
			WriteToImageData(imageData,i,j,illumColor);		
		}
	}

	CreatePPMImageFile(imageData);

	free(imageData);

}

