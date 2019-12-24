#include<iostream>
using namespace std;

namespace Ex13
{
	class CA
	{
/*
		static FUNPTR ca_vtable[];
		FUNPTR ca_vptr;

		CA():ca_vptr(ca_vtable)		{		}
*/	
	};
//  FUNPTR CA::ca_vtable[] = {CA::fx1,CA::fx2};

	class CB : public CA
	{
/*
		static FUNPTR cb_vtable[];
		
		CB():ca_vptr(cb_vtable)		{		}
*/
	};
//  FUNPTR CB::cb_vtable[] = {CB::fx1,CB::fx2,CB::fx3};
}
using namespace Ex13;

void main13()
{
	CA* p = new CB();

	//p->fx1(10,2056.67);		//p->vptr->vtable[0](10,2056.67);
	//p->fx2(234.56);			//p->vptr->vtable[1](234.56);
}
