#include<iostream>
using namespace std;

namespace Ex21
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
	void DoJob(CA& obj)
	{
		obj.fx1();
	}
};

using namespace Ex21;

void main21()
{
	CB obj;
	DoJob(obj);
}
