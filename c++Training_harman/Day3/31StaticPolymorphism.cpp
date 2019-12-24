#include <variant>
#include <iostream>
using namespace std;

//CRTP
template<typename T>
class CA
{
public:
	void DoJob()
	{
		cout << "Apple" << endl;
		static_cast<T*>(this)->YourJob();
		cout << "Orange" << endl;
	}
};

//ATL
class Derived:public CA<Derived>
{
public:
	void YourJob()
	{
		cout << "I am from derived " << endl;
	}
};

void main()
{
	Derived obj;
	obj.DoJob();
}