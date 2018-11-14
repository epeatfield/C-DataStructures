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
#include "Node.h"

using namespace std;

/**
* Constructor.
* @param the_value the initial value.
*/
Node::Node(const long the_value)
{
	value = the_value;
	constructor_count++;
}

/**
* Copy constructor.
* @param other the other node object to copy.
*/
Node::Node(const Node& other)
{
	copy_count++;
	value = other.value;
}
/**
* Destructor.
*/
Node::~Node()
{
	destructor_count++;
}

/**
* Getter.
* @return the value.
*/
long Node::get_value() const
{
	return value;
}

/**
* Getter.
* @return the value of the global constructor_count.
*/
long Node::get_constructor_count()
{
	return constructor_count;
}

/**
* Getter.
* @return the value of the global copy_count.
*/
long Node::get_copy_count()
{
	return copy_count;
}

/**
* Getter.
* @return the value of the global destructor_count.
*/
long Node::get_destructor_count()
{
	return destructor_count;
}

/**
* Reset the values of the global counters.
*/
void Node::reset()
{
	destructor_count = 0;
	copy_count = 0;
	constructor_count = 0;
}

/**
* Overloaded == operator.
* @return true if the values of two nodes are equal, else false.
*/
bool Node::operator ==(const Node& other) const
{
	if (other.value == value)
		return true;
	else
		return false;
}

/**
* Overloaded > operator.
* @return true if the value of this node is greater than
*              the value of the other node, else false.
*/
bool Node::operator  >(const Node& other) const
{
	if (value > other.value)
		return true;
	else
		return false;
}

/**
* Overloaded >= operator.
* @return true if the value of this node is greater than or equal to
*              the value of the other node, else false.
*/
bool Node::operator >=(const Node& other) const
{
	if (value >= other.value)
		return true;
	else
		return false;
}
 /*
 * initializing the static variables
 */
long Node::constructor_count = 0;
long Node::copy_count = 0;
long Node::destructor_count = 0;