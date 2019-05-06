#ifndef _MATRIX3D_H_
#define _MATRIX3D_H_

#include "Geometry.h"

typedef struct
{
	double mat[4][4];
} Mat4x4;


Vector3 matmul(Mat4x4 m,Vector3 pin)
{
	Vector3 pout;

	pout.x=m.mat[0][0]*pin.x+m.mat[0][1]*pin.y+m.mat[0][2]*pin.z+m.mat[0][3]*pin.w;
	pout.y=m.mat[1][0]*pin.x+m.mat[1][1]*pin.y+m.mat[1][2]*pin.z+m.mat[1][3]*pin.w;
	pout.z=m.mat[2][0]*pin.x+m.mat[2][1]*pin.y+m.mat[2][2]*pin.z+m.mat[2][3]*pin.w;
	pout.w=m.mat[3][0]*pin.x+m.mat[3][1]*pin.y+m.mat[3][2]*pin.z+m.mat[3][3]*pin.w;

	return pout;
}

Mat4x4 matmul4x4(Mat4x4 m1,Mat4x4 m2)
{
	
}


#endif
