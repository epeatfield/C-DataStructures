#include <string>
#include <iostream>
#include <cctype>

using namespace std;

string mix(string a, string b);

int main()
{
	string str1 = "goodbye";
	string str2 = "World";
	string strcombo(str1 + str2);
	strcombo = mix(str1, str2);
	cout << "Here is the mix: " << strcombo << endl;
	return 0;
}
/**
Return a string that mixes the characters in strings a and b.
If one string is longer than the other, append the suffix.
For example, mixing "San" and "Francisco" yields "SFarnancisco".
*/
string mix(string a, string b)
{
	int lengtha = a.length();
	int lengthb = b.length();
	int shortest = 0;
	string combo;
	if (lengtha < lengthb)
	{
		shortest = lengtha;
		combo = (a + b);
		for (int i = 0; i < shortest; i++)
		{
			combo[2 * i] = a[i];
			combo[2 * i + 1] = b[i];
		}
	}
	else
	{
		shortest = lengthb;
		combo = (b + a);
		for (int i = 0; i < shortest; i++)
		{
			combo[2 * i] = a[i];
			combo[2 * i + 1] = b[i];
		}
	}
	
	return combo;
}
