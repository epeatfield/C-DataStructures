
/*
Write a program that computes how many times a given number m occurs
in a positive integer n. For example, if n = 31314 and m is 31, then
the result is 2.

You may assume that m has no leading zeroes.

Now you will want to take the modulus with respect to a power of
10. In our case, that's 100. If m was a three-digit number, it would
be 1000. Use a loop to compute this power.
*/

#include <iostream>
using namespace std;

int main()
{
	cout << "n: " << endl;
	int n;
	cin >> n;
	cout << "d: " << endl;
	int d;
	cin >> d;
	int result = 0;
	int mod = 10;
	int num, test;
	int m = 0;
	test = d / mod;
	while (test > 0)
	{
		mod = mod * 10;
		test = d / mod;
	}
	while (n>0)
	{
		num = n % mod;
		if (num == d)
		{
			result = result + 1;
		}
		m = n / 10;
		n = m;
	}
		cout << "Count: " << result << endl;
	return 0;
}
