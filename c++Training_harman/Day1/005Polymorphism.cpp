#include<iostream>
using std::cout;
using std::endl;
namespace nm5
{
	//template method pattern
	class CA
	{
	protected:
		virtual void fun() = 0;
		/*{
			cout << "Apple" << endl;
		}*/
	public:
		CA()
		{
			//fun();
		}
		void MyFun()
		{
			cout << "Open the fruit box" << endl;
			fun();
			cout << "Close the fruit box" << endl;
		}

	};
	class CB :public CA
	{
	protected:
		virtual void fun() override
		{
			cout << "Orange" << endl;
		}
	public:
		CB()
		{
			//fun();
		}


	};

	void main1()
	{
		CB obj;
		obj.MyFun();

	}



	//CRTP
	template<typename T>
	class Base
	{
	public:
		void DoJob()
		{
			cout << "Apple" << endl;
			static_cast<T*>(this)->YourFun();//ATL
			cout << "Orange" << endl;
		}
	};

	class Derived :public Base<Derived>
	{
	public:
		void YourFun()
		{
			cout << "YourFun" << endl;
		}
	};
	void main()
	{
		Derived der;
		der.DoJob();
	}
}