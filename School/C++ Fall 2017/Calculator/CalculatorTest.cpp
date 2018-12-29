/**
* Assignment 10. Calculator
* Fall 2017
*
* Read in expressions from input. Compute the value of the
* expresssions and output the answer.
*
* Author: Emma Peatfield
*		  San Jose State University
*
*/
#include <iostream>
#include <string>
#include "Calculator.h"

using namespace std;


int main()
{
	cout << "Expression? " << endl;
	string expression;
	getline(cin, expression); //obtains expression from input
	do
	{
		Calculator ex(expression); //initializes the calculator
		ex.runtest(); //runs the test for evaluating the expression
		cout << endl;
		cout << "Expression? " << endl;
		getline(cin, expression);
	} while (expression != "."); //ends the loop if the user inputs '.'
	cout << "Done!" << endl;
	return 0;
}
	