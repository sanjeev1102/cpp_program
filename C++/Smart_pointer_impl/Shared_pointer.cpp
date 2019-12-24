#include<iostream>
using namespace std;
namespace shared_Pointer_nm01
{

	class A
	{
	public:
		A() { cout << "In AAAAAAAA Constructor...." << endl; }
		~A() { cout << "In AAAAAAAA Destructorrr...." << endl; }

		virtual void fun1() { cout << "In AAAAAAAA Fun1()...." << endl; }
	};
	class B : public A
	{
	public:
		B() { cout << "In BBBBBBBBB Constructor...." << endl; }
		~B() { cout << "In BBBBBBBBB Destructorrr...." << endl; }
		void fun1() { cout << "In BBBBBBBBB Fun1()...." << endl; }
	};
	int main()
	{
		//A a1;
		//A* ptr1;
		//ptr1 = new B();    // in this case we have to make destructor virtual of base class. so that derived class destructor is called automatically.
		//delete ptr1;
		shared_ptr<A> p = std::make_shared<B>();
		p->fun1();
		p = make_shared<A>();
		p->fun1();
		return 0;
	}

}