#include <iostream>

using namespace std;

void print_array(int a[], int n)
{
	if (n == 0) { cout << "{}" << endl; return; }
	cout << "{ ";
	for (int i = 0; i < n; i++)
	{
		if (i > 0) cout << ", ";
		cout << a[i];
	}
	cout << " }" << endl;
}

void flneg(int a[], int size, int* first, int* last);

int main()
{
	int a[] = { 1, 4, -9, 16, -25, -36, 49, -64, 81, 100, -121 };
	int f = -2;
	int l = -2;
	flneg(a, 11, &f, &l);
	cout << f << " " << l << endl;
	cout << "Expected: 2 10" << endl;
	f = -2;
	l = -2;
	flneg(a + 1, 3, &f, &l);
	cout << f << " " << l << endl;
	cout << "Expected: 1 1" << endl;
	flneg(a, 2, &f, &l);
	cout << f << " " << l << endl;
	cout << "Expected: -1 -1" << endl;
	return 0;
}