#include<iostream>
using std::cout;
using std::endl;
namespace nm3
{
	class CAT
	{
	public:
		CAT()//mov	DWORD PTR [eax], OFFSET ??_7CAT@@6B@
		{
		}
		virtual void fun2()
		{
			cout << "\t\tCAT::fun2" << endl;
		}
	};
	class Limb
	{
	public:
		Limb()
		{

		}
	};
	class Tiger :public CAT
	{
		Limb limbs;
	public:
		Tiger()
			/*
			call	??0CAT@@QAE@XZ				; CAT::CAT
			mov	DWORD PTR [eax], OFFSET ??_7Tiger@@6B@
			call	??0Limb@@QAE@XZ				; Limb::Limb
			*/
		{
		}
		virtual void fun4()
		{
			cout << "\t\tTiger::fun4" << endl;
		}
	};
	void main1()
	{
		Tiger tiger;
	}


	class CA
	{
	public:
		void fun1()
		{
		}
		virtual void fun2()
		{
		}
	};

	void main()
	{
		CA obj;
		CA & objRef = obj;
		CA *objPtr = &obj;
		obj.fun1();
		/*
		lea	ecx, DWORD PTR _obj$[ebp]
		call	?fun1@CA@@QAEXXZ			; CA::fun1
		*/
		obj.fun2();
		/*
		lea	ecx, DWORD PTR _obj$[ebp]
		call	?fun2@CA@@UAEXXZ			; CA::fun2
		*/
		objRef.fun1();
		/*
		mov	ecx, DWORD PTR _objRef$[ebp]
		call	?fun1@CA@@QAEXXZ			; CA::fun1
		*/
		objPtr->fun1();
		/*
		mov	ecx, DWORD PTR _objPtr$[ebp]
		call	?fun1@CA@@QAEXXZ			; CA::fun1
		*/

		objRef.fun2();//objref.vptr->vtable[0]()
		/*
		mov	eax, DWORD PTR _objRef$[ebp]
		mov	edx, DWORD PTR [eax]
		mov	esi, esp
		mov	ecx, DWORD PTR _objRef$[ebp]
		mov	eax, DWORD PTR [edx]
		call	eax
		cmp	esi, esp
		call	__RTC_CheckEsp
		*/
		objPtr->fun2();//objPtr->vptr->vtable[0]()
		/*
		mov	eax, DWORD PTR _objPtr$[ebp]
		mov	edx, DWORD PTR [eax]
		mov	esi, esp
		mov	ecx, DWORD PTR _objPtr$[ebp]
		mov	eax, DWORD PTR [edx]
		call	eax
		cmp	esi, esp
		call	__RTC_CheckEsp
		*/
	}
}