#include<iostream>
#include<new>
using namespace std;

namespace Ex19
{
	struct SA	//<-- prevent instantiation on heap
	{
	private:
		static void* operator new(size_t size)
		{
			return malloc(size);
		}
	};
};
using namespace Ex19;

void main19()
{
	SA stackObject;	
	//	stackObject::SA::SA(); 

	//SA *heapObject = new SA(); <-- error
	/*
		SA *p = SA::operator new(sizeof(SA)); <--error not accessible
		p->SA::SA();				
	*/
}