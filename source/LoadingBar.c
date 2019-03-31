#include "ConsoleGUI.h"

void main()
{
	int value;

	CreateConsole("Loading Bar Demo",200,100,2,2);
	SetBGcolor(MAGENTA);
	
	LoadingBar lb;
	
	lb.bordercolor=WHITE;
	lb.fillcolor=WHITE;
	lb.ox=screenwidth()/2;
	lb.oy=screenheight()/2;
	lb.width=screenwidth()/2;
	lb.height=15;
	lb.loadvalue=0;
	
	OnUpdate()
	{
		MakeLoadingBar(&lb);

		DrawFrame(FALSE);
		
		if(lb.loadvalue<=lb.endvalue)
			lb.loadvalue++;
		
		usleep(10000);
	}
}
