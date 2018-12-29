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
Swaps the first and last vowel in the string s.
For example, if s is "Farewell", it is changed to "Ferewall".
*/
void swap_first_last_vowel(string& s)
{
	int n = s.length();
	string first;
	string last; 
	string letter;
	int firstpos = -1;
	int lastpos = -1;
	for (int i = 0; i < n; i++)
	{
		letter = s.substr(i, 1);
		if (is_vowel(letter))
		{
			first = letter;
			firstpos = i;
			break;
		}
	}
	for (int k = (n - 1); k >= firstpos; k--)
	{
		letter = s.substr(k, 1);
		if (is_vowel(letter))
		{
			last = letter;
			lastpos = k;
			s.substr(lastpos, n) = first;
			s.substr(firstpos, n) = last;
			break;
		}
		else
		{
			last = first;
			lastpos = firstpos;
		}
	}
}
