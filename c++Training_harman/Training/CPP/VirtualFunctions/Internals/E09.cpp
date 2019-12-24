#include<iostream>
using namespace std;

namespace Ex9
{
	class CA
	{
	public:
		virtual void fx1()
		{
		}
		virtual void fx2()
		{
		}
	};
};using namespace Ex9;

void main9()
{
	CA* pobj = new CA();

	long* vptr = (long*) pobj;

	long* vtable = (long*) *vptr;

	typedef void(*FUNPTR)();

	FUNPTR pfun = (FUNPTR) vtable[1];

	pfun();
}