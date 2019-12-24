#include<iostream>
using namespace std;

namespace Ex29
{
	class CA
	{
	public:
		virtual void fx1()		{			cout<<"CA fx1"<<endl;		}
		virtual void fx2()		{			cout<<"CA fx2"<<endl;		}
		
		void fun()
		{
				CA::fx1();	
			CA::fx2();	
		}
	};
	class CB : public CA
	{
	public:
		virtual void fx1() 		{			cout<<"CB fx1"<<endl;		}
		virtual void fx2() 		{			cout<<"CB fx2"<<endl;		}
	};
};using namespace Ex29;
void main29()
{
	CB obj;
	obj.fun();
}
