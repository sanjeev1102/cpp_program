#include<iostream>
using namespace std;

namespace Ex32
{
	struct CA
	{
		bool flag;
		~CA()
		{
			if(flag==true) throw "Invalid State";

			cout<<"CA destroyed"<<endl;
		}
	};
};using namespace Ex32;
void main32()
{
	CA *p = new CA();
	p->flag = true;

	try{
		delete p;
	}catch(char*)	{		cout<<"couldnt destroy"<<endl;	}

	p->flag = false;
	delete p;
}