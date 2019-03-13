#ifndef _PIXELTEXT_H
#define _PIXELTEXT_H
#include "2DGC.h"

void putchara(char c,int x,int y,int textcolor)
{
	switch(c)
	{
		case 'A':
			
			//-3
			//putpixel(x-2,y-3,textcolor);
			putpixel(x-1,y-3,textcolor);
			putpixel(x-0,y-3,textcolor);
			putpixel(x+1,y-3,textcolor);
			//putpixel(x+2,y-3,textcolor);
			
			//-2
			putpixel(x-2,y-2,textcolor);
			//putpixel(x-1,y-2,textcolor);
			//putpixel(x-0,y-2,textcolor);
			//putpixel(x+1,y-2,textcolor);
			putpixel(x+2,y-2,textcolor);
 			
 			//-1
 			putpixel(x-2,y-1,textcolor);
			//putpixel(x-1,y-1,textcolor);
			//putpixel(x-0,y-1,textcolor);
			//putpixel(x+1,y-1,textcolor);
			putpixel(x+2,y-1,textcolor);
			
			//0
			putpixel(x-2,y-0,textcolor);
			putpixel(x-1,y-0,textcolor);
			putpixel(x-0,y-0,textcolor);
			putpixel(x+1,y-0,textcolor);
			putpixel(x+2,y-0,textcolor);
			
			//+1
			putpixel(x-2,y+1,textcolor);
			//putpixel(x-1,y+1,textcolor);
			//putpixel(x-0,y+1,textcolor);
			//putpixel(x+1,y+1,textcolor);
			putpixel(x+2,y+1,textcolor);
			
			//+2
			putpixel(x-2,y+2,textcolor);
			//putpixel(x-1,y+2,textcolor);
			//putpixel(x-0,y+2,textcolor);
			//putpixel(x+1,y+2,textcolor);
			putpixel(x+2,y+2,textcolor);
			
			//+3
    		putpixel(x-2,y+3,textcolor);
			//putpixel(x-1,y+3,textcolor);
			//putpixel(x-0,y+3,textcolor);
			//putpixel(x+1,y+3,textcolor);
			putpixel(x+2,y+3,textcolor);
			
			break;
			
		case 'B':
			//-3
			putpixel(x-2,y-3,textcolor);
			putpixel(x-1,y-3,textcolor);
			putpixel(x-0,y-3,textcolor);
			putpixel(x+1,y-3,textcolor);
			//putpixel(x+2,y-3,textcolor);
			
			//-2
			putpixel(x-2,y-2,textcolor);
			//putpixel(x-1,y-2,textcolor);
			//putpixel(x-0,y-2,textcolor);
			//putpixel(x+1,y-2,textcolor);
			putpixel(x+2,y-2,textcolor);
 			
 			//-1
 			putpixel(x-2,y-1,textcolor);
			//putpixel(x-1,y-1,textcolor);
			//putpixel(x-0,y-1,textcolor);
			//putpixel(x+1,y-1,textcolor);
			putpixel(x+2,y-1,textcolor);
			
			//0
			putpixel(x-2,y-0,textcolor);
			putpixel(x-1,y-0,textcolor);
			putpixel(x-0,y-0,textcolor);
			putpixel(x+1,y-0,textcolor);
			//putpixel(x+2,y-0,textcolor);
			
			//+1
			putpixel(x-2,y+1,textcolor);
			//putpixel(x-1,y+1,textcolor);
			//putpixel(x-0,y+1,textcolor);
			//putpixel(x+1,y+1,textcolor);
			putpixel(x+2,y+1,textcolor);
			
			//+2
			putpixel(x-2,y+2,textcolor);
			//putpixel(x-1,y+2,textcolor);
			//putpixel(x-0,y+2,textcolor);
			//putpixel(x+1,y+2,textcolor);
			putpixel(x+2,y+2,textcolor);
			
			//+3
    		putpixel(x-2,y+3,textcolor);
			putpixel(x-1,y+3,textcolor);
			putpixel(x-0,y+3,textcolor);
			putpixel(x+1,y+3,textcolor);
			//putpixel(x+2,y+3,textcolor);
			
			break;
		
		case 'C':
			//-3
			//putpixel(x-2,y-3,textcolor);
			putpixel(x-1,y-3,textcolor);
			putpixel(x-0,y-3,textcolor);
			putpixel(x+1,y-3,textcolor);
			//putpixel(x+2,y-3,textcolor);
			
			//-2
			putpixel(x-2,y-2,textcolor);
			//putpixel(x-1,y-2,textcolor);
			//putpixel(x-0,y-2,textcolor);
			//putpixel(x+1,y-2,textcolor);
			putpixel(x+2,y-2,textcolor);
 			
 			//-1
 			putpixel(x-2,y-1,textcolor);
			//putpixel(x-1,y-1,textcolor);
			//putpixel(x-0,y-1,textcolor);
			//putpixel(x+1,y-1,textcolor);
			//putpixel(x+2,y-1,textcolor);
			
			//0
			putpixel(x-2,y-0,textcolor);
			//putpixel(x-1,y-0,textcolor);
			//putpixel(x-0,y-0,textcolor);
			//putpixel(x+1,y-0,textcolor);
			//putpixel(x+2,y-0,textcolor);
			
			//+1
			putpixel(x-2,y+1,textcolor);
			//putpixel(x-1,y+1,textcolor);
			//putpixel(x-0,y+1,textcolor);
			//putpixel(x+1,y+1,textcolor);
			//putpixel(x+2,y+1,textcolor);
			
			//+2
			putpixel(x-2,y+2,textcolor);
			//putpixel(x-1,y+2,textcolor);
			//putpixel(x-0,y+2,textcolor);
			//putpixel(x+1,y+2,textcolor);
			putpixel(x+2,y+2,textcolor);
			
			//+3
    		//putpixel(x-2,y+3,textcolor);
			putpixel(x-1,y+3,textcolor);
			putpixel(x-0,y+3,textcolor);
			putpixel(x+1,y+3,textcolor);
			//putpixel(x+2,y+3,textcolor);
			
			break;
		
		case 'D':
			//-3
			putpixel(x-2,y-3,textcolor);
			putpixel(x-1,y-3,textcolor);
			putpixel(x-0,y-3,textcolor);
			putpixel(x+1,y-3,textcolor);
			//putpixel(x+2,y-3,textcolor);
			
			//-2
			putpixel(x-2,y-2,textcolor);
			//putpixel(x-1,y-2,textcolor);
			//putpixel(x-0,y-2,textcolor);
			//putpixel(x+1,y-2,textcolor);
			putpixel(x+2,y-2,textcolor);
 			
 			//-1
 			putpixel(x-2,y-1,textcolor);
			//putpixel(x-1,y-1,textcolor);
			//putpixel(x-0,y-1,textcolor);
			//putpixel(x+1,y-1,textcolor);
			putpixel(x+2,y-1,textcolor);
			
			//0
			putpixel(x-2,y-0,textcolor);
			//putpixel(x-1,y-0,textcolor);
			//putpixel(x-0,y-0,textcolor);
			//putpixel(x+1,y-0,textcolor);
			putpixel(x+2,y-0,textcolor);
			
			//+1
			putpixel(x-2,y+1,textcolor);
			//putpixel(x-1,y+1,textcolor);
			//putpixel(x-0,y+1,textcolor);
			//putpixel(x+1,y+1,textcolor);
			putpixel(x+2,y+1,textcolor);
			
			//+2
			putpixel(x-2,y+2,textcolor);
			//putpixel(x-1,y+2,textcolor);
			//putpixel(x-0,y+2,textcolor);
			//putpixel(x+1,y+2,textcolor);
			putpixel(x+2,y+2,textcolor);
			
			//+3
    		putpixel(x-2,y+3,textcolor);
			putpixel(x-1,y+3,textcolor);
			putpixel(x-0,y+3,textcolor);
			putpixel(x+1,y+3,textcolor);
			//putpixel(x+2,y+3,textcolor);
			
			break;
			
		case 'E':
			//-3
			putpixel(x-2,y-3,textcolor);
			putpixel(x-1,y-3,textcolor);
			putpixel(x-0,y-3,textcolor);
			putpixel(x+1,y-3,textcolor);
			putpixel(x+2,y-3,textcolor);
			
			//-2
			putpixel(x-2,y-2,textcolor);
			//putpixel(x-1,y-2,textcolor);
			//putpixel(x-0,y-2,textcolor);
			//putpixel(x+1,y-2,textcolor);
			//putpixel(x+2,y-2,textcolor);
 			
 			//-1
 			putpixel(x-2,y-1,textcolor);
			//putpixel(x-1,y-1,textcolor);
			//putpixel(x-0,y-1,textcolor);
			//putpixel(x+1,y-1,textcolor);
			//putpixel(x+2,y-1,textcolor);
			
			//0
			putpixel(x-2,y-0,textcolor);
			putpixel(x-1,y-0,textcolor);
			putpixel(x-0,y-0,textcolor);
			putpixel(x+1,y-0,textcolor);
			//putpixel(x+2,y-0,textcolor);
			
			//+1
			putpixel(x-2,y+1,textcolor);
			//putpixel(x-1,y+1,textcolor);
			//putpixel(x-0,y+1,textcolor);
			//putpixel(x+1,y+1,textcolor);
			//putpixel(x+2,y+1,textcolor);
			
			//+2
			putpixel(x-2,y+2,textcolor);
			//putpixel(x-1,y+2,textcolor);
			//putpixel(x-0,y+2,textcolor);
			//putpixel(x+1,y+2,textcolor);
			//putpixel(x+2,y+2,textcolor);
			
			//+3
    		putpixel(x-2,y+3,textcolor);
			putpixel(x-1,y+3,textcolor);
			putpixel(x-0,y+3,textcolor);
			putpixel(x+1,y+3,textcolor);
			putpixel(x+2,y+3,textcolor);
			
			break;
			
		case 'F':
			//-3
			putpixel(x-2,y-3,textcolor);
			putpixel(x-1,y-3,textcolor);
			putpixel(x-0,y-3,textcolor);
			putpixel(x+1,y-3,textcolor);
			putpixel(x+2,y-3,textcolor);
			
			//-2
			putpixel(x-2,y-2,textcolor);
			//putpixel(x-1,y-2,textcolor);
			//putpixel(x-0,y-2,textcolor);
			//putpixel(x+1,y-2,textcolor);
			//putpixel(x+2,y-2,textcolor);
 			
 			//-1
 			putpixel(x-2,y-1,textcolor);
			//putpixel(x-1,y-1,textcolor);
			//putpixel(x-0,y-1,textcolor);
			//putpixel(x+1,y-1,textcolor);
			//putpixel(x+2,y-1,textcolor);
			
			//0
			putpixel(x-2,y-0,textcolor);
			putpixel(x-1,y-0,textcolor);
			putpixel(x-0,y-0,textcolor);
			putpixel(x+1,y-0,textcolor);
			//putpixel(x+2,y-0,textcolor);
			
			//+1
			putpixel(x-2,y+1,textcolor);
			//putpixel(x-1,y+1,textcolor);
			//putpixel(x-0,y+1,textcolor);
			//putpixel(x+1,y+1,textcolor);
			//putpixel(x+2,y+1,textcolor);
			
			//+2
			putpixel(x-2,y+2,textcolor);
			//putpixel(x-1,y+2,textcolor);
			//putpixel(x-0,y+2,textcolor);
			//putpixel(x+1,y+2,textcolor);
			//putpixel(x+2,y+2,textcolor);
			
			//+3
    		putpixel(x-2,y+3,textcolor);
			//putpixel(x-1,y+3,textcolor);
			//putpixel(x-0,y+3,textcolor);
			//putpixel(x+1,y+3,textcolor);
			//putpixel(x+2,y+3,textcolor);
			
			break;
		
		case 'G':
			//-3
			//putpixel(x-2,y-3,textcolor);
			putpixel(x-1,y-3,textcolor);
			putpixel(x-0,y-3,textcolor);
			putpixel(x+1,y-3,textcolor);
			//putpixel(x+2,y-3,textcolor);
			
			//-2
			putpixel(x-2,y-2,textcolor);
			//putpixel(x-1,y-2,textcolor);
			//putpixel(x-0,y-2,textcolor);
			//putpixel(x+1,y-2,textcolor);
			putpixel(x+2,y-2,textcolor);
 			
 			//-1
 			putpixel(x-2,y-1,textcolor);
			//putpixel(x-1,y-1,textcolor);
			//putpixel(x-0,y-1,textcolor);
			//putpixel(x+1,y-1,textcolor);
			//putpixel(x+2,y-1,textcolor);
			
			//0
			putpixel(x-2,y-0,textcolor);
			//putpixel(x-1,y-0,textcolor);
			//putpixel(x-0,y-0,textcolor);
			//putpixel(x+1,y-0,textcolor);
			//putpixel(x+2,y-0,textcolor);
			
			//+1
			putpixel(x-2,y+1,textcolor);
			//putpixel(x-1,y+1,textcolor);
			//putpixel(x-0,y+1,textcolor);
			putpixel(x+1,y+1,textcolor);
			putpixel(x+2,y+1,textcolor);
			
			//+2
			putpixel(x-2,y+2,textcolor);
			//putpixel(x-1,y+2,textcolor);
			//putpixel(x-0,y+2,textcolor);
			//putpixel(x+1,y+2,textcolor);
			putpixel(x+2,y+2,textcolor);
			
			//+3
    		//putpixel(x-2,y+3,textcolor);
			putpixel(x-1,y+3,textcolor);
			putpixel(x-0,y+3,textcolor);
			putpixel(x+1,y+3,textcolor);
			//putpixel(x+2,y+3,textcolor);
			
			break;
			
		case 'H':
			//-3
			putpixel(x-2,y-3,textcolor);
			//putpixel(x-1,y-3,textcolor);
			//putpixel(x-0,y-3,textcolor);
			//putpixel(x+1,y-3,textcolor);
			putpixel(x+2,y-3,textcolor);
			
			//-2
			putpixel(x-2,y-2,textcolor);
			//putpixel(x-1,y-2,textcolor);
			//putpixel(x-0,y-2,textcolor);
			//putpixel(x+1,y-2,textcolor);
			putpixel(x+2,y-2,textcolor);
 			
 			//-1
 			putpixel(x-2,y-1,textcolor);
			//putpixel(x-1,y-1,textcolor);
			//putpixel(x-0,y-1,textcolor);
			//putpixel(x+1,y-1,textcolor);
			putpixel(x+2,y-1,textcolor);
			
			//0
			putpixel(x-2,y-0,textcolor);
			putpixel(x-1,y-0,textcolor);
			putpixel(x-0,y-0,textcolor);
			putpixel(x+1,y-0,textcolor);
			putpixel(x+2,y-0,textcolor);
			
			//+1
			putpixel(x-2,y+1,textcolor);
			//putpixel(x-1,y+1,textcolor);
			//putpixel(x-0,y+1,textcolor);
			//putpixel(x+1,y+1,textcolor);
			putpixel(x+2,y+1,textcolor);
			
			//+2
			putpixel(x-2,y+2,textcolor);
			//putpixel(x-1,y+2,textcolor);
			//putpixel(x-0,y+2,textcolor);
			//putpixel(x+1,y+2,textcolor);
			putpixel(x+2,y+2,textcolor);
			
			//+3
    		putpixel(x-2,y+3,textcolor);
			//putpixel(x-1,y+3,textcolor);
			//putpixel(x-0,y+3,textcolor);
			//putpixel(x+1,y+3,textcolor);
			putpixel(x+2,y+3,textcolor);
			
			break;
			
		case 'I':
			//-3
			//putpixel(x-2,y-3,textcolor);
			putpixel(x-1,y-3,textcolor);
			putpixel(x-0,y-3,textcolor);
			putpixel(x+1,y-3,textcolor);
			//putpixel(x+2,y-3,textcolor);
			
			//-2
			//putpixel(x-2,y-2,textcolor);
			//putpixel(x-1,y-2,textcolor);
			putpixel(x-0,y-2,textcolor);
			//putpixel(x+1,y-2,textcolor);
			//putpixel(x+2,y-2,textcolor);
 			
 			//-1
 			//putpixel(x-2,y-1,textcolor);
			//putpixel(x-1,y-1,textcolor);
			putpixel(x-0,y-1,textcolor);
			//putpixel(x+1,y-1,textcolor);
			//putpixel(x+2,y-1,textcolor);
			
			//0
			//putpixel(x-2,y-0,textcolor);
			//putpixel(x-1,y-0,textcolor);
			putpixel(x-0,y-0,textcolor);
			//putpixel(x+1,y-0,textcolor);
			//putpixel(x+2,y-0,textcolor);
			
			//+1
			//putpixel(x-2,y+1,textcolor);
			//putpixel(x-1,y+1,textcolor);
			putpixel(x-0,y+1,textcolor);
			//putpixel(x+1,y+1,textcolor);
			//putpixel(x+2,y+1,textcolor);
			
			//+2
			//putpixel(x-2,y+2,textcolor);
			//putpixel(x-1,y+2,textcolor);
			putpixel(x-0,y+2,textcolor);
			//putpixel(x+1,y+2,textcolor);
			//putpixel(x+2,y+2,textcolor);
			
			//+3
    		//putpixel(x-2,y+3,textcolor);
			putpixel(x-1,y+3,textcolor);
			putpixel(x-0,y+3,textcolor);
			putpixel(x+1,y+3,textcolor);
			//putpixel(x+2,y+3,textcolor);
		
		break;
		
		case 'J':
			//-3
			//putpixel(x-2,y-3,textcolor);
			//putpixel(x-1,y-3,textcolor);
			putpixel(x-0,y-3,textcolor);
			putpixel(x+1,y-3,textcolor);
			putpixel(x+2,y-3,textcolor);
			
			//-2
			//putpixel(x-2,y-2,textcolor);
			//putpixel(x-1,y-2,textcolor);
			//putpixel(x-0,y-2,textcolor);
			putpixel(x+1,y-2,textcolor);
			//putpixel(x+2,y-2,textcolor);
 			
 			//-1
 			//putpixel(x-2,y-1,textcolor);
			//putpixel(x-1,y-1,textcolor);
			//putpixel(x-0,y-1,textcolor);
			putpixel(x+1,y-1,textcolor);
			//putpixel(x+2,y-1,textcolor);
			
			//0
			//putpixel(x-2,y-0,textcolor);
			//putpixel(x-1,y-0,textcolor);
			//putpixel(x-0,y-0,textcolor);
			putpixel(x+1,y-0,textcolor);
			//putpixel(x+2,y-0,textcolor);
			
			//+1
			//putpixel(x-2,y+1,textcolor);
			//putpixel(x-1,y+1,textcolor);
			//putpixel(x-0,y+1,textcolor);
			putpixel(x+1,y+1,textcolor);
			//putpixel(x+2,y+1,textcolor);
			
			//+2
			putpixel(x-2,y+2,textcolor);
			//putpixel(x-1,y+2,textcolor);
			//putpixel(x-0,y+2,textcolor);
			putpixel(x+1,y+2,textcolor);
			//putpixel(x+2,y+2,textcolor);
			
			//+3
    		//putpixel(x-2,y+3,textcolor);
			putpixel(x-1,y+3,textcolor);
			putpixel(x-0,y+3,textcolor);
			//putpixel(x+1,y+3,textcolor);
			//putpixel(x+2,y+3,textcolor);
			
			break;
		
		case 'K':		
			//-3
			putpixel(x-2,y-3,textcolor);
			//putpixel(x-1,y-3,textcolor);
			//putpixel(x-0,y-3,textcolor);
			//putpixel(x+1,y-3,textcolor);
			putpixel(x+2,y-3,textcolor);
			
			//-2
			putpixel(x-2,y-2,textcolor);
			//putpixel(x-1,y-2,textcolor);
			//putpixel(x-0,y-2,textcolor);
			putpixel(x+1,y-2,textcolor);
			//putpixel(x+2,y-2,textcolor);
 			
 			//-1
 			putpixel(x-2,y-1,textcolor);
			//putpixel(x-1,y-1,textcolor);
			putpixel(x-0,y-1,textcolor);
			//putpixel(x+1,y-1,textcolor);
			//putpixel(x+2,y-1,textcolor);
			
			//0
			putpixel(x-2,y-0,textcolor);
			putpixel(x-1,y-0,textcolor);
			//putpixel(x-0,y-0,textcolor);
			//putpixel(x+1,y-0,textcolor);
			//putpixel(x+2,y-0,textcolor);
			
			//+1
			putpixel(x-2,y+1,textcolor);
			//putpixel(x-1,y+1,textcolor);
			putpixel(x-0,y+1,textcolor);
			//putpixel(x+1,y+1,textcolor);
			//putpixel(x+2,y+1,textcolor);
			
			//+2
			putpixel(x-2,y+2,textcolor);
			//putpixel(x-1,y+2,textcolor);
			//putpixel(x-0,y+2,textcolor);
			putpixel(x+1,y+2,textcolor);
			//putpixel(x+2,y+2,textcolor);
			
			//+3
    		putpixel(x-2,y+3,textcolor);
			//putpixel(x-1,y+3,textcolor);
			//putpixel(x-0,y+3,textcolor);
			//putpixel(x+1,y+3,textcolor);
			putpixel(x+2,y+3,textcolor);
			
			break;
			
		case 'L':
			//-3
			putpixel(x-2,y-3,textcolor);
			//putpixel(x-1,y-3,textcolor);
			//putpixel(x-0,y-3,textcolor);
			//putpixel(x+1,y-3,textcolor);
			//putpixel(x+2,y-3,textcolor);
			
			//-2
			putpixel(x-2,y-2,textcolor);
			//putpixel(x-1,y-2,textcolor);
			//putpixel(x-0,y-2,textcolor);
			//putpixel(x+1,y-2,textcolor);
			//putpixel(x+2,y-2,textcolor);
 			
 			//-1
 			putpixel(x-2,y-1,textcolor);
			//putpixel(x-1,y-1,textcolor);
			//putpixel(x-0,y-1,textcolor);
			//putpixel(x+1,y-1,textcolor);
			//putpixel(x+2,y-1,textcolor);
			
			//0
			putpixel(x-2,y-0,textcolor);
			//putpixel(x-1,y-0,textcolor);
			//putpixel(x-0,y-0,textcolor);
			//putpixel(x+1,y-0,textcolor);
			//putpixel(x+2,y-0,textcolor);
			
			//+1
			putpixel(x-2,y+1,textcolor);
			//putpixel(x-1,y+1,textcolor);
			//putpixel(x-0,y+1,textcolor);
			//putpixel(x+1,y+1,textcolor);
			//putpixel(x+2,y+1,textcolor);
			
			//+2
			putpixel(x-2,y+2,textcolor);
			//putpixel(x-1,y+2,textcolor);
			//putpixel(x-0,y+2,textcolor);
			//putpixel(x+1,y+2,textcolor);
			//putpixel(x+2,y+2,textcolor);
			
			//+3
    		putpixel(x-2,y+3,textcolor);
			putpixel(x-1,y+3,textcolor);
			putpixel(x-0,y+3,textcolor);
			putpixel(x+1,y+3,textcolor);
			putpixel(x+2,y+3,textcolor);	
    		
    		break;
    		
    	case 'M':
    		//-3
			putpixel(x-2,y-3,textcolor);
			//putpixel(x-1,y-3,textcolor);
			//putpixel(x-0,y-3,textcolor);
			//putpixel(x+1,y-3,textcolor);
			putpixel(x+2,y-3,textcolor);
			
			//-2
			putpixel(x-2,y-2,textcolor);
			putpixel(x-1,y-2,textcolor);
			//putpixel(x-0,y-2,textcolor);
			putpixel(x+1,y-2,textcolor);
			putpixel(x+2,y-2,textcolor);
 			
 			//-1
 			putpixel(x-2,y-1,textcolor);
			//putpixel(x-1,y-1,textcolor);
			putpixel(x-0,y-1,textcolor);
			//putpixel(x+1,y-1,textcolor);
			putpixel(x+2,y-1,textcolor);
			
			//0
			putpixel(x-2,y-0,textcolor);
			//putpixel(x-1,y-0,textcolor);
			putpixel(x-0,y-0,textcolor);
			//putpixel(x+1,y-0,textcolor);
			putpixel(x+2,y-0,textcolor);
			
			//+1
			putpixel(x-2,y+1,textcolor);
			//putpixel(x-1,y+1,textcolor);
			//putpixel(x-0,y+1,textcolor);
			//putpixel(x+1,y+1,textcolor);
			putpixel(x+2,y+1,textcolor);
			
			//+2
			putpixel(x-2,y+2,textcolor);
			//putpixel(x-1,y+2,textcolor);
			//putpixel(x-0,y+2,textcolor);
			//putpixel(x+1,y+2,textcolor);
			putpixel(x+2,y+2,textcolor);
			
			//+3
    		putpixel(x-2,y+3,textcolor);
			//putpixel(x-1,y+3,textcolor);
			//putpixel(x-0,y+3,textcolor);
			//putpixel(x+1,y+3,textcolor);
			putpixel(x+2,y+3,textcolor);
			
			break;
			
		case 'N':
			//-3
			putpixel(x-2,y-3,textcolor);
			//putpixel(x-1,y-3,textcolor);
			//putpixel(x-0,y-3,textcolor);
			//putpixel(x+1,y-3,textcolor);
			putpixel(x+2,y-3,textcolor);
			
			//-2
			putpixel(x-2,y-2,textcolor);
			//putpixel(x-1,y-2,textcolor);
			//putpixel(x-0,y-2,textcolor);
			//putpixel(x+1,y-2,textcolor);
			putpixel(x+2,y-2,textcolor);
 			
 			//-1
 			putpixel(x-2,y-1,textcolor);
			putpixel(x-1,y-1,textcolor);
			//putpixel(x-0,y-1,textcolor);
			//putpixel(x+1,y-1,textcolor);
			putpixel(x+2,y-1,textcolor);
			
			//0
			putpixel(x-2,y-0,textcolor);
			//putpixel(x-1,y-0,textcolor);
			putpixel(x-0,y-0,textcolor);
			//putpixel(x+1,y-0,textcolor);
			putpixel(x+2,y-0,textcolor);
			
			//+1
			putpixel(x-2,y+1,textcolor);
			//putpixel(x-1,y+1,textcolor);
			//putpixel(x-0,y+1,textcolor);
			putpixel(x+1,y+1,textcolor);
			putpixel(x+2,y+1,textcolor);
			
			//+2
			putpixel(x-2,y+2,textcolor);
			//putpixel(x-1,y+2,textcolor);
			//putpixel(x-0,y+2,textcolor);
			//putpixel(x+1,y+2,textcolor);
			putpixel(x+2,y+2,textcolor);
			
			//+3
    		putpixel(x-2,y+3,textcolor);
			//putpixel(x-1,y+3,textcolor);
			//putpixel(x-0,y+3,textcolor);
			//putpixel(x+1,y+3,textcolor);
			putpixel(x+2,y+3,textcolor);
			
			break;
			
		case 'O':
			//-3
			//putpixel(x-2,y-3,textcolor);
			putpixel(x-1,y-3,textcolor);
			putpixel(x-0,y-3,textcolor);
			putpixel(x+1,y-3,textcolor);
			//putpixel(x+2,y-3,textcolor);
			
			//-2
			putpixel(x-2,y-2,textcolor);
			//putpixel(x-1,y-2,textcolor);
			//putpixel(x-0,y-2,textcolor);
			//putpixel(x+1,y-2,textcolor);
			putpixel(x+2,y-2,textcolor);
 			
 			//-1
 			putpixel(x-2,y-1,textcolor);
			//putpixel(x-1,y-1,textcolor);
			//putpixel(x-0,y-1,textcolor);
			//putpixel(x+1,y-1,textcolor);
			putpixel(x+2,y-1,textcolor);
			
			//0
			putpixel(x-2,y-0,textcolor);
			//putpixel(x-1,y-0,textcolor);
			//putpixel(x-0,y-0,textcolor);
			//putpixel(x+1,y-0,textcolor);
			putpixel(x+2,y-0,textcolor);
			
			//+1
			putpixel(x-2,y+1,textcolor);
			//putpixel(x-1,y+1,textcolor);
			//putpixel(x-0,y+1,textcolor);
			//putpixel(x+1,y+1,textcolor);
			putpixel(x+2,y+1,textcolor);
			
			//+2
			putpixel(x-2,y+2,textcolor);
			//putpixel(x-1,y+2,textcolor);
			//putpixel(x-0,y+2,textcolor);
			//putpixel(x+1,y+2,textcolor);
			putpixel(x+2,y+2,textcolor);
			
			//+3
    		//putpixel(x-2,y+3,textcolor);
			putpixel(x-1,y+3,textcolor);
			putpixel(x-0,y+3,textcolor);
			putpixel(x+1,y+3,textcolor);
			//putpixel(x+2,y+3,textcolor);
			
			break;
			
		case 'P':
			//-3
			putpixel(x-2,y-3,textcolor);
			putpixel(x-1,y-3,textcolor);
			putpixel(x-0,y-3,textcolor);
			putpixel(x+1,y-3,textcolor);
			//putpixel(x+2,y-3,textcolor);
			
			//-2
			putpixel(x-2,y-2,textcolor);
			//putpixel(x-1,y-2,textcolor);
			//putpixel(x-0,y-2,textcolor);
			//putpixel(x+1,y-2,textcolor);
			putpixel(x+2,y-2,textcolor);
 			
 			//-1
 			putpixel(x-2,y-1,textcolor);
			//putpixel(x-1,y-1,textcolor);
			//putpixel(x-0,y-1,textcolor);
			//putpixel(x+1,y-1,textcolor);
			putpixel(x+2,y-1,textcolor);
			
			//0
			putpixel(x-2,y-0,textcolor);
			putpixel(x-1,y-0,textcolor);
			putpixel(x-0,y-0,textcolor);
			putpixel(x+1,y-0,textcolor);
			//putpixel(x+2,y-0,textcolor);
			
			//+1
			putpixel(x-2,y+1,textcolor);
			//putpixel(x-1,y+1,textcolor);
			//putpixel(x-0,y+1,textcolor);
			//putpixel(x+1,y+1,textcolor);
			//putpixel(x+2,y+1,textcolor);
			
			//+2
			putpixel(x-2,y+2,textcolor);
			//putpixel(x-1,y+2,textcolor);
			//putpixel(x-0,y+2,textcolor);
			//putpixel(x+1,y+2,textcolor);
			//putpixel(x+2,y+2,textcolor);
			
			//+3
    		putpixel(x-2,y+3,textcolor);
			//putpixel(x-1,y+3,textcolor);
			//putpixel(x-0,y+3,textcolor);
			//putpixel(x+1,y+3,textcolor);
			//putpixel(x+2,y+3,textcolor);
			
			break;
			
		case 'Q':
			//-3
			//putpixel(x-2,y-3,textcolor);
			putpixel(x-1,y-3,textcolor);
			putpixel(x-0,y-3,textcolor);
			putpixel(x+1,y-3,textcolor);
			//putpixel(x+2,y-3,textcolor);
			
			//-2
			putpixel(x-2,y-2,textcolor);
			//putpixel(x-1,y-2,textcolor);
			//putpixel(x-0,y-2,textcolor);
			//putpixel(x+1,y-2,textcolor);
			putpixel(x+2,y-2,textcolor);
 			
 			//-1
 			putpixel(x-2,y-1,textcolor);
			//putpixel(x-1,y-1,textcolor);
			//putpixel(x-0,y-1,textcolor);
			//putpixel(x+1,y-1,textcolor);
			putpixel(x+2,y-1,textcolor);
			
			//0
			putpixel(x-2,y-0,textcolor);
			//putpixel(x-1,y-0,textcolor);
			//putpixel(x-0,y-0,textcolor);
			//putpixel(x+1,y-0,textcolor);
			putpixel(x+2,y-0,textcolor);
			
			//+1
			putpixel(x-2,y+1,textcolor);
			//putpixel(x-1,y+1,textcolor);
			putpixel(x-0,y+1,textcolor);
			//putpixel(x+1,y+1,textcolor);
			putpixel(x+2,y+1,textcolor);
			
			//+2
			putpixel(x-2,y+2,textcolor);
			//putpixel(x-1,y+2,textcolor);
			//putpixel(x-0,y+2,textcolor);
			putpixel(x+1,y+2,textcolor);
			//putpixel(x+2,y+2,textcolor);
			
			//+3
    		//putpixel(x-2,y+3,textcolor);
			putpixel(x-1,y+3,textcolor);
			putpixel(x-0,y+3,textcolor);
			//putpixel(x+1,y+3,textcolor);
			putpixel(x+2,y+3,textcolor);
			
			break;
			
		case 'R':
			//-3
			putpixel(x-2,y-3,textcolor);
			putpixel(x-1,y-3,textcolor);
			putpixel(x-0,y-3,textcolor);
			putpixel(x+1,y-3,textcolor);
			//putpixel(x+2,y-3,textcolor);
			
			//-2
			putpixel(x-2,y-2,textcolor);
			//putpixel(x-1,y-2,textcolor);
			//putpixel(x-0,y-2,textcolor);
			//putpixel(x+1,y-2,textcolor);
			putpixel(x+2,y-2,textcolor);
 			
 			//-1
 			putpixel(x-2,y-1,textcolor);
			//putpixel(x-1,y-1,textcolor);
			//putpixel(x-0,y-1,textcolor);
			//putpixel(x+1,y-1,textcolor);
			putpixel(x+2,y-1,textcolor);
			
			//0
			putpixel(x-2,y-0,textcolor);
			putpixel(x-1,y-0,textcolor);
			putpixel(x-0,y-0,textcolor);
			putpixel(x+1,y-0,textcolor);
			//putpixel(x+2,y-0,textcolor);
			
			//+1
			putpixel(x-2,y+1,textcolor);
			//putpixel(x-1,y+1,textcolor);
			putpixel(x-0,y+1,textcolor);
			//putpixel(x+1,y+1,textcolor);
			//putpixel(x+2,y+1,textcolor);
			
			//+2
			putpixel(x-2,y+2,textcolor);
			//putpixel(x-1,y+2,textcolor);
			//putpixel(x-0,y+2,textcolor);
			putpixel(x+1,y+2,textcolor);
			//putpixel(x+2,y+2,textcolor);
			
			//+3
    		putpixel(x-2,y+3,textcolor);
			//putpixel(x-1,y+3,textcolor);
			//putpixel(x-0,y+3,textcolor);
			//putpixel(x+1,y+3,textcolor);
			putpixel(x+2,y+3,textcolor);
			
			break;
			
		case 'S':
			//-3
			//putpixel(x-2,y-3,textcolor);
			putpixel(x-1,y-3,textcolor);
			putpixel(x-0,y-3,textcolor);
			putpixel(x+1,y-3,textcolor);
			putpixel(x+2,y-3,textcolor);
			
			//-2
			putpixel(x-2,y-2,textcolor);
			//putpixel(x-1,y-2,textcolor);
			//putpixel(x-0,y-2,textcolor);
			//putpixel(x+1,y-2,textcolor);
			//putpixel(x+2,y-2,textcolor);
 			
 			//-1
 			putpixel(x-2,y-1,textcolor);
			//putpixel(x-1,y-1,textcolor);
			//putpixel(x-0,y-1,textcolor);
			//putpixel(x+1,y-1,textcolor);
			//putpixel(x+2,y-1,textcolor);
			
			//0
			//putpixel(x-2,y-0,textcolor);
			putpixel(x-1,y-0,textcolor);
			putpixel(x-0,y-0,textcolor);
			putpixel(x+1,y-0,textcolor);
			//putpixel(x+2,y-0,textcolor);
			
			//+1
			//putpixel(x-2,y+1,textcolor);
			//putpixel(x-1,y+1,textcolor);
			//putpixel(x-0,y+1,textcolor);
			//putpixel(x+1,y+1,textcolor);
			putpixel(x+2,y+1,textcolor);
			
			//+2
			//putpixel(x-2,y+2,textcolor);
			//putpixel(x-1,y+2,textcolor);
			//putpixel(x-0,y+2,textcolor);
			//putpixel(x+1,y+2,textcolor);
			putpixel(x+2,y+2,textcolor);
			
			//+3
    		putpixel(x-2,y+3,textcolor);
			putpixel(x-1,y+3,textcolor);
			putpixel(x-0,y+3,textcolor);
			putpixel(x+1,y+3,textcolor);
			//putpixel(x+2,y+3,textcolor);
			
			break;
			
		case 'T':
			//-3
			putpixel(x-2,y-3,textcolor);
			putpixel(x-1,y-3,textcolor);
			putpixel(x-0,y-3,textcolor);
			putpixel(x+1,y-3,textcolor);
			putpixel(x+2,y-3,textcolor);
			
			//-2
			//putpixel(x-2,y-2,textcolor);
			//putpixel(x-1,y-2,textcolor);
			putpixel(x-0,y-2,textcolor);
			//putpixel(x+1,y-2,textcolor);
			//putpixel(x+2,y-2,textcolor);
 			
 			//-1
 			//putpixel(x-2,y-1,textcolor);
			//putpixel(x-1,y-1,textcolor);
			putpixel(x-0,y-1,textcolor);
			//putpixel(x+1,y-1,textcolor);
			//putpixel(x+2,y-1,textcolor);
			
			//0
			//putpixel(x-2,y-0,textcolor);
			//putpixel(x-1,y-0,textcolor);
			putpixel(x-0,y-0,textcolor);
			//putpixel(x+1,y-0,textcolor);
			//putpixel(x+2,y-0,textcolor);
			
			//+1
			//putpixel(x-2,y+1,textcolor);
			//putpixel(x-1,y+1,textcolor);
			putpixel(x-0,y+1,textcolor);
			//putpixel(x+1,y+1,textcolor);
			//putpixel(x+2,y+1,textcolor);
			
			//+2
			//putpixel(x-2,y+2,textcolor);
			//putpixel(x-1,y+2,textcolor);
			putpixel(x-0,y+2,textcolor);
			//putpixel(x+1,y+2,textcolor);
			//putpixel(x+2,y+2,textcolor);
			
			//+3
    		//putpixel(x-2,y+3,textcolor);
			//putpixel(x-1,y+3,textcolor);
			putpixel(x-0,y+3,textcolor);
			//putpixel(x+1,y+3,textcolor);
			//putpixel(x+2,y+3,textcolor);
			
			break;
		
		case 'U':
			//-3
			putpixel(x-2,y-3,textcolor);
			//putpixel(x-1,y-3,textcolor);
			//putpixel(x-0,y-3,textcolor);
			//putpixel(x+1,y-3,textcolor);
			putpixel(x+2,y-3,textcolor);
			
			//-2
			putpixel(x-2,y-2,textcolor);
			//putpixel(x-1,y-2,textcolor);
			//putpixel(x-0,y-2,textcolor);
			//putpixel(x+1,y-2,textcolor);
			putpixel(x+2,y-2,textcolor);
 			
 			//-1
 			putpixel(x-2,y-1,textcolor);
			//putpixel(x-1,y-1,textcolor);
			//putpixel(x-0,y-1,textcolor);
			//putpixel(x+1,y-1,textcolor);
			putpixel(x+2,y-1,textcolor);
			
			//0
			putpixel(x-2,y-0,textcolor);
			//putpixel(x-1,y-0,textcolor);
			//putpixel(x-0,y-0,textcolor);
			//putpixel(x+1,y-0,textcolor);
			putpixel(x+2,y-0,textcolor);
			
			//+1
			putpixel(x-2,y+1,textcolor);
			//putpixel(x-1,y+1,textcolor);
			//putpixel(x-0,y+1,textcolor);
			//putpixel(x+1,y+1,textcolor);
			putpixel(x+2,y+1,textcolor);
			
			//+2
			putpixel(x-2,y+2,textcolor);
			//putpixel(x-1,y+2,textcolor);
			//putpixel(x-0,y+2,textcolor);
			//putpixel(x+1,y+2,textcolor);
			putpixel(x+2,y+2,textcolor);
			
			//+3
    		//putpixel(x-2,y+3,textcolor);
			putpixel(x-1,y+3,textcolor);
			putpixel(x-0,y+3,textcolor);
			putpixel(x+1,y+3,textcolor);
			//putpixel(x+2,y+3,textcolor);
			
			break;
			
		case 'V':
			//-3
			putpixel(x-2,y-3,textcolor);
			//putpixel(x-1,y-3,textcolor);
			//putpixel(x-0,y-3,textcolor);
			//putpixel(x+1,y-3,textcolor);
			putpixel(x+2,y-3,textcolor);
			
			//-2
			putpixel(x-2,y-2,textcolor);
			//putpixel(x-1,y-2,textcolor);
			//putpixel(x-0,y-2,textcolor);
			//putpixel(x+1,y-2,textcolor);
			putpixel(x+2,y-2,textcolor);
 			
 			//-1
 			putpixel(x-2,y-1,textcolor);
			//putpixel(x-1,y-1,textcolor);
			//putpixel(x-0,y-1,textcolor);
			//putpixel(x+1,y-1,textcolor);
			putpixel(x+2,y-1,textcolor);
			
			//0
			putpixel(x-2,y-0,textcolor);
			//putpixel(x-1,y-0,textcolor);
			//putpixel(x-0,y-0,textcolor);
			//putpixel(x+1,y-0,textcolor);
			putpixel(x+2,y-0,textcolor);
			
			//+1
			//putpixel(x-2,y+1,textcolor);
			putpixel(x-1,y+1,textcolor);
			//putpixel(x-0,y+1,textcolor);
			putpixel(x+1,y+1,textcolor);
			//putpixel(x+2,y+1,textcolor);
			
			//+2
			//putpixel(x-2,y+2,textcolor);
			putpixel(x-1,y+2,textcolor);
			//putpixel(x-0,y+2,textcolor);
			putpixel(x+1,y+2,textcolor);
			//putpixel(x+2,y+2,textcolor);
			
			//+3
    		//putpixel(x-2,y+3,textcolor);
			//putpixel(x-1,y+3,textcolor);
			putpixel(x-0,y+3,textcolor);
			//putpixel(x+1,y+3,textcolor);
			//putpixel(x+2,y+3,textcolor);
			
			break;
		
		case 'W':
			//-3
			putpixel(x-2,y-3,textcolor);
			//putpixel(x-1,y-3,textcolor);
			//putpixel(x-0,y-3,textcolor);
			//putpixel(x+1,y-3,textcolor);
			putpixel(x+2,y-3,textcolor);
			
			//-2
			putpixel(x-2,y-2,textcolor);
			//putpixel(x-1,y-2,textcolor);
			//putpixel(x-0,y-2,textcolor);
			//putpixel(x+1,y-2,textcolor);
			putpixel(x+2,y-2,textcolor);
 			
 			//-1
 			putpixel(x-2,y-1,textcolor);
			//putpixel(x-1,y-1,textcolor);
			//putpixel(x-0,y-1,textcolor);
			//putpixel(x+1,y-1,textcolor);
			putpixel(x+2,y-1,textcolor);
			
			//0
			putpixel(x-2,y-0,textcolor);
			//putpixel(x-1,y-0,textcolor);
			putpixel(x-0,y-0,textcolor);
			//putpixel(x+1,y-0,textcolor);
			putpixel(x+2,y-0,textcolor);
			
			//+1
			putpixel(x-2,y+1,textcolor);
			//putpixel(x-1,y+1,textcolor);
			putpixel(x-0,y+1,textcolor);
			//putpixel(x+1,y+1,textcolor);
			putpixel(x+2,y+1,textcolor);
			
			//+2
			putpixel(x-2,y+2,textcolor);
			//putpixel(x-1,y+2,textcolor);
			putpixel(x-0,y+2,textcolor);
			//putpixel(x+1,y+2,textcolor);
			putpixel(x+2,y+2,textcolor);
			
			//+3
    		//putpixel(x-2,y+3,textcolor);
			putpixel(x-1,y+3,textcolor);
			//putpixel(x-0,y+3,textcolor);
			putpixel(x+1,y+3,textcolor);
			//putpixel(x+2,y+3,textcolor);
			
			break;
			
		case 'X':
			//-3
			putpixel(x-2,y-3,textcolor);
			//putpixel(x-1,y-3,textcolor);
			//putpixel(x-0,y-3,textcolor);
			//putpixel(x+1,y-3,textcolor);
			putpixel(x+2,y-3,textcolor);
			
			//-2
			putpixel(x-2,y-2,textcolor);
			//putpixel(x-1,y-2,textcolor);
			//putpixel(x-0,y-2,textcolor);
			//putpixel(x+1,y-2,textcolor);
			putpixel(x+2,y-2,textcolor);
 			
 			//-1
 			//putpixel(x-2,y-1,textcolor);
			putpixel(x-1,y-1,textcolor);
			//putpixel(x-0,y-1,textcolor);
			putpixel(x+1,y-1,textcolor);
			//putpixel(x+2,y-1,textcolor);
			
			//0
			//putpixel(x-2,y-0,textcolor);
			//putpixel(x-1,y-0,textcolor);
			putpixel(x-0,y-0,textcolor);
			//putpixel(x+1,y-0,textcolor);
			//putpixel(x+2,y-0,textcolor);
			
			//+1
			//putpixel(x-2,y+1,textcolor);
			putpixel(x-1,y+1,textcolor);
			//putpixel(x-0,y+1,textcolor);
			putpixel(x+1,y+1,textcolor);
			//putpixel(x+2,y+1,textcolor);
			
			//+2
			putpixel(x-2,y+2,textcolor);
			//putpixel(x-1,y+2,textcolor);
			//putpixel(x-0,y+2,textcolor);
			//putpixel(x+1,y+2,textcolor);
			putpixel(x+2,y+2,textcolor);
			
			//+3
    		putpixel(x-2,y+3,textcolor);
			//putpixel(x-1,y+3,textcolor);
			//putpixel(x-0,y+3,textcolor);
			//putpixel(x+1,y+3,textcolor);
			putpixel(x+2,y+3,textcolor);
			
			break;
		
		case 'Y':
			//-3
			putpixel(x-2,y-3,textcolor);
			//putpixel(x-1,y-3,textcolor);
			//putpixel(x-0,y-3,textcolor);
			//putpixel(x+1,y-3,textcolor);
			putpixel(x+2,y-3,textcolor);
			
			//-2
			putpixel(x-2,y-2,textcolor);
			//putpixel(x-1,y-2,textcolor);
			//putpixel(x-0,y-2,textcolor);
			//putpixel(x+1,y-2,textcolor);
			putpixel(x+2,y-2,textcolor);
 			
 			//-1
 			//putpixel(x-2,y-1,textcolor);
			putpixel(x-1,y-1,textcolor);
			//putpixel(x-0,y-1,textcolor);
			putpixel(x+1,y-1,textcolor);
			//putpixel(x+2,y-1,textcolor);
			
			//0
			//putpixel(x-2,y-0,textcolor);
			//putpixel(x-1,y-0,textcolor);
			putpixel(x-0,y-0,textcolor);
			//putpixel(x+1,y-0,textcolor);
			//putpixel(x+2,y-0,textcolor);
			
			//+1
			//putpixel(x-2,y+1,textcolor);
			//putpixel(x-1,y+1,textcolor);
			putpixel(x-0,y+1,textcolor);
			//putpixel(x+1,y+1,textcolor);
			//putpixel(x+2,y+1,textcolor);
			
			//+2
			//putpixel(x-2,y+2,textcolor);
			//putpixel(x-1,y+2,textcolor);
			putpixel(x-0,y+2,textcolor);
			//putpixel(x+1,y+2,textcolor);
			//putpixel(x+2,y+2,textcolor);
			
			//+3
    		//putpixel(x-2,y+3,textcolor);
			//putpixel(x-1,y+3,textcolor);
			putpixel(x-0,y+3,textcolor);
			//putpixel(x+1,y+3,textcolor);
			//putpixel(x+2,y+3,textcolor);
			
			break;
			
		case 'Z':
			//-3
			putpixel(x-2,y-3,textcolor);
			putpixel(x-1,y-3,textcolor);
			putpixel(x-0,y-3,textcolor);
			putpixel(x+1,y-3,textcolor);
			putpixel(x+2,y-3,textcolor);
			
			//-2
			//putpixel(x-2,y-2,textcolor);
			//putpixel(x-1,y-2,textcolor);
			//putpixel(x-0,y-2,textcolor);
			//putpixel(x+1,y-2,textcolor);
			putpixel(x+2,y-2,textcolor);
 			
 			//-1
 			//putpixel(x-2,y-1,textcolor);
			//putpixel(x-1,y-1,textcolor);
			//putpixel(x-0,y-1,textcolor);
			putpixel(x+1,y-1,textcolor);
			//putpixel(x+2,y-1,textcolor);
			
			//0
			//putpixel(x-2,y-0,textcolor);
			//putpixel(x-1,y-0,textcolor);
			putpixel(x-0,y-0,textcolor);
			//putpixel(x+1,y-0,textcolor);
			//putpixel(x+2,y-0,textcolor);
			
			//+1
			//putpixel(x-2,y+1,textcolor);
			putpixel(x-1,y+1,textcolor);
			//putpixel(x-0,y+1,textcolor);
			//putpixel(x+1,y+1,textcolor);
			//putpixel(x+2,y+1,textcolor);
			
			//+2
			putpixel(x-2,y+2,textcolor);
			//putpixel(x-1,y+2,textcolor);
			//putpixel(x-0,y+2,textcolor);
			//putpixel(x+1,y+2,textcolor);
			//putpixel(x+2,y+2,textcolor);
			
			//+3
    		putpixel(x-2,y+3,textcolor);
			putpixel(x-1,y+3,textcolor);
			putpixel(x-0,y+3,textcolor);
			putpixel(x+1,y+3,textcolor);
			putpixel(x+2,y+3,textcolor);
			
			break;
		default:
			break;
	}
	
	return;
}


#endif
