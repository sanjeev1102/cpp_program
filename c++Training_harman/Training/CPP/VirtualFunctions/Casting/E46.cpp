#include<iostream>
using namespace std;

//<-- loose coupling

// ------------- begning of library -----------------------------
namespace Ex46
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
		void fx() {	cout<<"fx fun"<<endl;		}
		void fy() {	cout<<"fy fun"<<endl;		}
	};

	IX* create()
	{
		return new SA;
	}
};
// ------------- end of library -----------------------------
using namespace Ex46;

void main46()
{
	IX* px =create();
	px->fx();

	IY* py= (IY*)px;

	py->fy();
}













