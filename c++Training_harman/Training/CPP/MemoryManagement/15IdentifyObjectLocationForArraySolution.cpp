#include<iostream>
#include<new>
using namespace std;

namespace Ex25
{
	struct SA	
	{
		bool m_isOnHeap; //<-- identify where the object is
		static bool g_isOnHeap;
		static int g_count;
	public:
		SA()
		{
			m_isOnHeap = g_isOnHeap;
			if(g_count != 0)	--g_count;
			if(g_count ==0)	g_isOnHeap = false; //reset flag on last element
		}
		static void* operator new[](size_t size)
		{
			g_isOnHeap = true;			//set heap flag
			g_count= size/sizeof(SA); //total number of objects
			return malloc(size);
		}
	};
	bool SA::g_isOnHeap = false;
	int SA::g_count=0;
};
using namespace Ex25;

void main25()
{
	SA *heapObjects = new SA[5]; 
/*
	SA *heapObjects = SA::operator new(sizeof(SA) * 5);
	heapObjects[0]->SA::SA();
	heapObjects[1]->SA::SA();
	heapObjects[2]->SA::SA();
	heapObjects[3]->SA::SA();
	heapObjects[4]->SA::SA();
	*/	
}