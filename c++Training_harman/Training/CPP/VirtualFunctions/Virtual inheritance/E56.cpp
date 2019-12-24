#include<iostream>
using namespace std;

namespace Ex56
{
	struct CA
	{
		int a;
	};
	struct CB : virtual CA	{	};
	struct CC : virtual CA	{	};
	struct CD : CB,CC {	};
};
using namespace Ex56;

void main56()
{
	cout<<sizeof(CD)<<endl;
}