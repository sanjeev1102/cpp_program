#include<iostream>
using namespace std;

namespace Ex42
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
using namespace Ex42;

void main42()
{
	SC* pc =new SC;

	SA* pa = static_cast<SA*>(pc); // + 0
	pa->a = 30;

	SB* pb = static_cast<SB*>(pc);// + 4
	pb->b = 40;

	cout<<pc->a<<endl;
	cout<<pc->b<<endl;
}













