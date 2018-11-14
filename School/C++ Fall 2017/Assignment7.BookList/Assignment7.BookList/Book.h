#pragma once
#ifndef BOOK_H_
#define BOOK_H_
#include <string>
using namespace std;
/**
* The Book class.
*/
class Book
{
public:
	/**
	* Default constructor.
	*/
	Book();

	/*Constructor*/
	Book(string isbn, string last, string first, string title);

	/* Destructor.*/
	~Book();

	/* returns the book's ISBN string */
	string return_isbn() const;

	/* Returns the book's author string */
	string return_author() const;

	/* Overloads the ostream operator to output books */
	friend ostream& operator<<(ostream& outs, const Book& book);

	/* Overloads the istream operator to input books */
	friend istream& operator>>(istream& ins, Book& book);

private:
	string isbn_;
	string namelast;
	string namefirst;
	string booktitle;
	string cat;
};

#endif /* BOOK_H_ */
