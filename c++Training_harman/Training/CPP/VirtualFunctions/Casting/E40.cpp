#include<iostream>
using namespace std;

namespace Ex40
{
	struct SA	{
		int a;
	};
	struct SB	{	
		int b;
	};
	struct SC : SA,SB	{
	};
}; using namespace Ex40;
void main40()
{
	SC* pc =new SC;

	SA* pa = (SA*)pc;
	pa->a = 30;

	SB* pb = (SB*) pc;
	pb->b = 40; 

	cout<<pc->a<<endl;
	cout<<pc->b<<endl;
}













