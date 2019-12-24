#include<iostream>
using namespace std;

namespace Ex70
{
	struct Emp
	{
		Emp(int data) {}
		virtual void dojob()	{ cout<<"emp dojob"<<endl;		}
	};
	struct Manager : Emp
	{
		virtual void dojob()	{ cout<<"manager dojob"<<endl;	}
	};
	struct Tester : Emp
	{
		virtual void dojob()	{ cout<<"tester dojob"<<endl;	}
	};
};
using namespace Ex70;

void main70()
{
	Emp* emp = new Emp(12);
	emp->dojob(); 
}