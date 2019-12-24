#include<iostream>
using std::cout;
using std::endl;
namespace nm11
{
	class CA
	{
		int *i;
	public:
		CA() :i(new int(10))
		{
			cout << "CA Ctor created i=" << i << endl;
		}
		CA(const CA& par) :i(new int(*par.i))
		{
			cout << "CA Copy created i=" << i << endl;
		}
		CA& operator=(const CA & par)
		{
			*(this->i) = *par.i;
			return *this;
		}
		void fun()
		{
			cout << "i=" << *i << endl;
		}
		~CA()
		{
			cout << "CA D-tor releasing i=" << i << endl;
			delete i;
		}
	};

	void main1()
	{
		CA obj1;
		CA obj2(obj1);
		obj1 = obj2;
	}


	class CB//shallow copy
	{
		int *i;
		int *count;
	public:
		CB() :i(new int(10)), count(new int(1))
		{
			cout << "CB Ctor created i=" << i << endl;
		}
		CB(const CB& par) :i(par.i), count(par.count)
		{
			(*count)++;
			cout << "CB Copy worked i=" << i << endl;
		}
		/*
		CB& operator=(const CB & par)
		{
			this->CB::~CB();
			this->CB::CB(par);
			return *this;
		}
		*/
		CB& operator=(CB  par)
		{
			std::swap(par.i, this->i);
			std::swap(par.count, this->count);
			return *this;
		}
		void fun()
		{
			cout << "i=" << *i << endl;
		}
		~CB()
		{
			(*count)--;
			if ((*count) == 0)
			{
				cout << "CB D-tor releasing i=" << i << endl;
				delete count;
				delete i;
			}
		}
	};

	void main()
	{
		CB obj1;
		CB obj2(obj1);
		CB obj3;
		CB obj4(obj3);
		obj1 = obj3;
	}
}