	#include<iostream>
using namespace std;

namespace Ex18
{
	class CA
	{
	public:
		virtual double  fx1(int value1,double value2)
		{
			return value1 + value2;
		}
	};
	class CB : public CA
	{
	};
	class CC : public CA
	{
	};
	class CD : public CB,public CC
	{
	};
}
using namespace Ex18;

void main18()
{
		cout<<sizeof(CD)<<endl;
}
