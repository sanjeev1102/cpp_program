#include<iostream>
#include<string>
using namespace std;
namespace nm15
{
	template<typename T1, typename T2>
	void DoJob(T1 x, T2  y)
	{
		x(y);
	}

	void Increment(int & i)
	{
		i++;
	}

	void main()
	{
		int a = 10;
		DoJob(Increment, std::ref(a));
		cout << "a=" << a << endl;
	}
}  