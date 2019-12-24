#include<iostream>
#include<new>
using namespace std;

namespace Ex9
{
	struct SA
	{
	};
};
using namespace Ex9;

void main()
{
	SA *p;
	
	try
	{
		p= new SA();
	}
	catch(bad_alloc e)
	{
		cout<<"out of memory"<<endl;
		return ;
	}

	//use the object
	
	delete p;
}