
#include <thread>
#include <iostream>
#include <functional> // for std::ref
#include<mutex>
#include<Windows.h>
using namespace std;
//Protecting Shared Data
namespace nm8
{
	//*********************************************************************
	/*
	//Reference
	std::mutex m;
	unsigned counter=0;

	unsigned increment()
	{
	std::lock_guard<std::mutex> lk(m);//implicit lock
	return ++counter;
	}
	unsigned query()
	{
	std::lock_guard<std::mutex> lk(m);
	return counter;
	}


	*/
	//**********************************************************************
	//manual lock
	mutex m;
	class CA
	{
		int x;
		int y;
	public:
		CA():x(0),y(0)
		{
		}
		void AddFun()
		{
			for (x = 1; x <=5; x++)
			{
				cout<<"AddFun x="<<x<<endl;
				Sleep(1000);
			}
			m.lock();
			for (y = 1; y <=10; y++)
			{
				cout<<"AddFun y="<<y<<endl;
				Sleep(1000);
			}
			m.unlock();
		}
		void SubFun()
		{
			m.lock();
			for (y = -1; y >=-10; y--)
			{
				cout<<"SubFun y="<<y<<endl;
				Sleep(1000);
			}
			m.unlock();
			for (x = -1; x >=-5; x--)
			{
				cout<<"SubFun x="<<x<<endl;
				Sleep(1000);
			}
			
		}
	};
}

void maint8()
{
	using namespace nm8;
	CA obj;
	thread t1(&CA::AddFun,ref(obj));
	thread t2(&CA::SubFun,ref(obj));
	t1.join();
	t2.join();
}

