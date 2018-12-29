#include <iostream>
#include <string>

using namespace std;

void first_last_vowel_position(string, int&, int&);

int main()
{
	int f = -2;
	int l = -2;
	first_last_vowel_position("meat", f, l);
	cout << f << " " << l << endl;
	cout << "Expected: 1 2" << endl;
	first_last_vowel_position("Expectation", f, l);
	cout << f << " " << l << endl;
	cout << "Expected: 0 9" << endl;
	first_last_vowel_position("Tom", f, l);
	cout << f << " " << l << endl;
	cout << "Expected: 1 1" << endl;
	first_last_vowel_position("Brrrh", f, l); 
	cout << f << " " << l << endl;
	cout << "Expected: -1 -1" << endl;
	return 0;
}

