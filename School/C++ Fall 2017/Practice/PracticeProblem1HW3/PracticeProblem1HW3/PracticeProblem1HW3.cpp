/**
This program reads in the name of a file from stdin.
Then it opens the file and reads all lines of the file.
Each line has the form

label     value

The label is a nonempty string without spaces. The value
is a floating-point number.

Print out the label with the smallest and largest value,
in a left-justified, field of width 50, followed by the value
in a right-justified field of width 12, with two digits after
the decimal point.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
	float min = 100;
	string minlabel;
	float max = 0;
	string maxlabel;
	string input_file = "Text.txt";
	ifstream in(input_file);
	if (in.fail())
	{
		cout << "Input file opening failed. \n";
		exit(1);
	}
	string label;
	float value;
	while (!in.eof())
	{
		in >> label >> value;
		if (value < min)
		{
			min = value;
			minlabel = label;
		}
		if (value > max)
		{
			max = value;
			maxlabel = label;
		}
	}
	in.close();
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout.width(50);
	cout << minlabel;
	cout.width(12);
	cout << min << endl;
	cout.width(50);
	cout << maxlabel;
	cout.width(12);
	cout << max << endl;
	
	return 0;
}
