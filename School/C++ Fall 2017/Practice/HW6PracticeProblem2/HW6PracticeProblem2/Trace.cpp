/*
In the constructor, copy constructor, assignment operator, destructor
print messages "Constructing ...", "Copying ...", "Assigning ... to ...", "Destroying ...", and do what else is necessary.
*/

#include <iostream>
#include <string>
#include "Trace.h"

using namespace std;

Trace::Trace(string s)
{
	str = s;
	cout << "Constructing " << s << endl;
}

Trace::Trace(const Trace& other)
{
	str = other.str;
	cout << "Copying " << other.str << endl;
}

Trace& Trace::operator=(const Trace& other)
{
	cout << "Assigning " << other.str << " to " << str << endl;
	str = other.str;
	return *this;
}

Trace::~Trace()
{
	cout << "Destroying " << str << endl;
}