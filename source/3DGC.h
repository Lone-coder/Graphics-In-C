#ifndef __3DGC_H__
#define __3DGC_H__

#include<windows.h>
#include<math.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

#include "Matrix3D.h"
#include "Geometry.h"

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
short Projection;

int screenWidth;
int screenHeight;

double FOV=180;
double AspectRatio=0;

Mat3x3 IdMat=
{
    1,0,0,
    0,1,0,
    0,0,1
};

enum Projections
{
    Ortho,
    Presp
};

enum Color
{
    FG_BLACK		= 0x0000,
    FG_DARK_BLUE    = 0x0001,
    FG_DARK_GREEN   = 0x0002,
    FG_DARK_CYAN    = 0x0003,
    FG_DARK_RED     = 0x0004,
    FG_DARK_MAGENTA = 0x0005,
    FG_DARK_YELLOW  = 0x0006,
    FG_GREY			= 0x0007,
    FG_DARK_GREY    = 0x0008,
    FG_BLUE			= 0x0009,
    FG_GREEN		= 0x000A,
    FG_CYAN			= 0x000B,
    FG_RED			= 0x000C,
    FG_MAGENTA		= 0x000D,
    FG_YELLOW		= 0x000E,
    FG_WHITE		= 0x000F,
    BG_BLACK		= 0x0000,
    BG_DARK_BLUE	= 0x0010,
    BG_DARK_GREEN	= 0x0020,
    BG_DARK_CYAN	= 0x0030,
    BG_DARK_RED		= 0x0040,
    BG_DARK_MAGENTA = 0x0050,
    BG_DARK_YELLOW	= 0x0060,
    BG_GREY			= 0x0070,
    BG_DARK_GREY	= 0x0080,
    BG_BLUE			= 0x0090,
    BG_GREEN		= 0x00A0,
    BG_CYAN			= 0x00B0,
    BG_RED			= 0x00C0,
    BG_MAGENTA		= 0x00D0,
    BG_YELLOW		= 0x00E0,
    BG_WHITE		= 0x00F0,
};


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

    AspectRatio=screenWidth/screenHeight;
}

void clearbuffer()
{
    for(i=0; i<screenHeight; i++)
    {
        for(j=0; j<screenWidth; j++)
        {
            consoleBuffer[j +screenWidth* i].Char.AsciiChar =' ';
            consoleBuffer[j +screenWidth* i].Attributes=BG_BLACK;
        }
    }
}

void DrawFrame()
{
    WriteConsoleOutput(wHnd,consoleBuffer, characterBufferSize, characterPosition, &consoleWriteArea);
    clearbuffer();
}

void rewriteP()
{
    matmul(IdMat,pr[0],&p[0]);
    matmul(IdMat,pr[1],&p[1]);
    matmul(IdMat,pr[2],&p[2]);
    matmul(IdMat,pr[3],&p[3]);
    matmul(IdMat,pr[4],&p[4]);
    matmul(IdMat,pr[5],&p[5]);
    matmul(IdMat,pr[6],&p[6]);
    matmul(IdMat,pr[7],&p[7]);
}

void UpdateRotX(double ang,int B)
{
    double angle=(ang*M_PI)/180;

    Mat3x3 rotX=
    {
        1,0,0,
        0,cos(angle),-sin(angle),
        0,sin(angle),cos(angle)
    };

    matmul(rotX,p[0],&pr[0]);
    matmul(rotX,p[1],&pr[1]);
    matmul(rotX,p[2],&pr[2]);
    matmul(rotX,p[3],&pr[3]);
    matmul(rotX,p[4],&pr[4]);
    matmul(rotX,p[5],&pr[5]);
    matmul(rotX,p[6],&pr[6]);
    matmul(rotX,p[7],&pr[7]);

    if(B==TRUE)
        rewriteP();
}

void UpdateRotY(double ang,int B)
{
    double angle=(ang*M_PI)/180;

    Mat3x3 rotY=
    {
        cos(angle),0,sin(angle),
        0,1,0,
        -sin(angle),0,cos(angle)
    };

    matmul(rotY,p[0],&pr[0]);
    matmul(rotY,p[1],&pr[1]);
    matmul(rotY,p[2],&pr[2]);
    matmul(rotY,p[3],&pr[3]);
    matmul(rotY,p[4],&pr[4]);
    matmul(rotY,p[5],&pr[5]);
    matmul(rotY,p[6],&pr[6]);
    matmul(rotY,p[7],&pr[7]);

    if(B==TRUE)
        rewriteP();
}

void UpdateRotZ(double ang,int B)
{
    double angle=(ang*M_PI)/180;

    Mat3x3 rotZ=
    {
        cos(angle),-sin(angle),0,
        sin(angle),cos(angle),0,
        0,0,1
    };

    matmul(rotZ,p[0],&pr[0]);
    matmul(rotZ,p[1],&pr[1]);
    matmul(rotZ,p[2],&pr[2]);
    matmul(rotZ,p[3],&pr[3]);
    matmul(rotZ,p[4],&pr[4]);
    matmul(rotZ,p[5],&pr[5]);
    matmul(rotZ,p[6],&pr[6]);
    matmul(rotZ,p[7],&pr[7]);

    if(B==TRUE)
        rewriteP();
}

void ProjectPoint(vector3 pin,vector3 *pout)
{
    double d=3;
    double z=AspectRatio/tan(FOV*0.5*M_PI/180);

    //if(pin.z!=0)
    //    z=z/pin.z;

    z=AspectRatio/(d-pin.z);

    if(Projection==Presp)
    {
        Mat3x3 PrespProj={
            z*50,0,0,
            0,z*50,0,
            0,0,0
        };

        matmul(PrespProj,pin,pout);
    }
    else
    {
        Mat3x3 OrthoProj={
            50,0,0,
            0,50,0,
            0,0,0
        };

        matmul(OrthoProj,pin,pout);
    }

}

int tranX(int x)
{
    return x-(screenWidth/2);
}

int tranY(int y)
{
    return (screenHeight/2)-y;
}

void putpixel(int x,int y,int color)
{
    if(tranX(x)>(-screenWidth) && tranX(x)<(screenWidth) && tranY(y)>(-screenHeight) && tranY(y)<(screenHeight))
    {
        consoleBuffer[tranX(x) +screenWidth* tranY(y)].Char.AsciiChar = 219;
        consoleBuffer[tranX(x) +screenWidth* tranY(y)].Attributes =color | BG_WHITE;
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

void DrawTriangle(triangle t)
{
	DrawLine(t.vertex1.x,t.vertex1.y,t.vertex2.x,t.vertex2.y,FG_WHITE);
	DrawLine(t.vertex2.x,t.vertex2.y,t.vertex3.x,t.vertex3.y,FG_WHITE);
	DrawLine(t.vertex3.x,t.vertex3.y,t.vertex1.x,t.vertex1.y,FG_WHITE);
	
	FillTriangle(t.vertex1.x,t.vertex1.y,t.vertex2.x,t.vertex2.y,t.vertex3.x,t.vertex3.y,FG_WHITE);
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
