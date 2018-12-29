/**
* Assignment 3b. Spiral
*
* A program to create a spiral of numbers increasing counter-clockwise using a 2-D array and functions.
*
* CMPE 180-92 Data Structures and Algorithms in C++
* Fall 2017
*
* Author: Emma Peatfield
*         San Jose State University
*/

#include <iostream>
using namespace std;

const int MAX_SIZE = 101;  // maximum size of the square matrix
const int MAX_START = 50;   // maximum starting number
void do_spiral(const int n, const int start);
void make_spiral(const int n, const int start); //creates the spiral
void print_spiral(const int n, const int start, int spiralarr[MAX_SIZE][MAX_SIZE]); //prints the spiral

int main()
{
	do_spiral(1, 1);
	do_spiral(5, 1);
	do_spiral(9, 11);
	do_spiral(12, 13);
	do_spiral(15, 17);
	return 0;
}

void do_spiral(const int n, const int start)
{
	make_spiral(n, start);
}
void make_spiral(const int n, const int start)
{
	int spiral[MAX_SIZE][MAX_SIZE]; //initializes a 2-D array
	int finalnumber = 0; //the largest number in the array that will be in the lower righthand corner of the matrix
	if (n % 2 == 0) //ends program if the size is not odd
	{
		cout << "Spiral of size " << n << " starting at " << start << endl;
		cout << "***** Error: Size " << n << " must be odd." << endl;
		cout << endl;
	}
	else
	{
		int sp = n / 2; //center position of matrix
		int spc = n / 2; //spacing from the center to the sides of the matrix
		finalnumber = (n * n) + (start - 1);
		while (finalnumber >= start && spc >= 0)
		{
			int spleft = sp - spc; //spacing left or to the top from current position
			int spright = sp + spc; //spacing right or to the bottom from current position
			for (int i = spright; i >= spleft; i--) //bottom row
			{
				spiral[spright][i] = finalnumber;
				finalnumber = finalnumber - 1;
			}
			for (int j = (spright - 1); j >= spleft; j--) //leftmost column
			{
				spiral[j][spleft] = finalnumber;
				finalnumber = finalnumber - 1;
			}
			for (int k = (spleft + 1); k <= spright; k++) //top row
			{
				spiral[spleft][k] = finalnumber;
				finalnumber = finalnumber - 1;
			}
			for (int m = spleft + 1; m <= (spright - 1); m++) //rightmost column
			{
				spiral[m][spright] = finalnumber;
				finalnumber = finalnumber - 1;
			}
			spc = spc - 1; //moves the number placement towards the center
		}
		print_spiral(n, start, spiral); //calls the print_spiral function
	}
}
void print_spiral(const int n, const int start, int spiralarr[MAX_SIZE][MAX_SIZE]) //prints the spiral as a matrix
{
	cout << "Spiral of size " << n << " starting at " << start << endl;
	cout << endl;
	for (int l = 0; l < n; l++)
	{
		for (int h = 0; h < n; h++)
		{
			cout << spiralarr[l][h] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
