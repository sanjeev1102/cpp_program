#include<iostream>
using std::cout;
using std::endl;
namespace nm7
{
	class CA
	{
	public:
		CA()
		{
			cout << "CA ctor" << endl;
			throw 200;
		}
		~CA()
		{
			cout << "CA D-tor" << endl;
		}
		static void* operator new(std::size_t size)
		{
			cout << "CA::operator new called " << endl;
			return malloc(size);
		}
		static void operator delete(void *pv)
		{
			cout << "CA::operator delete called " << endl;
			free(pv);
		}
	};
	//DIE or DRY
	void main()
	{
		CA *objPtr = NULL;
		try
		{
			objPtr = new CA();
			/*
			CA *temp=operator new(1){ malloc(); //bad alloc}
			try
			{
				temp->CA::CA();
			}
			catch(...)
			{
				operator delete(temp);
				throw;
			}
			objPtr=temp;
			*/
			/*
			push	1
			call	??2CA@@SAPAXI@Z				; CA::operator new
			add	esp, 4
			mov	DWORD PTR tv132[ebp], eax
			mov	eax, DWORD PTR tv132[ebp]
			mov	DWORD PTR $T4[ebp], eax
			mov	BYTE PTR __$EHRec$[ebp+12], 1
			cmp	DWORD PTR $T4[ebp], 0
			je	SHORT $LN6@main
			mov	ecx, DWORD PTR $T4[ebp]
			call	??0CA@@QAE@XZ				; CA::CA
			mov	DWORD PTR tv135[ebp], eax
			mov	ecx, DWORD PTR tv135[ebp]
			mov	DWORD PTR tv74[ebp], ecx
			jmp	SHORT $LN7@main
			$LN6@main:
			mov	DWORD PTR tv74[ebp], 0
			$LN7@main:
			mov	edx, DWORD PTR tv74[ebp]
			mov	DWORD PTR $T5[ebp], edx
			mov	BYTE PTR __$EHRec$[ebp+12], 0
			mov	eax, DWORD PTR $T5[ebp]
			mov	DWORD PTR _objPtr$[ebp], eax
			*/

		}
		catch (int exp)
		{
			cout << "exp=" << exp << endl;
		}


		if (objPtr == NULL)
		{
			cout << "Apple" << endl;
		}
		else
		{
			cout << "Orange" << endl;
			delete objPtr;
		}
	}
}