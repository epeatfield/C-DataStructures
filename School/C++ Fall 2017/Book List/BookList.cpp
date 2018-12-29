#include <iostream>
#include <string>
#include "BookList.h"
#include "Book.h"
#include "BookNode.h"

using namespace std;

/* Constructs a Book List
* @param cat this strings category */
BookList::BookList(const string cat) : name(cat), head(nullptr), tail(nullptr)
{}
/* Prints out the Book List */
void BookList::print()
{
	cout << endl << "Book list: " << name << endl;
	cout << endl;
	sort();
	BookNode* temp = head;
	while (temp != tail)
	{
		cout << temp->book;
		temp = temp->next;
	}
	cout << tail->book;
}
/* Inserts an entry into the head of the Book List 
* @param bookinlist the book to be inserted into the list */
void BookList::insert(Book bookinlist)
{
	BookNode* new_booknode = new BookNode(bookinlist);
	if (head == nullptr) //Inserts into empty list
	{
		head = new_booknode;
		tail = new_booknode;
	}
	else //Inserts into list that has elements
	{
		new_booknode->next = head;
		head->prev = new_booknode;
		head = new_booknode;
	}
}
/* Takes in a full Book List and outputs the Book List sorted by ISBN */
void BookList::sort() 
{
	int count = 0;
	BookNode* tempc = head;
	while (tempc) // Finds the number of books in the book list
	{
		++count;
		tempc = tempc->next;
	}
	
	BookNode* check = head;
	BookNode* temp = nullptr;
	BookNode* tempback = nullptr;
	while (check->next != nullptr)
	{
		temp = check->next;
		if (check->book.return_isbn() > temp->book.return_isbn()) /* Switches the value that is greater with the one that is lower */
		{
			check->next = temp->next;
			temp->next = check;
			if (tempback != nullptr) tempback->next = temp;
			tempback = temp;
			if (head == check)
			{
				head = temp;
			}
			if (check->next == nullptr)
			{
				tail = check;
			}
		}
		else
		{
			tempback = check;
			check = check->next; //Continues to check the rest of the values
			goto finish; //Breaks the loop out to finish
		}
		tempback = nullptr;
		check = head;
	finish:;
	}
}
/* Looks for Duplicate ISBNs within the book list
* Pre-Conditions: A new book is being read with ISBN number isbn 
* a Book List find will be searched
* Post-Conditions: If the ISBN is found, the book will not be added and the function
* will return 0. If not found, the function will return -1 
*/
int BookList::find(const string isbn, const BookList find)
{
	BookNode* p = head;
	while (p != nullptr)
	{
		if (isbn == p->book.return_isbn())
		{
			return 0;
		}
		else p = p->next;
	}
	return -1;
}


