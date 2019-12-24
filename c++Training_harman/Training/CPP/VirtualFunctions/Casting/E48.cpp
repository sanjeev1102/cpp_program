#include<iostream>
#include<typeinfo>
using namespace std;

namespace Ex48
{
	struct IX
	{
		virtual void* GetVptr(const type_info& info)=0;
	};
	struct IY 
	{	
		virtual void* GetVptr(const type_info& info)=0;
	};
	struct SA : IX,IY
	{
		virtual void* GetVptr(const type_info& info)
		{
			if(typeid(IX) == info)
				return static_cast<IX*>(this); // + 0
			if(typeid(IY) == info)
				return static_cast<IY*>(this); // + 4
			return 0;
		}
	};
};
using namespace Ex48;

void main48()
{
	IX* px =static_cast<IX*>(new SA);

	IY* py = reinterpret_cast<IY*>( px->GetVptr(typeid(IY)) );	
}









