/**
* Assignment 7. Book List
* Fall 2017
*
* Read in text files with book entries. Sort into separate and merged 
* linked lists.
* 
* Author: Emma Peatfield
*		  San Jose State University
* 
*/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "BookList.h"
#include "Book.h"
#include "BookNode.h"

using namespace std;

/* String for the name of the categories file */
const string CATEGORIES_FILE_NAME = "categories.txt";
/**
* The main. Create and print the book lists.
*/
int main()
{
	ifstream input; 
	Book a; //initializes input book
	vector<string> category; //Vector of strings for the category names
	input.open(CATEGORIES_FILE_NAME);
	if (input.fail())
	{
		cout << "Failed to open " << CATEGORIES_FILE_NAME << endl;
		return -1;
	}
	int totalbooks = 0;	// Counter for Merged Book List
	int athrumcount = 0; // Counter for Authors A-M Book List
	int nthruzcount = 0; // Counter for Authors N-Z Book List
	string cat; 
	string merged = "MERGED";
	string authors_a_m = "AUTHORS A-M";
	string authors_n_z = "AUTHORS N_Z";
	BookList merg(merged); // Merged Book List
	BookList aA_M(authors_a_m); // Authors A-M Book List
	BookList aN_Z(authors_n_z); // Authors N-Z Book List
	do
	{
		getline(input, cat); //had to switch for codecheck
		if (input.eof()) break; //had to swicth with getline for codecheck
		category.push_back(cat); // Adds Category Name to vector
		string filename = cat + ".txt"; //creates the name for the file, ex: cat = history so filename = history.txt
		ifstream filein;
		filein.open(filename); 
		if (filein.fail())
		{
			cout << "Failed to open " << cat << ".txt" << endl;
			return -1;
		}
		int bookcount = 0; //count for amount of books in each category
		while (!filein.fail())
		{
			BookList b(cat); //Creates a book list for each category
			while (filein)
			{
				filein >> a; //had to switch for codecheck to work
				if (filein.eof()) break; //had to switch with filein>>a for codecheck to work
				string isb = a.return_isbn(); // Gets ISBN of Book a
				string last = a.return_author(); // Gets Last Name of Author of Book a
				
				int v = b.find(isb, b); // Checks for duplicate books
				if (v == -1) // If not a duplicate...
				{
					b.insert(a); //Add to category Book List
					merg.insert(a); //Add to merged Book List
					if (last < "N") // If last name A-M
					{
						aA_M.insert(a); // Add to A-M Book List
						athrumcount++;
					}
					else
					{
						aN_Z.insert(a); //Else add to N-Z Book List
						nthruzcount++;
					}
					bookcount++;
					totalbooks++;
				}
			}
			b.print(); // Print out the Category Book List
			cout << "    (" << bookcount << " books)" << endl;
			break;
		}	
	} while (input);
	merg.print(); // Print Merged Book List
	cout << "    (" << totalbooks << " books)" << endl;
	aA_M.print(); // Print Authors A-M Book List
	cout << "    (" << athrumcount << " books)" << endl;
	aN_Z.print(); // Print Authors N- Z Book List
	cout << "    (" << nthruzcount << " books)" << endl;
	return 0;
}
