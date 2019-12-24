#include<iostream>
using namespace std;

namespace Ex17
{
	class CA
	{
	public:
		virtual double  fx1(int value1,double value2)
		{
			return value1 + value2;
		}
		virtual double fx2(double value)
		{
			return value * 0.02;
		}
	};
	class CB
	{
	public:
		virtual double fx3(int value)
		{
			return value / 3;
		}
		virtual void fx4()
		{
		}
	};
	class CC : public CA, public CB
	{
	};
};
using namespace Ex17;

void main17()
{
	CA* pobj = new CC();

	long* vptr = (long*) pobj;
	vptr++;

	long* vtable = (long*) *vptr;

	typedef void(*FUNPTR)();
	FUNPTR pfun = (FUNPTR) vtable[2];
	pfun();
}