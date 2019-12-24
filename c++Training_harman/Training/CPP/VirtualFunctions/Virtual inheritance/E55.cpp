#include<iostream>
using namespace std;

namespace Ex55
{
	struct CA
	{
		int a;
	};
	struct CB : CA	{	};
	struct CC : CA	{	};
	struct CD : CB,CC {	};
};
using namespace Ex55;

void main55()
{
	cout<<sizeof(CD)<<endl;
}