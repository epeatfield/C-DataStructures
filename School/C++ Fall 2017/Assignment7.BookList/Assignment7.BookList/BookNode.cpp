#include <string>
#include "BookNode.h"
#include "Book.h"
#include "BookList.h"

/**
* Constructor.
* @param bookin this node's book.
*/
BookNode::BookNode(Book bookin)
{
	book = bookin;
	next = nullptr;
	prev = nullptr;
}

