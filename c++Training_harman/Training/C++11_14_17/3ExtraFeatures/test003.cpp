#include<iostream>
#include<thread>
#include<string>
using namespace std;
//
namespace nm3
{
class Greeting
{
    string message;
public:
    explicit Greeting(std::string const& message_):
        message(message_)
    {}
    void operator()() const
    {
        cout<<message<<std::endl;
    }
};
}

void maint3()
{
	using namespace nm3;
	thread t(Greeting("sachin"));
	t.join();

}