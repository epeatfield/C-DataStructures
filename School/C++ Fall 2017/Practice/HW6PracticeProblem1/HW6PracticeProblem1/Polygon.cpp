#include <cmath>
#include "Polygon.h"

using namespace std;

Polygon::Polygon()
{

}

void Polygon::add(Point p)
{
	points.push_back(p);
}

Point Polygon::get(int i) const
{
	return points[i];
}

double Polygon::circumference() const
{
	double result = 0;
	int size = points.size();
	for (int i = 0; i < size; i++)
	{
		if ((i + 1) < size)
		{
			result = result + get(i).distance(points[i + 1]);
		}
		else
		{
			result = result + get(i).distance(points[0]);
		}
	}
	return result;
}
