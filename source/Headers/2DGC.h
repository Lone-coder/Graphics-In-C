#ifndef _2DGC_H_
#define _2DGC_H_ 

#include<windows.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#include "Matrix3D.h"
#include "Geometry.h"

#define OnUpdate() while(1)
#define OnStart() if(1)

#define MAX(X,Y)  X > Y ? X : Y
#define MIN(X,Y)  X < Y ? X : Y

//Windows data types
HANDLE wHnd;
HANDLE rHnd;
COORD bufferSize;
COORD characterBufferSize;
COORD characterPosition;
SMALL_RECT windowSize;
SMALL_RECT consoleWriteArea ;
CHAR_INFO *consoleBuffer;

int screenWidth;
int screenHeight;

int bgColor = 0x00F0;
const char defaultChar = 219; 

float deltaTime = 0.05;

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

void CreateConsole(const char *AppName,int width,int height,int fontW,int fontH)
{
	
	wHnd=GetStdHandle(STD_OUTPUT_HANDLE); 
    rHnd=GetStdHandle(STD_INPUT_HANDLE);
    
    screenWidth= width;
    screenHeight= height;

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

    SetConsoleTitleA(AppName);
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

int midX()
{
	return screenwidth()/2;
}

int midY()
{
	return screenheight()/2;
}

int tranX(int x)
{
	return x + midX();
}

int tranY(int y)
{
	return midY() - y;
}

void ClearBuffer()
{
	int i, j;

    for(i=0; i<screenheight(); i++)
    {
        for(j=0; j<screenwidth(); j++)
        {
            consoleBuffer[j +screenWidth* i].Char.AsciiChar = defaultChar;
            consoleBuffer[j +screenWidth* i].Attributes = bgColor;
        }
    }
}

void SetBgColor(int color)
{
	bgColor = color;
	ClearBuffer();
}

void DrawFrame(int clear)
{
	WriteConsoleOutputA(wHnd,consoleBuffer,characterBufferSize, characterPosition, &consoleWriteArea);
	
	if(clear)
		ClearBuffer();
}

void PutPixel(int x,int y,int color)
{
	if(x<=screenwidth() && x>=0 && y<=screenheight() && y>=0)
	{
    	consoleBuffer[x + screenWidth * y].Char.AsciiChar = defaultChar;
    	consoleBuffer[x + screenWidth * y].Attributes =	color;		
	}
}

void putpixel(int x,int y,int color,char c)
{
	if(x>=(-screenWidth/2) && x<=(screenWidth/2) && y>=(-screenHeight/2) && y<=(screenHeight/2))
	{
		consoleBuffer[tranX(x) +screenWidth* tranY(y)].Char.AsciiChar = c;
		consoleBuffer[tranX(x)+screenWidth* tranY(y)].Attributes = color;
	}
}

void DrawLine(int x1, int y1, int x2, int y2,int col,char c)
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

		putpixel(x, y,col,c);

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
			putpixel(x, y,col,c);
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

		putpixel(x, y,col,c);

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
			putpixel(x, y,col,c);
		}
	}
}

void DrawCircle(int xc, int yc, int r,int col,char c)
{
	int x = 0;
	int y = r;
	int p = 3 - 2 * r;

	if (!r)
		return;

	while (y >= x)
	{
		putpixel(xc - x, yc - y,col,c);   //upper left left
		putpixel(xc - y, yc - x,col,c);   //upper upper left
		putpixel(xc + y, yc - x,col,c);   //upper upper right
		putpixel(xc + x, yc - y,col,c);   //upper right right
		putpixel(xc - x, yc + y,col,c);   //lower left left
		putpixel(xc - y, yc + x,col,c);   //lower lower left
		putpixel(xc + y, yc + x,col,c);   //lower lower right
		putpixel(xc + x, yc + y,col,c);   //lower right right

		if (p < 0)
			p += 4 * x++ + 6;
		else
			p += 4 * (x++ - y--) + 10;
	}
}

