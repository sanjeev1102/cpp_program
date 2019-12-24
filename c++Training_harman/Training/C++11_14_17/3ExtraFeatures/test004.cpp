#include<iostream>
#include<thread>
#include<string>
using namespace std;
//Passing Arguments to a Thread Function
namespace nm4
{
	void greeting(string const& message)
	{
		cout<<message<<std::endl;
	}

void write_sum(int x,int y)
{
    cout<<x<<" + "<<y<<" = "<<(x+y)<<endl;
}

}

void maint4_1()
{
	using namespace nm4;
	thread t(bind(greeting, "sachin"));
	t.join();

}

void maint4_2()
{
	using namespace nm4;
	thread t(greeting, "hi!");
	t.join();

}

void maint4_3()
{
	using namespace nm4;
	thread t(write_sum,123,456);
    t.join();

}



