#include<iostream>
using namespace std;

namespace Ex26
{
	class CA
	{
	public:
		~CA()		{			cout<<"CA dest"<<endl;		}
	};
	class CB : public CA
	{
	public:
		~CB()		{			cout<<"CB dest"<<endl;		}
	};
};
using namespace Ex26;

void main26()
{
	CA* pObj=new CB();
	//....
	delete pObj;
	/*
	pObj->CA::~CA();
	operator delete(pObj);
	*/
}
