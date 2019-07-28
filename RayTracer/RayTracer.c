#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#include<Vector3D.h>
#include<Matrix3D.h>
#include<Geometry.h>
#include<3DG.h>

#define MAX_RANGE 100
#define MAX(X,Y)  X > Y ? X : Y
#define MIN(X,Y)  X < Y ? X : Y

#define FLOAT FLOATPOINT

int i,j;

const int width = 640*3;
const int height = 360*3;

typedef struct PIXEL_UNIT
{
	FLOAT r,g,b;
} Pixel,Color;

typedef struct SPHERE
{
	FLOAT radius;
	Vector3 position;
	Color diffuseColor;
} Sphere;

typedef struct PLANE
{
	Vector3 normal;
	Vector3 position;
	FLOAT size;
	Color diffuseColor;
}Plane;

typedef struct RAY
{
	Vector3 origin;
	Vector3 direction;
} Ray;

typedef struct CAMERA
{
	Vector3 position;
	Vector3 lookAt;
}Camera;

typedef struct LIGHT
{
	Vector3 lightPosition;
	FLOAT intensity;
	Color lightColor;
}Light;

Pixel *imageData;

Color Red = {1,0,0};
Color White = {1,1,1};
Color Green = {0,1,0};
Color Blue = {0,0,1};
Color Black = {0,0,0};

Color NewColor(FLOAT r,FLOAT g,FLOAT b)
{
	Color color;

	color.r = r;
	color.g = g;
	color.b = b;

	return color;
}

Sphere NewSphere(FLOAT radius,Vector3 position,Color diffuseColor)
{
	Sphere sphere;

	sphere.position=position;
	sphere.radius=radius;
	sphere.diffuseColor=diffuseColor;

	return sphere;
}

bool IntersectsWithSphere(Ray ray,Sphere sphere,FLOAT *t)
{
	FLOAT a = 1;
	
	Vector3 oc = Vector3Subtract(ray.origin,sphere.position);

	FLOAT b = 2* Vector3Dot(ray.direction,oc);
	
	FLOAT c	= (Vector3Mag(oc)*Vector3Mag(oc))-(sphere.radius*sphere.radius);
	
	FLOAT d	= (b*b)-(4*a*c);

	if(d>=0)
	{

		FLOAT x1 = (-b-sqrt(d)) / 2*a;
		FLOAT x2 = (-b+sqrt(d)) / 2*a;

		*t = MIN(x1,x2);

		return true;
	}

	return false;
}

