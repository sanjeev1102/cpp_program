#include<iostream>
using namespace std;

namespace Ex31
{
	class CA{};
};
using namespace Ex31;

void main31()
{
	CA* p= new CA();
	
	/*
	-------------------------------------
	operator new ...
	{
		void* pv = malloc(sizeof(CA));
		if(pv == 0)
			throw bad_alloc();

		return pv;
	}
	try
		{
			((CA*)pv)->CA::CA();
		}
		catch(...)
		{
			free(pv);
			throw;
		}
		return pv;
	-------------------------------------
	*/
}