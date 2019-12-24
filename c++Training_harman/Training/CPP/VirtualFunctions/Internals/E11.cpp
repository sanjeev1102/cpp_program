#include<iostream>
using namespace std;

namespace Ex11
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
	};
};
using namespace Ex11;

void main11()
{
	cout<<sizeof(CB)<<endl;
}
