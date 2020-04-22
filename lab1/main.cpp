#include <iostream>
#incude <cmath>
#include "functions.h"

using namespace std;

int main()
{
    double a , a1;
    cin >> a;
    dis_frac_pt(&a);
    cout << a << endl;
    cin >> a1;
    dis_frac(a1);
    cout << a1 <<endl;

    float b , b1;
    int c , c1;
    cin >> b >> c ;
    change_sign_pt(&b,&c);
    cout << b << " " << c << endl;
    cin >> b1 >> c1;
    change_sign(b1,c1);
    cout << b1 << " " << c1 << endl;


    struct Circle cir;
    struct Vector vec;
    cout << "Enter the points in a sequence of x and y:" << endl ;
    cin >> cir.point1.x >> cir.point1.y  ;
    cout << "The radius = " << endl ;
    cin >> cir.radius ;
    cout << "Enter the x and y values of the vector to move the circle by:" << endl;
    cin >> vec.x >> vec.y;
    MoveCircle_pt(&cir, &vec);
    cout << "The new coordinates of the circle are:" << endl;
    cout << "Point1: (" << cir.point1.x << ", " << cir.point1.y << "). and radius = "<< cir.radius << endl;


    struct Circle cir1;
    struct Vector vec1;
    cout << "Enter the points in a sequence of x and y:"<< endl ;
    cin >> cir1.point1.x >> cir1.point1.y  ;
    cout << "The radius = " << endl ;
    cin >> cir1.radius ;
    cout << "Enter the x and y values of the vector to move the circle1 by:";
    cin >> vec1.x >> vec1.y;
    MoveCircle(cir1, vec1);
    cout << "The new coordinates of the square1 are:" << endl;
    cout << "Point1: (" << cir1.point1.x << ", " << cir1.point1.y << "). and radius = "<< cir1.radius << endl;




    struct Matrix Mat;
    double z;
    cout << "Put in matrix" << endl;
    for (int i = 0;i <3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            cin >> Mat.mat[i][j];
        }
    }
    cout << "put in number = " << endl;
    cin >> z;
    Mul_matrix_pt(&Mat, &z);
    for (int i = 0;i<3;i++)
    {
        for(int j = 0; j<3; j++)
        {
            cout << Mat.mat[i][j] << " ";
        }
    }
    cout << endl;

    struct Matrix Mat1;
    double z1;
    cout << "Put in matrix" << endl;
    for (int i = 0;i<3;i++)
    {
        for(int j = 0; j<3; j++)
        {
            cin >> Mat1.mat[i][j];
        }
    }
    cout << "put in number = " << endl;
    cin >> z1;
    Mul_matrix(Mat1, z1);
    for (int i = 0;i<3;i++)
    {
        for(int j = 0; j<3; j++)
        {
            cout << Mat1.mat[i][j] << " ";
        }
    }
    return 0;
}
