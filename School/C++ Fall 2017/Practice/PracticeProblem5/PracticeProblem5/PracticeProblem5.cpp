
/*
Write a program that computes how many digits two positive
integers m and n have in common. For example, if m is 112358 and
n is 17981, then the result is 2 because the numbers have the digits
1 and 8 in common.
*/

#include <iostream>
using namespace std;

int main()
{
	cout << "m: " << endl;
	int m;
	cin >> m;
	cout << "n: " << endl;
	int n;
	cin >> n;
	int result = 0;
	int n1 = 0, n2 = 0, n3 = 0, n4 = 0, n5 = 0, n6 = 0, n7 = 0, n8 = 0, n9 = 0, n0 = 0;
	int numn, numm;
	int dm, dn;
	int d = m;

	while (n > 0)
	{
		numn = n % 10;
		while (d > 0)
		{
			numm = d % 10;
			if (numm == numn)
			{
				switch (numn)
				{
				case 1: n1 = 1; break;
				case 2: n2 = 1; break;
				case 3: n3 = 1; break;
				case 4: n4 = 1; break;
				case 5: n5 = 1; break;
				case 6: n6 = 1; break;
				case 7: n7 = 1; break;
				case 8: n8 = 1; break;
				case 9: n9 = 1; break;
				default: n0 = 1; break;
				}
			}
			dm = d / 10;
			d = dm;
		}
		d = m;
		dn = n / 10;
		n = dn;
	}
	result = n0 + n1 + n2 + n3 + n4 + n5 + n6 + n7 + n8 + n9;
	cout << "Count: " << result << endl;
	return 0;
}
