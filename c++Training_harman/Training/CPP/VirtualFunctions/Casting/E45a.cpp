#include<iostream>
using namespace std;

namespace Ex45a
{
	struct SA					{	int a1;int a2;		};
	struct SB 					{	int b1;int b2;		};
	struct SC	: SA, SB	{	int c1; int c2;	};
	struct SD	: SB, SA	{	int d1; int d2;	};

};using namespace Ex45a;

void main45a()
{
	SD* pd =new SD;

	SA* pa = (SA*) pd; 

	SC* pc = (SC*) pa; 
	
	SB* pb = (SB*) pc; 
	
	pb->b1 = 10;
	pb->b2 = 20;
	cout<<pd->a1<<pd->a2<<pd->b1<<pd->b2<<pd->d1<<pd->d2<<endl;
}













