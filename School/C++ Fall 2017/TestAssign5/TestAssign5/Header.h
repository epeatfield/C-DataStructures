#pragma once
#ifndef ROMANNUMERAL_H_
#define ROMANNUMERAL_H_

using namespace std;

class RomanNumeral
{
public:
	RomanNumeral(); /*Default Constructor*/
	RomanNumeral(int d); /*Calls the function to_roman to get the roman numeral*/
	RomanNumeral(string r); /*Calls the function to_decimal to get the interger*/
	void print() const;
	friend int operator -(const RomanNumeral& num1, const RomanNumeral& num2); /*Overloads the - operator*/
	friend int operator +(const RomanNumeral& n1, const RomanNumeral& n2); /*Overloads the + Operator*/
	friend int operator *(const RomanNumeral& pl1, const RomanNumeral& pl2); /*Overloads the * Operator*/
	friend int operator /(const RomanNumeral& p1, const RomanNumeral& p2); /*Overloads the / operator*/
	friend bool operator ==(const RomanNumeral& b1, const RomanNumeral& b2); /*Overloads the == operator*/
	friend bool operator !=(const RomanNumeral& nb1, const RomanNumeral& nb2); /*Overloads the != operator*/
	friend ostream& operator <<(ostream& outs, const RomanNumeral& num); /*Overloads <<*/
	friend istream& operator >>(istream& ins, RomanNumeral& in1); /*Overloads >>*/
private:
	string roman; //Roman Numeral stored in string
	int decimal; //Integer value of same Roman Numeral
	void to_roman(int s); /*Converts integer s into a string d of the values Roman Numeral*/
	void to_decimal(string d); /*Converts string d into the corresponding value of that Roman Numeral*/
};

 /*Default Constructor*/
