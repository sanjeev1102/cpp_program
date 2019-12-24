#include<iostream>
using namespace std;

namespace Ex59
{
	struct CA
	{
		int a;
		virtual void fa() {}
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
};using namespace Ex59;

void main59()
{
	cout<<sizeof(CD)<<endl;
}