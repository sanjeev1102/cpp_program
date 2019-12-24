#include<iostream>
#include<future>
using std::cout;
using std::endl;
namespace nm16
{
	template<typename T>
	void DoJob(T obj)
	{
		cout << "Apple for " << typeid(obj).name() << endl;
		obj();//callback 
		cout << "Orange" << endl;
		cout << "_______________________" << endl;
	}


	class CA
	{
		int x;
	public:
		CA(int x) :x(x)
		{
		}
		void fun1()
		{
			cout << "CA::fun1 x=" << x << endl;
		}
		void fun2()
		{
			cout << "CA::fun2 x=" << x << endl;
		}
	};
	using DLG = void(CA::*)();

	class Functor
	{
		CA &objRef;
		DLG dlg;
	public:
		Functor(CA &objRef, DLG dl) :objRef(objRef), dlg(dl)
		{
		}
		void operator()()
		{
			(objRef.*dlg)();
		}
	};

	void fun(int x, int y)
	{
		cout << "fun called with x=" << x << " and y=" << y << endl;
	}

	void main1()
	{
		CA obj1(100), obj2(200);
		DLG dl = &CA::fun2;
		Functor fn(obj1, dl);
		DoJob(fn);
		auto fn1 = std::bind(dl, obj2);
		DoJob(fn1);
		auto fn2 = std::bind(&fun, 10, 20);
		DoJob(fn2);
	}


	void DoJobNew(std::function<double(double)> obj)
	{
		cout << "Apple  " << endl;
		double d = obj(100.98);//callback 
		cout << "Orange d=" << d << endl;
		cout << "_______________________" << endl;
	}

	double Div1(double x, double y)
	{
		return x / y;
	}

	void main2()
	{
		using namespace std::placeholders;
		auto fn = std::bind(&fun, 200, _1);
		fn(45);
		//	DoJobNew(fn);
	}

	void main3()
	{
		using namespace std::placeholders;
		std::function<double(double)> fn = std::bind(&Div1, 20, _1);
		//cout << fn(20) << endl;
		DoJobNew(fn);
	}

	void main()
	{
		auto l1 = [](double j) {cout << "Pine j= " << j << endl; return 5.67; };
		DoJobNew(l1);
	}
}