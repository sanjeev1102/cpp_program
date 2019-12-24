#include<iostream>
#include<string>
#include<thread>
#include<future>
#include<mutex>
using namespace std;

namespace nm20
{
	//MMT
	//GIB
	//IXIGO
	//IRCTC
	//HEG

	std::once_flag flg1, flg2;

	void BookA_Ticket(string name)
	{
		cout << "Trying to book (" << name << ")" << '\n';

		std::call_once(flg1, [name]() {cout << "Hai  i have booked [" << name << "]" << "\n"; });

	}

	void main()
	{
		thread t1(BookA_Ticket, "MMT");
		thread t2(BookA_Ticket, "GIB");
		thread t3(BookA_Ticket, "IXG");
		thread t4(BookA_Ticket, "IRCTC");
		thread t5(BookA_Ticket, "HEG");
		t1.join();
		t2.join();
		t3.join();
		t4.join();
		t5.join();
	}
}