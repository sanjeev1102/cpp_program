#include<iostream>
#include<vector>
using namespace std;

namespace Ex72
{
	struct Static {} STATIC;
	//**********************************************************
	struct Emp
	{
		static vector<Emp*> m_vec;
	protected:
		Emp(Static)
		{
			m_vec.push_back(this);
		}
	public:
		Emp(){}
		virtual void dojob()=0;
	};
	vector<Emp*> Emp::m_vec;
	//***********************************************************
	struct Manager : Emp
	{
	protected:
		static Manager m_instance;
		Manager(Static s):Emp(s){} //static constructor 
	public:
		Manager():Emp(){}
		virtual void dojob()	{ cout<<"manager dojob"<<endl;	}
	};
	Manager Manager::m_instance(STATIC);

	struct Tester : Emp
	{
	protected:
		static Tester m_instance;
		Tester(Static s) :Emp(s){}	//static constructor 
	public:
		Tester():Emp(){}
		virtual void dojob()	{ cout<<"tester dojob"<<endl;	}
	};
	Tester Tester::m_instance(STATIC);
};
using namespace Ex72;

void main72()	
{
}
