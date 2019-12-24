#include<iostream>
using namespace std;

namespace Ex71
{
	struct Emp
	{
		Emp *m_emp;
		Emp(int data); 

		virtual void dojob()	
		{
			m_emp->dojob();
		}
	protected:
		Emp(){}
	};
	struct Manager : Emp
	{
		virtual void dojob()	{ cout<<"manager dojob"<<endl;	}
	};

	struct Tester : Emp
	{
		virtual void dojob()	{ cout<<"tester dojob"<<endl;	}
	};
	Emp::Emp(int data) 
	{
		if(data < 10)
				m_emp = new Manager();
		if((data >= 10) && (data <20))
				m_emp = new Tester();
	}
};using namespace Ex71;

void main71()
{
	Emp* emp = new Emp(15);

	emp->dojob(); 
}



