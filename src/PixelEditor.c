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

typedef struct SPRITE
{
	Pixel *pixels;
	int nPixels;
}Sprite;

Sprite sp;
int colorIndex = 1;

double speed = 0.1;

void main()
{
	CreateConsole("Pixel Sprite Editor",80,60,12,12);
	
	double dt = 0.05,t1,t2;
	
	Cursor cursor;
	cursor.position = NewVector2(midX(),midY());
	
	int n;
	
	OnUpdate()
	{
		t1 = GetTime();
		 
		if(GetAsyncKeyState(VK_UP))
		{
			cursor.position.y -= 0.5;//1 * speed * dt;
			Sleep(200);
		}
			
		if(GetAsyncKeyState(VK_DOWN))
		{
			cursor.position.y += 0.5;//1 * speed * dt;
			Sleep(200);	
		}
			
		if(GetAsyncKeyState(VK_LEFT))
		{
			cursor.position.x -= 0.5;//1 * speed * dt;
			Sleep(200);	
		}
			
		if(GetAsyncKeyState(VK_RIGHT))
		{
			cursor.position.x += 0.5;//1 * speed * dt;
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
			sp.nPixels++;
			
			if(sp.nPixels==1)
				sp.pixels = (Pixel*)malloc(sizeof(Pixel)*sp.nPixels);
			else
				sp.pixels = (Pixel*)realloc(sp.pixels,sizeof(Pixel)*sp.nPixels);
				
			sp.pixels[sp.nPixels-1].position = cursor.position;
			sp.pixels[sp.nPixels-1].color = color[colorIndex];
			
			Sleep(200);
		}
			
		int i;
			
		for(i=0 ; i < sp.nPixels; i++)
		{
			PutPixel(sp.pixels[i].position.x,sp.pixels[i].position.y,sp.pixels[i].color,defaultChar);
		}
		
		//DrawLine(cursor.position.x,0,cursor.position.x,screenheight(),DARK_BLUE,defaultChar);
		//DrawLine(0,cursor.position.y,screenwidth()-1,cursor.position.y,DARK_RED,defaultChar);
		PutPixel(cursor.position.x,cursor.position.y,WHITE,defaultChar);
		PutPixel(0,0,color[colorIndex],defaultChar);
		DrawFrame(true);
		
		t2 = GetTime();
		dt = t2 - t1;
		
	}
}

