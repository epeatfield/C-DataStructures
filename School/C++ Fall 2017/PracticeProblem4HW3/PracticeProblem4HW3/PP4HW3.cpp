#include <iostream>
#include <vector>
using namespace std;

void neighbordiff(double a[], int n);

void print(double v[], int size)
{
	cout << "{";
	for (int i = 0; i < size; i++)
	{
		cout << v[i];
		if (i < size - 1) cout << ", ";
	}
	cout << "}" << endl;
}

int main()
{
	double values[] = { 3, 1, 4, 1, 5, 9, 2, 6 };
	neighbordiff(values, sizeof(values) / sizeof(values[0]));
	print(values, sizeof(values) / sizeof(values[0]));
	cout << "Expected: {3, -1, 0, -1, -8, 3, 3, 6}" << endl;

	double values2[] = { 1, -2, 3, -4, 5, -6 };
	neighbordiff(values2, sizeof(values2) / sizeof(values2[0]));
	print(values2, sizeof(values2) / sizeof(values2[0]));
	cout << "Expected: {1, -2, 2, -2, 2, -6}" << endl;

	double values3[] = { 1, 2 };
	neighbordiff(values3, sizeof(values3) / sizeof(values3[0]));
	print(values3, sizeof(values3) / sizeof(values3[0]));
	cout << "Expected: {1, 2}" << endl;

	double values4[] = { 1 };
	neighbordiff(values4, sizeof(values4) / sizeof(values4[0]));
	print(values4, sizeof(values4) / sizeof(values4[0]));
	cout << "Expected: {1}" << endl;

	//double values5[] = {};
	//neighbordiff(values5, sizeof(values5) / sizeof(values5[0]));
	//print(values5, sizeof(values5) / sizeof(values5[0]));
	//cout << "Expected: {}" << endl;

	return 0;
}
/**
Replaces each element in an array with the difference of its
neighbors. The first and last element are not changed. Do
not declare any arrays or vectors.
@param a an array
@param n the length of the array
*/
void neighbordiff(double a[], int n)
{
	double difference = 0;
	double temp2 = a[0];
	for (int i = 1; i < (n - 1); i++)
	{
		double temp = a[i];	
		difference = temp2 - a[i + 1];
		a[i] = difference;
		temp2 = temp;
	}
}