#include <optional>
#include <iostream>
#include<string>
using namespace std;
namespace nm29
{
	optional<string> fun1(int k)//c++17
	{
		if (10 == k)
			return "Sachin";
		return {};//nullopt
	}
	optional<string> fun2(int k)//c++17
	{
		if (10 == k)
			return "Sachin";
		return nullopt;
	}
	void main()
	{
		cout << fun1(10).value_or("Harman India") << endl;
		cout << fun1(20).value_or("Harman Korea") << endl;
		cout << fun2(10).value_or("Harman Marathahalli") << endl;
		cout << fun2(20).value_or("Harman Prestige") << endl;
	}
}