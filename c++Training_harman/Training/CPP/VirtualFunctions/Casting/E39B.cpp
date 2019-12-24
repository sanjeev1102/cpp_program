#include<iostream>
using namespace std;

struct CA{
	int i;
};
struct CB{
	int k;
};
struct CC: CB, CA{
	int m;
};
struct CD: CA, CB{
	int x;
};
void main39B()
{
	CC* pc = new CC; 
	CD* pd = (CD*) pc;

	CA* pa = pd; 
	pa->i =  10; 

	cout<<pc->i<<endl<<pc->k<<endl<<pc->m<<endl; 
}
