#pragma once
#ifndef BOOKNODE_H_
#define BOOKNODE_H_

#include "Book.h"


/**
* A book node in a linked list.
*/
class BookNode
{
public:
	/**
	* Constructor.
	* @param book this node's book.
	*/
	BookNode(Book bookin);

private:
	Book book;       // this node's book
	BookNode *next;  // link to the next node in the list
	BookNode *prev; // link to the previous node in the list
	friend class BookList;
	friend class Book;
};

#endif /* BOOKNODE_H_ */
