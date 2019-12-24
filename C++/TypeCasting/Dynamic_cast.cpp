#include<iostream>
#include<vector>
#include <thread>
using namespace std;

class base
{
public:
	base(){}

	virtual void dummy() {}
};

class Derived : public base
{

public:

	Derived()
	{

	}

	void dummy() {}
};

int main()
{
	base bobj;
	
	Derived dobj;
	base* bptr = &dobj;
	Derived* dptr;

	dptr = dynamic_cast<Derived*>(bptr);
	if (dptr == 0)
	{
		cout << "NUlllllllllllll  1st cast,  base to derived cast" << endl;
	}
	bptr = dynamic_cast<base*> (&dobj);
	if (bptr == 0)
	{
		cout << "NUlllllllllllll   2nd cast derived to base cast" << endl;
	}

	return 0;

}