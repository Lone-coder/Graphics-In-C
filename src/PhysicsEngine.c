#include "Headers\2DGC.h"
#include "Headers\PixelText.h"
#include "Headers\Vector2D.h"

typedef struct BALL
{
	int radius;
	int color;
	Vector2 position;
	Vector2 velocity;
	int mass;

} Ball;

Ball *balls;
int nball=0;

Vector2 gravity={0,10};

LARGE_INTEGER t1, t2;

Createball(int ox,int oy,int radius,int color)
{
	nball++;

	if(nball==1)
		balls = (Ball*)malloc(sizeof(Ball)*nball);
	else
		balls = (Ball*)realloc(balls,sizeof(Ball)*nball);

	balls[nball-1].position.x = ox;
	balls[nball-1].position.y = oy;
	balls[nball-1].radius = radius;
	balls[nball-1].color = color;
	balls[nball-1].velocity.x = 0;
	balls[nball-1].velocity.y = 0;
}

DrawBall()
{
	int i=0;

	if(nball!=0)
	{
		for(i=0; i<nball; i++)
		{
			DrawCircle(balls[i].position.x, balls[i].position.y, balls[i].radius, balls[i].color,defaultChar);	
		}
	}
}

void main()
{
	CreateConsole("Physics Simulation",400,300,2,2);
	SetBgColor(BLACK);
	
	int i = 0;
	int j = 0;

	OnUpdate()
	{
		QueryPerformanceCounter(&t1);
		
		PrintString("PRESS SPACEBAR",60,12,WHITE);
		
		FillRectArea(midX(),screenheight()-10,399,10,WHITE,defaultChar);
		
		if(GetAsyncKeyState(VK_SPACE) && 0x8000)
		{
			if(nball < 20)
				Createball(random(10,screenwidth()-30),random(20,screenheight()-50),random(2,8),WHITE);
		}
		
//		if(GetAsyncKeyState(VK_RIGHT) && 0x8000)
//		{
//			for(i = 0; i < nball; i++)
//			{
//				balls[i].velocity.x += 2 * deltaTime;
//				balls[i].position.x += balls[i].velocity.x * deltaTime;
//
//			}
//		}
//		
//		if(GetAsyncKeyState(VK_LEFT) && 0x8000)
//		{
//			for(i = 0; i < nball; i++)
//			{
//				balls[i].velocity.x += -2 * deltaTime;
//				balls[i].position.x += balls[i].velocity.x * deltaTime;
//
//			}
//		}

		PrintString(ToString(nball),150,12,WHITE);

		for(i = 0; i < nball; i++)
		{
			balls[i].velocity.y += gravity.y * deltaTime;
			balls[i].position.y += balls[i].velocity.y * deltaTime;
			
			//Coliision detection with platform
			if(balls[i].radius + balls[i].position.y >= screenheight()-20)
			{
				balls[i].velocity.y = -(balls[i].velocity.y * 1);
			}

		}
		
		
		//Collision handling
//		for(i=0;i<nball;i++)
//		{
//			for(j=i+1;j<nball;j++)
//			{
//				if(	(	(balls[i].position.x-balls[j].position.x)*(balls[i].position.x-balls[j].position.x)	
//					+	(balls[i].position.y-balls[j].position.y)*(balls[i].position.y-balls[j].position.y)	) 
//					< (balls[i].radius+balls[j].radius)*(balls[i].radius+balls[j].radius)	)
//					{
//						balls[i].color = RandomColor();
//						balls[j].color = RandomColor();
//						balls[i].velocity.y = -balls[i].velocity.y;
//						balls[i].position.y += balls[i].velocity.y * deltaTime;
//						balls[j].velocity.y = -balls[j].velocity.y;
//						balls[j].position.y += balls[j].velocity.y * deltaTime;
//					}
//			}
//		}
		
		
		QueryPerformanceCounter(&t2);

		deltaTime = (t2.QuadPart - t1.QuadPart)/1000.0;

		DrawBall();
		DrawFrame(true);

	}
}
