#include<iostream>
#include<tuple>
using namespace std;

namespace nm27
{
	class CA
	{
	public:
		int x = 10;
		int y = 20;

		CA(int x, int y) :x(x), y(y)
		{
		}
		void Display()
		{
			cout << "x=" << x << endl;
			cout << "y=" << y << endl;
		}
	};

	auto fun()
	{
		//123
		return tuple<int, float, double, char>(10, 1.f, 3.4, 'c');
	}

	void main1()
	{
		tuple<int, float, double, char> t = fun();
		cout << std::get<0>(t) << endl;
		cout << std::get<3>(t) << endl;

		int i;
		char c;
		std::tie(i, std::ignore, ignore, c) = t;// fun();//object destructuring
		cout << "i=" << i << endl;
		cout << "c=" << c << endl;

		int x = 10, y = 20;
		tie(x, y) = make_tuple(y, x);
		cout << "x=" << x << endl;
		cout << "y=" << y << endl;


	}


	CA fun1()
	{
		return { 1,2 };//type not specified c++11
	}

	void main2()
	{
		CA obj1 = fun1();
		obj1.Display();

	}


	void main3()
	{
		CA obj1 = fun1();
		auto[i, j] = obj1;//structured binding c++17 onwards

		i += 100;
		j += 200;
		cout << "i=" << i << endl;
		cout << "j=" << j << endl;
		obj1.Display();
	}


	void main4()
	{
		auto x = 10'00'0'0'00'00'0'00'00;//digit seperator c++14 onwards
		auto y = 400'000'000'00'000'000;

		auto z = 0b101;
		auto s = 0xA;

		cout << typeid(x).name() << endl;
		cout << y << endl;
		cout << z << endl;
		cout << s << endl;
	}

	void main5()
	{
		cout << sizeof(CA::x) << endl;//c++11
	}


	class CB
	{
		int x;
		int y;
	public:
		CB()
		{
			cout << "this=" << this << endl;
		}
		void * operator&()
		{
			return &y;
		}


	};

	void main6()
	{
		CB obj;
		cout << addressof(obj) << endl;
		cout << "&obj=" << &obj << endl;

	}
}