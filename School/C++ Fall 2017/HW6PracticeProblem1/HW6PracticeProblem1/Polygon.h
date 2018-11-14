#pragma once
#ifndef POLYGON_H
#define POLYGON_H
#include <vector>
#include "Point.h"

using namespace std;

class Polygon
{
public:
	/**
	Makes an empty polygon.
	*/
	Polygon();
	/**
	Adds a point to this polygon.
	*/
	void add(Point p);
	/**
	Gets the ith point from this polygon.
	*/
	Point get(int i) const;
	/**
	Gets the circumference of this polygon.
	*/
	double circumference() const;
private:
	vector<Point> points;
};

#endif