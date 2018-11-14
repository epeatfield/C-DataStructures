#include <iostream>
using namespace std;
/*
Given a pointer p to the first element in a character array
containing n strings (each terminated by '\0'), return a
dynamically allocated array of the starting addresses of all n strings.
*/
const char** starts(const char* p, int n)
{
	int size = sizeof(p);
	int place = 0;
	const char** arr = new const char*[n];
	char* dash = "\0";
	arr[0] = p;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (*p == *dash)
			{
				place = *p;
				arr[i] = p + place + 1;
				*p++;
				break;
			}
			else *p++;
		}
	}
	return arr;
}