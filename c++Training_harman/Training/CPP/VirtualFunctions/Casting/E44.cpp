#include<iostream>
using namespace std;

namespace Ex44
{
	struct SA
	{
		int a;
	};
	struct SB 
	{	
		int b;
	};
	struct SC : SA,SB
	{
	};
};
using namespace Ex44;

void main44()
{
	SA* pa =static_cast<SA*>(new SC);
	pa->a = 30;

	SC* pc;// = dynamic_cast<SC*>(pa);

	SB* pb = static_cast<SB*>(pc);
	pb->b = 40;

	cout<<pc->a<<endl;
	cout<<pc->b<<endl;
}













