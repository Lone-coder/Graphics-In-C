#include "2DGC.h"

void main()
{
	int x,y;
	int r=90;
	double inSquare,inCircle;
	double pivalue;
	int dist;
	
	FILE *file;
	file=fopen("PIvalue.txt","w");
	
	OnStart()
	{
		CreateConsole("Calculating PI using Monte Carlo method",200,200,4,4);
		DrawRect(10,10,190,190,FG_GREEN);
		DrawCircle(100,100,r,FG_RED);
	}
	
	OnUpdate()
	{
		for(i=0;i<100;i++)
		{
			x=10+rand()%180;
			y=10+rand()%180;
			putpixel(x,y,FG_BLUE);
			dist= (x-100)*(x-100) + (y-100)*(y-100);
			
			if(dist<=r*r)
			{
				inCircle+=1;
			}
			inSquare+=1;
						
		}
	
		pivalue=4*(inCircle/inSquare);
		fprintf(file,"%lf \n",pivalue);
		DrawFrame(FALSE);
	}
	
	fclose(file);
}
