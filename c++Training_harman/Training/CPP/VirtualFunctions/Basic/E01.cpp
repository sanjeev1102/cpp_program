#include<iostream>
using namespace std;

namespace Ex1
{
	struct CA
	{
		void f1()	{	cout<<"A"<<endl;	}
	};
	struct CB : CA
	{
		void f1()	{	cout<<"B"<<endl;	}
	};
	struct CC : CB
	{
		void f1()	{	cout<<"C"<<endl;	}
	};
}; using namespace Ex1;
void main1()
{
	CC* pc = new CC();
	CA* pa = pc;
	CB* pb = pc;
	pa->f1();					
	pb->f1();				
	pc->f1();				
}
	