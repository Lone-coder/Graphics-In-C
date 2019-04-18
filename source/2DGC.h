#ifndef _2DGC_H_
#define _2DGC_H_

#include<windows.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define FALSE 0
#define TRUE 1
#define OnUpdate() while(1)
#define OnStart() if(1)


// Windows data types
HANDLE wHnd;
HANDLE rHnd;
COORD bufferSize;
COORD characterBufferSize;
COORD characterPosition;
SMALL_RECT windowSize;
SMALL_RECT consoleWriteArea ;
CHAR_INFO *consoleBuffer;

int i,j;

int screenWidth;
int screenHeight;

int bgcolor=0x00F0;
const char defaultchar=219; 

LARGE_INTEGER freq;
float deltatime=0.01;

enum Color
{
    BLACK			= 0x0000,
    DARK_BLUE   	= 0x0001,
    DARK_GREEN   	= 0x0002,
    DARK_CYAN    	= 0x0003,
    DARK_RED     	= 0x0004,
    DARK_MAGENTA 	= 0x0005,
    DARK_YELLOW  	= 0x0006,
    GREY			= 0x0007,
    DARK_GREY    	= 0x0008,
    BLUE			= 0x0009,
    GREEN			= 0x000A,
    CYAN			= 0x000B,
    RED				= 0x000C,
    MAGENTA			= 0x000D,
    YELLOW			= 0x000E,
    WHITE			= 0x000F
};

int color[16]={	
	0x0000,
	0x0001,
	0x0002,
	0x0003,
	0x0004,
	0x0005,
	0x0006,
	0x0007,
	0x0008,
	0x0009,
	0x000A,
	0x000B,
	0x000C,
	0x000D,
	0x000E,
	0x000F
};

void CreateConsole(const char *AppName,int screenW,int screenH,int fontW,int fontH)
{
	wHnd=GetStdHandle(STD_OUTPUT_HANDLE); 
    rHnd=GetStdHandle(STD_INPUT_HANDLE);
    
	QueryPerformanceFrequency(&freq);
	
    screenWidth=screenW;
    screenHeight=screenH;

    windowSize.Left=0;
    windowSize.Top=0;
    windowSize.Right=screenWidth-1;
    windowSize.Bottom=screenHeight-1;

    bufferSize.X=screenWidth;
    bufferSize.Y=screenHeight;

    characterBufferSize.X=screenWidth;
    characterBufferSize.Y=screenHeight;

    characterPosition.X=0;
    characterPosition.Y=0;

    consoleWriteArea.Left=0;
    consoleWriteArea.Top=0;
    consoleWriteArea.Right=screenWidth - 1;
    consoleWriteArea.Bottom=screenHeight - 1;

    consoleBuffer=(CHAR_INFO*)malloc(screenWidth*screenHeight*sizeof(CHAR_INFO));

    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = fontW;
    cfi.dwFontSize.Y = fontH;
    cfi.FontFamily = 0;
    cfi.FontWeight =0;


    SetConsoleTitle(AppName);
    SetConsoleWindowInfo(wHnd,TRUE,&windowSize);
    SetCurrentConsoleFontEx(wHnd,TRUE,&cfi);
    SetConsoleScreenBufferSize(wHnd, bufferSize);
    SetConsoleMode(rHnd,ENABLE_MOUSE_INPUT|ENABLE_WINDOW_INPUT);
    
}

int screenwidth()
{
	return screenWidth;	
}

int screenheight()
{
	return screenHeight;
}

clearbuffer()
{
	int i,j;
    for(i=0; i<screenheight(); i++)
    {
        for(j=0; j<screenwidth(); j++)
        {
            consoleBuffer[j +screenWidth* i].Char.AsciiChar =defaultchar;
            consoleBuffer[j +screenWidth* i].Attributes=bgcolor;
        }
    }
}

void SetBGcolor(int color)
{
	bgcolor=color;
	clearbuffer();
}

void DrawFrame(int clear)
{
	WriteConsoleOutput(wHnd,consoleBuffer,characterBufferSize, characterPosition, &consoleWriteArea);
	
	if(clear)
		clearbuffer();
}

void putpixel(int x,int y,int color)
{
	if(x<screenwidth() && x>0 && y<screenheight() && y>0)
	{
    	consoleBuffer[x + screenWidth * y].Char.AsciiChar = defaultchar;
    	consoleBuffer[x + screenWidth * y].Attributes =	color;		
	}
}

