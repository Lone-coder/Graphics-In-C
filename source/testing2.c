#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<unistd.h>

//struct timespec start,end;
//time_t s,e;
long start,end;

void main()
{
//	clock_gettime(CLOCK_MONOTONIC,&start);
//	
//	
//	usleep(1);
//	
//	clock_gettime(CLOCK_MONOTONIC,&end);
//	
//	
//	double diff=end.tv_nsec-start.tv_nsec;

//	time(&s);
//	
//	sleep(3);
//	
//	time(&e);
//	
//	printf("%f \n",difftime(e,s));

	start=GetTickCount();
	
	sleep(3);
	
	end=GetTickCount();
	
	printf("%f \n",start);

}
