#include "2DGC.h"

void main()
{

	CreateConsole("Analog Clock",200,200,2,2);
	SetBGcolor(WHITE);
	int x=100,y=5;
	int ang=1;
		
	OnUpdate()
	{
		DrawLine(0,0,x,y,GREEN);
		//DrawCircle(100/2,100/2,40,BLUE);
		
		//UpdateRot(ang,&x,&y);

		DrawFrame(TRUE);
		//ang++;
		sleep(1);
	}
}
