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
#include "Calculator.h"
#include <iostream>

/**
* Default constructor.
*/
Calculator::Calculator()
{
	math = "";
	pos = nullptr;
	result = 0;
	backcount = 0;
	parencount = 0;
	zero = false;
}
/**
* Constructor.
*/
Calculator::Calculator(string expression)
{
	math = expression;
	pos = &math[0];
	result = 0;
	backcount = 0;
	parencount = 0;
	zero = false;
}
/* Destructor.*/
Calculator::~Calculator() {}
/**
*changes the position of the pointer to the expression
**/
void Calculator::change_position()
{
	*pos++;
}
/**
*intakes an expression string the returns
* number in the form of a double
**/
double Calculator::number(string expn)
{
	string num = "";
	while (*pos >= '0' && *pos <= '9')
	{
		num = num + *pos; //finds full number
		change_position();
	}
	while (*pos == ')')
	{
		backcount++;
		change_position();
	}
	double number = stod(num); //changes number from string to double
	return number;
}
/**
*intakes an expression string the returns
* a sum or difference
**/
double Calculator::expression(string expn)
{
	
	while (*pos != '\0' && *pos != ')' )
	{
		if (*pos == '+')
		{
			
			change_position();	
			string n = pos;
			result = result + number(n);
		
		}
		if (*pos == '-')
		{
			change_position();
			string n = pos;
			result = result - number(n);
		}
	}
	while (*pos == ')')
	{
		backcount++;
		change_position();
	}
	return result;
}
/**
* calls the factor function for the
* input string while checking for errors
**/
void Calculator::runtest()
{
	double finalnum = factor(math);
	if (backcount > parencount)
	{
		cout << "***** Unexpected )" << endl;
		result = 0;
	}
	else if (parencount > backcount)
	{
		cout << "***** Unexpected (" << endl;
		result = 0;
	}
	else if (zero)
	{
		cout << "***** Divide by zero" << endl;
	}
	else
	{
		cout << "= " << finalnum << endl;
	}

}
/**
*intakes an expression string the returns
* a factor or a quotient
**/
double Calculator::term(string expn)
{
	while (*pos != '\0' && *pos != ')')
	{
		if (*pos == '*')
		{

			change_position();
			string n = pos;
			result = result * number(n);

		}
		if (*pos == '/')
		{
			change_position();
			string n = pos;
			double num = number(n);
			try {
				errortest(num);
			}
			catch (...)
			{
				zero = true;
			}
			result = result / num;
		}
	}
	while (*pos == ')')
	{
		backcount++;
		change_position();
	}
	if (*pos == '+' || *pos == '-')
	{
		expression(pos);
	}
	return result;
}
/**
*intakes an expression string the returns
* the final value
**/
double Calculator::factor(string expn)
{
	char* temp = nullptr;
	bool mult = false;
	bool sub = false;
	bool add = false;
	double resulttemp = 0;
	string tempexp = "";
	pos = &expn[0];
	if (*pos >= '0' && *pos <= '9')
	{
		resulttemp = number(pos);
		if (*pos == '\0') 
		{ 
			result = resulttemp;
			return result;
		}
		temp = pos;
		*temp++;
		if (*temp == '(')
		{
			parencount++;
			while (*pos == '(') //skips all (
			{
				parencount++;
				change_position();
			}
			if (*pos == '+') { add = true; }
			else if (*pos == '-') { sub = true; }
			else if (*pos == '*') { mult = true; }
			*pos++;
			*pos++;
			if (add)
			{
				result = factor(pos) + resulttemp;
			}
			else if (sub)
			{
				result = resulttemp - factor(pos);
			}
			else if (mult)
			{
				result = factor(pos) * resulttemp;
			}
			else
			{
				double num = factor(pos);
				try {
					errortest(num);
				}
				catch (...)
				{
					zero = true;
				}
				result = resulttemp / num;
			}	
			*pos++;
		}
		else if (*temp >= '0' && *temp <= '9')
		{
			result = resulttemp;
			if (*pos == '-' || *pos == '+')
			{
				expression(pos);
			}
			else if (*pos == '*' || *pos == '/')
			{
				term(pos);
			}
			if (*pos == '-' || *pos == '+')
			{
				expression(pos);
			}
			else if (*pos == '*' || *pos == '/')
			{
				term(pos);
			}
		}
	}
	else if (*pos == '(')
	{
		while (*pos == '(')
		{
			parencount++;
			change_position();
		}
		factor(pos);
	}
	return result;
}
/**
*checks for dividing by 0
**/
void Calculator::errortest(double n)
{
	if (n == 0)
	{
		throw n;
	}
}