#include<iostream>
#include<string>
using namespace std;
//*****************************************************************
template<typename T1>
auto AddFun(T1 x, T1 y) ->int
{
	return x + y;
}

void main7_1()
{
	auto res = AddFun(12, 34);
	cout << "type of res=" << typeid(res).name() << endl;
	cout << "res=" << res << endl;
}
//******************************************************************

template<typename T1>
auto AddFunEx(T1 x, T1 y) ->T1
{
	return x + y;
}

void main7_2()
{
	auto res2 = AddFunEx<string>("sachin", " tendulkar");
	cout << "type of res2=" << typeid(res2).name() << endl;
	cout << "res2=" << res2 << endl;
	cout << "_____________________________" << endl;
	auto res1 = AddFunEx(12.3, 10.1);
	cout << "type of res2=" << typeid(res1).name() << endl;
	cout << "res2=" << res1 << endl;

}
//************************************************************************

