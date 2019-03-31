#include "2DGC.h"

void main()
{
	CreateConsole("Time calculation test",100,50,13,13);
	
	float ctime,ptime,dt;
	
	for(i=0;i<1000000;i++)
	{
		ctime=GetTime();		
		dt=ctime-ptime;
		printf("Current time: %f \t Prev time:%f \t delta time: %f \n",ctime,ptime,dt);
		usleep(3);
		ptime=ctime;	
	}

}
