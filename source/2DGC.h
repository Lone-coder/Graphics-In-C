#ifndef _2DGC_H_
#define _2DGC_H_

#include<windows.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>

#define FALSE 0
#define TRUE 1
#define OnUpdate() while(1)
#define OnStart() if(1)


// Windows data types
HANDLE wHnd;
HANDLE rHnd;
SMALL_RECT windowSize;
COORD bufferSize;
COORD characterBufferSize;
COORD characterPosition;
SMALL_RECT consoleWriteArea ;
CHAR_INFO *consoleBuffer;

short i,j;

int screenWidth;
int screenHeight;

int bgcolor=0x00F0;

enum Color
{
    FG_BLACK			= 0x0000,
    FG_DARK_BLUE   		= 0x0001,
    FG_DARK_GREEN   	= 0x0002,
    FG_DARK_CYAN    	= 0x0003,
    FG_DARK_RED     	= 0x0004,
    FG_DARK_MAGENTA 	= 0x0005,
    FG_DARK_YELLOW  	= 0x0006,
    FG_GREY				= 0x0007,
    FG_DARK_GREY    	= 0x0008,
    FG_BLUE				= 0x0009,
    FG_GREEN			= 0x000A,
    FG_CYAN				= 0x000B,
    FG_RED				= 0x000C,
    FG_MAGENTA			= 0x000D,
    FG_YELLOW			= 0x000E,
    FG_WHITE			= 0x000F,
    BG_BLACK			= 0x0000,
    BG_DARK_BLUE		= 0x0010,
    BG_DARK_GREEN		= 0x0020,
    BG_DARK_CYAN		= 0x0030,
    BG_DARK_RED			= 0x0040,
    BG_DARK_MAGENTA		= 0x0050,
    BG_DARK_YELLOW		= 0x0060,
    BG_GREY				= 0x0070,
    BG_DARK_GREY		= 0x0080,
    BG_BLUE				= 0x0090,
    BG_GREEN			= 0x00A0,
    BG_CYAN				= 0x00B0,
    BG_RED				= 0x00C0,
    BG_MAGENTA			= 0x00D0,
    BG_YELLOW			= 0x00E0,
    BG_WHITE			= 0x00F0,
};

void CreateConsole(char appName[],int screenW,int screenH,int fontW,int fontH)
{
    screenWidth=screenW;
    screenHeight=screenH;

    windowSize.Left=0;
    windowSize.Top=0;
    windowSize.Right=screenWidth - 1;
    windowSize.Bottom=screenHeight - 1;

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

    wHnd=GetStdHandle(STD_OUTPUT_HANDLE);
    rHnd=GetStdHandle(STD_INPUT_HANDLE);

    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = fontW;
    cfi.dwFontSize.Y = fontH;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;

    SetConsoleTitle(appName);
    SetCurrentConsoleFontEx(wHnd,FALSE,&cfi);
    SetConsoleWindowInfo(wHnd,TRUE,&windowSize);
    SetConsoleScreenBufferSize(wHnd, bufferSize);
}

int screenwidth()
{
	return screenWidth;	
}

int screenheight()
{
	return screenHeight;
}

void clearbuffer()
{
    for(i=0; i<screenHeight; i++)
    {
        for(j=0; j<screenWidth; j++)
        {
            consoleBuffer[j +screenWidth* i].Char.AsciiChar =' ';
            consoleBuffer[j +screenWidth* i].Attributes=bgcolor;
        }
    }
}

void SetBGcolor(int color)
{
	bgcolor=color;
}

int FGtoBG(int FGcolor)
{
		switch(FGcolor)
		{
			case FG_DARK_BLUE:
				return BG_DARK_BLUE;

		    case FG_DARK_GREEN:
		    	return BG_DARK_GREEN;
		    	
		    case FG_DARK_CYAN:
		    	return BG_DARK_CYAN;
		    	
		    case FG_DARK_RED:
		    	return BG_DARK_RED;
		    	
		    case FG_DARK_MAGENTA:
		    	return BG_DARK_MAGENTA;
		    	
		    case FG_DARK_YELLOW:
		    	return BG_DARK_YELLOW;
		    	
		    case FG_GREY:
				return BG_GREY;
						
		    case FG_DARK_GREY:
			    return BG_DARK_GREY;	
			    
		    case FG_BLUE:
				return BG_BLUE;
						
		    case FG_GREEN:
				return BG_GREEN;
				
		    case FG_CYAN:
				return BG_CYAN;
						
		    case FG_RED:
				return BG_RED;
						
		    case FG_MAGENTA:
				return BG_MAGENTA;
				
		    case FG_YELLOW:
				return BG_YELLOW;
				
		    case FG_WHITE:		
		    	return BG_WHITE;
		    	
		    default:
		    	return BG_BLACK;

		}
}

void DrawFrame(int clear)
{
    WriteConsoleOutput(wHnd,consoleBuffer, characterBufferSize, characterPosition, &consoleWriteArea);
    if(clear)
    	clearbuffer();
}

void putpixel(int x,int y,int color)
{
        consoleBuffer[x +screenWidth* y].Char.AsciiChar = 219;
        consoleBuffer[x +screenWidth* y].Attributes =color | bgcolor;
}

void putChar(int x,int y,char c,int fcolor,int bgcolor)
{
	consoleBuffer[x +screenWidth* y].Char.AsciiChar = c;
    consoleBuffer[x +screenWidth* y].Attributes =fcolor | bgcolor;
}

void printString(char *s,int x,int y,int fcolor,int bgcolor)
{
	int i=0;
	
	while(*(s+i)!=0)
	{
		putChar(x,y,*(s+i),fcolor,bgcolor);
		x++;
		i++;
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

void DrawRect(int x1,int y1,int x2,int y2,int color)
{
	for(i=x1;i<=x2;i++)
	{
		for(j=y1;j<=y2;j++)
		{
			if(i==x1 || i==x2 || j==y1 || j==y2)
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
};

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
	};
	
// Fills a rectangle 
void Fillrect(int x1,int y1,int x2,int y2,int color)
{
	for(i=x1;i<x2;i++)
	{
		for(j=y1;j<=y2;j++)
		{
			putpixel(i,j,color);
		}
	}
}

void UpdateRot(double ang,int *x,int *y)
{
    double angle=(ang*M_PI)/180;
    
	*x=*x*cos(angle)-*y*sin(angle);
	*y=*x*sin(angle)+*y*cos(angle);
	
}


#endif
