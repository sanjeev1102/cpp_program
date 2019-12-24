#include<iostream>
using namespace std;
namespace nm22
{
	void fun(int x)
	{
		cout << "Apple" << endl;
	}
	void fun(int *x)
	{
		cout << "Orange" << endl;
	}
	void main()
	{
		fun(NULL);
		fun(nullptr);//c++11

		char *c = nullptr;
		int *i = nullptr;
		bool *b = nullptr;
		//char c1 = nullptr;//error
		//int i1 = nullptr;
		bool b1 = nullptr;
	}
}