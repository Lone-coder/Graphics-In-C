#include "Headers/2DGC.h"
#include "Headers/Vector2D.h"
#include "Headers/PixelText.h"

typedef struct CURSOR
{
	Vector2 position;
}Cursor;

typedef struct PIXEL
{
	Vector2 position;
	int color;
}Pixel;

Pixel *sprite;
int nPixels = 0;
int colorIndex = 0;

void main()
{
	CreateConsole("Pixel Sprite Editor",40,30,16,16);
	
	double dt = 0.05,t1,t2;
	
	Cursor c;
	c.position = NewVector2(midX(),midY());
	
	OnUpdate()
	{
		t1 = GetTime();
		 
		if(GetAsyncKeyState(VK_UP))
		{
			c.position.y-=1;
			Sleep(200);
		}
			
		if(GetAsyncKeyState(VK_DOWN))
		{
			c.position.y+=1;
			Sleep(200);	
		}
			
		if(GetAsyncKeyState(VK_LEFT))
		{
			c.position.x-=1;
			Sleep(200);	
		}
			
		if(GetAsyncKeyState(VK_RIGHT))
		{
			c.position.x+=1;
			Sleep(200);
		}
		
		if(GetAsyncKeyState(VK_TAB))
		{
			colorIndex++;
			if(colorIndex > 15)
				colorIndex = 0;
			
			Sleep(200);	
		}
		
		if(GetAsyncKeyState(VK_SPACE))
		{
			nPixels++;
			
			if(nPixels==1)
				sprite = (Pixel*)malloc(sizeof(Pixel)*nPixels);
			else
				sprite = (Pixel*)realloc(sprite,sizeof(Pixel)*nPixels);
				
			sprite[nPixels-1].position = c.position;
			sprite[nPixels-1].color = color[colorIndex];
			
			Sleep(200);
		}
			
		int i;
			
		for(i=0 ; i < nPixels; i++)
		{
			PutPixel(sprite[i].position.x,sprite[i].position.y,sprite[i].color);
		}
		
		PutPixel(c.position.x,c.position.y,WHITE);
		PutPixel(0,0,color[colorIndex]);
		DrawFrame(true);
		
		t2 = GetTime();
		dt = t2 - t1;
		
	}
}

