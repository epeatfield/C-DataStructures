/*
Write a program that displays the longest subsequence of consecutive
repeating digits in a positive integer n. For example,
if n = 31332224, then the result is 222. If there are multiple
such sequences of equal maximum length, print the leftmost one.
*/

#include <iostream>
using namespace std;

int main()
{
	cout << "n: " << endl;
	int n;
	cin >> n;

	int numf; 
	int num0 = 0;
	int m = 0;
	int maxcount = 0;
	int repeatingnum = 0;
	int result;
	int maxnum = 0;
	int count = 1;
	
	while (n > 0)
	{
		numf = n % 10;
		m = n / 10;
		n = m;
		if (numf == num0)
		{
			repeatingnum = numf;
			count = count + 1;
			if (count >= maxcount)
			{
				maxcount = count;
				maxnum = repeatingnum;
			}
		}
		else
		{
			count = 1;
			repeatingnum = 0;
		}
		num0 = numf;
	}
	if (maxcount == 0)
	{
		cout << "Longest: " << numf << endl;
	}
	else
	{
		result = maxnum;
		cout << "Longest: ";
		for (int i = 0; i < maxcount; i++)
		{
			cout << result;
		}
	}
	cout << endl;
	return 0;
}
