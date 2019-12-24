//the trailing return types 
#include<iostream>
#include<string>
using namespace std;

int fun()
{
	cout << "fun" << endl;
	return 100;
}
template<typename T1, typename T2>
auto AddFunExt(T1 x, T2 y)-> decltype(fun())
{
	return 404;
}

template<typename T1, typename T2>
auto AddFunExtNew(T1 x, T2 y)-> decltype(x + y)//Use variables not templates
{
	return x + y;
}
template<typename T1, typename T2>
auto AddFunExtNew1(T1 x, T2 y)-> decltype(AddFunExtNew(x,y))//Use variables not templates
{
	return x + y;
}

//void main()
void main9(){

	//********************************************
	auto res3 = AddFunExt(23.4, 5);
	cout << "type of res3=" << typeid(res3).name() << endl;
	cout << "res3=" << res3 << endl;
	//*********************************************
	auto res4 = AddFunExtNew(3.14, 67);
	cout << "type of res4=" << typeid(res4).name() << endl;
	cout << "res4=" << res4 << endl;
	//********************************************
	auto res5 = AddFunExtNew1(12, 3.4);
	cout << "type of res5=" << typeid(res5).name() << endl;
	cout << "res4=" << res5 << endl;
	//*******************************************
}