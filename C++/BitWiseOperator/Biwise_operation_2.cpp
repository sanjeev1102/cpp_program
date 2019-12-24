
#include<iostream>
using namespace std;

namespace nm02
{
	class CAT
	{
	public:
		void fun1()
		{
			cout << "\t\tCAT::fun1" << endl;
		}
		virtual void fun2()
		{
			cout << "\t\tCAT::fun2" << endl;
		}
		virtual void fun3()
		{
			cout << "\t\tCAT::fun3" << endl;
		}
	};


	void main()
	{
		CAT cat;
		//cout << sizeof(cat) << endl;
		((void(*)()) * (long*) * (long*)& cat)();
		//step 1 reach the vptr
		long* vptr = (long*)& cat;
		//step 2 reach the vtable
		long* vtable = (long*)* vptr;
		//step 3 reach the function
		typedef void(*FPTR)();
		FPTR fp = (FPTR)vtable[1];
		//step 4 call back
		fp();
	}
}