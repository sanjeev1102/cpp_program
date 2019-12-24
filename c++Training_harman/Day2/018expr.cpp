#include<iostream>
using std::cout;
using std::endl;
namespace nm18
{
	constexpr int fun(int x)//c++11 onwards
	{
		if (10 == x)//c++14 relaxed const expr
			return 10;
		return 20;
	}
	template<typename T, int size>
	class CA
	{

	};

	void main()
	{
		CA<int, fun(10)> obj1;
		int arr[fun(11)];


	}
}