#include<iostream>
using namespace std;

namespace Ex27
{
	class CA
	{
	public:
		~CA()		{			cout<<"CA dest"<<endl;		}
	};

	class CB : public CA
	{
	public:
		virtual ~CB()		{			cout<<"CB dest"<<endl;		}
	};
};
using namespace Ex27;

void main27()
{
	CA* pObj=new CB();
	//....
	delete pObj;
}
