#include<iostream>
#include<string>
#include<thread>
#include<future>
#include<mutex>
using namespace std;

namespace nm18
{

	struct Div
	{
		void operator()(promise<int>&& p, int a, int b) {
			cout << "\t\t\Div called  by " << this_thread::get_id() << "\n";
			this_thread::sleep_for(chrono::seconds(1));
			cout << "\t\t\Div called  2\n";
			this_thread::sleep_for(chrono::seconds(1));
			try
			{
				if (0 == b)
				{
					throw runtime_error("Haaaaaa !!! Dividing by zero");
				}
				int res = a / b;
				p.set_value(res);
			}
			catch (...)
			{
				p.set_exception(current_exception());
			}
		}
	};

	void main1()
	{
		promise<int> p1;
		future<int> f1 = p1.get_future();
		Div div;
		thread t1(div, move(p1), 20, 0);
		cout << "\t\t\Main called  1\n";
		this_thread::sleep_for(chrono::seconds(1));
		cout << "\t\t\Main called  2\n";
		this_thread::sleep_for(chrono::seconds(1));
		try
		{
			cout << "20/0=" << f1.get() << endl;
		}
		catch (runtime_error & err)
		{
			cout << err.what() << endl;
		}

		t1.join();
	}


	class Print
	{
	public:
		void operator()(std::future<int>&& f1)
		{
			cout << "\t\t\Print called  1\n";
			this_thread::sleep_for(chrono::seconds(1));
			cout << "\t\t\Print called  2\n";
			this_thread::sleep_for(chrono::seconds(1));
			try
			{
				cout << "20/0=" << f1.get() << endl;
			}
			catch (runtime_error & err)
			{
				cout << err.what() << endl;
			}
		}
	};

	void main2()
	{
		promise<int> p1;
		future<int> f1 = p1.get_future();
		Div div;
		Print prn;
		thread t1(div, move(p1), 20, 10);
		thread t2(prn, move(f1));
		cout << "Main I am done " << endl;
		t1.join();
		t2.join();
	}
	mutex mute;
	class Informer
	{
	public:
		void operator()(std::shared_future<int> f1)
		{
			std::lock_guard<mutex> lock(mute);
			this_thread::sleep_for(chrono::seconds(1));
			cout << "\t\t\Informer called  by " << this_thread::get_id() << "\n";

			try
			{
				cout << "20/10=" << f1.get() << "\n";
			}
			catch (runtime_error & err)
			{
				cout << err.what() << "\n";
			}
		}
	};

	void main()
	{
		promise<int> p1;
		shared_future<int> f1 = p1.get_future();
		Div div;
		Informer inf;
		thread t1(div, move(p1), 20, 10);
		thread t2(inf, f1);
		thread t3(inf, f1);
		thread t4(inf, f1);
		thread t5(inf, f1);
		cout << "\t\t\Main called  by " << this_thread::get_id() << "\n";
		t1.join();
		t2.join();
		t3.join();
		t4.join();
		t5.join();
	}
}