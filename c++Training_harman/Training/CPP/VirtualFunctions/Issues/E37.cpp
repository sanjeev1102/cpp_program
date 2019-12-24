#include<iostream>
using namespace std;

namespace Ex37
{
	struct IX
	{
		virtual void fun()=0;
	};
	void IX::fun()
	{
		cout<<"IX fun"<<endl;
	}
	//*****************************************************
	class CA : public IX
	{
	public:
		virtual void fun()	
		{
			IX::fun(); //call base class function

			cout<<"CA fun"<<endl;	
		}
	};
};
using namespace Ex37;

void main37()
{
	CA obj;
	obj.fun();
}
