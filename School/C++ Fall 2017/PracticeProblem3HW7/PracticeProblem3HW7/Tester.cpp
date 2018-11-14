#include "List.h"
#include <iostream>
#include <iomanip>

using namespace std;

class Tester
{
public:
	void test1()
	{
		List lst;
		lst.push_front("Fred");
		lst.push_front("Wilma");
		Iterator iter = lst.begin();
		cout << boolalpha << iter.past_end() << endl;
		cout << "Expected: false" << endl;
		cout << iter.get() << endl;
		cout << "Expected: Wilma" << endl;
		iter.next();
		cout << iter.past_end() << endl;
		cout << "Expected: false" << endl;
		cout << iter.get() << endl;
		cout << "Expected: Fred" << endl;
		iter.next();
		cout << iter.past_end() << endl;
		cout << "Expected: true" << endl;
	}

	void test2()
	{
		List lst;
		lst.push_front("Barney");
		Iterator iter = lst.begin();
		cout << iter.past_end() << endl;
		cout << "Expected: false" << endl;
		cout << iter.get() << endl;
		cout << "Expected: Barney" << endl;
		iter.next();
		cout << iter.past_end() << endl;
		cout << "Expected: true" << endl;
	}

	void test3()
	{
		List lst;
		Iterator iter = lst.begin();
		cout << iter.past_end() << endl;
		cout << "Expected: true" << endl;
	}
};


int main()
{
	Tester tester;
	tester.test1();
	tester.test2();
	tester.test3();
	return 0;
}