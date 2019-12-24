#include<iostream>
using std::cout;
using std::endl;
namespace nm2
{
	class CA
	{
		int x;
		int y;
	public:
		CA()
		{
		}
		void fun()
		{
		}
	};
	class CB :public CA
	{
	public:
		CB()//	call	??0CA@@QAE@XZ				; CA::CA
		{

		}
	};
	void main1()
	{
		CB obj;
		/*
			lea	ecx, DWORD PTR _obj$[ebp]
			call	??0CB@@QAE@XZ				; CB::CB
		*/
		obj.fun();
	}

	class Animal {
	public:
		Animal()
		{
			//RAII
		}
	};
	class Limb
	{
	public:
		Limb()
		{

		}
	};
	class Human :public Animal
	{
		Limb limbs;
	public:
		Human()
			//call	??0Animal@@QAE@XZ			; Animal::Animal
			//call	??0Limb@@QAE@XZ				; Limb::Limb
		{

		}
	};
	void main2()
	{
		Human human;

	}


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


	void main3()
	{
		CAT cat;
		//cout << sizeof(cat) << endl;
		((void(*)())*(long*)*(long*)&cat)();
		//step 1 reach the vptr
		long* vptr = (long*)&cat;
		//step 2 reach the vtable
		long *vtable = (long*)*vptr;
		//step 3 reach the function
		typedef void(*FPTR)();
		FPTR fp = (FPTR)vtable[1];
		//step 4 call back
		fp();
	}
	class Tiger final :public CAT //final from c++11 onwards
	{
	public:
		virtual void fun4()
		{
			cout << "\t\tTiger::fun4" << endl;
		}
		//virtual void fun3()
		//void fun3()
		//void fun3(int k)
		//virtual void fun3(int k)
		//virtual void fun3(int k) override //c++11 error
		//virtual void fun3() override //c++11 permits
		//void fun3() override  //c++11 permits
		void fun3() override final //c++11 permits
		{
			cout << "\t\tTiger::fun3" << endl;
		}
	};
	void main()
	{
		CAT cat;
		Tiger tiger;
		long* vptr1 = (long*)&cat;
		long *vtable1 = (long*)*vptr1;
		cout << "CAT::VFTABLE=" << vtable1 << endl;
		using FPTR = void(*)();//from c++11 onwards
		((FPTR)vtable1[0])();
		((FPTR)vtable1[1])();

		long* vptr2 = (long*)&tiger;
		long *vtable2 = (long*)*vptr2;
		cout << "Tiger::VFTABLE=" << vtable2 << endl;
		((FPTR)vtable2[0])();
		((FPTR)vtable2[1])();
		((FPTR)vtable2[2])();

	}
}