#include <iostream>
#include <string>

using namespace std;

void swap_first_last_vowel(string&);

int main()
{
	string s = "Hello";
	swap_first_last_vowel(s);
	cout << s << endl;
	cout << "Expected: Holle" << endl;
	s = "Goodbye";
	swap_first_last_vowel(s);
	cout << s << endl;
	cout << "Expected: Geodbyo" << endl;
	s = "Tom";
	swap_first_last_vowel(s);
	cout << s << endl;
	cout << "Expected: Tom" << endl;
	s = "Bzzzt";
	cout << s << endl;
	cout << "Expected: Bzzzt" << endl;
	return 0;
}