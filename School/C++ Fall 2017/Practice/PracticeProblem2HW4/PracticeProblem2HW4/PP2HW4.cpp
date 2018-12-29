/**
You are given two pointers into an array, which point TO the first
element and PAST the last element. Return a pointer to the
first element that is negative, or a null pointer if there is none.

Use pointers only, no array syntax
*/

#include <iostream>
using namespace std;

int* firstneg(int* begin, int* end)
{
	int* result;
	while (*begin != '\0')
	{
		result = 0;
		if (*begin < 0)
		{
			result = begin;
			break;
		}
		begin++;
	}
	return result;
}
