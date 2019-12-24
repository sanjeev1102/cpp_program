#include<iostream>
#include<string>
#include<thread>
#include<future>
#include<mutex>
using namespace std;
namespace nm19
{
	int AddFun(int x, int y)
	{
		for (int i = 0; i < 5; i++)
		{
			this_thread::sleep_for(chrono::seconds(1));
			cout << "AddFun i=" << i << " " << this_thread::get_id() << "\n";
		}
		return x + y;
	}

	void main1()
	{
		future<int> f1 = async(AddFun, 10, 20);
		for (int i = 0; i < 5; i++)
		{
			this_thread::sleep_for(chrono::seconds(1));
			cout << "Main i=" << i << " " << this_thread::get_id() << "\n";
		}
		int result = f1.get();
		cout << "result=" << result << endl;
	}


	void main2()
	{
		async([]() {
			this_thread::sleep_for(chrono::seconds(1));
			cout << "Hello India 1" << endl;
			this_thread::sleep_for(chrono::seconds(1));
			cout << "Hello India 2" << endl;
		});//future
		cout << "main done" << endl;
	}


	void main3()
	{
		future<void> fut = async([]() {
			this_thread::sleep_for(chrono::seconds(1));
			cout << "Hello India 1" << endl;
			this_thread::sleep_for(chrono::seconds(2));
			cout << "Hello India 2" << endl;
		});
		this_thread::sleep_for(chrono::seconds(2));
		cout << "main done" << endl;
	}//future


	void main()
	{
		auto f1 = async(std::launch::async, []() {
			this_thread::sleep_for(chrono::seconds(2));
			cout << "Hello India 1" << endl;
		});
		auto f2 = async(std::launch::async, []() {
			this_thread::sleep_for(chrono::seconds(1));
			cout << "Hello India 2" << endl;
		});
		cout << "Hello India 3" << endl;
	}
}