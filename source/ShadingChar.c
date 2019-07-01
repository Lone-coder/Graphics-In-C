#include "Headers/3DGC.h"

void main()
{
	CreateConsole("Shading",400,300,2,2);
	
	int i,j;
	char c = 1;
	
	OnUpdate()
	{
		for(i=-150; i<300; i+=10)
		{
			for(j=-200; j<400; j+=10)
			{
				Fillrect2(i,j,20,20,RandomColor(),c);
				c++;
			}
		
		}
	
		DrawFrame();	
	}
	
	
}
