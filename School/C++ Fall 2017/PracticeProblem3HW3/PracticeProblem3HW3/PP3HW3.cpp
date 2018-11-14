#include <vector>
using namespace std;

/**
Swaps the second and second-to-last value of a.
For example, if a is {3, 1, 4, 1, 5, 9, 2, 6}
after calling this method it is {3, 2, 4, 1, 5, 9, 1, 6}.
If the array has length < 2, do nothing.
@param a a vector of integers
*/
void swap2(vector<int>& a)
{
	if (a.size() < 2)
	{
		return;
	}
	else
	{
		int value1 = a[1];
		int place = a.size() - 2;
		int value2 = a[place];
		int temp = value1;
		a[1] = value2;
		a[place] = temp;
	}
}