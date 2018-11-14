#include <string>

using namespace std;
/**
Turn a string of the form firstname lastname or
firstname middlename(s) lastname into lastname, firstname
(and middlenames if present).
For example, normalize_name("John Pierpont Flathead") should return
"Flathead, John Pierpont". If the string contains no spaces, return
it unchanged. Also, if the string already contains a comma, return
it unchanged.
Hint: If s is a string, then s.length() is the number of characters
in the string and s.substr(i, n) is the substring
starting at index i of length n. And if s and t are two strings,
then s + t is the concatenation of the two strings. You will want
to return a string of the form
s.substr(i1, n1) + ", " + s.substr(i2, n2)
except if s contains no spaces.
To find a space at position i, you can test whether s.substr(i, 1) == " ".
*/


#include <iostream>
#include <string>

using namespace std;

string normalize_name(string s);

int main()
{
	string name;
	string answer;
	name = "John Jacob Jingleheimer Schmidt";
	answer = normalize_name(name);
	cout << answer << endl;
}


string normalize_name(string s)
{
	int space = 0;
	int n = s.length();
	int n1 = 0; //length of first name
	int n2 = 0; //length of last name
	int n3 = 0; 
	int n4 = 0;
	int i2 = 0; //index beginning of last name
	int i3 = 0;
	int i4 = 0;

	for (int j = 0; j < n; j++)
	{
		if (s.substr(j, 1) == ",") return s;
	}
	for (int i = 0; i < n; i++)
	{
		if (s.substr(i, 1) == " ")
		{
			space = space + 1;
		}
	} 
	if (space == 0)
	{
		return s;
	}
	else if (space == 1)
	{
		for (int k = 0; k < n; k++)
		{
			if (s.substr(k, 1) == " ") break;
			else n1 = n1 + 1;
		}
		for (int h = n1; h < n; h++)
		{
			n2 = n2 + 1;
		}
		i2 = n1 + 1; 
		return (s.substr(i2, n2) + ", " + s.substr(0, n1));
	}
	else if (space == 2)
	{
		for (int m = 0; m < n; m++)
		{
			if (s.substr(m, 1) == " ") break;
			else n1 = n1 + 1;
		}
		for (int p = (n1 + 1); p < n; p++)
		{
			if (s.substr(p, 1) == " ") break;
			n3 = n3 + 1;
		}
		for (int l = (n2 + 1); l < n; l++)
		{
			n2 = n2 + 1;
		}
		i3 = n1 + 1;
		i2 = n3 + i3 + 1;
		return (s.substr(i2, n2) + ", " + s.substr(0, n1) + " " + s.substr(i3, n3));
	}
	else
	{
		for (int m = 0; m < n; m++)
		{
			if (s.substr(m, 1) == " ") break;
			else n1 = n1 + 1;
		}
		for (int p = (n1 + 1); p < n; p++)
		{
			if (s.substr(p, 1) == " ") break;
			n3 = n3 + 1;
		}
		for (int q = (n3+ n1 + 2); q < n; q++)
		{
			if (s.substr(q, 1) == " ") break;
			n4 = n4 + 1;
		}
		for (int l = (n2 + 1); l < n; l++)
		{
			n2 = n2 + 1;
		}
		i3 = n1 + 1;
		i4 = i3 + n3 + 1;
		i2 = n4 + i4 + 1;
		cout << i4 << ", " << n4 << endl;
		return (s.substr(i2, n2) + ", " + s.substr(0, n1) + " " + s.substr(i3, n3) + " " + s.substr(i4, n4));
	}
	
}