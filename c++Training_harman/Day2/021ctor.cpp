#include<iostream>
using std::cout;
using std::endl;
namespace nm21
{
	class CA
	{
		int *i;
	public:
		CA() :i(new int(10))
		{
			cout << this << " CA Ctor created i=" << i << endl;
		}
		CA(const CA& par) :i(new int(*par.i))
		{
			cout << this << " CA Deep Copy  i=" << i << endl;
		}
		CA(CA&& par) :i(par.i)
		{
			par.i = NULL;
			cout << this << " CA Move Shallow copy  i=" << i << endl;
		}
		void Display()
		{
			cout << this << " Display holding i=" << i << endl;
			cout << "__________________________" << endl;
		}
		~CA()
		{
			cout << this << " CA D-tor releasing i=" << i << endl;
			delete i;
		}
	};
	CA CreateCA()
	{
		CA temp;
		temp.Display();

		return temp;
	}
	/*
	memory collapse
	ctor ellission
	*/
	void main()
	{
		CA obj1 = CreateCA();
		obj1.Display();
		//CA obj2(obj1);//deepcopy
		CA obj2(std::move(obj1));
		obj2.Display();

	}

	void main1()
	{
		CA obj1;
		CA obj2(obj1);
		cout << "__________________________" << endl;
		obj1.Display();
		obj2.Display();
		cout << "__________________________" << endl;
	}

}