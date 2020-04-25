#include "Cpoint.h"

bool operator== (const CPoint& p1, const CPoint& p2)
{
	return p1.x == p2.x && p1.y == p2.y;
}

ostream& operator<< (ostream& out, const CPoint& point)
{
	out << "Point(" << point.x << ", " << point.y << ")";

	return out;
}

int operator%(const CPoint& d1, const int& d2)
{
	return d1.x % d2 + d1.y % d2 == 0;
};
