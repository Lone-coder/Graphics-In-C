#ifndef PutPixel_H
#define PutPixel_H

#include "2DGC.h"

void PutCharacter(char c,int x,int y,int textcolor)
{
	//textcolor=randcolor();
	switch(c)
	{
		case 'A':
			
			//-3
			//PutPixel(x-2,y-3,textcolor);
			PutPixel(x-1,y-3,textcolor);
			PutPixel(x-0,y-3,textcolor);
			PutPixel(x+1,y-3,textcolor);
			//PutPixel(x+2,y-3,textcolor);
			
			//-2
			PutPixel(x-2,y-2,textcolor);
			//PutPixel(x-1,y-2,textcolor);
			//PutPixel(x-0,y-2,textcolor);
			//PutPixel(x+1,y-2,textcolor);
			PutPixel(x+2,y-2,textcolor);
 			
 			//-1
 			PutPixel(x-2,y-1,textcolor);
			//PutPixel(x-1,y-1,textcolor);
			//PutPixel(x-0,y-1,textcolor);
			//PutPixel(x+1,y-1,textcolor);
			PutPixel(x+2,y-1,textcolor);
			
			//0
			PutPixel(x-2,y-0,textcolor);
			PutPixel(x-1,y-0,textcolor);
			PutPixel(x-0,y-0,textcolor);
			PutPixel(x+1,y-0,textcolor);
			PutPixel(x+2,y-0,textcolor);
			
			//+1
			PutPixel(x-2,y+1,textcolor);
			//PutPixel(x-1,y+1,textcolor);
			//PutPixel(x-0,y+1,textcolor);
			//PutPixel(x+1,y+1,textcolor);
			PutPixel(x+2,y+1,textcolor);
			
			//+2
			PutPixel(x-2,y+2,textcolor);
			//PutPixel(x-1,y+2,textcolor);
			//PutPixel(x-0,y+2,textcolor);
			//PutPixel(x+1,y+2,textcolor);
			PutPixel(x+2,y+2,textcolor);
			
			//+3
    		PutPixel(x-2,y+3,textcolor);
			//PutPixel(x-1,y+3,textcolor);
			//PutPixel(x-0,y+3,textcolor);
			//PutPixel(x+1,y+3,textcolor);
			PutPixel(x+2,y+3,textcolor);
			
			break;
			
		case 'B':
			//-3
			PutPixel(x-2,y-3,textcolor);
			PutPixel(x-1,y-3,textcolor);
			PutPixel(x-0,y-3,textcolor);
			PutPixel(x+1,y-3,textcolor);
			//PutPixel(x+2,y-3,textcolor);
			
			//-2
			PutPixel(x-2,y-2,textcolor);
			//PutPixel(x-1,y-2,textcolor);
			//PutPixel(x-0,y-2,textcolor);
			//PutPixel(x+1,y-2,textcolor);
			PutPixel(x+2,y-2,textcolor);
 			
 			//-1
 			PutPixel(x-2,y-1,textcolor);
			//PutPixel(x-1,y-1,textcolor);
			//PutPixel(x-0,y-1,textcolor);
			//PutPixel(x+1,y-1,textcolor);
			PutPixel(x+2,y-1,textcolor);
			
			//0
			PutPixel(x-2,y-0,textcolor);
			PutPixel(x-1,y-0,textcolor);
			PutPixel(x-0,y-0,textcolor);
			PutPixel(x+1,y-0,textcolor);
			//PutPixel(x+2,y-0,textcolor);
			
			//+1
			PutPixel(x-2,y+1,textcolor);
			//PutPixel(x-1,y+1,textcolor);
			//PutPixel(x-0,y+1,textcolor);
			//PutPixel(x+1,y+1,textcolor);
			PutPixel(x+2,y+1,textcolor);
			
			//+2
			PutPixel(x-2,y+2,textcolor);
			//PutPixel(x-1,y+2,textcolor);
			//PutPixel(x-0,y+2,textcolor);
			//PutPixel(x+1,y+2,textcolor);
			PutPixel(x+2,y+2,textcolor);
			
			//+3
    		PutPixel(x-2,y+3,textcolor);
			PutPixel(x-1,y+3,textcolor);
			PutPixel(x-0,y+3,textcolor);
			PutPixel(x+1,y+3,textcolor);
			//PutPixel(x+2,y+3,textcolor);
			
			break;
		
		case 'C':
			//-3
			//PutPixel(x-2,y-3,textcolor);
			PutPixel(x-1,y-3,textcolor);
			PutPixel(x-0,y-3,textcolor);
			PutPixel(x+1,y-3,textcolor);
			//PutPixel(x+2,y-3,textcolor);
			
			//-2
			PutPixel(x-2,y-2,textcolor);
			//PutPixel(x-1,y-2,textcolor);
			//PutPixel(x-0,y-2,textcolor);
			//PutPixel(x+1,y-2,textcolor);
			PutPixel(x+2,y-2,textcolor);
 			
 			//-1
 			PutPixel(x-2,y-1,textcolor);
			//PutPixel(x-1,y-1,textcolor);
			//PutPixel(x-0,y-1,textcolor);
			//PutPixel(x+1,y-1,textcolor);
			//PutPixel(x+2,y-1,textcolor);
			
			//0
			PutPixel(x-2,y-0,textcolor);
			//PutPixel(x-1,y-0,textcolor);
			//PutPixel(x-0,y-0,textcolor);
			//PutPixel(x+1,y-0,textcolor);
			//PutPixel(x+2,y-0,textcolor);
			
			//+1
			PutPixel(x-2,y+1,textcolor);
			//PutPixel(x-1,y+1,textcolor);
			//PutPixel(x-0,y+1,textcolor);
			//PutPixel(x+1,y+1,textcolor);
			//PutPixel(x+2,y+1,textcolor);
			
			//+2
			PutPixel(x-2,y+2,textcolor);
			//PutPixel(x-1,y+2,textcolor);
			//PutPixel(x-0,y+2,textcolor);
			//PutPixel(x+1,y+2,textcolor);
			PutPixel(x+2,y+2,textcolor);
			
			//+3
    		//PutPixel(x-2,y+3,textcolor);
			PutPixel(x-1,y+3,textcolor);
			PutPixel(x-0,y+3,textcolor);
			PutPixel(x+1,y+3,textcolor);
			//PutPixel(x+2,y+3,textcolor);
			
			break;
		
		case 'D':
			//-3
			PutPixel(x-2,y-3,textcolor);
			PutPixel(x-1,y-3,textcolor);
			PutPixel(x-0,y-3,textcolor);
			PutPixel(x+1,y-3,textcolor);
			//PutPixel(x+2,y-3,textcolor);
			
			//-2
			PutPixel(x-2,y-2,textcolor);
			//PutPixel(x-1,y-2,textcolor);
			//PutPixel(x-0,y-2,textcolor);
			//PutPixel(x+1,y-2,textcolor);
			PutPixel(x+2,y-2,textcolor);
 			
 			//-1
 			PutPixel(x-2,y-1,textcolor);
			//PutPixel(x-1,y-1,textcolor);
			//PutPixel(x-0,y-1,textcolor);
			//PutPixel(x+1,y-1,textcolor);
			PutPixel(x+2,y-1,textcolor);
			
			//0
			PutPixel(x-2,y-0,textcolor);
			//PutPixel(x-1,y-0,textcolor);
			//PutPixel(x-0,y-0,textcolor);
			//PutPixel(x+1,y-0,textcolor);
			PutPixel(x+2,y-0,textcolor);
			
			//+1
			PutPixel(x-2,y+1,textcolor);
			//PutPixel(x-1,y+1,textcolor);
			//PutPixel(x-0,y+1,textcolor);
			//PutPixel(x+1,y+1,textcolor);
			PutPixel(x+2,y+1,textcolor);
			
			//+2
			PutPixel(x-2,y+2,textcolor);
			//PutPixel(x-1,y+2,textcolor);
			//PutPixel(x-0,y+2,textcolor);
			//PutPixel(x+1,y+2,textcolor);
			PutPixel(x+2,y+2,textcolor);
			
			//+3
    		PutPixel(x-2,y+3,textcolor);
			PutPixel(x-1,y+3,textcolor);
			PutPixel(x-0,y+3,textcolor);
			PutPixel(x+1,y+3,textcolor);
			//PutPixel(x+2,y+3,textcolor);
			
			break;
			
		case 'E':
			//-3
			PutPixel(x-2,y-3,textcolor);
			PutPixel(x-1,y-3,textcolor);
			PutPixel(x-0,y-3,textcolor);
			PutPixel(x+1,y-3,textcolor);
			PutPixel(x+2,y-3,textcolor);
			
			//-2
			PutPixel(x-2,y-2,textcolor);
			//PutPixel(x-1,y-2,textcolor);
			//PutPixel(x-0,y-2,textcolor);
			//PutPixel(x+1,y-2,textcolor);
			//PutPixel(x+2,y-2,textcolor);
 			
 			//-1
 			PutPixel(x-2,y-1,textcolor);
			//PutPixel(x-1,y-1,textcolor);
			//PutPixel(x-0,y-1,textcolor);
			//PutPixel(x+1,y-1,textcolor);
			//PutPixel(x+2,y-1,textcolor);
			
			//0
			PutPixel(x-2,y-0,textcolor);
			PutPixel(x-1,y-0,textcolor);
			PutPixel(x-0,y-0,textcolor);
			PutPixel(x+1,y-0,textcolor);
			//PutPixel(x+2,y-0,textcolor);
			
			//+1
			PutPixel(x-2,y+1,textcolor);
			//PutPixel(x-1,y+1,textcolor);
			//PutPixel(x-0,y+1,textcolor);
			//PutPixel(x+1,y+1,textcolor);
			//PutPixel(x+2,y+1,textcolor);
			
			//+2
			PutPixel(x-2,y+2,textcolor);
			//PutPixel(x-1,y+2,textcolor);
			//PutPixel(x-0,y+2,textcolor);
			//PutPixel(x+1,y+2,textcolor);
			//PutPixel(x+2,y+2,textcolor);
			
			//+3
    		PutPixel(x-2,y+3,textcolor);
			PutPixel(x-1,y+3,textcolor);
			PutPixel(x-0,y+3,textcolor);
			PutPixel(x+1,y+3,textcolor);
			PutPixel(x+2,y+3,textcolor);
			
			break;
			
		case 'F':
			//-3
			PutPixel(x-2,y-3,textcolor);
			PutPixel(x-1,y-3,textcolor);
			PutPixel(x-0,y-3,textcolor);
			PutPixel(x+1,y-3,textcolor);
			PutPixel(x+2,y-3,textcolor);
			
			//-2
			PutPixel(x-2,y-2,textcolor);
			//PutPixel(x-1,y-2,textcolor);
			//PutPixel(x-0,y-2,textcolor);
			//PutPixel(x+1,y-2,textcolor);
			//PutPixel(x+2,y-2,textcolor);
 			
 			//-1
 			PutPixel(x-2,y-1,textcolor);
			//PutPixel(x-1,y-1,textcolor);
			//PutPixel(x-0,y-1,textcolor);
			//PutPixel(x+1,y-1,textcolor);
			//PutPixel(x+2,y-1,textcolor);
			
			//0
			PutPixel(x-2,y-0,textcolor);
			PutPixel(x-1,y-0,textcolor);
			PutPixel(x-0,y-0,textcolor);
			PutPixel(x+1,y-0,textcolor);
			//PutPixel(x+2,y-0,textcolor);
			
			//+1
			PutPixel(x-2,y+1,textcolor);
			//PutPixel(x-1,y+1,textcolor);
			//PutPixel(x-0,y+1,textcolor);
			//PutPixel(x+1,y+1,textcolor);
			//PutPixel(x+2,y+1,textcolor);
			
			//+2
			PutPixel(x-2,y+2,textcolor);
			//PutPixel(x-1,y+2,textcolor);
			//PutPixel(x-0,y+2,textcolor);
			//PutPixel(x+1,y+2,textcolor);
			//PutPixel(x+2,y+2,textcolor);
			
			//+3
    		PutPixel(x-2,y+3,textcolor);
			//PutPixel(x-1,y+3,textcolor);
			//PutPixel(x-0,y+3,textcolor);
			//PutPixel(x+1,y+3,textcolor);
			//PutPixel(x+2,y+3,textcolor);
			
			break;
		
		case 'G':
			//-3
			//PutPixel(x-2,y-3,textcolor);
			PutPixel(x-1,y-3,textcolor);
			PutPixel(x-0,y-3,textcolor);
			PutPixel(x+1,y-3,textcolor);
			//PutPixel(x+2,y-3,textcolor);
			
			//-2
			PutPixel(x-2,y-2,textcolor);
			//PutPixel(x-1,y-2,textcolor);
			//PutPixel(x-0,y-2,textcolor);
			//PutPixel(x+1,y-2,textcolor);
			PutPixel(x+2,y-2,textcolor);
 			
 			//-1
 			PutPixel(x-2,y-1,textcolor);
			//PutPixel(x-1,y-1,textcolor);
			//PutPixel(x-0,y-1,textcolor);
			//PutPixel(x+1,y-1,textcolor);
			//PutPixel(x+2,y-1,textcolor);
			
			//0
			PutPixel(x-2,y-0,textcolor);
			//PutPixel(x-1,y-0,textcolor);
			//PutPixel(x-0,y-0,textcolor);
			//PutPixel(x+1,y-0,textcolor);
			//PutPixel(x+2,y-0,textcolor);
			
			//+1
			PutPixel(x-2,y+1,textcolor);
			//PutPixel(x-1,y+1,textcolor);
			//PutPixel(x-0,y+1,textcolor);
			PutPixel(x+1,y+1,textcolor);
			PutPixel(x+2,y+1,textcolor);
			
			//+2
			PutPixel(x-2,y+2,textcolor);
			//PutPixel(x-1,y+2,textcolor);
			//PutPixel(x-0,y+2,textcolor);
			//PutPixel(x+1,y+2,textcolor);
			PutPixel(x+2,y+2,textcolor);
			
			//+3
    		//PutPixel(x-2,y+3,textcolor);
			PutPixel(x-1,y+3,textcolor);
			PutPixel(x-0,y+3,textcolor);
			PutPixel(x+1,y+3,textcolor);
			//PutPixel(x+2,y+3,textcolor);
			
			break;
			
		case 'H':
			//-3
			PutPixel(x-2,y-3,textcolor);
			//PutPixel(x-1,y-3,textcolor);
			//PutPixel(x-0,y-3,textcolor);
			//PutPixel(x+1,y-3,textcolor);
			PutPixel(x+2,y-3,textcolor);
			
			//-2
			PutPixel(x-2,y-2,textcolor);
			//PutPixel(x-1,y-2,textcolor);
			//PutPixel(x-0,y-2,textcolor);
			//PutPixel(x+1,y-2,textcolor);
			PutPixel(x+2,y-2,textcolor);
 			
 			//-1
 			PutPixel(x-2,y-1,textcolor);
			//PutPixel(x-1,y-1,textcolor);
			//PutPixel(x-0,y-1,textcolor);
			//PutPixel(x+1,y-1,textcolor);
			PutPixel(x+2,y-1,textcolor);
			
			//0
			PutPixel(x-2,y-0,textcolor);
			PutPixel(x-1,y-0,textcolor);
			PutPixel(x-0,y-0,textcolor);
			PutPixel(x+1,y-0,textcolor);
			PutPixel(x+2,y-0,textcolor);
			
			//+1
			PutPixel(x-2,y+1,textcolor);
			//PutPixel(x-1,y+1,textcolor);
			//PutPixel(x-0,y+1,textcolor);
			//PutPixel(x+1,y+1,textcolor);
			PutPixel(x+2,y+1,textcolor);
			
			//+2
			PutPixel(x-2,y+2,textcolor);
			//PutPixel(x-1,y+2,textcolor);
			//PutPixel(x-0,y+2,textcolor);
			//PutPixel(x+1,y+2,textcolor);
			PutPixel(x+2,y+2,textcolor);
			
			//+3
    		PutPixel(x-2,y+3,textcolor);
			//PutPixel(x-1,y+3,textcolor);
			//PutPixel(x-0,y+3,textcolor);
			//PutPixel(x+1,y+3,textcolor);
			PutPixel(x+2,y+3,textcolor);
			
			break;
			
		case 'I':
			//-3
			//PutPixel(x-2,y-3,textcolor);
			PutPixel(x-1,y-3,textcolor);
			PutPixel(x-0,y-3,textcolor);
			PutPixel(x+1,y-3,textcolor);
			//PutPixel(x+2,y-3,textcolor);
			
			//-2
			//PutPixel(x-2,y-2,textcolor);
			//PutPixel(x-1,y-2,textcolor);
			PutPixel(x-0,y-2,textcolor);
			//PutPixel(x+1,y-2,textcolor);
			//PutPixel(x+2,y-2,textcolor);
 			
 			//-1
 			//PutPixel(x-2,y-1,textcolor);
			//PutPixel(x-1,y-1,textcolor);
			PutPixel(x-0,y-1,textcolor);
			//PutPixel(x+1,y-1,textcolor);
			//PutPixel(x+2,y-1,textcolor);
			
			//0
			//PutPixel(x-2,y-0,textcolor);
			//PutPixel(x-1,y-0,textcolor);
			PutPixel(x-0,y-0,textcolor);
			//PutPixel(x+1,y-0,textcolor);
			//PutPixel(x+2,y-0,textcolor);
			
			//+1
			//PutPixel(x-2,y+1,textcolor);
			//PutPixel(x-1,y+1,textcolor);
			PutPixel(x-0,y+1,textcolor);
			//PutPixel(x+1,y+1,textcolor);
			//PutPixel(x+2,y+1,textcolor);
			
			//+2
			//PutPixel(x-2,y+2,textcolor);
			//PutPixel(x-1,y+2,textcolor);
			PutPixel(x-0,y+2,textcolor);
			//PutPixel(x+1,y+2,textcolor);
			//PutPixel(x+2,y+2,textcolor);
			
			//+3
    		//PutPixel(x-2,y+3,textcolor);
			PutPixel(x-1,y+3,textcolor);
			PutPixel(x-0,y+3,textcolor);
			PutPixel(x+1,y+3,textcolor);
			//PutPixel(x+2,y+3,textcolor);
		
		break;
		
		case 'J':
			//-3
			//PutPixel(x-2,y-3,textcolor);
			//PutPixel(x-1,y-3,textcolor);
			PutPixel(x-0,y-3,textcolor);
			PutPixel(x+1,y-3,textcolor);
			PutPixel(x+2,y-3,textcolor);
			
			//-2
			//PutPixel(x-2,y-2,textcolor);
			//PutPixel(x-1,y-2,textcolor);
			//PutPixel(x-0,y-2,textcolor);
			PutPixel(x+1,y-2,textcolor);
			//PutPixel(x+2,y-2,textcolor);
 			
 			//-1
 			//PutPixel(x-2,y-1,textcolor);
			//PutPixel(x-1,y-1,textcolor);
			//PutPixel(x-0,y-1,textcolor);
			PutPixel(x+1,y-1,textcolor);
			//PutPixel(x+2,y-1,textcolor);
			
			//0
			//PutPixel(x-2,y-0,textcolor);
			//PutPixel(x-1,y-0,textcolor);
			//PutPixel(x-0,y-0,textcolor);
			PutPixel(x+1,y-0,textcolor);
			//PutPixel(x+2,y-0,textcolor);
			
			//+1
			//PutPixel(x-2,y+1,textcolor);
			//PutPixel(x-1,y+1,textcolor);
			//PutPixel(x-0,y+1,textcolor);
			PutPixel(x+1,y+1,textcolor);
			//PutPixel(x+2,y+1,textcolor);
			
			//+2
			PutPixel(x-2,y+2,textcolor);
			//PutPixel(x-1,y+2,textcolor);
			//PutPixel(x-0,y+2,textcolor);
			PutPixel(x+1,y+2,textcolor);
			//PutPixel(x+2,y+2,textcolor);
			
			//+3
    		//PutPixel(x-2,y+3,textcolor);
			PutPixel(x-1,y+3,textcolor);
			PutPixel(x-0,y+3,textcolor);
			//PutPixel(x+1,y+3,textcolor);
			//PutPixel(x+2,y+3,textcolor);
			
			break;
		
		case 'K':		
			//-3
			PutPixel(x-2,y-3,textcolor);
			//PutPixel(x-1,y-3,textcolor);
			//PutPixel(x-0,y-3,textcolor);
			//PutPixel(x+1,y-3,textcolor);
			PutPixel(x+2,y-3,textcolor);
			
			//-2
			PutPixel(x-2,y-2,textcolor);
			//PutPixel(x-1,y-2,textcolor);
			//PutPixel(x-0,y-2,textcolor);
			PutPixel(x+1,y-2,textcolor);
			//PutPixel(x+2,y-2,textcolor);
 			
 			//-1
 			PutPixel(x-2,y-1,textcolor);
			//PutPixel(x-1,y-1,textcolor);
			PutPixel(x-0,y-1,textcolor);
			//PutPixel(x+1,y-1,textcolor);
			//PutPixel(x+2,y-1,textcolor);
			
			//0
			PutPixel(x-2,y-0,textcolor);
			PutPixel(x-1,y-0,textcolor);
			//PutPixel(x-0,y-0,textcolor);
			//PutPixel(x+1,y-0,textcolor);
			//PutPixel(x+2,y-0,textcolor);
			
			//+1
			PutPixel(x-2,y+1,textcolor);
			//PutPixel(x-1,y+1,textcolor);
			PutPixel(x-0,y+1,textcolor);
			//PutPixel(x+1,y+1,textcolor);
			//PutPixel(x+2,y+1,textcolor);
			
			//+2
			PutPixel(x-2,y+2,textcolor);
			//PutPixel(x-1,y+2,textcolor);
			//PutPixel(x-0,y+2,textcolor);
			PutPixel(x+1,y+2,textcolor);
			//PutPixel(x+2,y+2,textcolor);
			
			//+3
    		PutPixel(x-2,y+3,textcolor);
			//PutPixel(x-1,y+3,textcolor);
			//PutPixel(x-0,y+3,textcolor);
			//PutPixel(x+1,y+3,textcolor);
			PutPixel(x+2,y+3,textcolor);
			
			break;
			
		case 'L':
			//-3
			PutPixel(x-2,y-3,textcolor);
			//PutPixel(x-1,y-3,textcolor);
			//PutPixel(x-0,y-3,textcolor);
			//PutPixel(x+1,y-3,textcolor);
			//PutPixel(x+2,y-3,textcolor);
			
			//-2
			PutPixel(x-2,y-2,textcolor);
			//PutPixel(x-1,y-2,textcolor);
			//PutPixel(x-0,y-2,textcolor);
			//PutPixel(x+1,y-2,textcolor);
			//PutPixel(x+2,y-2,textcolor);
 			
 			//-1
 			PutPixel(x-2,y-1,textcolor);
			//PutPixel(x-1,y-1,textcolor);
			//PutPixel(x-0,y-1,textcolor);
			//PutPixel(x+1,y-1,textcolor);
			//PutPixel(x+2,y-1,textcolor);
			
			//0
			PutPixel(x-2,y-0,textcolor);
			//PutPixel(x-1,y-0,textcolor);
			//PutPixel(x-0,y-0,textcolor);
			//PutPixel(x+1,y-0,textcolor);
			//PutPixel(x+2,y-0,textcolor);
			
			//+1
			PutPixel(x-2,y+1,textcolor);
			//PutPixel(x-1,y+1,textcolor);
			//PutPixel(x-0,y+1,textcolor);
			//PutPixel(x+1,y+1,textcolor);
			//PutPixel(x+2,y+1,textcolor);
			
			//+2
			PutPixel(x-2,y+2,textcolor);
			//PutPixel(x-1,y+2,textcolor);
			//PutPixel(x-0,y+2,textcolor);
			//PutPixel(x+1,y+2,textcolor);
			//PutPixel(x+2,y+2,textcolor);
			
			//+3
    		PutPixel(x-2,y+3,textcolor);
			PutPixel(x-1,y+3,textcolor);
			PutPixel(x-0,y+3,textcolor);
			PutPixel(x+1,y+3,textcolor);
			PutPixel(x+2,y+3,textcolor);	
    		
    		break;
    		
    	case 'M':
    		//-3
			PutPixel(x-2,y-3,textcolor);
			//PutPixel(x-1,y-3,textcolor);
			//PutPixel(x-0,y-3,textcolor);
			//PutPixel(x+1,y-3,textcolor);
			PutPixel(x+2,y-3,textcolor);
			
			//-2
			PutPixel(x-2,y-2,textcolor);
			PutPixel(x-1,y-2,textcolor);
			//PutPixel(x-0,y-2,textcolor);
			PutPixel(x+1,y-2,textcolor);
			PutPixel(x+2,y-2,textcolor);
 			
 			//-1
 			PutPixel(x-2,y-1,textcolor);
			//PutPixel(x-1,y-1,textcolor);
			PutPixel(x-0,y-1,textcolor);
			//PutPixel(x+1,y-1,textcolor);
			PutPixel(x+2,y-1,textcolor);
			
			//0
			PutPixel(x-2,y-0,textcolor);
			//PutPixel(x-1,y-0,textcolor);
			PutPixel(x-0,y-0,textcolor);
			//PutPixel(x+1,y-0,textcolor);
			PutPixel(x+2,y-0,textcolor);
			
			//+1
			PutPixel(x-2,y+1,textcolor);
			//PutPixel(x-1,y+1,textcolor);
			//PutPixel(x-0,y+1,textcolor);
			//PutPixel(x+1,y+1,textcolor);
			PutPixel(x+2,y+1,textcolor);
			
			//+2
			PutPixel(x-2,y+2,textcolor);
			//PutPixel(x-1,y+2,textcolor);
			//PutPixel(x-0,y+2,textcolor);
			//PutPixel(x+1,y+2,textcolor);
			PutPixel(x+2,y+2,textcolor);
			
			//+3
    		PutPixel(x-2,y+3,textcolor);
			//PutPixel(x-1,y+3,textcolor);
			//PutPixel(x-0,y+3,textcolor);
			//PutPixel(x+1,y+3,textcolor);
			PutPixel(x+2,y+3,textcolor);
			
			break;
			
		case 'N':
			//-3
			PutPixel(x-2,y-3,textcolor);
			//PutPixel(x-1,y-3,textcolor);
			//PutPixel(x-0,y-3,textcolor);
			//PutPixel(x+1,y-3,textcolor);
			PutPixel(x+2,y-3,textcolor);
			
			//-2
			PutPixel(x-2,y-2,textcolor);
			//PutPixel(x-1,y-2,textcolor);
			//PutPixel(x-0,y-2,textcolor);
			//PutPixel(x+1,y-2,textcolor);
			PutPixel(x+2,y-2,textcolor);
 			
 			//-1
 			PutPixel(x-2,y-1,textcolor);
			PutPixel(x-1,y-1,textcolor);
			//PutPixel(x-0,y-1,textcolor);
			//PutPixel(x+1,y-1,textcolor);
			PutPixel(x+2,y-1,textcolor);
			
			//0
			PutPixel(x-2,y-0,textcolor);
			//PutPixel(x-1,y-0,textcolor);
			PutPixel(x-0,y-0,textcolor);
			//PutPixel(x+1,y-0,textcolor);
			PutPixel(x+2,y-0,textcolor);
			
			//+1
			PutPixel(x-2,y+1,textcolor);
			//PutPixel(x-1,y+1,textcolor);
			//PutPixel(x-0,y+1,textcolor);
			PutPixel(x+1,y+1,textcolor);
			PutPixel(x+2,y+1,textcolor);
			
			//+2
			PutPixel(x-2,y+2,textcolor);
			//PutPixel(x-1,y+2,textcolor);
			//PutPixel(x-0,y+2,textcolor);
			//PutPixel(x+1,y+2,textcolor);
			PutPixel(x+2,y+2,textcolor);
			
			//+3
    		PutPixel(x-2,y+3,textcolor);
			//PutPixel(x-1,y+3,textcolor);
			//PutPixel(x-0,y+3,textcolor);
			//PutPixel(x+1,y+3,textcolor);
			PutPixel(x+2,y+3,textcolor);
			
			break;
			
		case 'O':
			//-3
			//PutPixel(x-2,y-3,textcolor);
			PutPixel(x-1,y-3,textcolor);
			PutPixel(x-0,y-3,textcolor);
			PutPixel(x+1,y-3,textcolor);
			//PutPixel(x+2,y-3,textcolor);
			
			//-2
			PutPixel(x-2,y-2,textcolor);
			//PutPixel(x-1,y-2,textcolor);
			//PutPixel(x-0,y-2,textcolor);
			//PutPixel(x+1,y-2,textcolor);
			PutPixel(x+2,y-2,textcolor);
 			
 			//-1
 			PutPixel(x-2,y-1,textcolor);
			//PutPixel(x-1,y-1,textcolor);
			//PutPixel(x-0,y-1,textcolor);
			//PutPixel(x+1,y-1,textcolor);
			PutPixel(x+2,y-1,textcolor);
			
			//0
			PutPixel(x-2,y-0,textcolor);
			//PutPixel(x-1,y-0,textcolor);
			//PutPixel(x-0,y-0,textcolor);
			//PutPixel(x+1,y-0,textcolor);
			PutPixel(x+2,y-0,textcolor);
			
			//+1
			PutPixel(x-2,y+1,textcolor);
			//PutPixel(x-1,y+1,textcolor);
			//PutPixel(x-0,y+1,textcolor);
			//PutPixel(x+1,y+1,textcolor);
			PutPixel(x+2,y+1,textcolor);
			
			//+2
			PutPixel(x-2,y+2,textcolor);
			//PutPixel(x-1,y+2,textcolor);
			//PutPixel(x-0,y+2,textcolor);
			//PutPixel(x+1,y+2,textcolor);
			PutPixel(x+2,y+2,textcolor);
			
			//+3
    		//PutPixel(x-2,y+3,textcolor);
			PutPixel(x-1,y+3,textcolor);
			PutPixel(x-0,y+3,textcolor);
			PutPixel(x+1,y+3,textcolor);
			//PutPixel(x+2,y+3,textcolor);
			
			break;
			
		case 'P':
			//-3
			PutPixel(x-2,y-3,textcolor);
			PutPixel(x-1,y-3,textcolor);
			PutPixel(x-0,y-3,textcolor);
			PutPixel(x+1,y-3,textcolor);
			//PutPixel(x+2,y-3,textcolor);
			
			//-2
			PutPixel(x-2,y-2,textcolor);
			//PutPixel(x-1,y-2,textcolor);
			//PutPixel(x-0,y-2,textcolor);
			//PutPixel(x+1,y-2,textcolor);
			PutPixel(x+2,y-2,textcolor);
 			
 			//-1
 			PutPixel(x-2,y-1,textcolor);
			//PutPixel(x-1,y-1,textcolor);
			//PutPixel(x-0,y-1,textcolor);
			//PutPixel(x+1,y-1,textcolor);
			PutPixel(x+2,y-1,textcolor);
			
			//0
			PutPixel(x-2,y-0,textcolor);
			PutPixel(x-1,y-0,textcolor);
			PutPixel(x-0,y-0,textcolor);
			PutPixel(x+1,y-0,textcolor);
			//PutPixel(x+2,y-0,textcolor);
			
			//+1
			PutPixel(x-2,y+1,textcolor);
			//PutPixel(x-1,y+1,textcolor);
			//PutPixel(x-0,y+1,textcolor);
			//PutPixel(x+1,y+1,textcolor);
			//PutPixel(x+2,y+1,textcolor);
			
			//+2
			PutPixel(x-2,y+2,textcolor);
			//PutPixel(x-1,y+2,textcolor);
			//PutPixel(x-0,y+2,textcolor);
			//PutPixel(x+1,y+2,textcolor);
			//PutPixel(x+2,y+2,textcolor);
			
			//+3
    		PutPixel(x-2,y+3,textcolor);
			//PutPixel(x-1,y+3,textcolor);
			//PutPixel(x-0,y+3,textcolor);
			//PutPixel(x+1,y+3,textcolor);
			//PutPixel(x+2,y+3,textcolor);
			
			break;
			
		case 'Q':
			//-3
			//PutPixel(x-2,y-3,textcolor);
			PutPixel(x-1,y-3,textcolor);
			PutPixel(x-0,y-3,textcolor);
			PutPixel(x+1,y-3,textcolor);
			//PutPixel(x+2,y-3,textcolor);
			
			//-2
			PutPixel(x-2,y-2,textcolor);
			//PutPixel(x-1,y-2,textcolor);
			//PutPixel(x-0,y-2,textcolor);
			//PutPixel(x+1,y-2,textcolor);
			PutPixel(x+2,y-2,textcolor);
 			
 			//-1
 			PutPixel(x-2,y-1,textcolor);
			//PutPixel(x-1,y-1,textcolor);
			//PutPixel(x-0,y-1,textcolor);
			//PutPixel(x+1,y-1,textcolor);
			PutPixel(x+2,y-1,textcolor);
			
			//0
			PutPixel(x-2,y-0,textcolor);
			//PutPixel(x-1,y-0,textcolor);
			//PutPixel(x-0,y-0,textcolor);
			//PutPixel(x+1,y-0,textcolor);
			PutPixel(x+2,y-0,textcolor);
			
			//+1
			PutPixel(x-2,y+1,textcolor);
			//PutPixel(x-1,y+1,textcolor);
			PutPixel(x-0,y+1,textcolor);
			//PutPixel(x+1,y+1,textcolor);
			PutPixel(x+2,y+1,textcolor);
			
			//+2
			PutPixel(x-2,y+2,textcolor);
			//PutPixel(x-1,y+2,textcolor);
			//PutPixel(x-0,y+2,textcolor);
			PutPixel(x+1,y+2,textcolor);
			//PutPixel(x+2,y+2,textcolor);
			
			//+3
    		//PutPixel(x-2,y+3,textcolor);
			PutPixel(x-1,y+3,textcolor);
			PutPixel(x-0,y+3,textcolor);
			//PutPixel(x+1,y+3,textcolor);
			PutPixel(x+2,y+3,textcolor);
			
			break;
			
		case 'R':
			//-3
			PutPixel(x-2,y-3,textcolor);
			PutPixel(x-1,y-3,textcolor);
			PutPixel(x-0,y-3,textcolor);
			PutPixel(x+1,y-3,textcolor);
			//PutPixel(x+2,y-3,textcolor);
			
			//-2
			PutPixel(x-2,y-2,textcolor);
			//PutPixel(x-1,y-2,textcolor);
			//PutPixel(x-0,y-2,textcolor);
			//PutPixel(x+1,y-2,textcolor);
			PutPixel(x+2,y-2,textcolor);
 			
 			//-1
 			PutPixel(x-2,y-1,textcolor);
			//PutPixel(x-1,y-1,textcolor);
			//PutPixel(x-0,y-1,textcolor);
			//PutPixel(x+1,y-1,textcolor);
			PutPixel(x+2,y-1,textcolor);
			
			//0
			PutPixel(x-2,y-0,textcolor);
			PutPixel(x-1,y-0,textcolor);
			PutPixel(x-0,y-0,textcolor);
			PutPixel(x+1,y-0,textcolor);
			//PutPixel(x+2,y-0,textcolor);
			
			//+1
			PutPixel(x-2,y+1,textcolor);
			//PutPixel(x-1,y+1,textcolor);
			PutPixel(x-0,y+1,textcolor);
			//PutPixel(x+1,y+1,textcolor);
			//PutPixel(x+2,y+1,textcolor);
			
			//+2
			PutPixel(x-2,y+2,textcolor);
			//PutPixel(x-1,y+2,textcolor);
			//PutPixel(x-0,y+2,textcolor);
			PutPixel(x+1,y+2,textcolor);
			//PutPixel(x+2,y+2,textcolor);
			
			//+3
    		PutPixel(x-2,y+3,textcolor);
			//PutPixel(x-1,y+3,textcolor);
			//PutPixel(x-0,y+3,textcolor);
			//PutPixel(x+1,y+3,textcolor);
			PutPixel(x+2,y+3,textcolor);
			
			break;
			
		case 'S':
			//-3
			//PutPixel(x-2,y-3,textcolor);
			PutPixel(x-1,y-3,textcolor);
			PutPixel(x-0,y-3,textcolor);
			PutPixel(x+1,y-3,textcolor);
			PutPixel(x+2,y-3,textcolor);
			
			//-2
			PutPixel(x-2,y-2,textcolor);
			//PutPixel(x-1,y-2,textcolor);
			//PutPixel(x-0,y-2,textcolor);
			//PutPixel(x+1,y-2,textcolor);
			//PutPixel(x+2,y-2,textcolor);
 			
 			//-1
 			PutPixel(x-2,y-1,textcolor);
			//PutPixel(x-1,y-1,textcolor);
			//PutPixel(x-0,y-1,textcolor);
			//PutPixel(x+1,y-1,textcolor);
			//PutPixel(x+2,y-1,textcolor);
			
			//0
			//PutPixel(x-2,y-0,textcolor);
			PutPixel(x-1,y-0,textcolor);
			PutPixel(x-0,y-0,textcolor);
			PutPixel(x+1,y-0,textcolor);
			//PutPixel(x+2,y-0,textcolor);
			
			//+1
			//PutPixel(x-2,y+1,textcolor);
			//PutPixel(x-1,y+1,textcolor);
			//PutPixel(x-0,y+1,textcolor);
			//PutPixel(x+1,y+1,textcolor);
			PutPixel(x+2,y+1,textcolor);
			
			//+2
			//PutPixel(x-2,y+2,textcolor);
			//PutPixel(x-1,y+2,textcolor);
			//PutPixel(x-0,y+2,textcolor);
			//PutPixel(x+1,y+2,textcolor);
			PutPixel(x+2,y+2,textcolor);
			
			//+3
    		PutPixel(x-2,y+3,textcolor);
			PutPixel(x-1,y+3,textcolor);
			PutPixel(x-0,y+3,textcolor);
			PutPixel(x+1,y+3,textcolor);
			//PutPixel(x+2,y+3,textcolor);
			
			break;
			
		case 'T':
			//-3
			PutPixel(x-2,y-3,textcolor);
			PutPixel(x-1,y-3,textcolor);
			PutPixel(x-0,y-3,textcolor);
			PutPixel(x+1,y-3,textcolor);
			PutPixel(x+2,y-3,textcolor);
			
			//-2
			//PutPixel(x-2,y-2,textcolor);
			//PutPixel(x-1,y-2,textcolor);
			PutPixel(x-0,y-2,textcolor);
			//PutPixel(x+1,y-2,textcolor);
			//PutPixel(x+2,y-2,textcolor);
 			
 			//-1
 			//PutPixel(x-2,y-1,textcolor);
			//PutPixel(x-1,y-1,textcolor);
			PutPixel(x-0,y-1,textcolor);
			//PutPixel(x+1,y-1,textcolor);
			//PutPixel(x+2,y-1,textcolor);
			
			//0
			//PutPixel(x-2,y-0,textcolor);
			//PutPixel(x-1,y-0,textcolor);
			PutPixel(x-0,y-0,textcolor);
			//PutPixel(x+1,y-0,textcolor);
			//PutPixel(x+2,y-0,textcolor);
			
			//+1
			//PutPixel(x-2,y+1,textcolor);
			//PutPixel(x-1,y+1,textcolor);
			PutPixel(x-0,y+1,textcolor);
			//PutPixel(x+1,y+1,textcolor);
			//PutPixel(x+2,y+1,textcolor);
			
			//+2
			//PutPixel(x-2,y+2,textcolor);
			//PutPixel(x-1,y+2,textcolor);
			PutPixel(x-0,y+2,textcolor);
			//PutPixel(x+1,y+2,textcolor);
			//PutPixel(x+2,y+2,textcolor);
			
			//+3
    		//PutPixel(x-2,y+3,textcolor);
			//PutPixel(x-1,y+3,textcolor);
			PutPixel(x-0,y+3,textcolor);
			//PutPixel(x+1,y+3,textcolor);
			//PutPixel(x+2,y+3,textcolor);
			
			break;
		
		case 'U':
			//-3
			PutPixel(x-2,y-3,textcolor);
			//PutPixel(x-1,y-3,textcolor);
			//PutPixel(x-0,y-3,textcolor);
			//PutPixel(x+1,y-3,textcolor);
			PutPixel(x+2,y-3,textcolor);
			
			//-2
			PutPixel(x-2,y-2,textcolor);
			//PutPixel(x-1,y-2,textcolor);
			//PutPixel(x-0,y-2,textcolor);
			//PutPixel(x+1,y-2,textcolor);
			PutPixel(x+2,y-2,textcolor);
 			
 			//-1
 			PutPixel(x-2,y-1,textcolor);
			//PutPixel(x-1,y-1,textcolor);
			//PutPixel(x-0,y-1,textcolor);
			//PutPixel(x+1,y-1,textcolor);
			PutPixel(x+2,y-1,textcolor);
			
			//0
			PutPixel(x-2,y-0,textcolor);
			//PutPixel(x-1,y-0,textcolor);
			//PutPixel(x-0,y-0,textcolor);
			//PutPixel(x+1,y-0,textcolor);
			PutPixel(x+2,y-0,textcolor);
			
			//+1
			PutPixel(x-2,y+1,textcolor);
			//PutPixel(x-1,y+1,textcolor);
			//PutPixel(x-0,y+1,textcolor);
			//PutPixel(x+1,y+1,textcolor);
			PutPixel(x+2,y+1,textcolor);
			
			//+2
			PutPixel(x-2,y+2,textcolor);
			//PutPixel(x-1,y+2,textcolor);
			//PutPixel(x-0,y+2,textcolor);
			//PutPixel(x+1,y+2,textcolor);
			PutPixel(x+2,y+2,textcolor);
			
			//+3
    		//PutPixel(x-2,y+3,textcolor);
			PutPixel(x-1,y+3,textcolor);
			PutPixel(x-0,y+3,textcolor);
			PutPixel(x+1,y+3,textcolor);
			//PutPixel(x+2,y+3,textcolor);
			
			break;
			
		case 'V':
			//-3
			PutPixel(x-2,y-3,textcolor);
			//PutPixel(x-1,y-3,textcolor);
			//PutPixel(x-0,y-3,textcolor);
			//PutPixel(x+1,y-3,textcolor);
			PutPixel(x+2,y-3,textcolor);
			
			//-2
			PutPixel(x-2,y-2,textcolor);
			//PutPixel(x-1,y-2,textcolor);
			//PutPixel(x-0,y-2,textcolor);
			//PutPixel(x+1,y-2,textcolor);
			PutPixel(x+2,y-2,textcolor);
 			
 			//-1
 			PutPixel(x-2,y-1,textcolor);
			//PutPixel(x-1,y-1,textcolor);
			//PutPixel(x-0,y-1,textcolor);
			//PutPixel(x+1,y-1,textcolor);
			PutPixel(x+2,y-1,textcolor);
			
			//0
			PutPixel(x-2,y-0,textcolor);
			//PutPixel(x-1,y-0,textcolor);
			//PutPixel(x-0,y-0,textcolor);
			//PutPixel(x+1,y-0,textcolor);
			PutPixel(x+2,y-0,textcolor);
			
			//+1
			//PutPixel(x-2,y+1,textcolor);
			PutPixel(x-1,y+1,textcolor);
			//PutPixel(x-0,y+1,textcolor);
			PutPixel(x+1,y+1,textcolor);
			//PutPixel(x+2,y+1,textcolor);
			
			//+2
			//PutPixel(x-2,y+2,textcolor);
			PutPixel(x-1,y+2,textcolor);
			//PutPixel(x-0,y+2,textcolor);
			PutPixel(x+1,y+2,textcolor);
			//PutPixel(x+2,y+2,textcolor);
			
			//+3
    		//PutPixel(x-2,y+3,textcolor);
			//PutPixel(x-1,y+3,textcolor);
			PutPixel(x-0,y+3,textcolor);
			//PutPixel(x+1,y+3,textcolor);
			//PutPixel(x+2,y+3,textcolor);
			
			break;
		
		case 'W':
			//-3
			PutPixel(x-2,y-3,textcolor);
			//PutPixel(x-1,y-3,textcolor);
			//PutPixel(x-0,y-3,textcolor);
			//PutPixel(x+1,y-3,textcolor);
			PutPixel(x+2,y-3,textcolor);
			
			//-2
			PutPixel(x-2,y-2,textcolor);
			//PutPixel(x-1,y-2,textcolor);
			//PutPixel(x-0,y-2,textcolor);
			//PutPixel(x+1,y-2,textcolor);
			PutPixel(x+2,y-2,textcolor);
 			
 			//-1
 			PutPixel(x-2,y-1,textcolor);
			//PutPixel(x-1,y-1,textcolor);
			//PutPixel(x-0,y-1,textcolor);
			//PutPixel(x+1,y-1,textcolor);
			PutPixel(x+2,y-1,textcolor);
			
			//0
			PutPixel(x-2,y-0,textcolor);
			//PutPixel(x-1,y-0,textcolor);
			PutPixel(x-0,y-0,textcolor);
			//PutPixel(x+1,y-0,textcolor);
			PutPixel(x+2,y-0,textcolor);
			
			//+1
			PutPixel(x-2,y+1,textcolor);
			//PutPixel(x-1,y+1,textcolor);
			PutPixel(x-0,y+1,textcolor);
			//PutPixel(x+1,y+1,textcolor);
			PutPixel(x+2,y+1,textcolor);
			
			//+2
			PutPixel(x-2,y+2,textcolor);
			//PutPixel(x-1,y+2,textcolor);
			PutPixel(x-0,y+2,textcolor);
			//PutPixel(x+1,y+2,textcolor);
			PutPixel(x+2,y+2,textcolor);
			
			//+3
    		//PutPixel(x-2,y+3,textcolor);
			PutPixel(x-1,y+3,textcolor);
			//PutPixel(x-0,y+3,textcolor);
			PutPixel(x+1,y+3,textcolor);
			//PutPixel(x+2,y+3,textcolor);
			
			break;
			
		case 'X':
			//-3
			PutPixel(x-2,y-3,textcolor);
			//PutPixel(x-1,y-3,textcolor);
			//PutPixel(x-0,y-3,textcolor);
			//PutPixel(x+1,y-3,textcolor);
			PutPixel(x+2,y-3,textcolor);
			
			//-2
			PutPixel(x-2,y-2,textcolor);
			//PutPixel(x-1,y-2,textcolor);
			//PutPixel(x-0,y-2,textcolor);
			//PutPixel(x+1,y-2,textcolor);
			PutPixel(x+2,y-2,textcolor);
 			
 			//-1
 			//PutPixel(x-2,y-1,textcolor);
			PutPixel(x-1,y-1,textcolor);
			//PutPixel(x-0,y-1,textcolor);
			PutPixel(x+1,y-1,textcolor);
			//PutPixel(x+2,y-1,textcolor);
			
			//0
			//PutPixel(x-2,y-0,textcolor);
			//PutPixel(x-1,y-0,textcolor);
			PutPixel(x-0,y-0,textcolor);
			//PutPixel(x+1,y-0,textcolor);
			//PutPixel(x+2,y-0,textcolor);
			
			//+1
			//PutPixel(x-2,y+1,textcolor);
			PutPixel(x-1,y+1,textcolor);
			//PutPixel(x-0,y+1,textcolor);
			PutPixel(x+1,y+1,textcolor);
			//PutPixel(x+2,y+1,textcolor);
			
			//+2
			PutPixel(x-2,y+2,textcolor);
			//PutPixel(x-1,y+2,textcolor);
			//PutPixel(x-0,y+2,textcolor);
			//PutPixel(x+1,y+2,textcolor);
			PutPixel(x+2,y+2,textcolor);
			
			//+3
    		PutPixel(x-2,y+3,textcolor);
			//PutPixel(x-1,y+3,textcolor);
			//PutPixel(x-0,y+3,textcolor);
			//PutPixel(x+1,y+3,textcolor);
			PutPixel(x+2,y+3,textcolor);
			
			break;
		
		case 'Y':
			//-3
			PutPixel(x-2,y-3,textcolor);
			//PutPixel(x-1,y-3,textcolor);
			//PutPixel(x-0,y-3,textcolor);
			//PutPixel(x+1,y-3,textcolor);
			PutPixel(x+2,y-3,textcolor);
			
			//-2
			PutPixel(x-2,y-2,textcolor);
			//PutPixel(x-1,y-2,textcolor);
			//PutPixel(x-0,y-2,textcolor);
			//PutPixel(x+1,y-2,textcolor);
			PutPixel(x+2,y-2,textcolor);
 			
 			//-1
 			//PutPixel(x-2,y-1,textcolor);
			PutPixel(x-1,y-1,textcolor);
			//PutPixel(x-0,y-1,textcolor);
			PutPixel(x+1,y-1,textcolor);
			//PutPixel(x+2,y-1,textcolor);
			
			//0
			//PutPixel(x-2,y-0,textcolor);
			//PutPixel(x-1,y-0,textcolor);
			PutPixel(x-0,y-0,textcolor);
			//PutPixel(x+1,y-0,textcolor);
			//PutPixel(x+2,y-0,textcolor);
			
			//+1
			//PutPixel(x-2,y+1,textcolor);
			//PutPixel(x-1,y+1,textcolor);
			PutPixel(x-0,y+1,textcolor);
			//PutPixel(x+1,y+1,textcolor);
			//PutPixel(x+2,y+1,textcolor);
			
			//+2
			//PutPixel(x-2,y+2,textcolor);
			//PutPixel(x-1,y+2,textcolor);
			PutPixel(x-0,y+2,textcolor);
			//PutPixel(x+1,y+2,textcolor);
			//PutPixel(x+2,y+2,textcolor);
			
			//+3
    		//PutPixel(x-2,y+3,textcolor);
			//PutPixel(x-1,y+3,textcolor);
			PutPixel(x-0,y+3,textcolor);
			//PutPixel(x+1,y+3,textcolor);
			//PutPixel(x+2,y+3,textcolor);
			
			break;
			
		case 'Z':
			//-3
			PutPixel(x-2,y-3,textcolor);
			PutPixel(x-1,y-3,textcolor);
			PutPixel(x-0,y-3,textcolor);
			PutPixel(x+1,y-3,textcolor);
			PutPixel(x+2,y-3,textcolor);
			
			//-2
			//PutPixel(x-2,y-2,textcolor);
			//PutPixel(x-1,y-2,textcolor);
			//PutPixel(x-0,y-2,textcolor);
			//PutPixel(x+1,y-2,textcolor);
			PutPixel(x+2,y-2,textcolor);
 			
 			//-1
 			//PutPixel(x-2,y-1,textcolor);
			//PutPixel(x-1,y-1,textcolor);
			//PutPixel(x-0,y-1,textcolor);
			PutPixel(x+1,y-1,textcolor);
			//PutPixel(x+2,y-1,textcolor);
			
			//0
			//PutPixel(x-2,y-0,textcolor);
			//PutPixel(x-1,y-0,textcolor);
			PutPixel(x-0,y-0,textcolor);
			//PutPixel(x+1,y-0,textcolor);
			//PutPixel(x+2,y-0,textcolor);
			
			//+1
			//PutPixel(x-2,y+1,textcolor);
			PutPixel(x-1,y+1,textcolor);
			//PutPixel(x-0,y+1,textcolor);
			//PutPixel(x+1,y+1,textcolor);
			//PutPixel(x+2,y+1,textcolor);
			
			//+2
			PutPixel(x-2,y+2,textcolor);
			//PutPixel(x-1,y+2,textcolor);
			//PutPixel(x-0,y+2,textcolor);
			//PutPixel(x+1,y+2,textcolor);
			//PutPixel(x+2,y+2,textcolor);
			
			//+3
    		PutPixel(x-2,y+3,textcolor);
			PutPixel(x-1,y+3,textcolor);
			PutPixel(x-0,y+3,textcolor);
			PutPixel(x+1,y+3,textcolor);
			PutPixel(x+2,y+3,textcolor);
			
			break;
			
		case '1':
			//-3
			//PutPixel(x-2,y-3,textcolor);
			//PutPixel(x-1,y-3,textcolor);
			PutPixel(x-0,y-3,textcolor);
			//PutPixel(x+1,y-3,textcolor);
			//PutPixel(x+2,y-3,textcolor);
			
			//-2
			//PutPixel(x-2,y-2,textcolor);
			PutPixel(x-1,y-2,textcolor);
			PutPixel(x-0,y-2,textcolor);
			//PutPixel(x+1,y-2,textcolor);
			//PutPixel(x+2,y-2,textcolor);
 			
 			//-1
 			//PutPixel(x-2,y-1,textcolor);
			//PutPixel(x-1,y-1,textcolor);
			PutPixel(x-0,y-1,textcolor);
			//PutPixel(x+1,y-1,textcolor);
			//PutPixel(x+2,y-1,textcolor);
			
			//0
			//PutPixel(x-2,y-0,textcolor);
			//PutPixel(x-1,y-0,textcolor);
			PutPixel(x-0,y-0,textcolor);
			//PutPixel(x+1,y-0,textcolor);
			//PutPixel(x+2,y-0,textcolor);
			
			//+1
			//PutPixel(x-2,y+1,textcolor);
			//PutPixel(x-1,y+1,textcolor);
			PutPixel(x-0,y+1,textcolor);
			//PutPixel(x+1,y+1,textcolor);
			//PutPixel(x+2,y+1,textcolor);
			
			//+2
			//PutPixel(x-2,y+2,textcolor);
			//PutPixel(x-1,y+2,textcolor);
			PutPixel(x-0,y+2,textcolor);
			//PutPixel(x+1,y+2,textcolor);
			//PutPixel(x+2,y+2,textcolor);
			
			//+3
    		//PutPixel(x-2,y+3,textcolor);
			PutPixel(x-1,y+3,textcolor);
			PutPixel(x-0,y+3,textcolor);
			PutPixel(x+1,y+3,textcolor);
			//PutPixel(x+2,y+3,textcolor);
		break;
		case '2':
			//-3
			//PutPixel(x-2,y-3,textcolor);
			PutPixel(x-1,y-3,textcolor);
			PutPixel(x-0,y-3,textcolor);
			PutPixel(x+1,y-3,textcolor);
			//PutPixel(x+2,y-3,textcolor);
			
			//-2
			PutPixel(x-2,y-2,textcolor);
			//PutPixel(x-1,y-2,textcolor);
			//PutPixel(x-0,y-2,textcolor);
			//PutPixel(x+1,y-2,textcolor);
			PutPixel(x+2,y-2,textcolor);
 			
 			//-1
 			//PutPixel(x-2,y-1,textcolor);
			//PutPixel(x-1,y-1,textcolor);
			//PutPixel(x-0,y-1,textcolor);
			//PutPixel(x+1,y-1,textcolor);
			PutPixel(x+2,y-1,textcolor);
			
			//0
			//PutPixel(x-2,y-0,textcolor);
			//PutPixel(x-1,y-0,textcolor);
			//PutPixel(x-0,y-0,textcolor);
			PutPixel(x+1,y-0,textcolor);
			//PutPixel(x+2,y-0,textcolor);
			
			//+1
			//PutPixel(x-2,y+1,textcolor);
			//PutPixel(x-1,y+1,textcolor);
			PutPixel(x-0,y+1,textcolor);
			//PutPixel(x+1,y+1,textcolor);
			//PutPixel(x+2,y+1,textcolor);
			
			//+2
			//PutPixel(x-2,y+2,textcolor);
			PutPixel(x-1,y+2,textcolor);
			//PutPixel(x-0,y+2,textcolor);
			//PutPixel(x+1,y+2,textcolor);
			//PutPixel(x+2,y+2,textcolor);
			
			//+3
    		PutPixel(x-2,y+3,textcolor);
			PutPixel(x-1,y+3,textcolor);
			PutPixel(x-0,y+3,textcolor);
			PutPixel(x+1,y+3,textcolor);
			PutPixel(x+2,y+3,textcolor);
			break;
		case '3':
			//-3
			PutPixel(x-2,y-3,textcolor);
			PutPixel(x-1,y-3,textcolor);
			PutPixel(x-0,y-3,textcolor);
			PutPixel(x+1,y-3,textcolor);
			PutPixel(x+2,y-3,textcolor);
			
			//-2
			//PutPixel(x-2,y-2,textcolor);
			//PutPixel(x-1,y-2,textcolor);
			//PutPixel(x-0,y-2,textcolor);
			PutPixel(x+1,y-2,textcolor);
			//PutPixel(x+2,y-2,textcolor);
 			
 			//-1
 			//PutPixel(x-2,y-1,textcolor);
			//PutPixel(x-1,y-1,textcolor);
			PutPixel(x-0,y-1,textcolor);
			//PutPixel(x+1,y-1,textcolor);
			//PutPixel(x+2,y-1,textcolor);
			
			//0
			//PutPixel(x-2,y-0,textcolor);
			//PutPixel(x-1,y-0,textcolor);
			//PutPixel(x-0,y-0,textcolor);
			PutPixel(x+1,y-0,textcolor);
			//PutPixel(x+2,y-0,textcolor);
			
			//+1
			//PutPixel(x-2,y+1,textcolor);
			//PutPixel(x-1,y+1,textcolor);
			//PutPixel(x-0,y+1,textcolor);
			//PutPixel(x+1,y+1,textcolor);
			PutPixel(x+2,y+1,textcolor);
			
			//+2
			PutPixel(x-2,y+2,textcolor);
			//PutPixel(x-1,y+2,textcolor);
			//PutPixel(x-0,y+2,textcolor);
			//PutPixel(x+1,y+2,textcolor);
			PutPixel(x+2,y+2,textcolor);
			
			//+3
    		//PutPixel(x-2,y+3,textcolor);
			PutPixel(x-1,y+3,textcolor);
			PutPixel(x-0,y+3,textcolor);
			PutPixel(x+1,y+3,textcolor);
			//PutPixel(x+2,y+3,textcolor);
			break;
		case '4':
			//-3
			//PutPixel(x-2,y-3,textcolor);
			//PutPixel(x-1,y-3,textcolor);
			//PutPixel(x-0,y-3,textcolor);
			PutPixel(x+1,y-3,textcolor);
			//PutPixel(x+2,y-3,textcolor);
			
			//-2
			//PutPixel(x-2,y-2,textcolor);
			//PutPixel(x-1,y-2,textcolor);
			PutPixel(x-0,y-2,textcolor);
			PutPixel(x+1,y-2,textcolor);
			//PutPixel(x+2,y-2,textcolor);
 			
 			//-1
 			//PutPixel(x-2,y-1,textcolor);
			PutPixel(x-1,y-1,textcolor);
			//PutPixel(x-0,y-1,textcolor);
			PutPixel(x+1,y-1,textcolor);
			//PutPixel(x+2,y-1,textcolor);
			
			//0
			PutPixel(x-2,y-0,textcolor);
			//PutPixel(x-1,y-0,textcolor);
			//PutPixel(x-0,y-0,textcolor);
			PutPixel(x+1,y-0,textcolor);
			//PutPixel(x+2,y-0,textcolor);
			
			//+1
			PutPixel(x-2,y+1,textcolor);
			PutPixel(x-1,y+1,textcolor);
			PutPixel(x-0,y+1,textcolor);
			PutPixel(x+1,y+1,textcolor);
			PutPixel(x+2,y+1,textcolor);
			
			//+2
			//PutPixel(x-2,y+2,textcolor);
			//PutPixel(x-1,y+2,textcolor);
			//PutPixel(x-0,y+2,textcolor);
			PutPixel(x+1,y+2,textcolor);
			//PutPixel(x+2,y+2,textcolor);
			
			//+3
    		//PutPixel(x-2,y+3,textcolor);
			//PutPixel(x-1,y+3,textcolor);
			//PutPixel(x-0,y+3,textcolor);
			PutPixel(x+1,y+3,textcolor);
			//PutPixel(x+2,y+3,textcolor);
			break;
			
		case '5':
			//-3
			PutPixel(x-2,y-3,textcolor);
			PutPixel(x-1,y-3,textcolor);
			PutPixel(x-0,y-3,textcolor);
			PutPixel(x+1,y-3,textcolor);
			PutPixel(x+2,y-3,textcolor);
			
			//-2
			PutPixel(x-2,y-2,textcolor);
			//PutPixel(x-1,y-2,textcolor);
			//PutPixel(x-0,y-2,textcolor);
			//PutPixel(x+1,y-2,textcolor);
			//PutPixel(x+2,y-2,textcolor);
 			
 			//-1
 			PutPixel(x-2,y-1,textcolor);
			PutPixel(x-1,y-1,textcolor);
			PutPixel(x-0,y-1,textcolor);
			PutPixel(x+1,y-1,textcolor);
			//PutPixel(x+2,y-1,textcolor);
			
			//0
			//PutPixel(x-2,y-0,textcolor);
			//PutPixel(x-1,y-0,textcolor);
			//PutPixel(x-0,y-0,textcolor);
			//PutPixel(x+1,y-0,textcolor);
			PutPixel(x+2,y-0,textcolor);
			
			//+1
			//PutPixel(x-2,y+1,textcolor);
			//PutPixel(x-1,y+1,textcolor);
			//PutPixel(x-0,y+1,textcolor);
			//PutPixel(x+1,y+1,textcolor);
			PutPixel(x+2,y+1,textcolor);
			
			//+2
			PutPixel(x-2,y+2,textcolor);
			//PutPixel(x-1,y+2,textcolor);
			//PutPixel(x-0,y+2,textcolor);
			//PutPixel(x+1,y+2,textcolor);
			PutPixel(x+2,y+2,textcolor);
			
			//+3
    		//PutPixel(x-2,y+3,textcolor);
			PutPixel(x-1,y+3,textcolor);
			PutPixel(x-0,y+3,textcolor);
			PutPixel(x+1,y+3,textcolor);
			//PutPixel(x+2,y+3,textcolor);
			
			break;
			
			case '6':
			//-3
			//PutPixel(x-2,y-3,textcolor);
			//PutPixel(x-1,y-3,textcolor);
			PutPixel(x-0,y-3,textcolor);
			PutPixel(x+1,y-3,textcolor);
			//PutPixel(x+2,y-3,textcolor);
			
			//-2
			//PutPixel(x-2,y-2,textcolor);
			PutPixel(x-1,y-2,textcolor);
			//PutPixel(x-0,y-2,textcolor);
			//PutPixel(x+1,y-2,textcolor);
			//PutPixel(x+2,y-2,textcolor);
 			
 			//-1
 			PutPixel(x-2,y-1,textcolor);
			//PutPixel(x-1,y-1,textcolor);
			//PutPixel(x-0,y-1,textcolor);
			//PutPixel(x+1,y-1,textcolor);
			//PutPixel(x+2,y-1,textcolor);
			
			//0
			PutPixel(x-2,y-0,textcolor);
			PutPixel(x-1,y-0,textcolor);
			PutPixel(x-0,y-0,textcolor);
			PutPixel(x+1,y-0,textcolor);
			//PutPixel(x+2,y-0,textcolor);
			
			//+1
			PutPixel(x-2,y+1,textcolor);
			//PutPixel(x-1,y+1,textcolor);
			//PutPixel(x-0,y+1,textcolor);
			//PutPixel(x+1,y+1,textcolor);
			PutPixel(x+2,y+1,textcolor);
			
			//+2
			PutPixel(x-2,y+2,textcolor);
			//PutPixel(x-1,y+2,textcolor);
			//PutPixel(x-0,y+2,textcolor);
			//PutPixel(x+1,y+2,textcolor);
			PutPixel(x+2,y+2,textcolor);
			
			//+3
    		//PutPixel(x-2,y+3,textcolor);
			PutPixel(x-1,y+3,textcolor);
			PutPixel(x-0,y+3,textcolor);
			PutPixel(x+1,y+3,textcolor);
			//PutPixel(x+2,y+3,textcolor);
			
			break;
			
			case '7':
			//-3
			PutPixel(x-2,y-3,textcolor);
			PutPixel(x-1,y-3,textcolor);
			PutPixel(x-0,y-3,textcolor);
			PutPixel(x+1,y-3,textcolor);
			PutPixel(x+2,y-3,textcolor);
			
			//-2
			//PutPixel(x-2,y-2,textcolor);
			//PutPixel(x-1,y-2,textcolor);
			//PutPixel(x-0,y-2,textcolor);
			//PutPixel(x+1,y-2,textcolor);
			PutPixel(x+2,y-2,textcolor);
 			
 			//-1
 			//PutPixel(x-2,y-1,textcolor);
			//PutPixel(x-1,y-1,textcolor);
			//PutPixel(x-0,y-1,textcolor);
			PutPixel(x+1,y-1,textcolor);
			//PutPixel(x+2,y-1,textcolor);
			
			//0
			//PutPixel(x-2,y-0,textcolor);
			//PutPixel(x-1,y-0,textcolor);
			PutPixel(x-0,y-0,textcolor);
			//PutPixel(x+1,y-0,textcolor);
			//PutPixel(x+2,y-0,textcolor);
			
			//+1
			//PutPixel(x-2,y+1,textcolor);
			PutPixel(x-1,y+1,textcolor);
			//PutPixel(x-0,y+1,textcolor);
			//PutPixel(x+1,y+1,textcolor);
			//PutPixel(x+2,y+1,textcolor);
			
			//+2
			//PutPixel(x-2,y+2,textcolor);
			PutPixel(x-1,y+2,textcolor);
			//PutPixel(x-0,y+2,textcolor);
			//PutPixel(x+1,y+2,textcolor);
			//PutPixel(x+2,y+2,textcolor);
			
			//+3
    		//PutPixel(x-2,y+3,textcolor);
			PutPixel(x-1,y+3,textcolor);
			//PutPixel(x-0,y+3,textcolor);
			//PutPixel(x+1,y+3,textcolor);
			//PutPixel(x+2,y+3,textcolor);
			
			break;
			
			case '8':
			//-3
			//PutPixel(x-2,y-3,textcolor);
			PutPixel(x-1,y-3,textcolor);
			PutPixel(x-0,y-3,textcolor);
			PutPixel(x+1,y-3,textcolor);
			//PutPixel(x+2,y-3,textcolor);
			
			//-2
			PutPixel(x-2,y-2,textcolor);
			//PutPixel(x-1,y-2,textcolor);
			//PutPixel(x-0,y-2,textcolor);
			//PutPixel(x+1,y-2,textcolor);
			PutPixel(x+2,y-2,textcolor);
 			
 			//-1
 			PutPixel(x-2,y-1,textcolor);
			//PutPixel(x-1,y-1,textcolor);
			//PutPixel(x-0,y-1,textcolor);
			//PutPixel(x+1,y-1,textcolor);
			PutPixel(x+2,y-1,textcolor);
			
			//0
			//PutPixel(x-2,y-0,textcolor);
			PutPixel(x-1,y-0,textcolor);
			PutPixel(x-0,y-0,textcolor);
			PutPixel(x+1,y-0,textcolor);
			//PutPixel(x+2,y-0,textcolor);
			
			//+1
			PutPixel(x-2,y+1,textcolor);
			//PutPixel(x-1,y+1,textcolor);
			//PutPixel(x-0,y+1,textcolor);
			//PutPixel(x+1,y+1,textcolor);
			PutPixel(x+2,y+1,textcolor);
			
			//+2
			PutPixel(x-2,y+2,textcolor);
			//PutPixel(x-1,y+2,textcolor);
			//PutPixel(x-0,y+2,textcolor);
			//PutPixel(x+1,y+2,textcolor);
			PutPixel(x+2,y+2,textcolor);
			
			//+3
    		//PutPixel(x-2,y+3,textcolor);
			PutPixel(x-1,y+3,textcolor);
			PutPixel(x-0,y+3,textcolor);
			PutPixel(x+1,y+3,textcolor);
			//PutPixel(x+2,y+3,textcolor);
			
			break;
			
			case '9':
			//-3
			//PutPixel(x-2,y-3,textcolor);
			PutPixel(x-1,y-3,textcolor);
			PutPixel(x-0,y-3,textcolor);
			PutPixel(x+1,y-3,textcolor);
			//PutPixel(x+2,y-3,textcolor);
			
			//-2
			PutPixel(x-2,y-2,textcolor);
			//PutPixel(x-1,y-2,textcolor);
			//PutPixel(x-0,y-2,textcolor);
			//PutPixel(x+1,y-2,textcolor);
			PutPixel(x+2,y-2,textcolor);
 			
 			//-1
 			PutPixel(x-2,y-1,textcolor);
			//PutPixel(x-1,y-1,textcolor);
			//PutPixel(x-0,y-1,textcolor);
			//PutPixel(x+1,y-1,textcolor);
			PutPixel(x+2,y-1,textcolor);
			
			//0
			//PutPixel(x-2,y-0,textcolor);
			PutPixel(x-1,y-0,textcolor);
			PutPixel(x-0,y-0,textcolor);
			PutPixel(x+1,y-0,textcolor);
			PutPixel(x+2,y-0,textcolor);
			
			//+1
			//PutPixel(x-2,y+1,textcolor);
			//PutPixel(x-1,y+1,textcolor);
			//PutPixel(x-0,y+1,textcolor);
			//PutPixel(x+1,y+1,textcolor);
			PutPixel(x+2,y+1,textcolor);
			
			//+2
			//PutPixel(x-2,y+2,textcolor);
			//PutPixel(x-1,y+2,textcolor);
			//PutPixel(x-0,y+2,textcolor);
			PutPixel(x+1,y+2,textcolor);
			//PutPixel(x+2,y+2,textcolor);
			
			//+3
    		//PutPixel(x-2,y+3,textcolor);
			PutPixel(x-1,y+3,textcolor);
			PutPixel(x-0,y+3,textcolor);
			//PutPixel(x+1,y+3,textcolor);
			//PutPixel(x+2,y+3,textcolor);
			
			break;
		
			case '0':
			//-3
			//PutPixel(x-2,y-3,textcolor);
			PutPixel(x-1,y-3,textcolor);
			PutPixel(x-0,y-3,textcolor);
			PutPixel(x+1,y-3,textcolor);
			//PutPixel(x+2,y-3,textcolor);
			
			//-2
			PutPixel(x-2,y-2,textcolor);
			//PutPixel(x-1,y-2,textcolor);
			//PutPixel(x-0,y-2,textcolor);
			//PutPixel(x+1,y-2,textcolor);
			PutPixel(x+2,y-2,textcolor);
 			
 			//-1
 			PutPixel(x-2,y-1,textcolor);
			//PutPixel(x-1,y-1,textcolor);
			//PutPixel(x-0,y-1,textcolor);
			PutPixel(x+1,y-1,textcolor);
			PutPixel(x+2,y-1,textcolor);
			
			//0
			PutPixel(x-2,y-0,textcolor);
			//PutPixel(x-1,y-0,textcolor);
			PutPixel(x-0,y-0,textcolor);
			//PutPixel(x+1,y-0,textcolor);
			PutPixel(x+2,y-0,textcolor);
			
			//+1
			PutPixel(x-2,y+1,textcolor);
			PutPixel(x-1,y+1,textcolor);
			//PutPixel(x-0,y+1,textcolor);
			//PutPixel(x+1,y+1,textcolor);
			PutPixel(x+2,y+1,textcolor);
			
			//+2
			PutPixel(x-2,y+2,textcolor);
			//PutPixel(x-1,y+2,textcolor);
			//PutPixel(x-0,y+2,textcolor);
			//PutPixel(x+1,y+2,textcolor);
			PutPixel(x+2,y+2,textcolor);
			
			//+3
    		//PutPixel(x-2,y+3,textcolor);
			PutPixel(x-1,y+3,textcolor);
			PutPixel(x-0,y+3,textcolor);
			PutPixel(x+1,y+3,textcolor);
			//PutPixel(x+2,y+3,textcolor);
			
			break;				
		default:
			break;
	}
	
	return;
}


#endif
