#include "ConsoleGUI.h"

void main()
{
	CreateConsole("Pixel Sprite Editor",400,300,2,2);
	
	OnUpdate()
	{
		//Canvas
		DrawRect(midX()+40,midY(),260,240,WHITE);
		
		//ColorPalette
		Fillrect2(midX()-170+20,midY()-100+20,60,60,WHITE);
		Colorpalette(midX()-170,midY()-100);
		DrawFrame(TRUE);
		
	}
}

void Colorpalette(int x,int y)
{
	int i,j;
	int offx=0,offy=0;
	int icolor;
	
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			Fillrect2(x+offx,y+offy,10,10,color[icolor]);
			offx+=12;
			icolor++;	
		}
		offy+=12;
		offx=0;		
	}
}
