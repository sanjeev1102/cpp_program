#include<iostream>
using namespace std;

namespace Ex52
{
	struct SX {int x;};
	struct SY {int y;};
	struct SZ {int z;};
	struct CA : SX, SY,SZ	{int data;};
};
using namespace Ex52;

void main52()
{
	CA* p = new CA();
	SX* p2 = p;
	SY* p3 = p;
	SZ* p4 = p;

	cout<<(int)p2 - (int)p<<endl;
	cout<<(int)p3 - (int)p<<endl;
	cout<<(int)p4 - (int)p<<endl;
}