RomanNumeral::RomanNumeral() : roman(""), decimal(0)
{
}
/* Constructor that takes in a string input and converts it to it's integer value*/
RomanNumeral::RomanNumeral(string r) : roman(r)
{
	to_decimal(roman);
} 
/*Constructor that takes in an integer input and converts it into a Roman Numeral of the same value*/
RomanNumeral::RomanNumeral(int d) : decimal(d)
{
	to_roman(decimal);
} 
/*Returns a formatted value each time << is used */
ostream& operator <<(ostream& outs, const RomanNumeral& num) 
{
	outs << "[" << num.decimal << ":" << num.roman << "] ";
	return outs;
}
/*Inputs the string into the RomanNumeral class and places it through the functions*/
istream& operator >>(istream& ins, RomanNumeral& in1) 
{
	string n1;
	ins >> n1;
	in1 = n1;
	return ins;
}
/*Overloads the - operator so that one does not have to call other functions when r1 - r2 occurs*/
int operator -(const RomanNumeral& num1, const RomanNumeral& num2)
{
	return abs(num1.decimal - num2.decimal);
}
/*Overloads the + operator so that one does not have to call other functions when r1 + r2 occurs*/
int operator +(const RomanNumeral& n1, const RomanNumeral& n2)
{
	return (n1.decimal + n2.decimal);
}
/*Overloads the * operator so that one does not have to call other functions when r1 * r2 occurs*/
int operator *(const RomanNumeral& pl1, const RomanNumeral& pl2)
{
	return (pl1.decimal * pl2.decimal);
}
/*Overloads the / operator so that one does not have to call other functions when r1 / r2 occurs*/
int operator /(const RomanNumeral& p1, const RomanNumeral& p2)
{
	return (p1.decimal / p2.decimal);
}
/*Overloads the == operator so that one does not have to call other functions when r1 == r2 occurs*/
bool operator ==(const RomanNumeral& b1, const RomanNumeral& b2)
{
	return(b1.decimal == b2.decimal);
}
/*Overloads the != operator so that one does not have to call other functions when r1 != r2 occurs*/
bool operator !=(const RomanNumeral& nb1, const RomanNumeral& nb2)
{
	return(nb1.decimal != nb2.decimal);
}
/*Prints the answer in a formatted way*/
void RomanNumeral::print() const
{
	cout << "[" << decimal << ":" << roman << "] ";
}
/*Takes an integer and assigns it a Roman Numeral of the same value*/
void RomanNumeral::to_roman(int s)
{
	string m = "M";
	int temp = s;
	string temp1;
	int thousands = temp / 1000; /*Checks for any factors of 1000*/
	if (thousands != 0)
	{
		for (int i = 0; i < thousands; i++)
			temp1 = temp1 + m; //Adds and M for each factor of 1000
	}
	temp = temp % 1000;
	if (temp / 100 == 9)
	{
		temp1 = temp1 + "CM"; //Adds a CM for each factor of 900
		temp = temp % 900;
	}
	else if (temp / 100 == 4)
	{
		temp1 = temp1 + "CD"; //Adds a CD for each factor of 400
		temp = temp % 400;
	}
	else
	{
		string d5 = "D";
		int fivehund = temp / 500; /*Checks for any factors of 500*/
		if (fivehund != 0)
		{
			for (int i = 0; i < fivehund; i++)
				temp1 = temp1 + d5; //Adds a D for any factors of 500
		}
		temp = temp % 500;
	}
	string c = "C";
	int hundreds = temp / 100; /*Checks for any factors of 100*/
	if (hundreds != 0)
	{
		for (int i = 0; i < hundreds; i++)
			temp1 = temp1 + c; //Adds a C for any factors of 100
	}
	temp = temp % 100;
	if (temp / 10 == 9)
	{
		temp1 = temp1 + "XC"; //Adds an XC for any factors of 90
		temp = temp % 90;
	}
	else if (temp / 10 == 4)
	{
		temp1 = temp1 + "XL"; //Adds an XL for any factors of 40
		temp = temp % 40;
	}
	else
	{
		string l = "L";
		int fifties = temp / 50; /*Checks for any factors of 50*/
		if (fifties != 0)
		{
			for (int i = 0; i < fifties; i++)
				temp1 = temp1 + l; //Adds an L for any factors of 50
		}
		temp = temp % 50;
	}
	string x = "X";
	int tens = temp / 10; /*Checks for any factors of 10*/
	if (tens != 0)
	{
		for (int i = 0; i < tens; i++)
			temp1 = temp1 + x; //Adds an X for any factors of 10
	}
	temp = temp % 10;
	if (temp == 9)
	{
		temp1 = temp1 + "IX"; //Adds an IX for any factors of 9
	}
	else if (temp == 4)
	{
		temp1 = temp1 + "IV"; //Adds and IV for any factors of 4
	}
	else
	{
		string v = "V"; 
		int fives = temp / 5; /*Checks for any factors of 5*/
		if (fives != 0)
		{
			for (int i = 0; i < fives; i++)
				temp1 = temp1 + v; //Adds a V for any factors of 5
		}
		string ones = "I";
		int onespl = temp % 5;
		if (temp == 4)
		{
			temp1 = temp1 + "IV"; //Adds an IV for any factors of 4
		}
		else
		{
			if (onespl != 0)
			{
				for (int i = 0; i < onespl; i++)
					temp1 = temp1 + ones; //Add Is for remaining numbers
			}
		}
	}
	roman = temp1;
}
/*Takes a string and calculates its value and returns it as an integer*/
void RomanNumeral::to_decimal(string d)
{
	int ans = 0;
	d = roman;
	int length = d.length();
	for (int i = 0; i < length; i++)
	{
		if (d.substr(i, 1) == "M") /*Checks for any M's*/
		{
			ans = ans + 1000; //Adds 1000 for each M
		}
		else if (d.substr(i, 1) == "C") /*Checks for any C's*/
		{
			if (d.substr(i + 1, 1) == "M") /*Checks for any CM's*/
			{
				ans = ans + 900; //Adds 900 for each CM
				i++;
			}
			else if (d.substr(i + 1, 1) == "D") /*Checks for any CD's*/
			{
				ans = ans + 400; //Adds 400 for each CD
				i++;
			}
			else ans = ans + 100; //Adds 100 for each C
		}
		else if (d.substr(i, 1) == "D") /*Checks for any D's*/
		{
			ans = ans + 500; //Adds 500 for each D
		}
		else if (d.substr(i, 1) == "X") /*Checks for any X's*/
		{
			if (d.substr(i + 1, 1) == "C") /*Checks for any XC's*/
			{
				ans = ans + 90; //Adds 90 for each XC
				i++;
			}
			else if (d.substr(i + 1, 1) == "L") /*Checks for any XL's*/
			{
				ans = ans + 40; //Adds 40 for each XL
				i++;
			}
			else ans = ans + 10; //Adds 10 for each X
		}
		else if (d.substr(i, 1) == "L") /*Checks for any L's*/
		{
			ans = ans + 50; //Adds 50 for each L
		}
		else if (d.substr(i, 1) == "I") /*Checks for any I's*/
		{
			if (d.substr(i + 1, 1) == "X") /*Checks for any IX's*/
			{
				ans = ans + 9; //Adds 9 for each IX
				i++;
			}
			else if (d.substr(i + 1, 1) == "V") /*Checks for any IV's*/
			{
				ans = ans + 4; //Adds 4 for each IV
				i++;
			}
			else ans = ans + 1; //Adds 1 for each I
		}
		else /*Checks for any V's*/
		{
			ans = ans + 5; //Adds 5 for each V
		}
	}
	decimal = ans;
}
#endif /* ROMANNUMERAL_H_ */