#include<iostream>
using namespace std;

namespace Ex41
{
	struct SA				{		int a;		};
	struct SB 				{		int b;	};
	struct SC : SA,SB	{					};
};
using namespace Ex41;

void main41()
{
	SC* pc =new SC;

	SA* pa = (SA*) pc;//+0
	pa->a = 30;

	SB* pb = (SB*) pc; //+4
	pb->b = 40;

	cout<<pc->a<<endl;
	cout<<pc->b<<endl;
}













