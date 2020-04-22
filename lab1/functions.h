#ifndef FUNCTIONS_H
#define FUNCTIONS_H


void dis_frac_pt(double *x);
void dis_frac(double &x);


void change_sign_pt(float *c,int *d);
void change_sign(float &c,int &d);


struct point {
    int x;
    int y;
};
struct Vector {
    int x;
    int y;
};
struct Circle
{
    point point1;
    float radius ;

};
void MoveCircle_pt(struct Circle *cir, struct Vector *vec);

void MoveCircle(struct Circle &cir, struct Vector &vec);


struct Matrix
{
    double mat[3][3];
};
void Mul_matrix_pt(struct Matrix *Mat, double *z);
void Mul_matrix(struct Matrix &Mat, double &z);

#endif // FUNCTIONS_H
