#ifndef __GEOMETRY_H__
#define __GEOMETRY_H__

double xtheta,ytheta,ztheta;

typedef struct V{

    double x,y,z;

}vector3;

typedef struct T{

    vector3 tri[3];

}tris;

void initVector3(vector3 *p,double x,double y,double z)
{
    p->x=x;
    p->y=y;
    p->z=z;
}

vector3 p[8];
vector3 pr[8];
vector3 pp[8];

#endif
