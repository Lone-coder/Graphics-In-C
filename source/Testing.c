#include "Headers/2DGC.h"

void main()
{
	CreateConsole("Color test",200,200,2,2);
	
	OnUpdate()
	{
		SetBgColor(RandomColor());
		DrawFrame(true);
		sleep(1);
	}
}
