#include<iostream>
#include<string>
#include<vector>
#include<future>
#include<functional>
#include<list>
using namespace std;
//*************************************
class MyClass
{
public:
	MyClass(int x)
	{
		cout << "MyClass (int) param called ..." << endl;
	}
	MyClass(string x)
	{
		cout << "MyClass (string) param called ..." << endl;
	}
	MyClass(string x, int y)
	{
		cout << "MyClass (string,int) param called ..." << endl;
	}
};

class MyContainer
{
	MyClass mc;
public:
	template<typename... Args>
	MyContainer(Args&&... args)
		: mc(std::forward<Args>(args)...)
	{  }
};

void main_3_1()
{
	MyContainer t1(1);
	cout << "__________________" << endl;
	MyContainer t2("sachin");
	cout << "__________________" << endl;
	MyContainer t3("sachin", 909);
}
//****************************************
class SmartVector
{
	std::vector<std::string> _v;
public:

	template<typename... Args>
	SmartVector(Args&&... args)
		: _v(std::forward<Args>(args)...)
	{  }
	void Display()
	{
		for (auto x : _v)
		{
			cout << x << endl;
		}
	}
};

void main_3_2()
{
	const char * players[5] = { "sachin", "saurav", "rahul","sewag","dhoni" };

	SmartVector sv1(3, "Hi guys");
	sv1.Display();
	SmartVector sv2(players, players + 5);
	sv2.Display();
}

//*******************************Multi param forwarding***************
template<unsigned...> struct index_tuple{};

template<unsigned I, typename IndexTuple, typename... Types>
struct make_indices_impl;

template<unsigned I, unsigned... Indices, typename T, typename... Types>
struct make_indices_impl<I, index_tuple<Indices...>, T, Types...>
{
	typedef typename
	make_indices_impl<I + 1,
	index_tuple<Indices..., I>,
	Types...>::type type;
};

template<unsigned I, unsigned... Indices>
struct make_indices_impl<I, index_tuple<Indices...> >
{
	typedef index_tuple<Indices...> type;
};

template<typename... Types>
struct make_indices
	: make_indices_impl<0, index_tuple<>, Types...>
{};

class CForward
{
	std::vector<std::string> _v;
	std::list<double> _l;

public:

	template <typename... Args1,
		typename... Args2>
		CForward(std::tuple<Args1...> tuple1,
		std::tuple<Args2...> tuple2)
		: CForward(tuple1,
		tuple2,
		typename make_indices<Args1...>::type(),
		typename make_indices<Args2...>::type())
	{}

private:
	template <typename... Args1, typename... Args2, unsigned... Indices1, unsigned... Indices2>
	CForward(std::tuple<Args1...> tuple1, std::tuple<Args2...> tuple2, index_tuple<Indices1...>, index_tuple<Indices2...>)
		: _v(std::forward<Args1>(std::get<Indices1>(tuple1))...),
		_l(std::forward<Args2>(std::get<Indices2>(tuple2))...)
	{ }
public:
	void Display()
	{
		cout << "vector output ............." << endl;
		for (auto vt : _v)
		{
			cout << "\t" << vt;
		}
		cout << endl;
		cout << "list output ............." << endl;
		for (auto lst : _l)
		{
			cout << "\t" << lst;
		}
		cout << endl;
		cout << "_________________________________________________________________" << endl;
	}
};

void main_3_3()
{

	CForward b3(std::forward_as_tuple(5, "hyd"),
		std::forward_as_tuple(10, 99.99));
	// b3._v has 5 strings initialized to "C++ Truths" and
	// b3._l has 10 doubles initialized to 99.99
	b3.Display();
	CForward b4(std::forward_as_tuple(5),
		std::forward_as_tuple(10, 99.99));
	// b4._v has 5 empty strings and
	// b4._l has 10 doubles initialized to 99.99

	CForward b5(std::forward_as_tuple(),
		std::forward_as_tuple(10, 99.99));
	// b5._v is an empty vector 
	// b5._l has 10 doubles initialized to 99.99


}