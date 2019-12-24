#include<iostream>
#include<new>
using namespace std;

namespace Ex15
{
	struct SA
	{
		static void* operator new(size_t size)
		{
			cout<<"SA new operator with flag"<<endl;
			return malloc(size);
		}
		static void* operator new[](size_t size)
		{
			cout<<"SA new operator 3"<<endl;
			return malloc(size);
		}
	};
};
using namespace Ex15;

void main15()
{
	SA *p = new SA(); 
	/*
	SA *p = SA::operator new(sizeof(SA));
	p->SA::SA();
	*/
	SA *p2 = new SA[5];
	/*
	SA *p2 = SA::operator new[](sizeof(SA) * 5);
	p2[0]->SA::SA();
	p2[1]->SA::SA();
	p2[2]->SA::SA();
	p2[3]->SA::SA();
	p2[4]->SA::SA();
	delete [] p2;
	*/
}





