#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#include "Vector3D.h"

#define MAX_RANGE 100
#define MAX(X,Y)  X > Y ? X : Y
#define MIN(X,Y)  X < Y ? X : Y

int i,j;
const int width=1280;
const int height=720;

typedef struct PIXEL_COLOR
{
	char r,g,b;
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

Pixel *imageData;

Color Red= {255,0,0};
Color White= {255,255,255};
Color Green= {0,255,0};
Color Blue= {0,0,255};
Color Black= {0,0,0};

Color NewColor(char r,char g,char b)
{
	Color color;

	color.r=r;
	color.g=g;
	color.b=b;

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
	FLOAT a=1;
	
	Vector3 oc=Vector3Subtract(ray.origin,sphere.position);

	FLOAT b=2* Vector3Dot(ray.direction,oc);
	
	FLOAT c=(Vector3Mag(oc)*Vector3Mag(oc))-(sphere.radius*sphere.radius);
	
	FLOAT d= (b*b)-(4*a*c);

	if(d>=0)
	{

		FLOAT x1= (-b-sqrt(d))/2*a;
		FLOAT x2= (-b+sqrt(d))/2*a;

		*t=MIN(x1,x2);

		return true;
	}

	return false;
}

bool IntersectsWithPlane(Ray ray,Plane plane,FLOAT *t)
{
	Vector3 oa=Vector3Subtract(plane.position,ray.origin);
	
	FLOAT dn=Vector3Dot(ray.direction,plane.normal);
	
	FLOAT x=Vector3Dot(oa,plane.normal)/dn;
	
	if(x>0 && x<50)
	{
		*t=x;
		return true;
	}
	else
		return false;
}

void WriteToImageData(Pixel *imageData,int x,int y,Color color)
{
	imageData[x+y*width].r=color.r;
	imageData[x+y*width].g=color.g;
	imageData[x+y*width].b=color.b;
}

void CreatePPMImageFile(Pixel *imageData)
{
	FILE *imageFile=fopen("image.ppm","wb");
	fprintf(imageFile,"P6 %d %d 255 ",width,height);

	int i,j;

	for(j=0; j<height; j++)
	{
		for(i=0; i<width; i++)
		{
			fprintf(imageFile,"%c%c%c",(char)imageData[i+j*width].r,(char)imageData[i+j*width].g,(char)imageData[i+j*width].b);
		}
	}

	fclose(imageFile);
}

void main()
{
	imageData=(Pixel*)malloc(width*height*sizeof(Pixel));

	Sphere sphere=NewSphere(10,NewVector3(0,0,50),Red);
	
	Plane plane;
	plane.position=NewVector3(0,-1,50);
	plane.normal=NewVector3(0,1,0);
	plane.size=30;
	plane.diffuseColor=White;

	int FOV=M_PI/2;

	Vector3 lightPosition= {30,50,0};
	
	FLOAT lightIntensity=1e6;
	Color lightColor=White;
	
	Color AmbientColor=NewColor(sphere.diffuseColor.r*0.8,sphere.diffuseColor.g*0.8,sphere.diffuseColor.g*0.8);
	
	


	for(j=0; j<height; j++)
	{
		for(i=0; i<width; i++)
		{

			FLOAT x =  (2*(i + 0.5)/width  - 1)*tan(FOV/2.0)*width/(FLOAT)height;
			FLOAT y = -(2*(j + 0.5)/height - 1)*tan(FOV/2.0);
			FLOAT z=1;

			FLOAT t=0;
			FLOAT distance;
			
			Ray ray;

			ray.origin=NewVector3(x,y,0);

			ray.direction=NewVector3(x,y,z);

			Vector3Normalize(&ray.direction);
			
			if(IntersectsWithSphere(ray,sphere,&t))
			{
				distance=Vector3Length(sphere.position,lightPosition);
				
				Vector3Scale(&ray.direction,t);
				
				Vector3 p=Vector3Add(ray.origin,ray.direction);
				
				Vector3 normal=Vector3Subtract(p,sphere.position);
				Vector3Normalize(&normal);
				
				Vector3 lP=Vector3Subtract(lightPosition,p);
				Vector3Normalize(&lP);
								
				FLOAT ki=MAX(0,Vector3Dot(normal,lP));
								
				Color illumColor;
								
				illumColor.r=(char)((AmbientColor.r)+(ki*lightColor.r*lightIntensity*sphere.diffuseColor.r)/(distance*distance));
				illumColor.g=(char)((AmbientColor.g)+(ki*lightColor.g*lightIntensity*sphere.diffuseColor.g)/(distance*distance));
				illumColor.b=(char)((AmbientColor.b)+(ki*lightColor.b*lightIntensity*sphere.diffuseColor.b)/(distance*distance));

				WriteToImageData(imageData,i,j,illumColor);
			}
			else if(IntersectsWithPlane(ray,plane,&t))
			{				
				distance=Vector3Length(plane.position,lightPosition);
				
				Vector3Scale(&ray.direction,t);
				
				Vector3 p=Vector3Add(ray.origin,ray.direction);
				
				Ray shadowRay;
				
				shadowRay.origin=p;
				shadowRay.direction=Vector3Subtract(p,lightPosition);
				Vector3Normalize(&shadowRay.direction);
				
				if(IntersectsWithSphere(shadowRay,sphere,&t))
				{
					WriteToImageData(imageData,i,j,Black);
				}
				else
				{
					Vector3 lP=Vector3Subtract(lightPosition,p);
				
					Vector3Normalize(&lP);
								
					FLOAT ki=MAX(0,Vector3Dot(plane.normal,lP));
								
					Color illumColor;
				
					illumColor.r=(char)((AmbientColor.r)+(ki*lightColor.r*lightIntensity*plane.diffuseColor.r)/(distance*distance));
					illumColor.g=(char)((AmbientColor.g)+(ki*lightColor.g*lightIntensity*plane.diffuseColor.g)/(distance*distance));
					illumColor.b=(char)((AmbientColor.b)+(ki*lightColor.b*lightIntensity*plane.diffuseColor.b)/(distance*distance));
				
					WriteToImageData(imageData,i,j,illumColor);
				}
				
			}
			else
			{
				WriteToImageData(imageData,i,j,NewColor(160,220,255));
			}
				

		}
	}

	CreatePPMImageFile(imageData);

	free(imageData);


}

