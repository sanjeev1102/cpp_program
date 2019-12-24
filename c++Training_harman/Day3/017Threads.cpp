#include<iostream>
#include<string>
#include<thread>
#include<future>
using namespace std;
namespace nm17
{
	/*
	 //promise
	 1) set value
	 2) a notification
	 3) a exception
	 4) wait check for value existance

	*/

	void DoJob(std::promise<string> * prmOb)
	{
		cout << "\t\t\DoJob called  1\n";
		this_thread::sleep_for(chrono::seconds(1));
		cout << "\t\t\DoJob called  2\n";
		prmOb->set_value("This is the info");
		this_thread::sleep_for(chrono::seconds(1));
		cout << "\t\t\DoJob called  3\n";
		this_thread::sleep_for(chrono::seconds(1));
		cout << "\t\t\DoJob called  4\n";
		this_thread::sleep_for(chrono::seconds(1));

	}

	void main1()
	{
		std::promise<string> prm;
		std::future<string> fut = prm.get_future();
		thread t1(DoJob, &prm);
		cout << "\t\t\Main called  1\n";
		this_thread::sleep_for(chrono::seconds(1));
		cout << "\t\t\Main called  2\n";

		string msg = fut.get();
		cout << "The message recieved is " << msg << endl;
		cout << "Apple" << endl;
		t1.join();
		cout << "Orange" << endl;
	}

	void Mul(promise<int>&& p, int a, int b)
	{
		int res = a*b;
		p.set_value(res);

	}
	struct Div
	{
		void operator()(promise<int>&& p, int a, int b) {
			int res = a / b;
			p.set_value(res);
		}
	};

	void main()
	{
		int a = 20, b = 10;
		promise<int> p1, p2;
		future<int> f1 = p1.get_future(), f2 = p2.get_future();
		Div div;

		thread t1(Mul, move(p1), a, b);
		thread t2(div, move(p2), a, b);


		int mulRes = f1.get();
		int divResult = f2.get();
		cout << "Mul=" << mulRes << endl;
		cout << "Div=" << divResult << endl;
		t1.join();
		t2.join();
	}
}