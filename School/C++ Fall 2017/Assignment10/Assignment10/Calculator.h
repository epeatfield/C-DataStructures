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
#pragma once
#ifndef CALCULATOR_H_
#define CALCULATOR_H_
 
#include <string>
using namespace std; 

class Calculator
{
public:
	/**
	* Default constructor.
	*/
	Calculator();

	/*Constructor*/
	Calculator(string expression);

	/* Destructor.*/
	~Calculator();
	 /** 
	 *intakes an expression string the returns
	 * a sum or difference
	 **/
	double expression(string expn);
	/**
	*intakes an expression string the returns
	* number in the form of a double
	**/
	double number(string expn);
	/**
	*intakes an expression string the returns
	* a factor or a quotient
	**/
	double term(string expn);
	/**
	*intakes an expression string the returns
	* the final value 
	**/
	double factor(string expn);
	/**
	* calls the factor function for the 
	* input string
	**/
	void runtest();
	/**
	*changes the position of the pointer to the expression
	**/
	void change_position();
	/**
	*checks for errors like dividing by 0
	**/
	void errortest(double n);
private:
	string math; 
	char* pos;
	double result; 
	int parencount; //count of (
	int backcount; //count of )
	bool zero; //flag for 0
};

#endif /* CALCULATOR_H_ */