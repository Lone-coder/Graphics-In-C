#include "ConsoleGUI.h"

typedef struct BALL
{
	int ox,oy;
	int radius;
	int color;
	float dy,dv;
	bool collided;
	
}Ball;

Ball *balls;
int nball=0;
float gravity =30;	
float start,end;
float FPS;

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
	balls[nball-1].dy=0;
	balls[nball-1].dv=0;
	balls[nball-1].collided=false;
}

DrawBall()
{
	int i=0;
	
	if(nball!=0)
	{
		for(i=0;i<nball;i++)
		{
			DrawCircle(balls[i].ox,balls[i].oy,balls[i].radius,balls[i].color);
		}		
	}
}

void main()
{
	CreateConsole("Physics Simulation",300,200,2,2);
	SetBGcolor(BLACK);
	
	OnUpdate()
	{
		//start=GetTime();
		
		printString(toString((int)FPS),3,4,WHITE);
			
		if(GetAsyncKeyState(VK_SPACE) & 0x8000)
		{
			Createball(random(10,screenwidth()-30),random(10,screenheight()-30),10,randcolor());	
		}
		
		int i=0;
		int j=0;
		
		
		for(i=0;i<nball;i++)
		{			
			if(!balls[i].collided)
			{
				balls[i].dv+=gravity*deltatime;
				balls[i].dy+=balls[i].dv*deltatime;
				balls[i].oy+=balls[i].dy*deltatime;	
			}
		
			if(balls[i].radius+balls[i].oy>screenheight()-20)
			{
				balls[i].collided=true;		
			}
		
		}
		
		
		for(i=0;i<nball;i++)
		{
			for(j=i+1;j<nball;j++)
			{
				if( ((balls[i].ox-balls[j].ox)*(balls[i].ox-balls[j].ox) + (balls[i].oy-balls[j].oy)*(balls[i].oy-balls[j].oy) 
				  ) < ((balls[i].radius+balls[j].radius) ))
				  {
				  	printString("COLLISION",150,4,WHITE);
				  }
			}
		}
		
		DrawBall();
		DrawFrame(true);
			
		end=GetTime();
			
		deltatime=end-start;
		deltatime/=1000;
		FPS=1/deltatime;
	}
}
