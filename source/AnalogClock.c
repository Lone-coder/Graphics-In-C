#include "2DGC.h"

void main()
{

	CreateConsole("Analog Clock",100,80,4,3);
	SetBGcolor(BG_WHITE);
	int x=100/2,y=10;
	int ang=6;
		
	OnUpdate()
	{
		DrawLine(100/2,80/2,x,y,FG_GREEN);
		DrawCircle(100/2,80/2,35,FG_BLUE);
		x=x-50;y=y-40;
		UpdateRot(ang,&x,&y);
		x=x+50;y=y+40;
		DrawFrame(TRUE);
		ang++;
		sleep(1);
	}
}
