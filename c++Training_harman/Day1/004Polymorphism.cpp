#include<iostream>
using std::cout;
using std::endl;
namespace nm4
{
	class CA
	{
	public:
		CA()
			//setvptr(CA::VFTable)
		{

		}
		void fun1()
		{
			cout << "CA::fun1 called " << endl;
		}
		virtual void fun2()
		{
			cout << "CA::fun2 called " << endl;
		}
	};
	class CB :public CA
	{
	public:
		CB()
			//call CA::CA()
			//setvptr(CB::VFTable)
		{
		}
		void fun1()
		{
			cout << "CB::fun1 called " << endl;
		}
		virtual void fun2()
		{
			cout << "CB::fun2 called " << endl;
		}
	};
	void main()
	{
		CB obj1;
		//CA *caPtr=NULL;
		CA *caPtr = &obj1;


		caPtr->fun1();
		/*
			mov	ecx, DWORD PTR _caPtr$[ebp]
			call	?fun1@CA@@QAEXXZ			; CA::fun1
		*/
		caPtr->fun2();//caPtr->vptr->vtable[0]()
		/*
			mov	eax, DWORD PTR _caPtr$[ebp]
			mov	edx, DWORD PTR [eax]
			mov	esi, esp
			mov	ecx, DWORD PTR _caPtr$[ebp]
			mov	eax, DWORD PTR [edx]
			call	eax
			cmp	esi, esp
			call	__RTC_CheckEsp
		*/
		cout << "_________________________" << endl;
		caPtr->CA::CA();
		caPtr->fun2();//caPtr->vptr->vtable[0]()
		/*
			mov	eax, DWORD PTR _caPtr$[ebp]
			mov	edx, DWORD PTR [eax]
			mov	esi, esp
			mov	ecx, DWORD PTR _caPtr$[ebp]
			mov	eax, DWORD PTR [edx]
			call	eax
			cmp	esi, esp
			call	__RTC_CheckEsp
		*/

	}
}