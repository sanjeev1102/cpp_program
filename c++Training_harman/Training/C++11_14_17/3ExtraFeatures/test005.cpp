//Invoking a member function on a new thread

#include <thread>
#include <iostream>

using namespace std;
namespace nm5
{
class SayHello
{
public:
    void greeting() const
    {
        cout<<"hello"<<endl;
    }
};
}
void maint5()
{
	using namespace nm5;
    SayHello x;
    std::thread t(&SayHello::greeting,&x);
    t.join();

}
