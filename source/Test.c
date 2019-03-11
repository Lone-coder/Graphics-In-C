#include "2DGC.h"


void main()
{
	OnStart()
	{
		CreateConsole("Logic Gate Simulator",200,150,1,1);
		SetBGcolor(BG_BLACK);
		
	}
	
	OnUpdate()
	{		
		fill(50,40,80,60,FG_BLUE);
		FillCircle(50,50,10,FG_BLACK);
		FillCircle(80,50,10,FG_BLUE);
		
		fill(50,90,80,110,FG_GREEN);
		FillCircle(80,100,10,FG_GREEN);
		
		FillCircle(150,100,1,FG_BLUE);
		
		DrawFrame(TRUE);
	}
}
