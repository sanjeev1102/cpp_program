#include<new>
#include<iostream>
using namespace std;

//singleton pattern
namespace Ex34
{
	class CA
	{
	public:
		static CA* CreateInstance()
		{
			static CA* p= new CA();
			return p;
		}
		void operator delete(void* pv)	{	}
	protected:
		CA()	{		cout<<"CA created"<<endl;		}
	};
};
using namespace Ex34;

void main34()
{
	CA * p = CA::CreateInstance();
	CA * p2 = CA::CreateInstance();
	CA * p3 = CA::CreateInstance();

	delete p;
	delete p2;
	delete p3;
}