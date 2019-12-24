#include<iostream>
#include<string>
using namespace std;

//void main()
void main8()
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	for (auto i = arr[0]; i<5; i++)
	{
		cout << "arr[" << i << "]=" << arr[i] << endl;
	}
	//*****************************
	auto x = 100;
	auto y = x;
	decltype(x) z = x;

	cout << "type of x=" << typeid(x).name() << " value of x is " << x << endl;
	cout << "type of y=" << typeid(y).name() << " value of y is " << y << endl;
	cout << "type of z=" << typeid(z).name() << " value of z is " << z << endl;
	//*****************************
	auto x1 = 100;
	auto y1 = 3.78;
	decltype(x1*y1) z1 = 4.5;

	cout << "type of x1=" << typeid(x1).name() << " value of x1 is " << x1 << endl;
	cout << "type of y1=" << typeid(y1).name() << " value of y1 is " << y1 << endl;
	cout << "type of z1=" << typeid(z1).name() << " value of z1 is " << z1 << endl;


}
