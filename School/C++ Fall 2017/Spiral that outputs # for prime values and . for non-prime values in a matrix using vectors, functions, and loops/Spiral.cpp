/**
* Assignment 3c. Prime Spiral
*
* A program to create a spiral that outputs # for prime values and . for non-prime values in a matrix using vectors, functions, and loops.
*
* CMPE 180-92 Data Structures and Algorithms in C++
* Fall 2017
*
* Author: Emma Peatfield
*         San Jose State University
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;


const int MAX_START = 50;   // maximum starting number

void do_prime_spiral(const int n, const int start); /* calls all functions to create spiral */
void make_spiral(const int n, const int start); /* makes the spiral with # and . for prime and not prime values */
void print_spiral(const int n, const int start, vector< vector<string> > spiralvec); /* prints the spiral */
bool compute_primes(int number, const int n); /* computes whether or not the value is prime */


/**
* The main: Generate and print prime spirals of various sizes.
*/
int main()
{
	do_prime_spiral(5, 1);
	do_prime_spiral(25, 11);
	do_prime_spiral(35, 0);
	do_prime_spiral(50, 31);
	do_prime_spiral(101, 41);

	return 0;
}

void do_prime_spiral(const int n, const int start) // runs if start values and size values are within range
{
	if (start < 1 || start > 50)
	{
		cout << "Prime spiral of size " << n << " starting at " << start << endl;
		cout << "***** Error: Starting value " << start << " < 1 or > 50" << endl;
		cout << endl;
	}
	else if ((n % 2) == 0)
	{
		cout << "Prime spiral of size " << n << " starting at " << start << endl;
		cout << "***** Error: Size " << n << " must be odd." << endl;
		cout << endl;
	}
	else
	{
		make_spiral(n, start); //calls the make_spiral function
	}
}

void make_spiral(const int n, const int start) //Creates the 2-D vector using # and . for prime or non-prime value and arranges them in a spiral
{
	vector< vector<string> > spiral; //initializes the 2-D vector
	spiral.resize(n); //Resizes the 2-D vector rows so that it is only as large as neccessary 
	for (int v = 0; v < n; v++)
	{
		spiral[v].resize(n); //Resizes the columns
	}

	int sp = n / 2; //middle position in matrix
	int spc = n / 2; //spacing distance from sides of matrix
	int finalnumber = (n * n) + (start - 1); //Last number in the spiral in lower righthand corner
	while (finalnumber >= start && spc >= 0)
	{
		int spleft = sp - spc; //distance number is from left or top of matrix
		int spright = sp + spc; //distance number is from right or bottom of matrix
	/* Creates the array in a spiral fashion starting in lower right-hand corner and moving clockwise into the middle */
		for (int i = spright; i >= spleft; i--)  //Bottom row
		{
			compute_primes(finalnumber, n); 
			if (compute_primes(finalnumber, n))
			{
				spiral[spright][i] = "#";
			}
			else
			{
				spiral[spright][i] = ".";
			}
			finalnumber = finalnumber - 1;
		}
		for (int j = (spright - 1); j >= spleft; j--) //Left hand side column
		{
			compute_primes(finalnumber, n);
			if (compute_primes(finalnumber, n))
			{
				spiral[j][spleft] = "#";
			}
			else
			{
				spiral[j][spleft] = ".";
			}
			finalnumber = finalnumber - 1;
		}
		for (int k = (spleft + 1); k <= spright; k++) //Top row
		{
			compute_primes(finalnumber, n);
			if (compute_primes(finalnumber, n))
			{
				spiral[spleft][k] = "#";
			}
			else
			{
				spiral[spleft][k] = ".";
			}
			finalnumber = finalnumber - 1;
		}
		for (int m = spleft + 1; m <= (spright - 1); m++) //Right hand side column
		{
			compute_primes(finalnumber, n);
			if (compute_primes(finalnumber, n))
			{
				spiral[m][spright] = "#";
			}
			else
			{
				spiral[m][spright] = ".";
			}
			finalnumber = finalnumber - 1;
		}
		spc = spc - 1;
	}
	print_spiral(n, start, spiral);
}
void print_spiral(const int n, const int start, vector< vector<string> > spiralvec) //prints the final matrix
{
	cout << "Prime spiral of size " << n << " starting at " << start << endl;
	cout << endl;
	for (int l = 0; l < n; l++)
	{
		for (int h = 0; h < n; h++)
		{
			cout << spiralvec[l][h];
		}
		cout << endl;
	}
	cout << endl;
}

bool compute_primes(int number, const int n) //computes the primes and returns true if the value is prime
{
	int prime = 0;
	vector<int> primes; //vector that stores the prime values
	int size = n*n; 
	primes.resize(size); //resizing the vector
	if (number == 2)
	{
		prime = 1;
		primes.push_back(number); 
	}
	else if (number == 1)
	{
		prime = 0;
	}
	else 
	{
		for (int p = 2; p < number; p++)
		{
			int rem = number % p; 
			if (rem == 0) //Leaves the function if divisible by another number(i.e. not prime)
			{
				prime = 0;
				break;
			}
			else
			{
				prime = 1;
				primes.push_back(number);
			}
		}
	}
	return (prime == 1);
}
