#pragma once
#include <string>
#include <fstream>
using namespace std;

/// Bapiant 2
struct Vector {
    double x;
    double y;
};

class Square
{
public:
    Square(double x, double y, double side, double angle);
    double operator ==(const Square & other) const;
    double operator !=(const Square & other) const;
    double operator >(const Square & other) const;
    double operator <(const Square & other) const;
    friend Square operator *=(Square &square, const double &num);
    friend Square operator +=(Square &square, const Vector &vector);
    friend std::ostream& operator <<(std::ostream&, const Square &square);

private:
    double x;
    double y;
    double angle;
    double side;
};

/// Bapiant 6
class Array {
private:
    int* array;
    int size;
public:
    Array();
    Array(int size);
    Array(Array const& prevArray);
    int getSize() const;
    int& operator [] (int idx);
    Array operator + (Array array2);
    bool operator == (const Array& array2) const;
    bool operator > (const Array& array2) const;
    bool operator < (const Array& array2) const;
    bool operator != (const Array& array2) const;
    operator string();
};

