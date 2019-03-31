#include "2DGC.h"

DWORD cNumRead, fdwMode, n; 
INPUT_RECORD irInBuf[128]; 
int offsetx, offsety;

const float speed=1; 

typedef struct POS{
	float x;
	float y;
}pos;

typedef struct SNAKE{
	pos snakepos;
	int size;
}Snake;

void GetInput();

Snake snake;
pos *poshist;
int oldsize;

void main()
{
	CreateConsole("Snake Game",100,60,10,10);
	SetBGcolor(BLACK);

	snake.snakepos.x=30;
	snake.snakepos.y=30;
	snake.size=1;
	
	poshist=(pos*)malloc(sizeof(pos)*snake.size);
	
	poshist[0].x=30;
	poshist[0].x=30;
	
	OnUpdate()
	{		
		GetInput();
		incsize();
		updatesnake();
		drawsnake();
		DrawFrame(TRUE);
		
	}
}

void incsize()
{
	if(snake.size>oldsize)
	{
		realloc(poshist,sizeof(pos)*3);
		oldsize=snake.size;
	}
}

void updatesnake()
{
	int i;
	
	for(i=0;i<=snake.size;i++)
	{
		poshist[i+1]=poshist[i];
	}
	
	poshist[0].x=snake.snakepos.x;
	poshist[0].y=snake.snakepos.y;
}

void drawsnake()
{
	int i;
	
	for(i=0;i<snake.size;i++)
	{
		putpixel(poshist[i].x,poshist[i].y,WHITE);
	}
}

void GetInput()
{
        ReadConsoleInput(rHnd,      // input buffer handle 
                		irInBuf,     // buffer to read into 
                		128,         // size of read buffer 
                		&cNumRead); // number of records read  
 
        for (n = 0; n< cNumRead; n++) 
        {
            switch(irInBuf[n].EventType) 
            { 
                case KEY_EVENT: 
                    	if(irInBuf[n].Event.KeyEvent.wVirtualKeyCode==VK_UP)
							snake.snakepos.y-=speed;
							
                    	else if(irInBuf[n].Event.KeyEvent.wVirtualKeyCode==VK_DOWN)
							snake.snakepos.y+=speed;
						
						else if(irInBuf[n].Event.KeyEvent.wVirtualKeyCode==VK_RIGHT)
							snake.snakepos.x+=speed;
						
						else if(irInBuf[n].Event.KeyEvent.wVirtualKeyCode==VK_LEFT)
							snake.snakepos.x-=speed;						
						else if(irInBuf[n].Event.KeyEvent.wVirtualKeyCode==VK_TAB)
							snake.size++;
                    break; 
 
                case MOUSE_EVENT:
 
                case WINDOW_BUFFER_SIZE_EVENT:
 
                case FOCUS_EVENT:
 
                case MENU_EVENT: 
                    break; 
 
                default: 
                    break; 
            } 
        }
}

