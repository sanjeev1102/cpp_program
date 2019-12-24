#include<iostream>
using std::cout;
using std::endl;

class CA
{
public:
	CA() = default;//c++11
	CA(int j)
	{
	}
	CA& operator=(const CA&) = delete;
	CA(const CA&) = delete;//c++11
	~CA() = default;

	double AddFun(double x, double y)
	{
		return x + y;
	}
	int AddFun(int x, int y) = delete;

	template<typename T>
	T SubFun(T x, T y) = delete;

	double SubFun(double x, double y)
	{
		return x - y;
	}
};

void main()
{
	CA obj;
	//CA obj1(obj);
	CA obj2;
	//obj = obj2;
	obj2.AddFun(12.3, 4.5);
	//obj2.AddFun(1, 2);
}