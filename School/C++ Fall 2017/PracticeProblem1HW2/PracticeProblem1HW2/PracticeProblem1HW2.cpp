#include <iostream>
using namespace std;

int largest(int a, int b, int c, int d);
int smallest(int a, int b, int c, int d);
double middle(int a, int b, int c, int d);

int main()
{
	double average = 0;
	int e, f, g, h;
	cout << "Please enter 4 numbers: ";
	cin >> e >> f >> g >> h;
	average = middle(e, f, g, h); 
	cout << "The average number is: " << average << endl;
	return 0;
}

int largest(int a, int b, int c, int d)
{
	int result = a;
	if (b > result) result = b;
	if (c > result) result = c;
	if (d > result) result = d;
	return result;
}

int smallest(int a, int b, int c, int d)
{
	int smallnum = a;
	if (b < smallnum) smallnum = b;
	if (c < smallnum) smallnum = c;
	if (d < smallnum) smallnum = d;
	return smallnum;
}

double middle(int a, int b, int c, int d)
{
	int mida, midb, midc, midd;
	double avg = 0;
	int large = largest(a, b, c, d);
	int small = smallest(a, b, c, d);
	if (a != large && a != small) mida = a;
	else mida = 0;
	if (b != large && b != small) midb = b;
	else midb = 0;
	if (c != large && c != small) midc = c;
	else midc = 0;
	if (d != large && d != small) midd = d;
	else midd = 0;
	double mid = mida + midb + midc + midd;
	avg = mid / 2;
	return avg;
}