#include "3DGC.h"

int main()
{
    CreateConsole("Filled polygon",600,200,1,1);

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

        FillTriangle(pp[0].x,pp[0].y,pp[1].x,pp[1].y,pp[2].x,pp[2].y,FG_BLUE);
        FillTriangle(pp[0].x,pp[0].y,pp[3].x,pp[3].y,pp[2].x,pp[2].y,FG_GREEN);
        FillTriangle(pp[4].x,pp[4].y,pp[5].x,pp[5].y,pp[6].x,pp[6].y,FG_RED);
        FillTriangle(pp[4].x,pp[4].y,pp[6].x,pp[6].y,pp[7].x,pp[7].y,FG_CYAN);


        DrawFrame();
        xtheta++;
    }
}
