#include<iostream>
using namespace std;

namespace Ex30
{
	struct Emp
	{
		Emp(int code)
		{
			if(code < 1)	throw "InvalidData";
		}
	};
};using namespace Ex30;

void main30()
{
	Emp *e;
	try{
		e = new Emp(-12);
		cout<<"created object"<<endl;
	}
	catch(...){
		e =0;
		cout<<"failed to created object"<<endl;
	}

	delete e;
}