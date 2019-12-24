#include<iostream>
#include<new>
using namespace std;

namespace Ex14
{
	struct Flag{} flag;

	struct SA
	{
		static void* operator new(size_t size,Flag)
		{
			cout<<"SA new operator with flag"<<endl;
			return malloc(size);
		}
		static void* operator new(size_t size,int x,int y)
		{
			cout<<"SA new operator 3"<<endl;
			return malloc(size);
		}
		static void* operator new(size_t size,...)
		{
			cout<<"SA new operator 4"<<endl;
			return malloc(size);
		}
	};
};
using namespace Ex14;

void main()
{
	SA *p = new SA(); 
	/*
	SA *p = SA::operator new(sizeof(SA));
	p->SA::SA();
	*/
	SA *p2 = new(flag) SA();
	/*
	SA *p2 = SA::operator new(sizeof(SA),flag);
	p2->SA::SA();
	*/
	SA *p3 = new(10,20) SA();
	/*
	SA *p2 = SA::operator new(sizeof(SA),10,20);
	p2->SA::SA();
	*/
	SA *p4 = new(23,34,345,45,56) SA();

	delete p;
}





