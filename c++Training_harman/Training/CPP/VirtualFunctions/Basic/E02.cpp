#include<iostream>
using namespace std;

namespace Ex2
{
	class CA
	{
	public:
		virtual void f1()	{	cout<<"A f1"<<endl;	}
	};
	class CB : public CA
	{
	public:
		 void f1()				{	cout<<"B f1"<<endl;	}
	};
	class CC : public CB
	{
	public:
		void f1()	{	cout<<"C f1"<<endl;	}
	};
};
using namespace Ex2;

void main2()
{
	CC* pc = new CC();
	CA* pa = pc;
	CB* pb = pc;

	pa->f1();				
	pb->f1();				
	pc->f1();				
}

//pa->vptr->vtable[0]()
//pb->vptr->vtable[0]()
//pc->vptr->vtable[0]()