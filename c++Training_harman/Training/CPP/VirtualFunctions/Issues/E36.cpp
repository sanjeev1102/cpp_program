#include<iostream>
using namespace std;

namespace Ex36
{
	struct IX
	{
		virtual void fun()=0;
	};
	//*****************************************************
	class CA : public IX
	{
	public:
		virtual void fun()	
		{
			//IX::fun(); //<--- call base class function
			cout<<"CA fun"<<endl;	
		}
	};
};
using namespace Ex36;

void main36()
{
	CA obj;
	obj.fun();
}