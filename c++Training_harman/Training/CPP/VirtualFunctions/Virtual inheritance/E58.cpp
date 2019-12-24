#include<iostream>
using namespace std;

namespace Ex58
{
	struct CA
	{
		int a;
	};
	struct CB : virtual CA	
	{	
		virtual void fb() {}
	};
	struct CC : virtual CA	
	{	
		virtual void fc() {}
	};
	struct CD : CB,CC 
	{	
		virtual void fd() {}
	};
};
using namespace Ex58;

void main58()
{
	cout<<sizeof(CD)<<endl;
}