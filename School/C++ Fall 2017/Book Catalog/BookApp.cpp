/**
* Assignment 6. Book Catalog
* Fall 2017
*
*Read in a text file with commands and book entries. Search, add, and remove book entries.
*
*Author: Emma Peatfield
*		 San Jose State University
*
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Book.h"

using namespace std;

// Status codes.
enum class StatusCode { OK, DUPLICATE, NOT_FOUND, INVALID_COMMAND };

/**
* Find the book in the catalog with the given ISBN.
* Use a binary search.
* @param isbn the ISBN.
* @param catalog the vector of book records.
* @return the vector index of the book if found, else return -1.
*/
int find(const string isbn, const vector<Book>& catalog);
/**
* Find the book in the catalog with the given author.
* Use a linear search.
* @param auth the Author.
* @param catalog the vector of book records.
* Prints the necessary book entries.
*/
void find_author(const string auth, const vector<Book>& catalog);
/**
* Find the book in the catalog with the given category.
* Use a linear search.
* @param categorycompare the Category.
* @param catalog the vector of book records.
* Prints the necessary book entries.
*/
void find_category(const string categorycompare, const vector<Book>& catalog);

const string INPUT_FILE_NAME = "commands.in";

/**
* The main. Open the command input file and loop to process commands.
*/
int main()
{
	// Open the input file.
	ifstream input;
	input.open(INPUT_FILE_NAME);
	if (input.fail())
	{
		cout << "Failed to open " << INPUT_FILE_NAME << endl;
		return -1;
	}

	vector<Book> catalog;  // book catalog
	char command;
	Book b;
	string a1, a2, lasts, titles, isb, categ, b1, b2, b5, line, firstn, isbn1;
	int i = 0;
	int previousnum = 0;
	cout << endl; 
	while (true)
	{
		input >> command;
		if (input.eof()) break;
		if (command == '+')
		{
			getline(input, b5, ','); //Reads a string until a new comma
			a1 = b5.substr(1, 14); //Gets rid of an extra space
			getline(input, lasts, ',');
			getline(input, firstn, ',');
			getline(input, titles, ',');
			getline(input, categ);
			int number = stoi(a1.substr(4, 10)); //converts a string of numbers to an int

			Book::Category cat1;
			if (categ == "history")
			{
				cat1 = Book::Category::HISTORY; //sets category to history
			}
			else if (categ == "fiction")
			{
				cat1 = Book::Category::FICTION; //sets category to fiction
			}
			else
			{
				cat1 = Book::Category::TECHNICAL; //sets category to technical
			}

			Book b(a1, lasts, firstn, titles, cat1); //creates book from the strings
			int size = catalog.size(); 
			if (size == 0)
			{
				catalog.push_back(b);
				cout << command << " Inserted at index " << 0 << ": " << catalog[0] << endl; //creates the first entry
			}
			else
			{
				int v = find(a1, catalog); //checks for duplicates
				if (v == -1)
				{
					for (int k = 0; k < size; k++) 
					{
						for (int j = 0; j < size; j++)
						{
							isbn1 = catalog[j].return_isbn(); 
							previousnum = stoi(isbn1.substr(4, 10)); //converts the string isbn into an integer
							if (number < previousnum)
							{
								catalog.insert(catalog.begin() + j, b); //if less than another entry, insert into an earlier spot
								cout << command << " Inserted at index " << j << ": " << catalog[j] << endl; 
								goto finish;
							}
						}
						catalog.push_back(b); //adds to end if not less than another enrty
						cout << command << " Inserted at index " << i + 1 << ": " << catalog[i + 1] << endl;
						i++;
						break;
					}
				finish:;
				}
				else
				{
					cout << command << " Inserted at index " << v << ": " << catalog[v];
					cout << "*** Duplicate ISDN ***" << endl;
					cout << endl;
				}
			}
		}
		else if (command == '-')
		{
			getline(input, isb, '\n');
			string isb2 = isb.substr(1, 14);
			int value = find(isb2, catalog); //checks for the specific isbn
			if (value > -1)
			{
				cout << command << " Removed " << catalog[value] << endl;
				catalog.erase(catalog.begin() + value); //erases an entry
			}
			else
			{
				Book c(isb2, "", "", "", Book::Category::NONE);
				cout << command << " Removed " << c;
				cout << "*** Book not found ***" << endl;
				cout << endl;
			}
		}
		else if (command == '?')
		{
			getline(input, a2, '\n');
			if (a2.substr(0, 2) == " a") 
			{
				if (a2.substr(8, 1) == "M")
				{
					b2 = a2.substr(8, 3);
				}
				else if (a2.substr(8, 1) == "K")
				{
					b2 = a2.substr(8, 4);
				}
				else b2 = a2.substr(8, 9);
				cout << command << " Books by author " << b2 << ": " << endl;
				find_author(b2, catalog); //searches and prints other entries with given author name
				cout << endl;
			}
			else if (a2.substr(0, 2) == " c")
			{
				if (a2.substr(10, 1) == "f")
				{
					b2 = a2.substr(10, 7);
				}
				else if (a2.substr(10, 1) == "t")
				{
					b2 = a2.substr(10, 9);
				}
				else b2 = a2.substr(10, 7);
				cout << command << " Books in category " << b2 << ": " << endl;
				find_category(b2, catalog); // searches and prints other entries with given category name
				cout << endl;
			}
			else if (a2.substr(0, 2) == " i")
			{
				b2 = a2.substr(6, 14);
				cout << command << " Book with ISBN " << b2 << ": " << endl;
				int n = find(b2, catalog); // searches and prints other entries with given ISBN
				if (n != -1)
					cout << catalog[n] << endl;
				else
					cout << endl;
			}
			else
			{
				cout << command << " All books in the catalog: " << endl;
				int size = catalog.size();
				for (int i = 0; i < size; i++)
				{
					cout << catalog[i];  //prints all books in the catalog
				}
				cout << endl;
			}
		}
		else
		{
			getline(input, b1, '\n');
			cout << command << " *** Invalid Command ***" << endl;
			cout << endl;
		}
	}
	return 0;
}
//uses an iterative binary search to find a repeating isbn in a sorted array
int find(const string isbn, const vector<Book>& catalog)
{
	int value = stoi(isbn.substr(5, 10));
	int high = (catalog.size() - 1);
	int low = 0;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		string midv = catalog[mid].return_isbn();
		int midvalue = stoi(midv.substr(4, 10));
		if (isbn == midv)
		{
			return mid;
		}
		else if (value < midvalue)
		{
			high = mid - 1;
		}
		else low = mid + 1;
	}
	return -1;
}
//finds books with the same author
void find_author(const string auth, const vector<Book>& catalog)
{
	int n = catalog.size();
	for (int i = 0; i < n; i++)
	{
		string compare = catalog[i].return_author();
		if (auth == compare)
			cout << catalog[i];
	}
}
//finds books with the same category
void find_category(const string categorycompare, const vector<Book>& catalog)
{
	int n = catalog.size();
	Book::Category test;
	if (categorycompare == "fiction")
		test = Book::Category::FICTION;
	else if (categorycompare == "history")
		test = Book::Category::HISTORY;
	else
		test = Book::Category::TECHNICAL;
	for (int k = 0; k < n; k++)
	{
		Book::Category compare = catalog[k].get_category();
		if (test == compare)
			cout << catalog[k];
	}
}