#include<iostream>
#include<typeinfo>
using namespace std;

namespace Ex49
{
	struct IX
	{
		virtual void* GetVptr(int id)=0;
	};
	struct IY 
	{	
		virtual void* GetVptr(int id)=0;
	};
	struct SA : IX,IY
	{
		virtual void* GetVptr(int id)
		{
			if(id == 1)
				return static_cast<IX*>(this); // + 0
			if(id == 2)
				return static_cast<IY*>(this); // + 4
			return 0;
		}
	};
};
using namespace Ex49;

void main49()
{
	IX* px =static_cast<IX*>(new SA);

	IY* py = reinterpret_cast<IY*>( px->GetVptr(2) );	
}
	