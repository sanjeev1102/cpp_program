#include<iostream>
using namespace std;

namespace Ex43
{
	struct SA				{		int a;		};
	struct SB 				{		int b;	};
	struct SC : SA,SB
	{
	};
};
using namespace Ex43;

void main43()
{
	SB* pb =(SB*) new SC; // + 4
	pb->b = 30;		//mov pb +0 ,30

	SC* pc = (SC*) pb;	// - 4

	SA* pa = (SA*) pc;	// + 0
	pa->a = 40;		//mov pa + 0, 40

	cout<<pc->a<<endl;
	cout<<pc->b<<endl;
}













