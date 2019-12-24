#include<iostream>
using namespace std;

namespace Ex57
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
	struct CD : CB,CC {	};
};
using namespace Ex57;

void main57()
{
	cout<<sizeof(CD)<<endl;
}