#include<iostream>
#include<string>
using namespace std;
class CB
{
public:
	int x;
	int y;
	CB(int x, int y) :x(x), y(y)
	{
	}
};
class CA {
	int x = 7; //class member initializer 
	//int y[5]{1, 2, 3, 4};
	string s1="Rahul";
	string s2 = "sachin";
	CB obj{ 1, 2 };
public:
	CA(){
	}
	void operator()()
	{
		cout << "x=" << x << endl;
		cout << "s1=" << s1 << endl;
		cout << "s1=" << s2 << endl;
		cout << "x=" << obj.x <<" and y="<<obj.y<<endl;
	}
};

//void main()
void main2_1()
{
	CA obj;
	obj();
}