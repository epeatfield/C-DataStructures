#pragma once
#ifndef BOOK_H_
#define BOOK_H_

#include <string>
using namespace std;

/***** Complete this file. *****/

/**
* The Book class.
*/
class Book
{
public:
	/**
	* Book categories.
	*/
	enum class Category { FICTION, HISTORY, TECHNICAL, NONE };

	/**
	* Default constructor.
	*/
	Book();

	/**
	* Constructor.
	*/
	Book(string isbn, string last, string first, string title, Category category);

	/**
	* Destructor.
	*/
	~Book();
	/* returns the book's ISBN string */
	string return_isbn() const;
	/* Returns the book's author string */
	string return_author() const;

	void SetCategory(string acteg)
	{
		Book::Category catfunc;
		if (acteg == "fiction")
		{
			catfunc = Book::Category::FICTION;
		}
		else if (acteg == "history")
		{
			catfunc = Book::Category::HISTORY;
		}
		else if (acteg == "technical")
		{
			catfunc = Book::Category::TECHNICAL;
		}
		else catfunc = Book::Category::NONE;
		cat = catfunc;
	}
	/* Returns the book's category */
	Book::Category get_category() const
	{
		return cat;
	}
	/* Overloading the >> and << operators */
	friend istream& operator>>(istream& ins, Book& book);

	friend ostream& operator<<(ostream& outs, const Book& book);

private:
	string num;
	string lastname;
	string firstname;
	string booktitle;
	Book::Category cat;
};

#endif /* BOOK_H_ */
