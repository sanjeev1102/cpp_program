#include<iostream>
using std::cout;
using std::endl;

namespace nm12
{
	class CA
	{
		CA()
		{
			cout << "CA Ctor" << endl;
		}
		~CA()
		{
			cout << "CA D-tor" << endl;
		}
	public:

		void fun()
		{
			cout << "CA fun " << endl;
		}
		friend class Smart;
	};

	void DoJob(CA *p)
	{
		cout << "Apple" << endl;
		p->fun();
		cout << "Orange" << endl;
	}

	class Smart
	{
		static void * operator new(std::size_t size)
		{
			return NULL;
		}
		static void * operator new[](std::size_t size)
		{
			return NULL;
		}
			static void operator delete(void*)
		{
		}
		static void operator delete[](void*)
		{
		}
		CA *ptr;
	public:
		Smart() :ptr(new CA())
		{
		}
		Smart(Smart & par) :ptr(par.ptr) {//transfer ownership
			par.ptr = NULL;
		}
		Smart& operator=(Smart par)
		{
			std::swap(ptr, par.ptr);
			return *this;
		}
		CA* operator->()
		{
			return ptr;
		}
		~Smart()
		{
			delete ptr;
		}
		operator CA*()
		{
			return ptr;
		}
		/*operator int()
		{
			return 678;
		}*/
		explicit operator double() //c++11 onwards
		{
			return 3.14159;
		}
	};

	void main1()
	{
		Smart sm;
		Smart sm1(sm);
		sm1 = sm;
		sm1->fun();//

		CA *pt = sm;
		DoJob(sm);
		int x = (double)sm;
		double g = (double)sm;

	}
}