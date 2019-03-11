#ifndef _CONSOLEGUI_H_
#define _CONSOLEGUI_H_

#include "2DGC.h"

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
	
	if(*(B.label)!=0)
	{
		int textXO;
		int textYO;
		textXO=(( B.width - stringsize(B.label)) / 2)+ x1;
		textYO=(( B.height - 1) / 2)+ y1;
		printString(B.label,textXO,textYO,B.textColor,FGtoBG(B.color));	
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

void readChar(char alpha)
{
	int n=0;
	char c=0;
	
	FILE *cifile;
	cifile=fopen("CGtext.cif","r");
	
	while(CharInfo[n]!=EOF)
	{
		CharInfo[n]=fgetc(cifile);
		n++;	
	}
	
	n=0;
	
	fclose(cifile);
	
	while(n<1000)
	{
		c=CharInfo[n];
		
		if(c==alpha)
		{
			n+=2;
			i=0;
			
			while(i<35)
			{
				cho[i]=CharInfo[n];
				//printf("%c",cho[i]);						
				i++;
				n++;
			}
			//printf("\n");
			return;
		}
		
		n++;
	}
	
}

int stringsize(char *p)
{
	int n=0;
	
	while(*(p+n)!=0)
	{
		n++;
	}
	return n;
}

void printStr(const char *s)
{
	int n=0,x=0;
	int charSpace=2;
	
	if(s[n]!=0)
	{
		readChar(s[n]);
		
		for(i=0;i<7;i++)
		{
			for(j=0;j<5;j++)
			{
				if(cho[j+i*5]=='.')
					putpixel(j,i,FG_BLACK);
					
				if(cho[j+i*5]=='o')
					putpixel(j,i,FG_GREEN);
			}
		}
		
		//x+=charSpace;
		n++;
	}
}

void OnClick(Button B)
{
	//Do on click event
}

#endif
