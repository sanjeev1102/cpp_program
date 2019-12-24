#include<iostream>
#include<vector>
using namespace std;

namespace Ex29
{
	vector<void**> stack;
	//***********************************************************************
	void TraversePointers()
	{
		for(int i=0;i < stack.size(); i++)
		{
			cout<<" pointer "<< stack[i] <<" points to "<<*stack[i] <<endl;
		}
	}
	//***********************************************************************
	template<typename T>
	class Ptr
	{
		T* m_p;
	public:
		Ptr(T* p=0):m_p(p)
		{
			stack.push_back((void**) &m_p); 
		}
		Ptr(Ptr<T>& rhs):m_p(rhs.m_p)
		{
			stack.push_back((void**) &m_p); 
		}
		~Ptr()
		{
			m_p =0;
		}
	};
};
using namespace Ex29;


void main()
{
	Ptr<int> p1 = new int();

	Ptr<double> p2 = new double();
	
	Ptr<int> p3 = new int();

	Ptr<int> p4 = p3;

	Ptr<double> p5;

	int i = 234;

	TraversePointers();
	getchar();
}