#include<iostream>
using std::cout;
using std::endl;
namespace nm19
{
	constexpr long double operator"" _rad(long double deg)
	{
		return deg*3.14159 / 180.0;
	}

	void main1()
	{

		double angle = 90.0_rad;

		cout << angle << endl;
	}
}