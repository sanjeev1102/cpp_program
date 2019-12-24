#include<iostream>
using namespace std;

namespace Ex28
{
	class CA
	{
	public:
		virtual ~CA()		{			cout<<"CA dest"<<endl;		}
	};

	class CB : public CA
	{
	public:
		 ~CB()				{			cout<<"CB dest"<<endl;		} //CA::~CA()
	};
};
using namespace Ex28;

void main28()
{
	CA* pObj=new CB();
	//....
	delete pObj;
	/*
	pObj->vptr->vtable[0]();
	operator delete(pObj);
	*/
}
