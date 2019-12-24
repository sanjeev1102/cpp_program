#include<iostream>
using namespace std;

namespace Ex33
{
	class CA
	{
	public:
		virtual void fx1()
		{
			cout<<"CA fx1"<<endl;
		}
		~CA() //:ca_vptr(ca_vtable) 
		{
			fx1();
		}
	};

	class CB : public CA
	{
	public:
		virtual void fx1()
		{
			cout<<"CB fx1"<<endl;
		}
//		~CB():cb_vptr(cb_vtable){}CA::~CA()
	};
};

using namespace Ex33;

void main33()
{
	CB obj; 
}//obj.CB::~CB();