void SWAP(int* x, int* y)
{
	int t = *x;
	*x = *y;
	*y = t;
};

void drawline(int sx, int ex, int ny,int col,char c)
{
	int i;
	for (i = sx; i <= ex; i++)
		putpixel(i, ny,col,c);
};

void FillTriangle(int x1, int y1, int x2, int y2, int x3, int y3,int col,char c)
{
	int t1x, t2x, y, minx, maxx, t1xp, t2xp;
	int changed1 = FALSE;
	int changed2 = FALSE;
	int signx1, signx2, dx1, dy1, dx2, dy2;
	int e1, e2;
	int i;

	if (y1>y2)
	{
		SWAP(&y1,&y2);
		SWAP(&x1,&x2);
	}
	if (y1>y3)
	{
		SWAP(&y1,&y3);
		SWAP(&x1,&x3);
	}
	if (y2>y3)
	{
		SWAP(&y2,&y3);
		SWAP(&x2,&x3);
	}

	t1x = t2x = x1;
	y = y1;
	dx1 = (int)(x2 - x1);
	if (dx1<0)
	{
		dx1 = -dx1;
		signx1 = -1;
	}
	else
		signx1 = 1;
	dy1 = (int)(y2 - y1);

	dx2 = (int)(x3 - x1);
	if (dx2<0)
	{
		dx2 = -dx2;
		signx2 = -1;
	}
	else
		signx2 = 1;
	dy2 = (int)(y3 - y1);

	if (dy1 > dx1)
	{
		SWAP(&dx1,&dy1);
		changed1 = TRUE;
	}
	if (dy2 > dx2)
	{
		SWAP(&dy2,&dx2);
		changed2 = TRUE;
	}

	e2 = (int)(dx2 >> 1);

	if (y1 == y2)
		goto next;
	e1 = (int)(dx1 >> 1);

	for (i = 0; i < dx1;)
	{
		t1xp = 0;
		t2xp = 0;
		if (t1x<t2x)
		{
			minx = t1x;
			maxx = t2x;
		}
		else
		{
			minx = t2x;
			maxx = t1x;
		}

		while (i<dx1)
		{
			i++;
			e1 += dy1;
			while (e1 >= dx1)
			{
				e1 -= dx1;
				if (changed1)
					t1xp = signx1;
				else
					goto next1;
			}
			if (changed1)
				break;
			else
				t1x += signx1;
		}

next1:

		while (1)
		{
			e2 += dy2;
			while (e2 >= dx2)
			{
				e2 -= dx2;
				if (changed2)
					t2xp = signx2;
				else
					goto next2;
			}
			if (changed2)
				break;
			else
				t2x += signx2;
		}
next2:
		if (minx>t1x)
			minx = t1x;
		if (minx>t2x)
			minx = t2x;
		if (maxx<t1x)
			maxx = t1x;
		if (maxx<t2x)
			maxx = t2x;
		drawline(minx, maxx, y,col,c);

		if (!changed1)
			t1x += signx1;
		t1x += t1xp;
		if (!changed2)
			t2x += signx2;
		t2x += t2xp;
		y += 1;
		if (y == y2)
			break;

	}
next:
	dx1 = (int)(x3 - x2);
	if (dx1<0)
	{
		dx1 = -dx1;
		signx1 = -1;
	}
	else
		signx1 = 1;
	dy1 = (int)(y3 - y2);
	t1x = x2;

	if (dy1 > dx1)
	{
		SWAP(&dy1,&dx1);
		changed1 = TRUE;
	}
	else
		changed1 = FALSE;

	e1 = (int)(dx1 >> 1);

	for (i = 0; i <= dx1; i++)
	{
		t1xp = 0;
		t2xp = 0;
		if (t1x<t2x)
		{
			minx = t1x;
			maxx = t2x;
		}
		else
		{
			minx = t2x;
			maxx = t1x;
		}

		while (i<dx1)
		{
			e1 += dy1;
			while (e1 >= dx1)
			{
				e1 -= dx1;
				if (changed1)
				{
					t1xp = signx1;
					break;
				}
				else
					goto next3;
			}
			if (changed1)
				break;
			else
				t1x += signx1;
			if (i<dx1)
				i++;
		}
next3:

		while (t2x != x3)
		{
			e2 += dy2;
			while (e2 >= dx2)
			{
				e2 -= dx2;
				if (changed2)
					t2xp = signx2;
				else
					goto next4;
			}
			if (changed2)
				break;
			else
				t2x += signx2;
		}
next4:

		if (minx>t1x)
			minx = t1x;
		if (minx>t2x)
			minx = t2x;
		if (maxx<t1x)
			maxx = t1x;
		if (maxx<t2x)
			maxx = t2x;
		drawline(minx, maxx, y,col,c);
		if (!changed1)
			t1x += signx1;
		t1x += t1xp;
		if (!changed2)
			t2x += signx2;
		t2x += t2xp;
		y += 1;
		if (y>y3)
			return;
	}

}

