#include "Headers/2DGC.h"
#include "Headers/PixelText.h"

DWORD cNumRead, fdwMode, n; 
INPUT_RECORD irInBuf[32];

const float speed=1; 
int score=0;

typedef struct POSITION_2D{
	float x;
	float y;
}POS;

typedef struct SNAKE{
	POS snakepos;
	int size;
}Snake;

Snake snake;
POS *poshist;

char *toString(int num);
void printString(char *s,int x,int y,int color);

void main()
{
	CreateConsole("Snake Game",80,60,12,12);
	SetBgColor(BLACK);

	snake.snakepos.x=screenwidth()/2;
	snake.snakepos.y=screenheight()/2;
	snake.size=1;
	
	poshist=(POS*)malloc(sizeof(POS)*snake.size);
	
	poshist[0].x=snake.snakepos.x;
	poshist[0].y=snake.snakepos.y;
	
	int fx=random(1,screenwidth()-3);
	int fy=random(1,screenheight()-3);
	
	OnUpdate()
	{	
		DrawRect(screenwidth()/2,screenheight()/2+4,screenwidth()-1,screenheight()-10,WHITE);
		printString("SNAKE GAME",3,4,GREEN);	
		
		if(snake.snakepos.x==fx && snake.snakepos.y==fy)
		{
			score+=1;
			fx=random(1,screenwidth()-3);
			fy=random(1,screenheight()-3);
			PutPixel(fx,fy,DARK_RED);
			incsize();
		}
		else
			PutPixel(fx,fy,DARK_RED);
		
		updatesnake();	
		drawsnake();
		GetInput();
		DrawFrame(TRUE);
	}
}

incsize()
{
	snake.size++;
	poshist=realloc(poshist,sizeof(POS)*snake.size);
}

updatesnake()
{
	int i;
	
	for(i=snake.size;i>0;i--)
	{
		poshist[i]=poshist[i-1];
	}
	
	poshist[0].x=snake.snakepos.x;
	poshist[0].y=snake.snakepos.y;
}

drawsnake()
{
	int i;
	
	for(i=0;i<snake.size;i++)
	{
		if(i%2==0)
			PutPixel(poshist[i].x,poshist[i].y,DARK_GREEN);
		else
			PutPixel(poshist[i].x,poshist[i].y,GREEN);
	}
}

GetInput()
{
        ReadConsoleInput(rHnd,      // input buffer handle 
                		irInBuf,     // buffer to read into 
                		32,         // size of read buffer 
                		&cNumRead); // number of records read  
 
        for (n = 0; n< cNumRead; n++) 
        {
            switch(irInBuf[n].EventType) 
            { 
                case KEY_EVENT: 
                    	if(irInBuf[n].Event.KeyEvent.wVirtualKeyCode==VK_UP)
                    	{
                    		snake.snakepos.y-=speed;	
						}
							
                    	else if(irInBuf[n].Event.KeyEvent.wVirtualKeyCode==VK_DOWN)
                    	{
                    		snake.snakepos.y+=speed;	
						}
													
						else if(irInBuf[n].Event.KeyEvent.wVirtualKeyCode==VK_RIGHT)
						{
							snake.snakepos.x+=speed;	
						}
							
						else if(irInBuf[n].Event.KeyEvent.wVirtualKeyCode==VK_LEFT)
						{
							snake.snakepos.x-=speed;	
						}
						else
							return;
							
						if(snake.snakepos.x>screenwidth())
							snake.snakepos.x=0;
						if(snake.snakepos.x<0)
							snake.snakepos.x=screenwidth();					
						
                    return;  
            } 
        }
}

void printString(char *s,int x,int y,int color)
{
	int i=0;
	int space=0;
	
	while(*(s+i)!=0)
	{
		PutCharacter(*(s+i),x+space,y,color);
		space+=6;
		i++;
	}
}


char *toString(int num)
{
	int n=num;
	int numdigits;
	char *number_str;
	
	while(n!=0)
	{
		n=n/10;
		numdigits++;
	}
	
	number_str=(char*)malloc(sizeof(char)*numdigits);
	
	itoa(num,number_str,10);
	
	return number_str;	
}
