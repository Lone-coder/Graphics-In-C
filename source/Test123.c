#include<stdio.h>
#include<stdlib.h>

void main()
{
	int *p1=(int*)malloc(sizeof(int)*4);
	p1[0]=10;
	p1[5]=11;
	printf("%d\n",p1[4]);
		
	p1=(int*)malloc(sizeof(int)*5);
	
	printf("%d",p1[0]);
	
	free(p1);
}
