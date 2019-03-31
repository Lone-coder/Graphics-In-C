//Monte Carlo method to calculate approx value of PI

#include "2DGC.h"

void main()
{
	double x,y;
	double r=90;
	double inSquare,inCircle;
	double pivalue;
	double dist;
	
	FILE *file;
	file=fopen("PIvalue.txt","w");
	
	OnStart()
	{
		CreateConsole("Calculating PI using Monte Carlo method",200,200,2,2);
		DrawRect(100,100,180,180,GREEN);
		DrawCircle(100,100,r,RED);
	}
	
	OnUpdate()
	{
		for(i=0;i<1000;i++)
		{
			x=10+rand()%180;
			y=10+rand()%180;
			putpixel((int)x,(int)y,BLUE);
			dist= (x-100)*(x-100) + (y-100)*(y-100);
			
			if(dist<r*r)
			{
				inCircle+=1;
			}
			inSquare+=1;
						
		}
	
		pivalue=4*(inCircle/inSquare);
		fprintf(file,"%.15lf \n",pivalue);
		DrawFrame(FALSE);
	}

	fclose(file);
}
