#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

void cube_root(float& x, float a);
float find_pi();

int main()
{
	float finalpi = find_pi();
	cout << "The final pi for the number of iterations is: " << finalpi << endl;
	return 0;
}

void cube_root(float& x, float a) //Newtons
{
	float xn = 0;
	float xn1 = 0;
	float rem = (2 * a) / 3;
	while (rem > (a/3))
	{
		rem = rem / 3;
	}
	xn = rem;
	float y = abs(a - (xn*xn*xn));
	while (y > 0.0001)
	{
		xn1 = ((a / (xn*xn)) + 2 * xn)/3;
		xn = xn1;
		y = abs(a - (xn*xn*xn));
	} 
	x = xn;
}
float find_pi()
{
	float a0 = 1.0 / 3.0;
	float r0 = (sqrt(3) - 1) / 2;
	float sx = (1 - (r0*r0*r0));
	float s0;
	cube_root(s0, sx);
	float tn, wn, vn, an, un, sn, rn, rnx, unx, pin;
	for (int n = 1; n < 3; n++)
	{
		tn = 1 + 2 * r0;
		unx = 9 * r0*(1 + r0 + (r0*r0));
		cube_root(un, unx);
		vn = (tn*tn) + tn*un + (un*un);
		wn = 27 * ((1 + s0 + s0*s0) / vn);
		an = wn*a0 + pow(3, (2 * n - 3))*(1 - wn);
		pin = 1 / an;
		sn = ((1 - r0)*(1 - r0)*(1 - r0)) / (vn*(tn + 2 * un));
		rnx = (1 - sn*sn*sn);
		cube_root(rn, rnx);
		a0 = an;
		s0 = sn; 
		r0 = rn;
	}
	return pin;
}