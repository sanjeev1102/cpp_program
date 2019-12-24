#include<iostream>
using namespace std;

namespace Ex34
{
	struct IX
	{
		virtual void fun()=0;
	};
	struct IY 
	{
		virtual void fun()=0;
	};
	class CA : public IX, public IY
	{
	public:
		virtual void fun()	{	cout<<"SA fun"<<endl;	}
	};
}; using namespace Ex34;

void main34()
{
	CA* pa = new CA();
	IX *px = pa; 
	px->fun();
	IY* py = pa;	
	py->fun(); 
}













