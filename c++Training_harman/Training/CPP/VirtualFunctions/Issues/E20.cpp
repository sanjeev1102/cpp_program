#include<iostream>
using namespace std;

namespace Ex20
{
	class CA
	{
	public:
		virtual void fx1()		{			cout<<"CA fx1"<<endl;		}
	};
	class CB : public CA
	{
	public:
		virtual void fx1()		{			cout<<"CB fx1"<<endl;		}
	};
	void DoJob(CA obj) 
	{
		obj.fx1();
	}
}; using namespace Ex20;

void main20()
{
	CB obj;
	DoJob(obj);
}
