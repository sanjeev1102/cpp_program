#include<iostream>
using namespace std;

struct CA
{
	//CA(CA& rhs):vptr(ca_table)
	virtual void fx1()	{	cout<<"A"<<endl;		}
};
struct CB : CA
{
	virtual void fx1()	{	cout<<"B"<<endl;		}
};
void main30()
{
	CB obj;
	obj.fx1();

	CA* p = &obj;
	p->fx1();
	
	CA& r = obj;
	r.fx1();
	
	CA  o = obj;	//<-- object slicing
	o.fx1();		//o.vptr.vtable[0]();
}
