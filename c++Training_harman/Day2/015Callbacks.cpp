#include<iostream>
using std::cout;
using std::endl;
namespace nm15
{
	template<typename T>
	void DoJob(T obj)
	{
		cout << "Apple for " << typeid(obj).name() << endl;
		obj();//callback 
		cout << "Orange" << endl;
		cout << "_______________________" << endl;
	}

	//---------------------
	class Func1
	{
		int x;
		int y;
	public:
		Func1(int x, int y) :x(x), y(y)
		{
		}
		//void operator()()//mutator
		void operator()() const //inpector
		{
			cout << "Client job done x=" << x << " y=" << y << endl;
		}
	};

	class Func2
	{
		int x;
		int y;
		int z;
	public:
		Func2(int x, int y, int z) :x(x), y(y), z(z)
		{
		}
		void operator()()//mutator
		//void operator()() const //inpector
		{
			cout << "Client job done x=" << x << " y=" << y << " z=" << z << endl;
		}
	};

	void main1()
	{
		int x = 10, y = 20, z = 30;//closure
		Func1 fn1(x, y);
		DoJob(fn1);
		Func2 fn2(x, y, z);
		DoJob(fn2);

	}

	void main3()
	{
		//type inference c++11
		auto x = 10;
		auto y = 20.78;
		auto z = 30.8f;
		decltype(y + x) a = 10;
		//lambda expression
		auto fn1 = []() { cout << "Here I am a functor" << endl; };
		DoJob(fn1);
		auto fn2 = [x, z]() { /*x++;//error because it is an inspector */ cout << "Here I am a new functor x=" << x << endl; };
		DoJob(fn2);
		auto fn3 = [x, z]() mutable {x++; cout << "Here I am a new functor x=" << x << endl; };
		DoJob(fn3);
		auto fn4 = [=]() mutable {x++; cout << "Here I am a new functor x=" << x << endl; };
		DoJob(fn4);
		auto fn5 = [&x]() {x++; cout << "Here I am a new functor x=" << x << endl; };
		DoJob(fn5);
		auto fn6 = [&]() {x++; cout << "Here I am a new functor x=" << x << endl; };
		DoJob(fn6);
		auto fn7 = [=, &x]() {x++; cout << "Here I am a new functor x=" << x << endl; };
		DoJob(fn7);
		auto fn8 = [&, x]() mutable {x++; cout << "Here I am a new functor x=" << x << endl; };
		DoJob(fn8);
	}
}