bool IntersectsWithPlane(Ray ray,Plane plane,FLOAT *t)
{	
	FLOAT dn = Vector3Dot(ray.direction,plane.normal);
	
	if(dn==0)
		return false;
		
	Vector3 oa = Vector3Subtract(plane.position,ray.origin);
	
	FLOAT x = Vector3Dot(oa,plane.normal)/dn;
	
	Vector3Scale(&ray.direction,x);
				
	Vector3 P = Vector3Add(ray.origin,ray.direction);
	
	if(Vector3SqrLength(P,plane.position) <= plane.size * plane.size)
//	if(P.x >-plane.size/2 && P.x < plane.size/2 && P.z >-plane.size/2 && P.z < plane.size/2 && fabs(P.y - plane.position.y) < 0.000001)
	{
		*t = x;
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

FLOAT Clamp(FLOAT min,FLOAT max,FLOAT value)
{
	return MAX(0,MIN(1,value));
}

void WriteToImageData(Pixel *imageData,int x,int y,Color color)
{
	imageData[x+y*width].r = color.r;
	imageData[x+y*width].g = color.g;
	imageData[x+y*width].b = color.b;
}

char *ToString(int num)
{
	int n = num;
	int numdigits = 0;
	char *number;

	while (n != 0)
	{
		n = n / 10;
		numdigits++;
	}

	number = (char*)malloc(sizeof(char)*numdigits);

	itoa(num,number,10);

	return number;
}

void CreatePPMImageFile(Pixel *imageData,int frameIndex)
{
	char imageFileName[10] = "image";
	
	strcat(imageFileName,ToString(frameIndex));
	strcat(imageFileName,".ppm");
	
	FILE *imageFile = fopen(imageFileName,"wb");
	fprintf(imageFile,"P6 %d %d 255 ",width,height);

	int i;

	for(i=0; i<height*width; i++)
	{
		fprintf(imageFile,"%c",(char) (255.0*imageData[i].r));
		fprintf(imageFile,"%c",(char) (255.0*imageData[i].g));
		fprintf(imageFile,"%c",(char) (255.0*imageData[i].b));
	}

	fclose(imageFile);
}

Mat4x4 CameraToWorld(Camera cam)
{
	Vector3 up = {0,1,0};
	
	Mat4x4 mat;
	
	Vector3 forwardVect = Vector3Subtract(cam.lookAt,cam.position);
	Vector3Normalize(&forwardVect);
	Vector3 rightVect = Vector3Cross(up,forwardVect);
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

Color CastRay(Ray ray,Sphere sphere,Plane plane,Light light,int depth)
{
	Color illumColor;
	FLOAT t;
	
	if(depth>4)
	{
		illumColor = NewColor(0.2,0.92,0.98);
		return illumColor;
	}
		
	
	if(IntersectsWithSphere(ray,sphere,&t))
	{		
		Ray reflected;
		
		Vector3Scale(&ray.direction,t);
		
		Vector3 P = Vector3Add(ray.origin,ray.direction);
		
		Vector3 N = Vector3Subtract(P,sphere.position);
		Vector3Normalize(&N);
		
		Vector3Normalize(&ray.direction);
		
		reflected.origin = P;
		reflected.direction = ReflectDir(ray.direction,N);
		
		Color reflectColor = CastRay(reflected,sphere,plane,light,depth+1);
		
		reflectColor.r*=0.9;
		reflectColor.g*=0.9;
		reflectColor.b*=0.9;
		
		Vector3 PL = Vector3Subtract(light.lightPosition,P);
		Vector3Normalize(&PL);
		
		FLOAT ki = MAX(0,Vector3Dot(N,PL));
						
		illumColor.r = ((reflectColor.r+ki*light.lightColor.r*light.intensity*sphere.diffuseColor.r)/M_PI);
		illumColor.g = ((reflectColor.g+ki*light.lightColor.g*light.intensity*sphere.diffuseColor.g)/M_PI);
		illumColor.b = ((reflectColor.b+ki*light.lightColor.b*light.intensity*sphere.diffuseColor.b)/M_PI);
	}
	else if(IntersectsWithPlane(ray,plane,&t))
	{
		Ray reflected;
		reflected.direction = ReflectDir(ray.direction,plane.normal);
		Vector3Normalize(&reflected.direction);
									
		Vector3Scale(&ray.direction,t);
		
		Vector3 P = Vector3Add(ray.origin,ray.direction);
		
		reflected.origin = P;
		
		
		Color reflectColor; //= CastRay(reflected,sphere,plane,light,2);
		
		reflectColor.r*=0;
		reflectColor.g*=0;
		reflectColor.b*=0;
		
		if(1)
		{
			bool xblack = false,zblack = false;
			
			Color c = plane.diffuseColor;
			
			if((P.x>-20 && P.x<-10) || (P.x>0 && P.x<10))
			{
				plane.diffuseColor = White; xblack=true;
			}
			if((P.z>-20 && P.z<-10) || (P.z>0 && P.z<10))
			{
				plane.diffuseColor = White; zblack=true;
			}
			if(xblack && zblack)
			{
				plane.diffuseColor = c;
			}
		
			Vector3 PL = Vector3Subtract(light.lightPosition,P);
			
			Vector3Normalize(&PL);
							
			FLOAT ki = MAX(0,Vector3Dot(plane.normal,PL));
			
			illumColor.r = ((reflectColor.r+ki*light.lightColor.r*light.intensity*plane.diffuseColor.r)/M_PI);
			illumColor.g = ((reflectColor.g+ki*light.lightColor.g*light.intensity*plane.diffuseColor.g)/M_PI);
			illumColor.b = ((reflectColor.b+ki*light.lightColor.b*light.intensity*plane.diffuseColor.b)/M_PI);
		}
	}
	else
	{
		illumColor = NewColor(0.2,0.92,0.98);
	}
	
	return illumColor;
}

void main()
{
	imageData = (Pixel*)malloc(width*height*sizeof(Pixel));

	Sphere sphere = NewSphere(5,NewVector3(0,0,0),Blue);
	
	Plane plane;
	plane.position = NewVector3(0,-5,0);
	plane.normal = NewVector3(0,1,0);
	plane.size = 40;
	plane.diffuseColor = Green;

	FLOAT FOV = M_PI/3;
	
	//Light
	Light mainLight;
	mainLight.lightPosition = NewVector3(0,6,0);
	mainLight.lightColor = White;
	mainLight.intensity = 2;
	
	//Camera
	Camera cam;
	cam.position = NewVector3(0,6,50);
	cam.lookAt = NewVector3(0,0,0);
	
	Color ambientColor = NewColor(0.05,0.05,0.05);
	
	int frame=0;
	
	for(frame=0; frame<1; frame++)
	{		
		Mat4x4 camToWorld = CameraToWorld(cam);
		
		for(j=0; j<height; j++)
		{
			for(i=0; i<width; i++)
			{
				FLOAT x = (2.0*(i + 0.5)/width  - 1) * tan(FOV/2.0)*width/(FLOAT)height;
				FLOAT y = -(2.0*(j + 0.5)/height - 1) * tan(FOV/2.0);
				
				Color illumColor;
				
				Vector3 origin = NewVector3(0,0,0);
				Vector3 cImagePlane = NewVector3(x,y,-1);
				
				Ray ray;
				ray.origin = matmul(camToWorld,origin);
				Vector3 wImagePLane = matmul(camToWorld,cImagePlane);			
				ray.direction = Vector3Subtract(wImagePLane,ray.origin);			
				Vector3Normalize(&ray.direction);
				
				illumColor = CastRay(ray,sphere,plane,mainLight,0);
				
				illumColor.r+=ambientColor.r;
				illumColor.r+=ambientColor.g;
				illumColor.r+=ambientColor.b;
				
				WriteToImageData(imageData,i,j,illumColor);	
			}
		}
	
	CreatePPMImageFile(imageData,frame);
	printf("Frame : %d",frame);
	
	cam.position.x+=0.5;
		
	}
	

	free(imageData);
}

