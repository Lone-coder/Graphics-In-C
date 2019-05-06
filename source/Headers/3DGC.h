#ifndef __3DGC_H__
#define __3DGC_H__

#include<windows.h>
#include<math.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<stdlib.h>

#include "Matrix3D.h"
#include "Geometry.h"

#define MAX(x,y)  x > y ? x : y
#define MIN(x,y)  x < y ? x : y

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
short scale;

int screenWidth;
int screenHeight;

int bgColor=0x00F0;
const char defaultChar=219;

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

int color[16]=
{
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

int randcolor()
{
	int index=rand()%15;
	return color[index];
}


void CreateConsole(const char *appName,int screenW,int screenH,int fontW,int fontH)
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

int midX()
{
	return screenwidth()/2;
}

int midY()
{
	return screenheight()/2;
}

void clearbuffer()
{
	for(i=0; i<screenHeight; i++)
	{
		for(j=0; j<screenWidth; j++)
		{
			consoleBuffer[j +screenWidth* i].Char.AsciiChar =defaultChar;
			consoleBuffer[j +screenWidth* i].Attributes=bgColor;
		}
	}
}

void SetBgColor(int color)
{
	bgColor=color;
	clearbuffer();
}

void DrawFrame()
{
	WriteConsoleOutputA(wHnd,consoleBuffer, characterBufferSize, characterPosition, &consoleWriteArea);
	clearbuffer();
}


Vector3 ProjectPoint(Vector3 v)
{
	Vector3 projected;

	Mat4x4 OrthoProj=
	{
		scale,0,0,0,
		0,scale,0,0,
		0,0,1,0,
		0,0,0,1
	};

	projected=matmul(OrthoProj,v);

	return projected;
}


Vector3 UpdateRotationZ(Vector3 toRotate,double ang)
{
	double angle=(ang*M_PI)/180;

	Vector3 rotated;

	Mat4x4 rotZ=
	{
		cos(angle),-sin(angle),0,0,
		sin(angle),cos(angle),0,0,
		0,0,1,0,
		0,0,0,1
	};

	rotated=matmul(rotZ,toRotate);

	return rotated;

}

Vector3 UpdateRotationY(Vector3 toRotate,double ang)
{
	double angle=(ang*M_PI)/180;

	Vector3 rotated;

	Mat4x4 rotY=
	{
		cos(angle),0,sin(angle),0,
		0,1,0,0,
		-sin(angle),0,cos(angle),0,
		0,0,0,1
	};

	rotated=matmul(rotY,toRotate);

	return rotated;

}

Vector3 UpdateRotationX(Vector3 toRotate,double ang)
{
	double angle=(ang*M_PI)/180;

	Vector3 rotated;

	Mat4x4 rotX=
	{
		1,0,0,0,
		0,cos(angle),-sin(angle),0,
		0,sin(angle),cos(angle),0,
		0,0,0,1
	};

	rotated=matmul(rotX,toRotate);

	return rotated;

}

Vector3 TranslateObject(Vector3 v,FLOATPOINT x,FLOATPOINT y,FLOATPOINT z)
{
	Vector3 translated;

	Mat4x4 translate=
	{
		1,0,0,x,
		0,1,0,y,
		0,0,1,z,
		0,0,0,1
	};

	translated=matmul(translate,v);

	return translated;
}

int tranX(int x)
{
	return x+(screenWidth/2);
}

int tranY(int y)
{
	return (screenHeight/2)-y;
}

void putpixel(int x,int y,int color)
{
	if(x>(-screenWidth/2) && x<(screenWidth/2) && y>(-screenHeight/2) && y<(screenHeight/2))
	{
		consoleBuffer[tranX(x) +screenWidth* tranY(y)].Char.AsciiChar = defaultChar;
		consoleBuffer[tranX(x)+screenWidth* tranY(y)].Attributes =color;
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

void SWAP(int* x, int* y)
{
	int t = *x;
	*x = *y;
	*y = t;
};

void drawline(int sx, int ex, int ny,int col)
{
	int i;
	for (i = sx; i <= ex; i++)
		putpixel(i, ny,col);
};

void FillTriangle(int x1, int y1, int x2, int y2, int x3, int y3,int col)
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
		drawline(minx, maxx, y,col);

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
		drawline(minx, maxx, y,col);
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

void DrawTriangle(Triangle t,int color)
{
	DrawLine(t.vertex1.x,t.vertex1.y,t.vertex2.x,t.vertex2.y,color);
	DrawLine(t.vertex2.x,t.vertex2.y,t.vertex3.x,t.vertex3.y,color);
	DrawLine(t.vertex3.x,t.vertex3.y,t.vertex1.x,t.vertex1.y,color);

}

void Filltriangle(Triangle t,int color)
{
	FillTriangle(t.vertex1.x,t.vertex1.y,t.vertex2.x,t.vertex2.y,t.vertex3.x,t.vertex3.y,color);
}


//for debug

void printMat(double mat[3][1])
{
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
