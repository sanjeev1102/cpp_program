#include<iostream>
using namespace std;

namespace Ex60
{
	struct CA
	{
		int a;
		virtual void fa() {}
	};
	struct CB : virtual CA	
	{	
		int b;
		virtual void fb() {}
	};
	struct CC : virtual CA	
	{	
		int c;
		virtual void fc() {}
	};
	struct CD : CB,CC 
	{	
		int d;
		virtual void fd() {}
	};
};
using namespace Ex60;

void main60()
{
	cout<<sizeof(CD)<<endl;
}