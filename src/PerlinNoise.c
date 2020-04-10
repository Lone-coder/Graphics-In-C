#include "Headers/2DGC.h"
#include "Headers/Vector2D.h"

Vector2 gradientVectors[4] = { {1,1},{1,-1},{-1,1},{-1,-1} };

float LinearInterpolate(float a,float b,float offset)
{
	float value;
	
	value = (a * offset) + (b-a);
	
	return value;
}

float PerlinNoise2D(float x,float y,int xSize,int ySize)
{
	float perlinValue = 0;
	
	Vector2 points[4];
	Vector2 gradients[4];
	Vector2 direction[4];
	
	Vector2 localPosition;
	
	float dotProducts[4];
	
	int i;
	int xMin = x;
	int xMax = x;
	int yMin = y;
	int yMax = y;
	
	//find the four points 
	while(1)
	{		
		if(xMin % xSize == 0)
			break;
			
		xMin--;
	}
	
	while(1)
	{
		if(xMax % xSize == 0)
			break;
		
		xMax++;
	}
	
	while(1)
	{		
		if(yMin % ySize == 0)
			break;
			
		yMin--;
	}
	
	while(1)
	{		
		if(yMax % ySize == 0)
			break;
			
		yMax++;
	}
	
	points[0] = NewVector2(xMin,yMin);
	points[1] = NewVector2(xMax,yMin);
	points[2] = NewVector2(xMin,yMax);
	points[3] = NewVector2(xMax,yMax);
	
	//local position
	localPosition.x = x - points[0].x;
	localPosition.y = y - points[0].y;
	
	//set the gradients
	for(i=0; i<4; i++)
	{
		gradients[i] = gradientVectors[rand()%4];
	}
	
	//find the distance vectors
	for(i=0; i<4; i++)
	{		
		direction[i] = Vector2Subtract(NewVector2(x,y),points[i]);
		Vector2Normalize(direction + i);
	}
	
	//calculate the dot product
	for(i=0; i<4; i++)
	{
		dotProducts[i] = Vector2Dot(gradients[i],direction[i]);
	}
	
	//linearly interolate the dot product values
	float AB = LinearInterpolate(dotProducts[0],dotProducts[1],localPosition.x);
	float CD = LinearInterpolate(dotProducts[2],dotProducts[3],localPosition.x);
	
	perlinValue = LinearInterpolate(AB,CD,localPosition.y);
	
	return perlinValue;
}


void main()
{

	int i,j;
	
	CreateConsole("PerlinNoise",400,300,2,2);
	
	OnUpdate()
	{
	
	for(i=0; i<400; i++)
	{
		for(j=0; j<300; j++)
		{
			float cosTheta = PerlinNoise2D(i,j,5,5)/10;
			
			if(cosTheta >-1)
				PutPixel(i,j,DARK_BLUE);
			if(cosTheta >0.2)
				PutPixel(i,j,BLUE);
			if(cosTheta >0.3)
				PutPixel(i,j,CYAN);
			if(cosTheta >0.4)
				PutPixel(i,j,DARK_GREEN);
			if(cosTheta >0.5)
				PutPixel(i,j,GREEN);
			if(cosTheta >0.6)
				PutPixel(i,j,YELLOW);
			if(cosTheta >0.7)
				PutPixel(i,j,DARK_RED);
			if(cosTheta >0.8)
				PutPixel(i,j,MAGENTA);
			if(cosTheta >0.9)
				PutPixel(i,j,WHITE);
				}
			}
	
		DrawFrame(TRUE);
	}
	
	
	
	
		
}