void DrawLine(int x1, int y1, int x2, int y2,int col)
{
    int x, y, dx, dy, dx1, dy1, px, py, xe, ye, i;
    dx = x2 - x1;
    dy = y2 - y1;
    dx1 = abs(dx);
    dy1 = abs(dy);
    px = 2 * dy1 - dx1;
    py = 2 * dx1 - dy1;

    if (dy1 <= dx1)
    {
        if (dx >= 0)
        {
            x = x1;
            y = y1;
            xe = x2;
        }
        else
        {
            x = x2;
            y = y2;
            xe = x1;
        }

        putpixel(x, y,col);

        for (i = 0; x<xe; i++)
        {
            x = x + 1;
            if (px<0)
                px = px + 2 * dy1;
            else
            {
                if ((dx<0 && dy<0) || (dx>0 && dy>0))
                    y = y + 1;
                else
                    y = y - 1;
                px = px + 2 * (dy1 - dx1);
            }
            putpixel(x, y,col);
        }
    }
    else
    {
        if (dy >= 0)
        {
            x = x1;
            y = y1;
            ye = y2;
        }
        else
        {
            x = x2;
            y = y2;
            ye = y1;
        }

        putpixel(x, y,col);

        for (i = 0; y<ye; i++)
        {
            y = y + 1;
            if (py <= 0)
                py = py + 2 * dx1;
            else
            {
                if ((dx<0 && dy<0) || (dx>0 && dy>0))
                    x = x + 1;
                else
                    x = x - 1;
                py = py + 2 * (dx1 - dy1);
            }
            putpixel(x, y,col);
        }
    }
}

void DrawCircle(int xc, int yc, int r,int col)
{
    int x = 0;
    int y = r;
    int p = 3 - 2 * r;

    if (!r)
        return;

    while (y >= x)
    {
        putpixel(xc - x, yc - y,col);   //upper left left
        putpixel(xc - y, yc - x,col);   //upper upper left
        putpixel(xc + y, yc - x,col);   //upper upper right
        putpixel(xc + x, yc - y,col);   //upper right right
        putpixel(xc - x, yc + y,col);   //lower left left
        putpixel(xc - y, yc + x,col);   //lower lower left
        putpixel(xc + y, yc + x,col);   //lower lower right
        putpixel(xc + x, yc + y,col);   //lower right right

        if (p < 0)
            p += 4 * x++ + 6;
        else
            p += 4 * (x++ - y--) + 10;
    }
}

void DrawRect(int ox,int oy,int width,int height,int color)
{
	int x1,x2,y1,y2;
	
	x1=ox-(width/2);
	x2=ox+(width/2);
	y1=oy-(height/2);
	y2=oy+(height/2);
	
	for(i=x1;i<x2;i++)
	{
		for(j=y1;j<y2;j++)
		{
			if(i==x1 || i==x2-1 || j==y1 || j==y2-1)
				putpixel(i,j,color);
		}
	}
}

//for Circle filling 
void drawline(int sx, int ex, int ny,int col)
{
	int i;
	for (i = sx; i <= ex; i++)
		putpixel(i, ny,col);
}

void FillCircle(int xc, int yc, int r,int col)
{
	int x = 0;
	int y = r;
	int p = 3 - 2 * r;
	if (!r) return;

	while (y >= x)
	{
		drawline(xc - x, xc + x, yc - y,col);
		drawline(xc - y, xc + y, yc - x,col);
		drawline(xc - x, xc + x, yc + y,col);
		drawline(xc - y, xc + y, yc + x,col);
		if (p < 0) p += 4 * x++ + 6;
		else p += 4 * (x++ - y--) + 10;
	}
}
	
// Fills a rectangle 
void Fillrect(int x1,int y1,int x2,int y2,int color)
{
	int i,j;
	for(i=x1;i<x2;i++)
	{
		for(j=y1;j<y2;j++)
		{
			putpixel(i,j,color);
		}
	}
}

void Fillrect2(int ox,int oy,int width,int height,int color)
{
	int x1,x2,y1,y2;
	int i,j;
	x1=ox-(width/2);
	x2=ox+(width/2);
	y1=oy-(height/2);
	y2=oy+(height/2);
	
	for(i=x1;i<x2;i++)
	{
		for(j=y1;j<y2;j++)
		{
				putpixel(i,j,color);
		}
	}
}

DrawGrid(int ox,int oy,int width,int height,int col,int row,int color)
{
	int offsetx=width/col;
	int offsety=height/row;
	
	int x1=ox-(width/2);
	int x2=ox+(width/2);
	int y1=oy-(height/2);
	int y2=oy+(height/2);
	
	int r=x1,c=y1;
	
	while(r<x2)
	{
		DrawLine(r,y1,r,y2,color);
		r+=offsetx;
	}
	
	while(c<y2)
	{
		DrawLine(x1,c,x2,c,color);
		c+=offsety;
	}
}

void UpdateRot(double ang,int *x,int *y)
{
    double angle=(ang*M_PI)/180;
    
	*x=*x*cos(angle)-*y*sin(angle);
	*y=*x*sin(angle)+*y*cos(angle);	
}

int random(int min,int max)
{
	return min+rand()%max;
}

int randcolor()
{
	int index=rand()%15;
	return color[index];
}

float GetTime()
{
	LARGE_INTEGER time;
	QueryPerformanceCounter(&time);
	return (float)time.QuadPart/freq.QuadPart;
}

#endif
