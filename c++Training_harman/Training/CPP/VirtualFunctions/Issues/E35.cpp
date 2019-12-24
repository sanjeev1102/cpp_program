#include<iostream>
#include<typeinfo>
using namespace std;

namespace Ex35
{
	struct IX
	{
		virtual void fun()=0;
	};
	struct IY 
	{
		virtual void fun()=0;
	};
	//***************************************************
	class _IX : public IX
	{
	public:
			virtual void fun()	{	cout<<"SA IX fun"<<endl;	}
	};
	class _IY : public IY
	{
	public:
		virtual void fun()	{	cout<<"SA IY fun"<<endl;	}
	};
	//***************************************************
	struct CA : public _IX, public _IY
	{
	};
};
using namespace Ex35;

void main35()
{
	CA* pa = new CA();

	IX *px = pa; 
	px->fun();
	
	IY* py = pa;	
	py->fun(); 
}













