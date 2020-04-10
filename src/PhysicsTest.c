#include "Headers\ConsoleGUI.h"

typedef struct BALL
{
	float ox,oy;
	int radius;
	int color;
	float dv;
	bool collided;
	int mass;

} Ball;

Ball *balls;
int nball=0;
float gravity =30;
float start,end;
int nCollisions;
LARGE_INTEGER t1, t2;

Createball(int ox,int oy,int radius,int color)
{
	nball++;

	if(nball==1)
		balls=(Ball*)malloc(sizeof(Ball)*nball);
	else
		balls=(Ball*)realloc(balls,sizeof(Ball)*nball);

	balls[nball-1].ox=ox;
	balls[nball-1].oy=oy;
	balls[nball-1].radius=radius;
	balls[nball-1].color=color;
	balls[nball-1].dv=0;
	balls[nball-1].collided=false;
}

DrawBall()
{
	int i=0;

	if(nball!=0)
	{
		for(i=0; i<nball; i++)
		{
			DrawCircle(balls[i].ox, balls[i].oy, balls[i].radius, balls[i].color);
		}
	}
}

void main()
{
	CreateConsole("Physics Simulation",300,200,2,2);
	SetBgColor(BLACK);


	QueryPerformanceFrequency(&freq);

	OnUpdate()
	{
		QueryPerformanceCounter(&t1);

		if(GetAsyncKeyState(VK_SPACE) & 0x8000)
		{
			if(nball<100)
				Createball(random(10,screenwidth()-30),random(20,screenheight()-50),random(1,5),randcolor());
		}

		PrintString(ToString(nball),150,12,WHITE);

		int i=0;
		int j=0;

		for(i=0; i<nball; i++)
		{
			if(!balls[i].collided)
			{
				balls[i].dv+=gravity*deltaTime;
				balls[i].oy+=balls[i].dv*deltaTime;
			}

			if(balls[i].radius+balls[i].oy>screenheight()-20)
			{
				balls[i].dv=-balls[i].dv;
				balls[i].oy+=balls[i].dv*deltaTime;
			}

		}

		QueryPerformanceCounter(&t2);

		deltaTime = (t2.QuadPart - t1.QuadPart)/500.0;

		DrawBall();
		DrawFrame(true);


	}
}
