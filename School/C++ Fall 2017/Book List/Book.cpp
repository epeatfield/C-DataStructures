#include <iostream>
#include "Book.h"

using namespace std;
/* Default Constructor */
Book::Book()
{
	isbn_ = "";
	namefirst = "";
	namelast = "";
	booktitle = "";
}
/* Constructor */
Book::Book(string isbn, string last, string first, string title) : isbn_(isbn), namelast(last), namefirst(first), booktitle(title)
{}

/* Deconstructor */
Book::~Book()
{}

/* Returns ISBN */
string Book::return_isbn() const
{
	return isbn_;
}

/* Returns author */
string Book::return_author() const
{
	return namelast;
}
/* Overloads << Operator */
ostream& operator<<(ostream& outs, const Book& book)
{
	outs << "  Book{ISBN=" << book.isbn_ << ", last=" << book.namelast << ", first=" << book.namefirst << ", title=" << book.booktitle << "}" << endl;
	return outs;
}
/* Overloads >> Operator */
istream& operator>>(istream& ins, Book& book)
{
	getline(ins, book.isbn_, ',');
	getline(ins, book.namelast, ',');
	getline(ins, book.namefirst, ',');
	getline(ins, book.booktitle);

	return ins;
}

