#include<iostream>
#include<string>
using namespace std;

struct BasicStruct {
	int x;
	double y;
	void operator()()
	{
		cout << "x=" << x << endl;
		cout << "y=" << y << endl;
	}
};

struct AltStruct {
	AltStruct(int x, double y) : x_{ x }, y_{ y } 
	{
		cout << "param ctor AltStruct.." << endl;
	}
	void operator()()
	{
		cout << "x=" << x_ << endl;
		cout << "y=" << y_ << endl;
	}
private:
	int x_;
	double y_;
};

//void main()
void main2_2_1()
{
	BasicStruct var1{ 5, 3.2 };
	var1();
	AltStruct var2{ 2, 4.3 };
	
	var2();
}