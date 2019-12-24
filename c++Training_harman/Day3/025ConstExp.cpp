#include<iostream>
using namespace std;

namespace nm25
{
	template<typename T, int size>
	class CA
	{
		T arr[size];

	};


	constexpr unsigned long fun(int x)//c++11
	{
		if (x == 10)//c++14
			return 5;
		return 3;
	}

	void main1()
	{
		CA<int, fun(10)> obj1;
		CA<double, fun(2)> obj2;

		int arr[fun(3)];
	}
	//old way
	template<unsigned n>
	struct Fib
	{
		static const unsigned value = Fib<n - 1>::value + Fib<n - 2>::value;
	};

	template<>
	struct Fib<0>
	{
		static const unsigned value = 0;
	};

	template<>
	struct Fib<1>
	{
		static const unsigned value = 1;
	};

	void main()
	{
		int arr[Fib<5>::value];
		const int i = Fib<5>::value;
		cout << "i=" << i << endl;
	}
}