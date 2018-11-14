#include <string>
#include <iostream>
using namespace std;


/**
Given a letter grade (A, B, C, D, F) possibly with a suffix (+ or -)
produce the numerical value of the grade. An A is a 4, B a 3,
C a 2, D a 1, and F a zero. The suffix + adds 0.3, the suffix
- subtracts 0.3. However, an A+ has value 4. Invalid grades have
a value of -1. (This includes F+ and F-, as well as any other malformed
grades.)
*/

double gradeValue(string grade);

int main()
{
	string letter;
	double finalgpa = 0;
	cout << "Enter grade: ";
	cin >> letter;
	finalgpa = gradeValue(letter);
	cout << "Final GPA: " << finalgpa << endl;
	return 0;
}
double gradeValue(string grade)
{
	double gpa = 0;
	int n = grade.length();
	if (grade == "") gpa = -1;
	if (grade.substr(0, 1) == "A")
	{
		gpa = 4.0;
		if (grade.substr(1, 1) == "+") gpa = gpa + 0.3;
		else if (grade.substr(1, 1) == "-") gpa = gpa - 0.3;
		else if (grade.substr(1, 1) == "") gpa = 4.0;
		else gpa = -1;
	}
	else if (grade.substr(0, 1) == "B")
	{
		gpa = 3.0;
		if (grade.substr(1, 1) == "+") gpa = gpa + 0.3;
		else if (grade.substr(1, 1) == "-") gpa = gpa - 0.3;
		else if (grade.substr(1, 1) == "") gpa = 3.0;
		else gpa = -1;
	}
	else if (grade.substr(0, 1) == "C")
	{
		gpa = 2.0;
		if (grade.substr(1, 1) == "+") gpa = gpa + 0.3;
		else if (grade.substr(1, 1) == "-") gpa = gpa - 0.3;
		else if (grade.substr(1, 1) == "") gpa = 2.0;
		else gpa = -1;
	}
	else if (grade.substr(0, 1) == "D")
	{
		gpa = 1.0;
		if (grade.substr(1, 1) == "+") gpa = gpa + 0.3;
		else if (grade.substr(1, 1) == "-") gpa = gpa - 0.3;
		else if (grade.substr(1, 1) == "") gpa = 1.0;
		else gpa = -1;
	}
	else if (grade.substr(0, 1) == "F")
	{
		gpa = 0;
		if (grade.substr(1, 1) == "+") gpa = -1;
		else if (grade.substr(1, 1) == "-") gpa = -1;
		else if (grade.substr(1, 1) == "") gpa = 0;
		else gpa = -1;
	}
	else
	{
		gpa = -1;
	}
	return gpa;
}
