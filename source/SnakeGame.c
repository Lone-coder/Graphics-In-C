#include "Headers/2DGC.h"
#include "Headers/PixelText.h"

DWORD cNumRead, fdwMode, n; 
INPUT_RECORD irInBuf[32];

const float speed = 0.5; 
int score = 0;

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

incsize()
{
	snake.size++;
	poshist = realloc(poshist,sizeof(POS)*snake.size);
}

updatesnake()
{
	int i = 0;
	
	for(i = snake.size; i>0; i--)
	{
		poshist[i] = poshist[i-1];
	}
	
	poshist[0].x = snake.snakepos.x;
	poshist[0].y = snake.snakepos.y;
	
}

drawsnake()
{
	int i = 0;
	
	for(i = snake.size; i >= 0; i--)
	{
		if(i==0)
			PutPixel(poshist[i].x,poshist[i].y,DARK_GREEN);
		else
			PutPixel(poshist[i].x,poshist[i].y,GREEN);
	}
}

GetInput()
{
        ReadConsoleInput(rHnd,irInBuf,32,&cNumRead);  
 
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
            } 
        }
}

void main()
{
	CreateConsole("Snake Game",40,30,14,14);
	SetBgColor(BLACK);

	snake.snakepos.x=screenwidth()/2;
	snake.snakepos.y=screenheight()/2;
	snake.size = 1;
	
	poshist = (POS*)malloc(sizeof(POS)*snake.size);
	
	poshist[0].x = snake.snakepos.x;
	poshist[0].y = snake.snakepos.y;
	
	int fx = random(1,screenwidth()-3);
	int fy = random(1,screenheight()-3);
	
	OnUpdate()
	{	
		DrawRect(screenwidth()/2,screenheight()/2,screenwidth()-1,screenheight()-1,WHITE);
		//printString("SNAKE GAME",3,4,GREEN);	
		
		if(snake.snakepos.x > screenwidth())
			snake.snakepos.x = 0;
		if(snake.snakepos.x < 0)
			snake.snakepos.x = screenwidth();
		
		if(poshist[0].x==fx && poshist[0].y==fy)
		{
			score += 1;
			fx = random(3,screenwidth()-3);
			fy = random(3,screenheight()-3);
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
