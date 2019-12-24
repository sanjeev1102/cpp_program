#include<iostream>
#include<tuple>
#include<string>
using namespace std;


void main27_1()
{

	tuple<int, float, string> t(1, 2.f, "sachin");
	int x = get<0>(t);
	float y = get<1>(t);
	string z = get<2>(t);
	cout << "x=" << x << endl;
	cout << "y=" << y << endl;
	cout << "z=" << z << endl;
}
//*************************************************************
void main27_2()
{
	int myint;
	char mychar;
	tuple<int, float, char> mytuple;
	// packing values into tuple 
	mytuple = make_tuple(10, 2.6, 'a');
	// unpacking tuple into variables
	std::tie(myint, std::ignore, mychar) = mytuple;
	cout << "myint=" << myint << endl;
	//cout << "y=" << y << endl;
	cout << "mychar=" << mychar << endl;
}


void main27_3()
{
	int a = 5;
	int b = 6;
	std::tie(b, a) = make_tuple(a, b);
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
}


void main27_4()
{

}