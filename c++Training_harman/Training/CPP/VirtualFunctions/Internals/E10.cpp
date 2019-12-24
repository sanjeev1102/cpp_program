#include<iostream>
using namespace std;

namespace Ex10
{
	class CA
	{
	public:
		virtual double  fx1(int value1,double value2)
		{
			return value1 + value2;
		}
		virtual double fx2(double value)
		{
			return value * 0.02;
		}
	};
	class CB : public CA
	{
	};
};
using namespace Ex10;

void main10()
{
	cout<<sizeof(CB)<<endl;
}
