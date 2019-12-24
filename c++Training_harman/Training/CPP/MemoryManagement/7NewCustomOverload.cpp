#include<iostream>
#include<new>
using namespace std;

namespace Ex12
{
	struct SA
	{
		static void* operator new(size_t size)
		{
			//execute custom logic for memory allocation
			return malloc(size);
		}
	};
};
using namespace Ex12;

void main12()
{
	SA *p = new SA(); 

	delete p;
}





