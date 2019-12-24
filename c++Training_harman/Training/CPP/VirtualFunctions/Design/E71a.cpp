#include<iostream>
using namespace std;

namespace Ex71a
{
	struct Emp
	{
		virtual void dojob()	=0;
	};
	struct Manager : Emp
	{
		virtual void dojob()	{ cout<<"manager dojob"<<endl;	}
	};
	struct Tester : Emp
	{
		virtual void dojob()	{ cout<<"tester dojob"<<endl;	}
	};
	Emp* create(int data) 
	{
		if(data < 10)
				return new Manager();
		if((data >= 10) && (data <20))
				return new Tester();
	}
};using namespace Ex71a;

void main71a()
{
	Emp* emp = create(15);

	emp->dojob(); 
}



