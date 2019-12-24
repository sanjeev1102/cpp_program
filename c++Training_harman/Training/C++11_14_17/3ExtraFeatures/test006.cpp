#include <thread>
#include <iostream>
#include<string>
#include<memory>
using namespace std;
namespace nm6
{
class SayHello
{
public:
    void greeting(std::string const& message) const
    {
        cout<<message<<endl;
    }
};

}

void maint6_1()
{
	using namespace nm6;
	SayHello x;
	std::thread t(&SayHello::greeting, &x, "goodbye");
	t.join();


}


void maint6()
{
	using namespace nm6;
	  std::shared_ptr<SayHello> p(new SayHello);//std::shared_ptr<SayHello> to ensure that the object stays around as long as the thread does
    std::thread t(&SayHello::greeting,p,"goodbye");
    t.join();
}

