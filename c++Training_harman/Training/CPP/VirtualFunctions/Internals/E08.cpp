#include<iostream>
using namespace std;

namespace Ex8
{
	class CA
	{
//		static FUNPTR ca_vtable[];
	public:
//		FUNPTR ca_vptr;
//		CA():ca_vptr(ca_vtable){}

		virtual double  fx1(int value1,double value2)
		{
			return value1 + value2;
		}
		virtual double fx2(double value)
		{
			return value * 0.02;
		}
	};
};
//  FUNPTR CA::ca_vtable[] = {CA::fx1,CA::fx2};
using namespace Ex8;

void main8()
{
	CA* p = new CA();

	p->fx1(10,2056.67);		//p->vptr->vtable[0](10,2056.67);
	p->fx2(234.56);			//p->vptr->vtable[1](234.56);
}