#include <iostream>
#include <iomanip>
#include <cmath>
#include "Polygon.h"

using namespace std;

int main()
{
	const double TOLERANCE = 1E-6;

	Polygon p;
	p.add(Point(10, 20));
	p.add(Point(20, 20));
	p.add(Point(20, 10));
	p.add(Point(10, 10));
	cout << p.get(1).get_y() << endl;
	cout << "Expected: 20" << endl;
	cout << p.get(2).get_y() << endl;
	cout << "Expected: 10" << endl;
	cout << p.circumference() << endl;
	cout << "Expected: 40" << endl;

	p = Polygon();
	for (int i = 0; i < 6; i++)
		p.add(Point(sin(i * 3.14159 / 3),
			cos(i * 3.14159 / 3)));
	cout << p.circumference() << endl;
	cout << "Expected: 6" << endl;

	p = Polygon();
	int n = 6000;
	for (int i = 0; i < n; i++)
		p.add(Point(sin(i * 2 * 3.14159 / n),
			cos(i * 2 * 3.14159 / n)));

	cout << boolalpha << (fabs(p.circumference() - 2 * 3.14159) < TOLERANCE) << endl;
	cout << "Expected: true" << endl;

	return 0;
}