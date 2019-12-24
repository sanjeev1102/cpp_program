#include<iostream>
using namespace std;

namespace Ex3
{
	class CA
	{
	public:
		 void f1()			{	cout<<"A"<<endl;	}
	};
	class CB : public CA
	{
	public:
		virtual void f1()	{	cout<<"B"<<endl;	}
	};
	class CC : public CB
	{
	public:
		void f1()				{	cout<<"C"<<endl;	}
	};
};
using namespace Ex3;

void main3()
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