#include <iostream>

using namespace std;

#define expect(a, e) _expect(#a, a, e)

template <typename T, typename U> void _expect(const char* tag, const T& a, const U& e)
{
	cout << tag << ": " << a << endl;
	cout << "Expected: " << e << endl;
}

const char** starts(const char* p, int n);

int main()
{
	const char* p = "Mary\0had\0a\0little\0lamb\0";
	const char** r = starts(p, 5);
	expect(r[0] - p, 0);
	expect(r[1] - p, 5);
	expect(r[2] - p, 9);
	p = "Mary\0\0had\0a\0little\0lamb\0";
	r = starts(p, 6);
	expect(r[0] - p, 0);
	expect(r[1] - p, 5);
	expect(r[2] - p, 6);
	expect(r[5], "lamb");

	return 0;
}