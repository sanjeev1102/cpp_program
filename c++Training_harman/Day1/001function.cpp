#include<iostream>
using std::cout;
using std::endl;
namespace nm1
{
	//functions
	/*
	1. naming convention
	2. return type
	3. calling conventions
	4. name
	5. parameters/arguements
	6. exception list
	7. prolog
	8. Body
	9. epilog
	*/
	extern "C++" void __cdecl fun(int x, int y) throw(int, float)
	{

	}


	void fun1()//?fun1@@YAXXZ
	{
	}
	void fun1(int x)//?fun1@@YAXH@Z
	{
	}
	extern "C++" void fun2()//?fun2@@YAXXZ
	{
	}
	extern "C" void fun3()//_fun3
	{
	}
	void  main1()
	{
		fun1();  //call	?fun1@@YAXXZ
		fun1(20);//call	?fun1@@YAXH@Z
		fun2();//call	?fun2@@YAXXZ
		fun3();//call	_fun3
	}

	void fun4(int x, int y)
	{
	}//ret	0

	void __cdecl fun5(int x, int y)
	{
	}//ret	0
	void __stdcall fun6(int x, int y)
	{
	}//ret	8
	void __fastcall fun7(int x, int y)
	{
	}//ret	0

	class CA
	{
		int i;
		int j;
	public:
		void __thiscall fun8()//const CA *this;
			//_this$ = ecx
		{

			this->i = 90;
		}
		void fun9() const //const  CA* const this;
		{

		}
	};

	void main2()
	{
		fun4(10, 20);
		/*
			push	20					; 00000014H
			push	10					; 0000000aH
			call	?fun4@@YAXHH@Z				; fun4
			add	esp, 8

		*/
		fun5(11, 22);
		/*
			push	22					; 00000016H
			push	11					; 0000000bH
			call	?fun5@@YAXHH@Z				; fun5
			add	esp, 8
		*/
		fun6(111, 222);
		/*
				push	222					; 000000deH
				push	111					; 0000006fH
				call	?fun6@@YGXHH@Z				; fun6
		*/
		fun7(1, 2);
		/*
			mov	edx, 2
			mov	ecx, 1
			call	?fun7@@YIXHH@Z				; fun7
		*/
		CA obj;
		obj.fun8();
		/*
			lea	ecx, DWORD PTR _obj$[ebp]
			call	?fun8@CA@@QAEXXZ			; CA::fun8
		*/
	}


	void fun10(int x) noexcept(true)//throw() //c++17
	{
		if (10 == x)
			throw 100;
	}
	void MyTerminate()
	{
		cout << "My Terminate worked" << endl;
		exit(0);
	}

	void main()
	{
		std::set_terminate(MyTerminate);
		std::cout << "apple" << endl;
		try
		{
			fun10(10);
		}
		catch (...)
		{
			cout << "Exception " << endl;
		}
		cout << "Orange" << endl;
	}
}