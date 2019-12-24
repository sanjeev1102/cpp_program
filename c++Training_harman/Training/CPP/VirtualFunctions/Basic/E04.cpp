#include<iostream>
using namespace std;

//will virtual function ork in Struct

namespace Ex4
{
	struct SA
	{
		virtual void f1()	{	cout<<"CA f1"<<endl;	}
	};
	struct SB : SA
	{
		void f1()	{	cout<<"CB f1"<<endl;	}
	};
	struct SC : SB
	{
		void f1()	{	cout<<"CC f1"<<endl;	}
	};
};
using namespace Ex4;

void main4()
{
	SA* pa= new SC();
	
	pa->f1();				
}