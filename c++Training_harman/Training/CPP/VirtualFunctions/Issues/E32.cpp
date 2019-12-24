#include<iostream>
using namespace std;

namespace Ex32
{
	class CA
	{
	public:
		virtual void fx1()		{			cout<<"CA fx1"<<endl;		}
		~CA()
		{
			fx1();
		}
	};
	class CB : public CA
	{
	public:
		virtual void fx1()		{			cout<<"CB fx1"<<endl;		}
	};
};
using namespace Ex32;

void main32()
{
	CB obj;
}//
