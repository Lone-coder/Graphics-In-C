#include "3DGC.h"

void main()
{
	CreateConsole("Perspective Demo",200,200,2,2);

    OnStart()
    {
        initVector3(&p[0],1,1,1);
        initVector3(&p[1],-1,1,1);
        initVector3(&p[2],-1,-1,1);
        initVector3(&p[3],1,-1,1);
        initVector3(&p[4],1,1,-1);
        initVector3(&p[5],-1,1,-1);
        initVector3(&p[6],-1,-1,-1);
        initVector3(&p[7],1,-1,-1);
        
        UpdateRotY(0,TRUE);
        UpdateRotX(30,TRUE);
        UpdateRotZ(10,TRUE);
    }

	OnUpdate()
	{
        UpdateRotY(xtheta,FALSE);
		Projection=Presp;

		ProjectPoint(pr[0],&pp[0]);
		ProjectPoint(pr[1],&pp[1]);
		ProjectPoint(pr[2],&pp[2]);
		ProjectPoint(pr[3],&pp[3]);
		ProjectPoint(pr[4],&pp[4]);
		ProjectPoint(pr[5],&pp[5]);
		ProjectPoint(pr[6],&pp[6]);
		ProjectPoint(pr[7],&pp[7]);


        putpixel(pp[0].x,pp[0].y,FG_BLUE);
        putpixel(pp[1].x,pp[1].y,FG_BLUE);
        putpixel(pp[2].x,pp[2].y,FG_BLUE);
        putpixel(pp[3].x,pp[3].y,FG_BLUE);
        putpixel(pp[4].x,pp[4].y,FG_BLUE);
        putpixel(pp[5].x,pp[5].y,FG_BLUE);
        putpixel(pp[6].x,pp[6].y,FG_BLUE);
        putpixel(pp[7].x,pp[7].y,FG_BLUE);

		DrawLine(pp[0].x,pp[0].y,pp[1].x,pp[1].y,FG_BLUE);
		DrawLine(pp[1].x,pp[1].y,pp[2].x,pp[2].y,FG_CYAN);
		DrawLine(pp[2].x,pp[2].y,pp[3].x,pp[3].y,FG_DARK_BLUE);
		DrawLine(pp[3].x,pp[3].y,pp[0].x,pp[0].y,FG_DARK_CYAN);
		DrawLine(pp[4].x,pp[4].y,pp[5].x,pp[5].y,FG_DARK_GREEN);
		DrawLine(pp[5].x,pp[5].y,pp[6].x,pp[6].y,FG_DARK_GREY);
		DrawLine(pp[6].x,pp[6].y,pp[7].x,pp[7].y,FG_DARK_MAGENTA);
		DrawLine(pp[7].x,pp[7].y,pp[4].x,pp[4].y,FG_DARK_RED);

		DrawLine(pp[0].x,pp[0].y,pp[4].x,pp[4].y,FG_DARK_YELLOW);
		DrawLine(pp[1].x,pp[1].y,pp[5].x,pp[5].y,FG_GREEN);
		DrawLine(pp[2].x,pp[2].y,pp[6].x,pp[6].y,FG_MAGENTA);
		DrawLine(pp[3].x,pp[3].y,pp[7].x,pp[7].y,FG_RED);

        DrawFrame();
		xtheta+=2;

	}
}
