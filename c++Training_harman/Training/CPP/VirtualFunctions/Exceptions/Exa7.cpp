#include<iostream.h>

struct CX	
{
	int x;
	virtual void fun(){}
};
//------------------------------------------------
struct CY : virtual CX	{	int y; 	virtual void fun(){}};
struct CZ : virtual CX	{	int z;};

//------------------------------------------------
struct CP : virtual CY,virtual CZ	{ int p; };
struct CQ : virtual CY,virtual CZ	{ int q; };
//------------------------------------------------
struct CR : CP,CQ { int r; };
//------------------------------------------------
void main()
{
	cout<<sizeof(CR)<<endl;
/*
	CR* obj = new CR();

	long* vptr = (long*) obj;
	vptr++;
	vptr++;
	long* vtable = (long*) *vptr;

	cout<<vtable[1]<<endl;
	cout<<vtable[2]<<endl;
	cout<<vtable[3]<<endl;
*/
}