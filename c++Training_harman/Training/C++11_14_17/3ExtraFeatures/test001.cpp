#include<iostream>
#include<thread>
#include<Windows.h>
using namespace std;
namespace nm1
{
void fun1()
{
	for (int i = 0; i < 100; i++)
	{
		cout<<"hi fun1 ="<<i<<endl;
		Sleep(1000);
	}
}
void fun2()
{
	for (int i = 0; i < 100; i++)
	{
		cout<<"hi fun2 ="<<i<<endl;
		Sleep(1000);
	}
}

}
void maint1()
{
	using namespace nm1;
	thread t1(fun1);
	thread t2(fun2);
	t1.join();
	t2.join();


}


