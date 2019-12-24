#include<iostream>
using namespace std;

namespace Ex22
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
 	void DoJob(CA* pObj)
	{
		pObj->fx1();
	}
};
using namespace Ex22;

void main22()
{
	CB obj;
	DoJob(&obj);
}
