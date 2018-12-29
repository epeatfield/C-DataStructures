#include "List.h"
#include <iostream>

using namespace std;

class Tester
{
public:
	void test1()
	{
		List lst;
		lst.push_front("Fred");
		lst.push_front("Wilma");
		lst.pop_front();
		cout << lst.first->data << endl;
		cout << "Expected: Fred" << endl;
		cout << lst.last->data << endl;
		cout << "Expected: Fred" << endl;
		cout << lst.first->next << endl;
		cout << "Expected: 0" << endl;
		cout << lst.first->previous << endl;
		cout << "Expected: 0" << endl;
		cout << lst.last->next << endl;
		cout << "Expected: 0" << endl;
		cout << lst.last->previous << endl;
		cout << "Expected: 0" << endl;
	}

	void test2()
	{
		List lst;
		lst.push_front("Fred");
		lst.push_front("Wilma");
		lst.push_front("Barney");
		lst.pop_front();
		cout << lst.first->data << endl;
		cout << "Expected: Wilma" << endl;
		cout << lst.last->data << endl;
		cout << "Expected: Fred" << endl;
		cout << lst.first->next->data << endl;
		cout << "Expected: Fred" << endl;
		cout << lst.first->previous << endl;
		cout << "Expected: 0" << endl;
		cout << lst.last->next << endl;
		cout << "Expected: 0" << endl;
		cout << lst.last->previous->data << endl;
		cout << "Expected: Wilma" << endl;
	}

	void test3()
	{
		List lst;
		lst.push_front("Fred");
		lst.pop_front();
		cout << lst.first << endl;
		cout << "Expected: 0" << endl;
		cout << lst.last << endl;
		cout << "Expected: 0" << endl;
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