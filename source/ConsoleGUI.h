#ifndef _CONSOLEGUI_H_
#define _CONSOLEGUI_H_

#include "2DGC.h"
#include "PixelText.h"

int stringsize(char*);
char CharInfo[1000];
char cho[35];

typedef struct panel
{
	int ox,oy;
	int width,height;
	int color;
	
}Panel;

typedef struct button
{
	int ox,oy;
	int width,height;
	int color;
	int textColor;
	char *label;
	
}Button;

typedef struct loadingbar
{
	int ox,oy;
	int width,height;
	int bordercolor;
	int fillcolor;
	int loadvalue;
	int endvalue;	
	
}LoadingBar;

void MakeButton(Button B,int border,int bdcol)
{
	int x1,x2,y1,y2;
	
	x1=B.ox-(B.width/2);
	x2=B.ox+(B.width/2);
	y1=B.oy-(B.height/2);
	y2=B.oy+(B.height/2);
	
	Fillrect(x1,y1,x2,y2,B.color);
	
	if(border)
	{
		for(i=x1;i<x2;i++)
		{
			for(j=y1;j<=y2;j++)
			{
				if(i==x1 || i==x2-1 || j==y1 || j==y2)
					putpixel(i,j,bdcol);
			}
		}
	}
}

void MakePanel(Panel P)
{
	int x1,x2,y1,y2;
	
	x1=P.ox-(P.width/2);
	x2=P.ox+(P.width/2);
	y1=P.oy-(P.height/2);
	y2=P.oy+(P.height/2);
	
	Fillrect(x1,y1,x2,y2,P.color);
}

void MakeLoadingBar(LoadingBar *Lb)
{
	int x1,x2,y1,y2;
	
	x1=Lb->ox-(Lb->width/2);
	x2=Lb->ox+(Lb->width/2);
	y1=Lb->oy-(Lb->height/2);
	y2=Lb->oy+(Lb->height/2);
	
	Lb->endvalue=x2-2;
	
	DrawRect(x1,y1,x2,y2,Lb->bordercolor);
	Fillrect(x1+2,y1+2,Lb->loadvalue,y2-2,Lb->fillcolor);
	
}

void printString(const char *s,int x,int y,int color)
{
	int l=0;
	int space=0;
	
	while(*(s+l)!=0)
	{
		putchara(*(s+l),x+space,y,color);
		space+=6;
		l++;
	}
}

void OnClick(Button B)
{
	//Do on click event
}

#endif
