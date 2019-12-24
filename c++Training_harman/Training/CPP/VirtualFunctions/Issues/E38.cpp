#include<iostream>
using namespace std;

namespace Ex38
{
	class __declspec(novtable) CA
	{
	public: 
		virtual void fun()=0;
	};
	class CB : public CA
	{
	public:
		virtual void fun()	
		{
			//IX::fun(); //call base class function
			cout<<"CB fun"<<endl;	
		}
	};
};using namespace Ex38;

void main38()
{
	CB obj;
	obj.fun();
}
