#pragma once
#ifndef ROMANNUMERAL_H_
#define ROMANNUMERAL_H_

using namespace std;

class RomanNumeral
{
public:
	/**
	* Default constructor.
	*/
	RomanNumeral();
	RomanNumeral(int d);
	RomanNumeral(string r);
	void print() const;
private:
	string roman;
	int decimal;
	void to_roman();
	void to_decimal();
};

RomanNumeral::RomanNumeral() : roman(""), decimal(0)
{
}
RomanNumeral::RomanNumeral(string r) : roman(r)
{

}
RomanNumeral::RomanNumeral(int d) :decimal(d)
{

}

void RomanNumeral::print()
{
	cout << "[" << decimal << ":" << roman << "] ";
}

void RomanNumeral::to_roman()
{
	string m = "M";
	int temp = decimal;
	int thousands = temp / 1000;
	if (thousands != 0)
	{
		for (int i = 0; i < thousands; i++)
			roman = roman + m;
	}
	temp = temp % 1000;
	if (temp / 100 == 9)
	{
		roman = roman + "CM";
		temp = temp % 900;
	}
	else if (temp / 100 == 4)
	{
		roman = roman + "CD";
		temp = temp % 400;
	}
	else
	{
		string d5 = "D";
		int fivehund = temp / 500;
		if (fivehund != 0)
		{
			for (int i = 0; i < fivehund; i++)
				roman = roman + d5;
		}
		temp = temp % 500;
	}
	string c = "C";
	int hundreds = temp / 100;
	if (hundreds != 0)
	{
		for (int i = 0; i < hundreds; i++)
			roman = roman + c;
	}
	temp = temp % 100;
	if (temp / 10 == 9)
	{
		roman = roman + "XC";
		temp = temp % 90;
	}
	else if (temp / 10 == 4)
	{
		roman = roman + "XL";
		temp = temp % 40;
	}
	else
	{
		string l = "L";
		int fifties = temp / 50;
		if (fifties != 0)
		{
			for (int i = 0; i < fifties; i++)
				roman = roman + l;
		}
		temp = temp % 50;
	}
	string x = "X";
	int tens = temp / 10;
	if (tens != 0)
	{
		for (int i = 0; i < tens; i++)
			roman = roman + x;
	}
	temp = temp % 10;
	if (temp == 9)
	{
		roman = roman + "IX";
	}
	else if (temp == 4)
	{
		roman = roman + "IV";
	}
	else
	{
		string v = "V";
		int fives = temp / 5;
		if (fives != 0)
		{
			for (int i = 0; i < fives; i++)
				roman = roman + v;
		}
		string ones = "I";
		int onespl = temp % 5;
		if (temp == 4)
		{
			roman = roman + "IV";
		}
		else
		{
			if (onespl != 0)
			{
				for (int i = 0; i < onespl; i++)
					roman = roman + ones;
			}
		}
	}
}

void RomanNumeral::to_decimal()
{
	int ans = 0;
	for (int i = 0; i < roman.length(); i++)
	{
		if (roman.substr(i, 1) == "M")
		{
			ans = ans + 1000;
		}
		else if (roman.substr(i, 1) == "C")
		{
			if (roman.substr(i + 1, 1) == "M")
			{
				ans = ans + 900;
				i++;
			}
			else if (roman.substr(i + 1, 1) == "D")
			{
				ans = ans + 400;
				i++;
			}
			else ans = ans + 100;
		}
		else if (roman.substr(i, 1) == "D")
		{
			ans = ans + 500;
		}
		else if (roman.substr(i, 1) == "X")
		{
			if (roman.substr(i + 1, 1) == "C")
			{
				ans = ans + 90;
				i++;
			}
			else if (roman.substr(i + 1, 1) == "L")
			{
				ans = ans + 40;
				i++;
			}
			else ans = ans + 10;
		}
		else if (roman.substr(i, 1) == "L")
		{
			ans = ans + 50;
		}
		else if (roman.substr(i, 1) == "I")
		{
			if (roman.substr(i + 1, 1) == "X")
			{
				ans = ans + 9;
				i++;
			}
			else if (roman.substr(i + 1, 1) == "V")
			{
				ans = ans + 4;
				i++;
			}
			else ans = ans + 1;
		}
		else
		{
			ans = ans + 5;
		}
	}
	decimal = ans;
}



#endif /* ROMANNUMERAL_H_ */
