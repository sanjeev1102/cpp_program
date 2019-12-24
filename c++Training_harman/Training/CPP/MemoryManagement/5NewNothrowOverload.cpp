#include<iostream>
#include<new>
using namespace std;

namespace Ex10
{
	struct SA
	{
	};
};
using namespace Ex10;

void main10()
{
	SA *p = new(nothrow) SA(); 

	if(p == 0)
	{
		cout<<"out of memory"<<endl;
		return ;
	}

	//use the object
	delete p;
}