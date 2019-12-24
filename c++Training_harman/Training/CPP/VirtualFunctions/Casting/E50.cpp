#include<iostream>
#include<string>
#include<typeinfo>
using namespace std;

namespace Ex50
{
	struct MetaData
	{
		string className;
		int size;
		MetaData* parent;
	};

     
	struct SA
	{
		static MetaData rtti;

		static MetaData& GetCtti()	{ return rtti;}
		virtual MetaData& GetRtti()	{ return rtti;}
	};
		MetaData SA::rtti={"SA",sizeof(SA),0};
};
using namespace Ex50;

void main50()
{
	SA* pa =new SA;
	
	MetaData rtti=pa->GetRtti();

	cout<<rtti.className<<endl;
	cout<<rtti.size<<endl;
}
	