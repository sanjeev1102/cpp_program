#include<iostream>
#include<string>
using namespace std;
template<class T>
struct Check  {
    static_assert(sizeof(int) <= sizeof(T), "T is not big enough!");
};
template<class Integral>
Integral foo(Integral x, Integral y) {
	static_assert(std::is_integral<Integral>::value, "foo() parameter must be an integral type.");
}

void main23_1()
{
	Check<int> obj;
//	auto str=foo("sachin", "saurav");
}