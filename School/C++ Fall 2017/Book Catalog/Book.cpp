#include <iostream>
#include "Book.h"

using namespace std;
/* Default Constructor */
Book::Book()
{
	num = "";
	firstname = "";
	lastname = "";
	booktitle = "";
	cat = Book::Category::NONE;
}
/* Constructor */
Book::Book(string isbn, string last, string first, string title, Category category)
{
	num = isbn;
	firstname = first;
	lastname = last;
	booktitle = title;
	cat = category;
}
/* Deconstructor */
Book::~Book()
{

}
/* Returns ISBN */
string Book::return_isbn() const
{
	return num;
}
/* Returns author */
string Book::return_author() const
{
	return lastname;
}
/* Overloads << Operator */
ostream& operator<<(ostream& outs, const Book& book)
{

	string cat1;
	if (book.cat == Book::Category::TECHNICAL)
	{
		cat1 = "technical";
		outs << "Book{ISBN=" << book.num << ", last=" << book.lastname << ", first=" << book.firstname << ", title=" << book.booktitle << ", category=" << cat1 << "}" << endl;
	}
	else if (book.cat == Book::Category::HISTORY)
	{
		cat1 = "history";
		outs << "Book{ISBN=" << book.num << ", last=" << book.lastname << ", first=" << book.firstname << ", title=" << book.booktitle << ", category=" << cat1 << "}" << endl;
	}
	else if (book.cat == Book::Category::FICTION)
	{
		cat1 = "fiction";
		outs << "Book{ISBN=" << book.num << ", last=" << book.lastname << ", first=" << book.firstname << ", title=" << book.booktitle << ", category=" << cat1 << "}" << endl;
	}
	else
	{
		cat1 = "none";
		outs << "Book{ISBN=" << book.num << ", last=" << book.lastname << ", first=" << book.firstname << ", title=" << book.booktitle << ", category=" << cat1 << "}" << endl;
	}
	return outs;
}
/* Overloads >> Operator */
istream& operator>>(istream& ins, Book& book)
{
	char op, ch;
	string isbn, search, b1, b2, b3, b4, b5;
	ins >> op; // read the first command
	ins >> b1;

	return ins;
}

