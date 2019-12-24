#include<iostream>
using namespace std;
namespace nm24
{
	template<typename T>
	class CA
	{
	public:
		using Type = T; //template alias  c++11
		CA(T x)
		{
			cout << "x type=" << typeid(x).name() << " x=" << x << endl;
		}
	};

	template<typename T>
	T CreateT(typename T::Type x)
	{
		cout << "t1=" << typeid(x).name() << endl;
		//additional businesss
		return T(x);
	}

	void main()
	{
		CA<int> obj = CreateT<CA<int>>(100);//c++11
		CA<double> obj1 = CreateT<CA<double>>(90);//c++11
	}
}