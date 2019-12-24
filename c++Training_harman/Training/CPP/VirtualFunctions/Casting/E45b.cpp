#include<iostream>
using namespace std;

namespace Ex45b
{
	struct SX{
		virtual void fx1()	{	cout<<"sx fx1"<<endl;	}
		virtual void fx2()	{	cout<<"sx fx2"<<endl;	}
	};
	struct SY{
		virtual void fy1()	{	cout<<"sy fy1"<<endl;	}
		virtual void fy2()	{	cout<<"sy fy2"<<endl;	}
	};
	struct SA : SX,SY{
		virtual void fx1()	{	cout<<"sa fx1"<<endl;	}
		virtual void fy2()	{	cout<<"sa fy2"<<endl;	}
	};
};using namespace Ex45b;
void main45b()
{
	SX* px =new SA; //+ 0
	px->fx1();			//px->vptr->vtable[0]();
	px->fx2();			//px->vptr->vtable[1]();

	SY* py= (SY*)(SA*)px; 
	py->fy1();			//py->vptr->vtable[0]();
	py->fy2();			//py->vptr->vtable[1]();
}













