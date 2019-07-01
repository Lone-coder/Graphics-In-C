//libray to plot graphs on console window

#ifndef GRAPHPLOT_H
#define GRAPHPLOT_H

#include "2DGC.h"
#include "PixelText.h"

#define AXIS_OFFSET 20

int x[50],y[50];
int max_X,max_Y;
int xscale,yscale;

void plotgraph()
{
	//CreateConsole("Graph",300,200,2,2);
	//SetBgColor(BLACK);
	
	int i = 0,j = 0;
	
	if(1)
	{
		//drawing axis
		//DrawLine(AXIS_OFFSET,screenheight()-AXIS_OFFSET,screenwidth()-AXIS_OFFSET,screenheight()-AXIS_OFFSET,GREEN);
		//DrawLine(AXIS_OFFSET,screenheight()-AXIS_OFFSET,AXIS_OFFSET,AXIS_OFFSET,GREEN);
		
		for(i=0; i<(180 ); i++)
		{
			for(j=0; j<(180); j++)
			{
				//if( j == (int)sin(i)*100)
					//PutPixel(i,j,RED);
				printf("sin(x): %d\n",(int)sin(i)*100.0);
					
			}
		}
		
		//DrawFrame(TRUE);
	}
}


#endif
