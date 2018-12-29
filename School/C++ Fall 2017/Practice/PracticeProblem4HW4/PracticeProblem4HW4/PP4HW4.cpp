#include <cstring>

using namespace std;

/**
Given a '\0'-terminated character array, split it by replacing
each space in the character array with a '\0'. Return the number
of strings into which you have split the input.

Use pointers. Don't use array syntax.
*/
int split(char* words)
{
	int count = 1;
	char* space = " ";
	while (*words != '\0')
	{
		if (*words == *space)
		{
			*words = '\0';
			count = count + 1;
		}
		*words++;
	}
	return count;
}