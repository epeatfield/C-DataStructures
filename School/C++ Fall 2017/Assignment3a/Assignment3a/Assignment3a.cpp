/**
* Assignment 3a. Prime Numbers 
*
* A program to find the prime numbers in a list of numbers using the Sieve of Eratosthenes.
* Fills an array and prints only the prime numbers in that array.
*
* CMPE 180-92 Data Structures and Algorithms in C++
* Fall 2017
*
* Author: Emma Peatfield
*         San Jose State University
*/

#include <iostream>
using namespace std;

const int MAX_NUMBER = 1000;  // maximum possible prime number
const int ROW_SIZE = 20;    // row size for printing
void compute_primes(int numberslist[], int size); //Function used to compute primes
void print_primes(int numberslist[], int size, int rows); //Function used to print primes

int main()
{
	int list[MAX_NUMBER]; //Initializing the array

	for (int i = 1; i < MAX_NUMBER; i++)
	{
		list[i - 1] = i + 1; //Filling the array from 2 to MAX_NUMBER
	}
	compute_primes(list, MAX_NUMBER); //calling functions
	print_primes(list, MAX_NUMBER, ROW_SIZE);
	return 0;
}

void compute_primes(int numberslist[], int size) //computes the primes
{
	int p = 2;
	for (int k = 0; k < (size - 2); k++)
	{
		for (int j = (k + 1); j < (size - 1); j++)
		{
			int rem = numberslist[j] % p; //Computes primes by marking the numbers that are multiples of p
			if (rem == 0) //Marks the multiples of p
			{
				numberslist[j] = -1;
			}
		}
		if (numberslist[k] != -1) //Sets up the next p in the array
		{
			p = numberslist[k];
		}
	}
} //The remaining numbers in the array are all prime numbers from 2 to MAX_NUMBER
void print_primes(int numberslist[], int size, int rows)
{
	int count = 0;
	for (int l = 0; l < (size - 1); l++)
	{
		if (count == rows) //sets up the row size, so it skips to the next row after 20 numbers
		{
			cout << endl;
			count = 0;
		}
		if (numberslist[l] != -1) //If the value in this spot in the array is not equal to -1, it is prime so it prints that value
		{
			cout << numberslist[l] << " ";
			count = count + 1;
		}
	}
	cout << endl;
	cout << endl;
	cout << "Done!" << endl;
}