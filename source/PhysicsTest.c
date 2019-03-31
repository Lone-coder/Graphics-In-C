#include "ConsoleGUI.h"

void main()
{
	CreateConsole("Physics Test",200,200,2,2);
	SetBGcolor(BLACK);
	int radius=20;
	int dx,dy;
	
	OnUpdate()
	{
		//DrawCircle(random(0,screenwidth()),random(0,screenheight()),random(5,20),randcolor());
		DrawCircle(screenwidth()/2+dx,10+dy,radius,WHITE);
		
		DrawRect(100,160,160,10,WHITE);

		if(GetAsyncKeyState(VK_LEFT))
			dx-=2;
		if(GetAsyncKeyState(VK_RIGHT))
			dx+=2;
		if(GetAsyncKeyState(VK_UP))
			dy-=2;
		if(GetAsyncKeyState(VK_DOWN))
			dy+=2;
			
		DrawFrame(TRUE);
	}
}
