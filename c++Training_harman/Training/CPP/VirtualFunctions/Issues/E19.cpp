#include<iostream>
using namespace std;

namespace Ex19
{
	struct  CA
	{
		void fx1()				{			cout<<"CA fx1"<<endl;		}
	};
	struct  CB : CA
	{
		virtual void fx1()		{			cout<<"CB fx1"<<endl;		}
	};
	void DoJob(CA* pObj)
	{
		pObj->fx1();
	}
};using namespace Ex19;

void main19()
{
	CB* pObj=new CB();
	DoJob(pObj);
	delete pObj;
}
