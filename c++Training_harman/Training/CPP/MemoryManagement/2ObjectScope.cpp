#include<iostream>
#include<new>
using namespace std;

namespace Ex7
{
	struct SA
	{
	};

	SA dataSegmentObject; //application scope, life of module 
};
using namespace Ex7;

static SA dataSegmentObject2; //file scope, life of module

void main7()
{
	static SA dataSegmentObject3; //function scope, life of module

	SA stackObject;	//life of function

	SA *heapObject = new SA(); //life controled by code (dangerous)
 
}