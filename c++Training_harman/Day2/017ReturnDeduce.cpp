#include<iostream>
#include<future>
#include<string>
using std::cout;
using std::endl;
namespace nm17
{
	//return type deduce

	auto fun(int x)//auto deduce intrdoducedd c++14 onwards
	{
		if (10 == x)
			return 100;
		return 200;
	}

	//auto fun1(int x)->int//auto deduce intrdoducedd c++11 onwards
	//self reading
	//auto
	//auto&
	//auto&&
	//decltype(auto)
	auto fun1(int x)->decltype(fun(10))//auto deduce intrdoducedd c++11 onwards
	{
		if (10 == x)
			return 100;
		return 200.90;
	}
	//compile time assertion
	static_assert(std::is_same<int, decltype(fun(10))>(), "Does not match");//c++ 11 onwards
	//static_assert(std::is_same<double, decltype(fun(10))>(), "Does not match");
	//static_assert(std::is_same<double, decltype(fun(10))>());//c++ 17 onwards


	//currying
	//using std::string;
	//auto Greet(string msg)
	//{
	//	//business 1
	//	return [msg](string sep) {
	//		//business 2
	//		return [=](string name) {
	//			//business 3
	//			cout << "Mr." + name + sep + msg<<endl;
	//		};
	//	};
	//}

	//currying
	using std::string;

	auto Greet(string msg)->std::function<std::function<void(string)>(string)>
	{
		//business 1
		return [msg](string sep)->std::function<void(string)> {
			//business 2
			return [=](string name) {
				//business 3
				cout << "Mr." + name + sep + msg << endl;
			};
		};
	}



	void main1()
	{
		Greet("Welcome")("--->")("Sewag");
		auto nam = Greet("Namaskara")("****");
		nam("Jayalalitha");
		nam("Rajinikanth");
		nam("Arjun");
	}
	//generic lambda from c++14 onwards
	auto fun10([](auto x, auto y) {return x + y; });

	void main()
	{
		cout << fun10(10, 20) << endl;
		cout << typeid(fun10(10, 20)).name() << endl;
		cout << typeid(fun10(10.14, 20.24)).name() << endl;
	}
}