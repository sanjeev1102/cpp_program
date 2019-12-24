#include<iostream>
#include<string>
using namespace std;

namespace nm13
{

	class CA
	{
		bool is_on_heap;
		static int count;
	public:
		CA()
		{

			if (count <= 0)
			{
				is_on_heap = false;
			}
			else
			{
				is_on_heap = true;
			}
			count--;
		}
		static void* operator new(size_t size)
		{
			count = 1;
			return malloc(size);
		}
		static void* operator new[](size_t size)
		{
			count = size / sizeof(CA);
			return malloc(size);
		}
			void Location()
		{
			if (is_on_heap == true)
			{
				cout << "Object heap" << endl;
			}
			else
			{
				cout << "Object (NOT) on heap" << endl;
			}
		}
	};

	int CA::count = 0;

	void main()
	{
		CA obj1;
		CA *obj2 = new CA();
		CA obj3;
		CA *obj6 = new CA[5];
		CA obj5;
		CA *obj4 = new CA();


		obj1.Location();
		obj3.Location();
		obj5.Location();
		cout << "________________________" << endl;
		obj2->Location();
		obj4->Location();
		cout << "________________________" << endl;
		for (int i = 0; i < 5; i++)
		{
			(obj6 + i)->Location();
		}

		delete obj2;
		delete obj4;
		delete[] obj6;
	}
}