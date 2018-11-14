#pragma once
#include <string>
using namespace std;

class Trace
{
public:
	Trace(string s);
	Trace(const Trace& other);
	Trace& operator=(const Trace& other);
	~Trace();
private:
	string str;
};