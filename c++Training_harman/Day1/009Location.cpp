#include<iostream>
using std::cout;
using std::endl;
namespace nm9
{
	class CA
	{
		bool IsOnHeap;
		static int count;
	public:
		CA() :IsOnHeap(true)
		{
			count--;
			if (count < 0)
				IsOnHeap = false;
		}
		static void* operator new(std::size_t size)
		{
			CA* temp = (CA*)malloc(size);
			count = 1;
			return temp;
		}
		static void* operator new[](std::size_t size)
		{
			CA* temp = (CA*)malloc(size);
			count = size / sizeof(CA);
			return temp;
		}
			void Location()
		{
			if (IsOnHeap == true)
			{
				cout << "Object on heap" << endl;
			}
			else
				//if (IsOnHeap == false)
			{
				cout << "Object (NOT) on heap" << endl;
			}
		}
	};
	int CA::count = 0;

	void main()
	{
		CA obj1;
		CA *obj3 = new CA();
		/*
		obj3=operator new();
		obj3->CA::CA();
		*/
		CA *obj4 = new CA();
		CA obj2;
		CA *obj5 = new CA[5];
		/*
		obj5=operator new[](5);
		(obj5+0)->CA::CA();
		(obj5+1)->CA::CA();
		(obj5+2)->CA::CA();
		(obj5+3)->CA::CA();
		(obj5+4)->CA::CA();
		*/
		obj1.Location();
		obj2.Location();
		cout << "______________________" << endl;
		obj3->Location();
		obj4->Location();
		cout << "______________________" << endl;
		for (int i = 0; i < 5; i++)
		{
			(obj5 + i)->Location();

		}
	}
}