void DrawTriangle(Triangle t,int color,char c)
{
	DrawLine(t.vertex1.x,t.vertex1.y,t.vertex2.x,t.vertex2.y,color,c);
	DrawLine(t.vertex2.x,t.vertex2.y,t.vertex3.x,t.vertex3.y,color,c);
	DrawLine(t.vertex3.x,t.vertex3.y,t.vertex1.x,t.vertex1.y,color,c);
}

void Filltriangle(Triangle t,int color,char c)
{
	FillTriangle(t.vertex1.x,t.vertex1.y,t.vertex2.x,t.vertex2.y,t.vertex3.x,t.vertex3.y,color,c);
}

void FillRectArea(int ox,int oy,int width,int height,int color,char c)
{
	int i, j;
	int x1,x2,y1,y2;
	
	x1 = ox-(width/2);
	x2 = ox+(width/2);
	y1 = oy-(height/2);
	y2 = oy+(height/2);
	
	for(i = x1; i <= x2; i++)
	{
		for(j = y1; j <= y2; j++)
		{
				putpixel(i,j,color,c);
		}
	}
}

void DrawRectArea(int ox,int oy,int width,int height,int color,char c)
{
	int i, j;
	int x1,x2,y1,y2;
	
	x1 = ox-(width/2);
	x2 = ox+(width/2);
	y1 = oy-(height/2);
	y2 = oy+(height/2);
	
	for(i = x1; i <= x2; i++)
	{
		for(j = y1; j <= y2; j++)
		{
			if(i==x1 || i==x2 || j==y1 || j==y2)
				putpixel(i,j,color,c);
		}
	}
}

void DrawGrid(int ox,int oy,int width,int height,int col,int row,int color)
{
	int offsetx = width/col;
	int offsety = height/row;
	
	int x1 = ox-(width/2);
	int x2 = ox+(width/2);
	int y1 = oy-(height/2);
	int y2 = oy+(height/2);
	
	int r = x1,c = y1;
	
	while(r <= x2)
	{
		DrawLine(r,y1,r,y2,color,defaultChar);
		r += offsetx;
	}
	
	while(c <= y2)
	{
		DrawLine(x1,c,x2,c,color,defaultChar);
		c += offsety;
	}
}

int random(int min,int max)
{
	return min+rand()%max;
}

int RandomColor()
{
	int index = rand()%15;
	return color[index];
}

double GetTime()
{
	LARGE_INTEGER time;
	QueryPerformanceCounter(&time);
	return time.QuadPart/ 10000.0;
}

//for debug
void printMat(double mat[3][1])
{
	int i,j;
	
	for(i=0; i<1; i++)
	{
		for(j=0; j<3; j++)
		{
			printf("%lf ; ",mat[i][j]);
		}
		printf("\n");
	}
}

#endif
