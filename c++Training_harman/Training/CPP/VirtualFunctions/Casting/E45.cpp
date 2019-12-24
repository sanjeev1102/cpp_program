#include<iostream>
using namespace std;

namespace Ex45
{
	struct SA
	{
		int a;
		virtual ~SA(){} //<-- vtable is a must for rtti to work
	};
	struct SB 
	{	
		int b;
		virtual ~SB(){}
	};
	struct SC : SA,SB
	{
	};
};
using namespace Ex45;

void main45()
{
	SA* pa =static_cast<SA*>(new SC);
	pa->a = 30;

	SC* pc = dynamic_cast<SC*>(pa);

	SB* pb = static_cast<SB*>(pc);
	pb->b = 40;

	cout<<pc->a<<endl;
	cout<<pc->b<<endl;
}













