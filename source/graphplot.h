#ifndef GRAPHPLOT_H
#define GRAPHPLOT_H

#include "2DgC.h"

int x[50],y[50];
int max_X,max_Y;
int xscale,yscale;

void plotgraph()
{
	CreateConsole("Graph",200,200,2,2);
	SetBGcolor(WHITE);
	
	
	OnUpdate()
	{
		DrawLine(10,180,screenwidth()-10,180,BLUE);
		DrawLine(10,180,10,10,BLUE);
		
		DrawFrame(TRUE);
	}
}
//libray to plot graphs on console window

#endif
