	#include<iostream>
#include<new>
using namespace std;

namespace Ex23
{
	struct SA	
	{
		bool m_isOnHeap; //<-- identify where the object is
		static bool g_isOnHeap;
	public:
		SA()
		{
			m_isOnHeap = g_isOnHeap;
			g_isOnHeap = false;
		}
		static void* operator new(size_t size)
		{
			g_isOnHeap = true;
			return malloc(size);
		}
		void doJob()
		{
			if(m_isOnHeap)
				cout<<"object is on heap"<<endl;
			else
				cout<<"object is on stack"<<endl;
		}
	};
	bool SA::g_isOnHeap = false;
};
using namespace Ex23;

void main23()
{
	SA stackObject;	
	//	stackObject::SA::SA(); 

	SA *heapObject = new SA(); 
	/*
		SA *p = SA::operator new(sizeof(SA)); 
		p->SA::SA();				
	*/
	stackObject.doJob();
	heapObject->doJob();
}