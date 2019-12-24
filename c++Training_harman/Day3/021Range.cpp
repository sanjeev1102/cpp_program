#include<iostream>
using namespace std;

namespace nm21
{
	void main()
	{
		int arr[] = { 11,22,33,44,55 };

		for (int & val : arr)//range based loop c++11
		{
			val *= 10;
		}
		for (auto x : arr)
		{
			cout << x << endl;
		}
		cout << "_________________" << endl;
		for each (int y in arr)
		{
			cout << y << endl;
		}
	}
}