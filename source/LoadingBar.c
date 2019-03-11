#include "ConsoleGUI.h"

void main()
{
	int value;

	CreateConsole("Loading Bar Demo",100,80,5,5);
	SetBGcolor(BG_BLACK);
	
	LoadingBar lb;
	
	lb.bordercolor=FG_WHITE;
	lb.fillcolor=FG_GREEN;
	lb.ox=screenwidth()/2;
	lb.oy=screenheight()/2;
	lb.width=screenwidth()/2;
	lb.height=10;
	lb.loadvalue=0;
	
	OnUpdate()
	{
		MakeLoadingBar(&lb);

		DrawFrame(TRUE);
		
		if(lb.loadvalue<=lb.endvalue)
			lb.loadvalue++;
		
		usleep(10000);
	}
}
