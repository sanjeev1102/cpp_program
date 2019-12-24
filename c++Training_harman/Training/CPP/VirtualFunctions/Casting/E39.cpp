#include<iostream>
using namespace std;

namespace Ex39
{
	struct SA				{	int a;		};
	struct SB 				{	int b;	};
	struct SC : SA,SB	{				};
};using namespace Ex39;

void main39()
{
	SC* pc =new SC;

	SA* pa = (SA*) pc;
	pa->a = 30;

	SB* pb = (SB*) pa;
	pb->b = 40;

	cout<<pc->a<<endl;
	cout<<pc->b<<endl;
}













