#pragma once
#ifndef POINT_H
#define POINT_H

class Point
{
public:
	Point(double xvalue, double yvalue);
	double get_x();
	double get_y();
	/**
	Compute the distance between this point and another point.
	@param other the other point
	@return the distance between them.
	*/
	double distance(Point other) const;
private:
	double x;
	double y;
};


#endif