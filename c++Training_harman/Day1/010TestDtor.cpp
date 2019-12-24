#include<iostream>
using std::cout;
using std::endl;

class CA
{
public:
	CA()
	{
		cout << "CA ctor" << endl;
	}
	~CA()
	{
		cout << "CA D-tor" << endl;
		delete this;
	}
	static void* operator new(std::size_t size)
	{
		cout << "CA::operator new called " << endl;
		return malloc(size);
	}
	static void operator delete(void *pv)
	{
		cout << "CA::operator delete called " << endl;
		free(pv);
	}
};

void main()
{
	CA* ptr= new CA();
	delete ptr;
}