#include<iostream>
using namespace std;

namespace Ex12
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
	public:
		virtual double fx2(double value)
		{
			return value * 0.05;
		}
		virtual double fx3(int value)
		{
			return value / 3;
		}
	};
};
using namespace Ex12;

void main12()
{
	cout<<sizeof(CB)<<endl;
}
