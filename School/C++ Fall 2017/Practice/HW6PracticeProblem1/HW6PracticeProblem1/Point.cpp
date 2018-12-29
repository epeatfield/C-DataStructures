#include <cmath>
#include "Point.h"

using namespace std;

Point::Point(double xvalue, double yvalue)
{
	x = xvalue;
	y = yvalue;
}

double Point::get_x() { return x; }
double Point::get_y() { return y; }

double Point::distance(Point other) const
{
	double dx = x - other.x;
	double dy = y - other.y;
	return sqrt(dx * dx + dy * dy);
}