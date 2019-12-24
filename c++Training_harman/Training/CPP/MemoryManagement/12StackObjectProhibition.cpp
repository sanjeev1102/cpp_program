#include<iostream>
#include<new>
using namespace std;

namespace Ex21
{
	struct SA	//<-- prevent instantiation on stack 
	{
	private:
		SA(){		}
	public:
		static SA* create()
		{
			return new SA();
			/*
				SA *p = SA::operator new(sizeof(SA));
				p->SA::SA();				<--  accessible
			*/
		}
	};
};
using namespace Ex21;

void main21()
{
	//SA stackObject;	<-- error
	//stackObject::SA::SA(); <-- not accessible

	SA *heapObject = SA::create();
}