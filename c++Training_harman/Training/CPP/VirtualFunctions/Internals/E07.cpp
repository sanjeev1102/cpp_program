#include<iostream>
using namespace std;

namespace Ex7
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
};
using namespace Ex7;

void main7()
{
	cout<<sizeof(CA)<<endl;
}
