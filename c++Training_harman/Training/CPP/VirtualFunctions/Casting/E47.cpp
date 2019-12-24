#include<iostream>
using namespace std;

//<-- loose coupling

// ------------- begning of library -----------------------------
namespace Ex47
{
	struct IX
	{
		virtual void fx()=0;
	};
	struct IY
	{
		virtual void fy()=0;
	};
	struct SA : IX,IY	
	{
		void fx() {}
		void fy() {}
	};
};
// ------------- end of library -----------------------------
using namespace Ex47;

void main47()
{
	IX* px =(IX*) new SA;	// upcast(+0)
	px->fx();

	IY* py=(IY*)(SA*) px;	//downcast(-0),upcast(+4) 

	py->fy();
}













