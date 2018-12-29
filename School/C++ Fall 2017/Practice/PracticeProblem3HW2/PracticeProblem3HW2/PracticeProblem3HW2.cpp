#include <string>
#include <iostream>

using namespace std;

/**
Returns true if c is a vowel.
*/
bool is_vowel(string c)
{
	return c == "a" || c == "e" || c == "i" || c == "o" || c == "u"
		|| c == "A" || c == "E" || c == "I" || c == "O" || c == "U";
}

/**
Sets first to the index of the first vowel in the string s
and last to the index of the last vowel in s. If s has no vowels,
first and last are set to -1.
*/


void first_last_vowel_position(string s, int& first, int& last)
{
	int n = s.length();
	string letter;
	for (int i = 0; i < n; i++)
	{
		letter = s.substr(i, 1);
		if (is_vowel(letter))
		{
			first = i;
			break;
		}
		else first = -1;
	}
	for (int k = (n - 1); k > first; k--)
	{
		letter = s.substr(k, 1);
		if (is_vowel(letter))
		{
			last = k;
			break;
		}
		else last = first;
	}
}
