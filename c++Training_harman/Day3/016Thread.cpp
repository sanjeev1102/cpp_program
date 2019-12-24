#include<iostream>
#include<string>
#include<thread>
#include<mutex>
using namespace std;

namespace nm016
{
	void fun()
	{
		for (int i = 0; i < 10; i++)
		{
			cout << "\t\t\tFun called i=" << i << "\n";
			this_thread::sleep_for(chrono::seconds(1));
		}
	}

	void main1()
	{
		thread t1(fun);
		for (int i = 0; i < 6; i++)
		{
			cout << "Main called i=" << i << "\n";
			this_thread::sleep_for(chrono::seconds(1));
		}
		t1.join();
		cout << "Apple" << endl;
	}

	void MyFun(int x, int y)
	{
		for (int i = 0; i < 10; i++)
		{
			cout << "\t\t\tMyFun called i=" << i << "\n";
			this_thread::sleep_for(chrono::seconds(1));
		}
	}

	void main2()
	{

		//thread t1(std::bind(MyFun,10,20));
		thread t1(MyFun, 10, 20);
		for (int i = 0; i < 6; i++)
		{
			cout << "Main called i=" << i << "\n";
			this_thread::sleep_for(chrono::seconds(1));
		}
		t1.join();
		cout << "Apple" << endl;
	}


	class Func
	{
	public:
		void operator()()
		{
			for (int i = 0; i < 5; i++)
			{
				cout << "\t\t\t()() i=" << i << "\n";
				this_thread::sleep_for(chrono::seconds(1));
			}
		}
	};

	void main3()
	{
		Func fnc;
		thread t1(fnc);
		for (int i = 0; i < 6; i++)
		{
			cout << "Main called i=" << i << "\n";
			this_thread::sleep_for(chrono::seconds(1));
		}
		t1.join();
		cout << "Apple" << endl;
	}

	class MyClass
	{
	public:
		void MyMethod()
		{
			for (int i = 0; i < 5; i++)
			{
				cout << "\t\t\tMy Method i=" << i << "\n";
				this_thread::sleep_for(chrono::seconds(1));
			}
		}
		void MyMethodNew(string info)
		{
			for (int i = 0; i < 5; i++)
			{
				cout << "\t\t\tMy Method i=" << i << " " << info << "\n";
				this_thread::sleep_for(chrono::seconds(1));
			}
		}
	};

	void main4()
	{
		MyClass mc;
		//thread t1(std::bind(&MyClass::MyMethod,mc));
		//thread t1(&MyClass::MyMethod, mc);
		thread t1(&MyClass::MyMethodNew, mc, "India wins NZ");
		for (int i = 0; i < 6; i++)
		{
			cout << "Main called i=" << i << "\n";
			this_thread::sleep_for(chrono::seconds(1));
		}
		t1.join();

		cout << "Apple" << endl;
	}


	class CA
	{
	public:
		void Display()
		{
			cout << "this=" << this << endl;
		}
	};
	void main6()
	{
		CA obj;
		obj.Display();
		//thread t1(&CA::Display, obj);
		thread t1(&CA::Display, std::ref(obj));
		t1.join();

	}

	class CB
	{
		int x = 90;
	public:
		CB() //= default;
		{

		}
		CB(int x) :x(x)
		{
		}
		void operator()()
		{
			cout << "this =" << this << " x=" << x << endl;
		}
	};

	void main7()
	{
		//thread t1(CB(10));
		thread t1((CB()));

		t1.join();
	}



	mutex mute;
	class CAT
	{
		int x;
		int y;
	public:
		void AddFun()
		{
			for (x = 1; x <= 5; x++)
			{
				cout << "Addfun x=" << x << "\n";
				this_thread::sleep_for(chrono::seconds(1));
			}
			mute.lock();
			for (y = 1; y <= 10; y++)
			{
				cout << "AddFun  y=" << y << "\n";
				this_thread::sleep_for(chrono::seconds(1));
			}
			mute.unlock();
		}
		void SubFun()
		{
			mute.lock();
			for (y = -1; y > -10; y--)
			{
				cout << "\t\tSubfun  y=" << y << "\n";
				this_thread::sleep_for(chrono::seconds(1));
			}
			mute.unlock();
			for (x = -1; x > -5; x--)
			{
				cout << "\t\tSubfun x=" << x << "\n";
				this_thread::sleep_for(chrono::seconds(1));
			}
		}
	};

	void main()
	{
		CAT cat;
		thread t1(&CAT::AddFun, std::ref(cat));
		thread t2(&CAT::SubFun, std::ref(cat));

		t1.join();
		t2.join();
	}
}