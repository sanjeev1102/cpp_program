#include<iostream>
#include<thread>

using namespace std;
//Running a function object on another thread
namespace nm2
{
		class CA
		{
		public:
			void operator()() 
			{
				std::cout<<"hello"<<std::endl;
			}
		};

}

void maint2()
{
	using namespace nm2;
	CA obj;
	thread t(obj);
	t.join();

}

void maint2_1()
{
	using namespace nm2;
	thread t((CA()));
	t.join();

}