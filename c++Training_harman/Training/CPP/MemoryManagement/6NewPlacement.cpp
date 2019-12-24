#include<iostream>
#include<new>
using namespace std;

namespace Ex11
{
	struct SA
	{
		int data;
		~SA()
		{
			cout<<"dtor"<<endl;
		}
	};
};
using namespace Ex11;

//char buffer[255];	

void main()
{
	char* buffer = new char[255];
	//char buffer[255];

	SA *p1 = new(buffer) SA(); 
	SA *p2 = new(buffer + 5) SA(); 
	SA *p3 = new(buffer + 10) SA(); 

	//never call delete 
	p1->SA::~SA();
	p2->SA::~SA();
	p3->SA::~SA();

	int *pi = new(buffer) int;

	delete[] buffer; //if it is heap
	getchar();
}

