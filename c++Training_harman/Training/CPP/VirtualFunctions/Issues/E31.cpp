#include<iostream>
using namespace std;

namespace Ex31
{
	class CA
	{
//		static FUNPTR ca_vtable[];
	public:
//		FUNPTR ca_vptr;
		CA() //:ca_vptr(ca_vtable) 
		{
			fx1();
		}
		virtual void fx1()		{			cout<<"CA fx1"<<endl;		}
	};

	class CB : public CA
	{
//		static FUNPTR cb_vtable[];
	public:
//		CB():CA(),cb_vptr(cb_vtable){}

		virtual void fx1()		{			cout<<"CB fx1"<<endl;		}
	};
//  FUNPTR CB::cb_vtable[] = {CB::fx1,CB::fx2};
};

using namespace Ex31;

void main31()
{
	CB obj; //obj.CB::CB();
}
