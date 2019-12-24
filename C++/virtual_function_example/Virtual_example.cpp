

// Example program
#include <iostream>
#include <string>

using namespace std;
class A
{
public:
	A() { cout << "In AAAAA constructor..." << endl; }
	~A() { cout << "In AAAAA destructorrrr.." << endl; }

	virtual void fun() { cout << "In A Fun function.." << endl; }



};
class B : public A
{
public:
	B() { cout << "In BBBB constructorrr.." << endl; }
	~B() { cout << "In BBBB destructorrrr.." << endl; }

private:
	void fun() { cout << "In BBBB Fun function.." << endl; }
};

int main()
{
	A* p;
	B obj1;
	A obj2;
	p = &obj1;
	p->fun();
	p = &obj2;

	p->fun();
	return 0;

}