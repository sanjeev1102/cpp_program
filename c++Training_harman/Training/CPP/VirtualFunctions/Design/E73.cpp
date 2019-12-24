#include<iostream>
#include<vector>
using namespace std;

namespace Ex73
{
	struct Static {} STATIC;
	//**********************************************************
	struct Emp
	{
		static vector<Emp*> m_vec;			//prototypes
	protected:
		Emp(Static)							//static constructor 
		{
			m_vec.push_back(this);
		}
		virtual Emp* Clone(int data)=0;		//factory method 
	public:
		Emp(){}								//instance constructor

		static Emp* Create(int data)		//factory
		{
			for(int i=0;i < m_vec.size(); i++)
			{
				Emp* p = m_vec[i];
				Emp* e = p->Clone(data);
				if(e)
					return e;
			}
			return 0;
		}
		virtual void dojob()=0;				//business function
	};
	vector<Emp*> Emp::m_vec;
	//***********************************************************
	struct Manager : Emp
	{
	protected:
		static Manager m_instance;
		Manager(Static s):Emp(s){}			//static constructor 

		Emp* Clone(int data)				//factory method 
		{
			if(data < 10)
				return new Manager;
			return 0;
		}
	public:
		Manager():Emp(){}
		virtual void dojob()	{ cout<<"manager dojob"<<endl;	}
	};
	Manager Manager::m_instance(STATIC);
	//---------------------------------------------------------
	struct Tester : Emp
	{
	protected:
		static Tester m_instance;
		Tester(Static s) :Emp(s){}			//static constructor 

		Emp* Clone(int data)				//factory method 
		{
			if((data >= 10) && (data <20))
				return new Tester;
			return 0;
		}
	public:
		Tester():Emp(){}
		virtual void dojob()	{ cout<<"tester dojob"<<endl;	}
	};
	Tester Tester::m_instance(STATIC);
	//---------------------------------------------------------
	struct Prog : Emp
	{
	protected:
		static Prog m_instance;
		Prog(Static s) :Emp(s){}			//static constructor 

		Emp* Clone(int data)				//factory method 
		{
			if((data >= 20) && (data <30))
				return new Prog;
			return 0;
		}
	public:
		Prog():Emp(){}
		virtual void dojob()	{ cout<<"Prog dojob"<<endl;	}
	};
	Prog Prog::m_instance(STATIC);
};
using namespace Ex73;
void main()
{
	Emp *e = Emp::Create(25);

	e->dojob(); 
}
