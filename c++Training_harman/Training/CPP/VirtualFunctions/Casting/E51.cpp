#include<iostream>
#include<string>
#include<typeinfo>
using namespace std;

namespace Ex51
{
	struct MetaData
	{
		string className;
		int size;
		MetaData* parent;
	};

	#define ENABLE_RTTI() \
			static MetaData rtti;\
			static MetaData& GetCtti()	{ return rtti;} \
			virtual MetaData& GetRtti()	{ return rtti;}
	//---------------------------------------------------------------------------------------
    struct SA
	{
		ENABLE_RTTI()
	};
		MetaData SA::rtti={"SA",sizeof(SA),0};
	
	struct SB:SA
	{
		ENABLE_RTTI()
	};
		MetaData SB::rtti={"SB",sizeof(SB),&SA::GetCtti()};
};
using namespace Ex51;

void main51()
{
	SA* pa =new SB;
	
	MetaData rtti=pa->GetRtti();

	cout<<rtti.className<<endl;
	cout<<rtti.size<<endl;
}
	