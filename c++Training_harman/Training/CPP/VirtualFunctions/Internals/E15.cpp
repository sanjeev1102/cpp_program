#include<iostream>
using namespace std;

namespace Ex15
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
	class CB
	{
	public:
		virtual double fx3(int value)
		{
			return value / 3;
		}
		virtual void fx4()
		{
		}
	};
	class CC : public CA, public CB
	{
	public:
		virtual void fx5()
		{
		}
	};
};
using namespace Ex15;

void main15()
{
	CA* p = new CC;
}
