#include <iostream>

using namespace std;

double oddavg(int a[], int alen);

int main()
{

	return 0;
}


/**
Computes the average of all odd elements in the given array.
@param a an array of integers
@param alen the number of elements in a
@return the average of all odd elements in a, or 0 if there are none.
*/
double oddavg(int a[], int alen)
{
	double sum = 0;
	int count = 0;
	double avg = 0;
	if (alen == 0)
	{
		avg = 0;
	}
	else
	{
		for (int i = 0; i < alen; i++)
		{
			int quotient = a[i] % 2;
			if (quotient != 0)
			{
				sum = sum + a[i];
				count = count + 1;
			}
		}
		if (count == 0) avg = 0;
		else avg = sum / count;
	}
	return avg;
}