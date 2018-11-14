/*
Write a program that computes how many times the most frequently
occurring digit occurs in a positive integer n. For example,
if n = 31332224, then the result is 3.
*/

#include <iostream>
using namespace std;

int main()
{
	cout << "n: " << endl;
	int n;
	cin >> n;
	int result = 0;
	int num;
	int maxnum = 0;
	int m = 0, n1 = 0, n2 = 0, n3 = 0, n4 = 0, n5 = 0, n6 = 0, n7 = 0, n8 = 0, n9 = 0, n0 = 0;
	while (n>0)
	{
		num = n % 10;
		switch (num)
		{
		case 1: n1 = n1 + 1; break;
		case 2: n2 = n2 + 1; break;
		case 3: n3 = n3 + 1; break;
		case 4: n4 = n4 + 1; break;
		case 5: n5 = n5 + 1; break;
		case 6: n6 = n6 + 1; break;
		case 7: n7 = n7 + 1; break;
		case 8: n8 = n8 + 1; break;
		case 9: n9 = n9 + 1; break;
		default: n0 = n0 + 1; break;
		}
		m = n / 10;
		n = m;
	}
	if (n1 >= n0)
	{
		maxnum = n1;
	}
	else
	{
		maxnum = n0;
	}
	if (n2 >= maxnum)
	{
		maxnum = n2;
	}
	if (n3 >= maxnum)
	{
		maxnum = n3;
	}
	if (n4 >= maxnum)
	{
		maxnum = n4;
	}
	if (n5 >= maxnum)
	{
		maxnum = n5;
	}
	if (n6 >= maxnum)
	{
		maxnum = n6;
	}
	if (n7 >= maxnum)
	{
		maxnum = n7;
	}
	if (n8 >= maxnum)
	{
		maxnum = n8;
	}
	if (n9 >= maxnum)
	{
		maxnum = n9;
	}
	result = maxnum;
		cout << "Count: " << result << endl;
	return 0;
}