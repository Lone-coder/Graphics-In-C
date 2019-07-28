#include<3DG.h>

void main()
{
	Object cube = LoadOBJFile("cube.obj");
	
	int i;
	
	for(i=0;i<cube.nTriangles;i++)
	{
		printf("%d",i+1);
		PrintVector3(cube.normals[i],"");
	}
	
	return;
}
