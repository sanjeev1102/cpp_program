#include<iostream>
#include<string>
#include<map>
using namespace std;
namespace nm14
{
	class CA
	{
	public:
		CA()
		{
			cout << "CA Ctor " << endl;
		}
		void DoJob()
		{
			cout << "CA::Job done " << endl;
		}
		~CA()
		{
			cout << "CA D-tor " << endl;
		}
	};

	class SmartPtr
	{
		CA *ptr;
		static map<CA*, int> myMap;
	public:
		SmartPtr() :ptr(new CA())
		{
			myMap[ptr] = 1;
		}
		SmartPtr(const SmartPtr& par) :ptr(par.ptr)
		{
			myMap[ptr]++;
		}
		CA* operator->()
		{
			return ptr;
		}

		/*SmartPtr& operator=(const SmartPtr & par)
		{
			this->SmartPtr::~SmartPtr();
			this->SmartPtr::SmartPtr(par);
			return *this;
		}*/
		SmartPtr& operator=(SmartPtr  par)
		{
			swap(this->ptr, par.ptr);
			return *this;
		}

		~SmartPtr()
		{
			myMap[ptr]--;
			if (myMap[ptr] == 0)
			{
				delete ptr;
				myMap.erase(ptr);
			}
		}
	};

	map<CA*, int> SmartPtr::myMap;

	void main()
	{
		SmartPtr ptr1;
		ptr1->DoJob();
		SmartPtr ptr2(ptr1);
		SmartPtr ptr3;
		SmartPtr ptr4(ptr3);
		SmartPtr ptr5(ptr3);
		ptr1 = ptr3;
	}
}