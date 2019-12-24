
// Only one instanc at any point of time
// global access to that instance

#include <iostream>
using namespace std;

namespace singleton_1
{

	class Singleton {
		static Singleton* instance;
		int data;

		// Private constructor so that no objects can be created.
		Singleton() {
			data = 0;
		}

	public:
		static Singleton* getInstance() {
			if (!instance)
				instance = new Singleton;
			return instance;
		}

		int getData() {
			return this->data;
		}

		void setData(int data) {
			this->data = data;
		}
	};

	//Initialize pointer to zero so that it can be initialized in first call to getInstance
	Singleton* Singleton::instance = nullptr;

	int main() {
		Singleton* s = s->getInstance();
		cout << s->getData() << endl;
		s->setData(100);
		cout << s->getData() << endl;
		return 0;
	}


}

/* 
class GlobalClass
{
	int m_value;
	static GlobalClass* s_instance;
	GlobalClass(int v = 0)
	{
		m_value = v;
	}
public:
	int get_value()
	{
		return m_value;
	}
	void set_value(int v)
	{
		m_value = v;
	}
	static GlobalClass* instance()
	{
		if (!s_instance)
			s_instance = new GlobalClass;
		return s_instance;
	}
};

// Allocating and initializing GlobalClass's
// static data member.  The pointer is being
// allocated - not the object inself.
GlobalClass* GlobalClass::s_instance = 0;
void foo(void)
{
	GlobalClass::instance()->set_value(1);
	cout << "foo: global_ptr is " << GlobalClass::instance()->get_value() << '\n';
}

void bar(void)
{
	GlobalClass::instance()->set_value(2);
	cout << "bar: global_ptr is " << GlobalClass::instance()->get_value() << '\n';
}

int main()
{
	cout << "main: global_ptr is " << GlobalClass::instance()->get_value() << '\n';
	foo();
	bar();
}

 */

