#include "2DGC.h"

void main()
{
	CreateConsole("Noise Test",200,200,2,2);
	
	OnUpdate()
	{
		for(i=0;i<screenwidth();i++)
		{
			for(j=0;j<screenheight();j++)
			{
				putpixel(i,j,randcolor());
			}
		}

		DrawFrame(TRUE);
	}

	//printf("%d",randcolor());
}
