#include "2DGC.h"

void main()
{
	float start=GetTime();
	printf("\n\nExecution  time : %.10lf",start);
	printf("Hello World");
	
	float end=GetTime();
	printf("\n\nExecution  time : %.10lf",end);
	float dt=end-start;
	printf("\n\nExecution  time : %.10lf",dt);
	
}
