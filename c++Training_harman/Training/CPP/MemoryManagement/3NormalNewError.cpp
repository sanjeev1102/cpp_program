#include<iostream>
#include<new>
using namespace std;

namespace Ex8
{
	struct SA
	{
	};
};
using namespace Ex8;

void main8()
{
	//create
	SA *p = new SA(); 
	if(p == 0)
	{
		cout<<"out of memory"<<endl;
		return ;
	}

	//use the object

	//free
	delete p;
}