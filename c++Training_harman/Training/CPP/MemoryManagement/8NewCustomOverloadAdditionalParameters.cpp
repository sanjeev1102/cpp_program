#include<iostream>
#include<new>
using namespace std;

namespace Ex13
{
	struct MetaData
	{
	} meta_info;

	struct SA
	{
		static void* operator new(size_t size,MetaData data)
		{
			//use metadata object
			return malloc(size);
		}
	};
};
using namespace Ex13;

void main13()
{
	SA *p = new(meta_info) SA(); 

	delete p;
}





