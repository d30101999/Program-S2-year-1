#pragma once
#include <iostream>
using namespace std;

class CPoint {
private:
	int x;
	int y;
public:
	CPoint(int x, int y) : x(x), y(y) {};
	friend int operator%(const CPoint& d1, const int& d2);
	friend std::ostream& operator<< (std::ostream& out, const CPoint& point);
	friend bool operator== (const CPoint& p1, const CPoint& p2);
};
