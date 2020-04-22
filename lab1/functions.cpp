#include <iostream>
#inlcude <cmath>
#include "functions.h"

void dis_frac_pt(double *x)
{
   *x = round(*x);

}
void dis_frac(double &x)
{
    x = round(x);
}


void change_sign_pt(float *c,int *d)
{
    *c = -*c;
    *d = -*d;
}
void change_sign(float &c,int &d)
{
    c = -c;
    d = -d;
}



void MoveCircle_pt(struct Circle *cir, struct Vector *vec)
{
    cir->point1.x += vec->x;
    cir->point1.y += vec->y;


}
void MoveCircle(Circle &cir, const Vector &vec)
{
    cir.point1.x += vec.x;
    cir.point1.y += vec.y;


}


void Mul_matrix_pt(Matrix *Mat, double*z)
{
     for (int i = 0; i<3 ; i++)
     {
         for(int j = 0; j<3; j++)
         {
             (*Mat).mat[i][j] *= *z;
         }
     }
}
void Mul_matrix(struct Matrix &Mat, double &z)
{
     for (int i = 0;i<3;i++)
     {
         for(int j = 0; j<3; j++)
         {
             Mat.mat[i][j] *= z;
         }
     }
}
