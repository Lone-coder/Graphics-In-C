#ifndef __MATRIX3D_H__
#define __MATRIX3D_H__

#include "Geometry.h"

typedef struct{

    double mat[3][3];

}Mat3x3;

void matmul(Mat3x3 m,vector3 pin,vector3 *pout)
{
    pout->x=m.mat[0][0]*pin.x+m.mat[0][1]*pin.y+m.mat[0][2]*pin.z;
    pout->y=m.mat[1][0]*pin.x+m.mat[1][1]*pin.y+m.mat[1][2]*pin.z;
    pout->z=m.mat[2][0]*pin.x+m.mat[2][1]*pin.y+m.mat[2][2]*pin.z;
}

#endif
