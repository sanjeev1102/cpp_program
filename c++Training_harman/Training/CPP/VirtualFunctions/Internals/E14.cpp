#include<iostream>
using namespace std;

namespace Ex14
{
	class CA
	{
	public:
		double  fx1(int value1,double value2)
		{
			return value1 + value2;
		}
		double fx2(double value)
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
using namespace Ex14;

void main14()
{
	cout<<sizeof(CB)<<endl;
}
