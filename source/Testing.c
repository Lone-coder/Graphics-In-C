#include "2DGC.h"

void main()
{
	CreateConsole("Color test",200,200,2,2);
	
	OnUpdate()
	{
		SetBGcolor(randcolor());
		DrawFrame(TRUE);
		sleep(1);
	}
}
