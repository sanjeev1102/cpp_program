#include<iostream>
using namespace std;

namespace Ex30
{
	class CA
	{
	public:
		CA()
		{
			fx1();
		}
		virtual void fx1()		{			cout<<"CA fx1"<<endl;		}
	};

	class CB : public CA
	{
	public:
		virtual void fx1()		{			cout<<"CB fx1"<<endl;		}
	};
};
using namespace Ex30;

void main30()
{
	CB obj;
}
