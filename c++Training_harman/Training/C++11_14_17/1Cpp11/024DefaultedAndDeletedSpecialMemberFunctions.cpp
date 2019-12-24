#include<iostream>
#include<string>
using namespace std;
//**********Default ctor
class CA
{
public:
	CA() = default;
	CA(int x){
		cout << "CA int x=" << x << endl;
	}
};
void main24_1()
{

	CA obj;
	CA obj1(999);
}
//**************************************************
class CB
{
	CB() = delete;
public:
	

	CB(int x){
		cout << "CA int x=" << x << endl;
	}
};
void main24_2()
{
	//CB obj;
	CB obj1(78);
}
//******************************************************
struct CC	 {
	CC() = default;
	CC(const CC&) = delete;
	CC & operator=(const CC&) = delete;
};

void main24_3()
{
	CC obj;
	//CC obj1(obj);

}
//**********************************************************
struct CD {
	void f(double i){}
	void f(int) = delete;
};
void main24_4()
{
	CD obj;
	//obj.f(23);
	obj.f(12.8);
}
//****************************************************************
struct CE {
	void f(int d){}
	template<class T> void f(T) = delete;
};

void main24_5()
{
	CE obj;
	obj.f(343);
}