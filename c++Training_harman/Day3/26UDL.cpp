#include<iostream>
using namespace std;

namespace nm26
{
	constexpr long double operator "" _rad(long double deg)
	{
		return deg*3.14159 / 180.0;
	}

	void main()
	{
		double radians = 90.0_rad;

		cout << radians << endl;


	}
}