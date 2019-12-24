#include<iostream>
#include<new>
using namespace std;

namespace Ex24
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
		static void* operator new[](size_t size)
		{
			g_isOnHeap = true;
			return malloc(size);
		}
	};
	bool SA::g_isOnHeap = false;
};
using namespace Ex24;

void main24()
{
	SA *heapObjects = new SA[5]; 
	
}