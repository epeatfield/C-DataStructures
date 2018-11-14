#include <iostream>
#include <cstring>

using namespace std;

int split(char* words);

int main()
{
	char words[] = "Hello Goodbye Bonjour Arrivederci";
	int n = split(words);
	cout << n << endl;
	cout << "Expected: " << 4 << endl;
	cout << words << endl;
	cout << "Expected: " << "Hello" << endl;
	cout << words + 6 << endl;
	cout << "Expected: " << "Goodbye" << endl;
	cout << words + 14 << endl;
	cout << "Expected: " << "Bonjour" << endl;
	cout << words + 22 << endl;
	cout << "Expected: " << "Arrivederci" << endl;

	char morewords[] = "Hello  Goodbye"; // Note two spaces
	n = split(morewords);
	cout << n << endl;
	cout << "Expected: " << 3 << endl;
	cout << morewords << endl;
	cout << "Expected: " << "Hello" << endl;
	cout << strlen(morewords + 6) << endl;
	cout << "Expected: " << 0 << endl;
	cout << morewords + 7 << endl;
	cout << "Expected: " << "Goodbye" << endl;

	return 0;
}