#pragma once
#ifndef BOOKLIST_H_
#define BOOKLIST_H_
#include <string>
#include "Book.h"
#include "BookNode.h"

using namespace std;

/**
* A list of book nodes.
*/
class BookList
{
public:
	/**
	* Constructor.
	* @param cat the name of this list.
	*/
	BookList(const string cat);
	/*
	* Inserts a Book into the list
	*/
	void insert(Book bookinlist);
	/**
	* Sorts the list
	*/
	void sort();
	/**
	* Print the list.
	*/
	void print();
	/**
	* Searches for duplicate isbns.
	*/
	int find(const string isbn, const BookList find);

private:
	string name;  // name of this book list
	BookNode* head;   // head of the list of book nodes
	BookNode* tail;   // tail of the list of book nodes
};

#endif /* BOOKLIST_H_ */
