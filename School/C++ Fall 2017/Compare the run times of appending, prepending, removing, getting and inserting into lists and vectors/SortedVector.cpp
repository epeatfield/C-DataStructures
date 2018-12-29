/**
* Assignment 8. STL List and Vector
* Fall 2017
*
* Compare the run times of appending, prepending, removing, getting
* and inserting into lists and vectors.
*
* Author: Emma Peatfield
*		  San Jose State University
*
*/
#include <iostream>
#include <iterator>
#include "SortedVector.h"
#include "Node.h"

using namespace std;

/**
* Defaut constructor.
* Reset the global Node counters.
*/
SortedVector::SortedVector()
{
	Node::reset();
}

/**
* Destructor.
* Reset the global Node counters.
*/
SortedVector::~SortedVector()
{
	Node::reset();
}

/**
* @return the size of the data vector.
*/
int SortedVector::size() const { return data.size(); }

/**
* Check that the data is sorted.
* @return true if sorted, false if not.
*/
bool SortedVector::check() const
{
	if (data.size() == 0) return true;

	vector<Node>::const_iterator it = data.begin();
	vector<Node>::const_iterator prev = it;

	it++;

	// Ensure that each node is greater than the previous node.
	while ((it != data.end()) && (*it >= *prev))
	{
		prev = it;
		it++;
	}

	return it == data.end();  // Good if reached the end.
}

/**
* Insert a new node at the beginning of the data vector.
* @param value the new node's value.
*/
void SortedVector::prepend(const long value)
{
	Node new_one(value);
	data.insert(data.begin(), new_one);
}

/**
* Append a new node at the end of the data vector.
* @param value the new node's value.
*/
void SortedVector::append(const long value)
{
	Node newone(value);
	data.push_back(newone);
}

/**
* Remove a node.
* @param index the index of the node to remove.
*/
void SortedVector::remove(const int index)
{
	data.erase(data.begin() + index);
}

/**
* Insert a new node into the data vector at the
* appropriate position to keep the vector sorted.
*/
void SortedVector::insert(const long value)
{
	Node inserts(value);
	int size = data.size();
	if (check())
	{
		for (int i = 0; i < size; i++)
		{
			if (value <= data[i].get_value())
			{
				data.insert(data.begin() + i, inserts);
				return;
			}
		}
		data.push_back(inserts);
	}
}

/**
* Return the data node at the indexed position.
* @param the index of the node.
* @return a copy of the data node.
*/
Node SortedVector::at(const int index) const
{
	return data[index];
}

/**
* Sort the vector
*/
/*void SortedVector::sort()
{
	int size1 = size();
	Node test = 0;
	Node temp = 0;
	Node temp2 = 0;
	vector<Node>::iterator it = data.begin();
	while (it != data.end())
	{
		for (int i = 1; i < size1; i++)
		{
			test = data[i - 1];
			temp = data[i];
			if (temp.get_value() <= test.get_value())
			{
				data[i - 1] = temp;
				data[i] = test;
				goto finish;
			}
		}
		it++;
	finish:;
	}
} */