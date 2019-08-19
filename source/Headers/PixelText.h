#ifndef PutPixel_H
#define PutPixel_H

void PutCharacter(char,int,int,int);

int stringsize(const char *s)
{
	int n = 0;

	while (*(s + n) != 0)
		n++;

	return n;
}

void PrintString(const char *s, int x, int y, int color)
{
	int i = 0;
	int space = 0;
	int tsize = ( stringsize(s) * 5 + stringsize(s)-1 );
	int p = (tsize / 2);
	x = x - p + 2;

	while (*(s + i) != 0)
	{
		PutCharacter(*(s + i), x + space, y, color);
		space += 7;
		i++;
	}
}

char *ToString(int numToConvert)
{
	int n = numToConvert;
	int numdigits = 0;
	char *numberInChar;

	while (n != 0)
	{
		n = n / 10;
		numdigits++;
	}

	numberInChar = (char*)malloc(sizeof(char)*numdigits);

	itoa(numToConvert,numberInChar,10);

	return numberInChar;
}

void PutCharacter(char c,int x,int y,int textcolor)
{
	//textcolor=randcolor();
	switch(c)
	{
		case 'A':
		case 'a':
			
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
		case 'b':
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
		case 'c':
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
		case 'd':
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
		case 'e':
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
		case 'f':
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
		case 'g':
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
		case 'h':
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
		case 'i':
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
		case 'j':
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
		case 'k':		
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
		case 'l':
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
    	case 'm':
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
		case 'n':
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
		case 'o':
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
		case 'p':
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
		case 'q':
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
		case 'r':
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
		case 's':
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
		case 't':
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
		case 'u':
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
		case 'v':
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
		case 'w':
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
		case 'x':
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
		case 'y':
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
		case 'z':
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
			
		case ':':
			//-3
			//PutPixel(x-2,y-3,textcolor);
			//PutPixel(x-1,y-3,textcolor);
			//PutPixel(x-0,y-3,textcolor);
			//PutPixel(x+1,y-3,textcolor);
			//PutPixel(x+2,y-3,textcolor);
			
			//-2
			//PutPixel(x-2,y-2,textcolor);
			PutPixel(x-1,y-2,textcolor);
			PutPixel(x-0,y-2,textcolor);
			PutPixel(x+1,y-2,textcolor);
			//PutPixel(x+2,y-2,textcolor);
 			
 			//-1
 			//PutPixel(x-2,y-1,textcolor);
			PutPixel(x-1,y-1,textcolor);
			PutPixel(x-0,y-1,textcolor);
			PutPixel(x+1,y-1,textcolor);
			//PutPixel(x+2,y-1,textcolor);
			
			//0
			//PutPixel(x-2,y-0,textcolor);
			//PutPixel(x-1,y-0,textcolor);
			//PutPixel(x-0,y-0,textcolor);
			//PutPixel(x+1,y-0,textcolor);
			//PutPixel(x+2,y-0,textcolor);
			
			//+1
			//PutPixel(x-2,y+1,textcolor);
			PutPixel(x-1,y+1,textcolor);
			PutPixel(x-0,y+1,textcolor);
			PutPixel(x+1,y+1,textcolor);
			//PutPixel(x+2,y+1,textcolor);
			
			//+2
			//PutPixel(x-2,y+2,textcolor);
			PutPixel(x-1,y+2,textcolor);
			PutPixel(x-0,y+2,textcolor);
			PutPixel(x+1,y+2,textcolor);
			//PutPixel(x+2,y+2,textcolor);
			
			//+3
    		//PutPixel(x-2,y+3,textcolor);
			//PutPixel(x-1,y+3,textcolor);
			//PutPixel(x-0,y+3,textcolor);
			//PutPixel(x+1,y+3,textcolor);
			//PutPixel(x+2,y+3,textcolor);
			
			break;		
						
		default:
			break;
	}
	
	return;
}


#endif
