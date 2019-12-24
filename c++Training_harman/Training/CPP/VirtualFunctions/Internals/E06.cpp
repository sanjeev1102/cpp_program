#include<iostream>
using namespace std;

namespace Ex6
{
	class CA
	{
	public:
		void fx1()
		{
			int data;
		}
		double fx2(double value)
		{
			return value * 0.02;
		}
	};
};
using namespace Ex6;

void main6()
{
	cout<<sizeof(CA)<<endl;
}
