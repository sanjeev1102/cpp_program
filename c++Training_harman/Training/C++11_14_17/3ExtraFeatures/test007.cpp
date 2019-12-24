//Passing function objects and arguments to a thread by reference

#include <thread>
#include <iostream>
#include <functional> // for std::ref
using namespace std;
namespace nm7
{
class PrintThis
{
public:
    void operator()() const
    {
        std::cout<<"this="<<this<<std::endl;
    }
};
}



void increment(int& i)
{
	++i;
}

void maint7_1()
{
	int x = 42;
	std::thread t(increment, std::ref(x));
	t.join();
	std::cout << "x=" << x << std::endl;
}


void maint7()
{
	using namespace nm7;
    PrintThis x;
    x();
    std::thread t(std::ref(x));
    t.join();
    std::thread t2(x);
    t2.join();

}

