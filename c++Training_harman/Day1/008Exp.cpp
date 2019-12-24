#include<iostream>
using std::cout;
using std::endl;
namespace nm8
{
	class CA
	{
		static int count;
		int x;
	public:
		CA()
		{
			count++;
			x = count;
			cout << "CA Ctor" << endl;
		}
		CA(const CA&)
		{
			count++;
			x = count;
			cout << "CA Copy" << endl;
		}
		~CA()
		{
			cout << "CA D-tor x=" << x << endl;
		}
	};
	int CA::count = 0;
	void main1()
	{
		int x = 10;
		CA obj;
		try
		{
			if (10 == x)
				throw 200;
		}
		catch (int exp)
		{
			cout << "exp=" << exp << endl;
		}
		cout << "Apple" << endl;
	}


	void main2()
	{
		int x = 10;

		try
		{
			CA obj;
			if (10 == x)
				throw 200;
		}
		catch (int exp)
		{
			cout << "exp=" << exp << endl;
		}
		cout << "Apple" << endl;
	}


	void main3()
	{
		int x = 10;
		try
		{
			CA obj;
			if (10 == x)
				throw obj;
		}
		//catch (CA exp)
		catch (CA &exp)
		{
			cout << "exp" << endl;
		}
		cout << "Apple" << endl;
	}


	class CB
	{
	public:
		CB()
		{
			cout << "Ctor" << endl;
		}
		~CB()
		{
			cout << "D-tor" << endl;
			throw 400;
		}
	};
	void fun()
	{
		CB obj;
	}
	void main4()
	{
		int x = 20;
		try
		{

			fun();
			if (10 == x)
				throw 200;

		}
		catch (int exp)
		{
			cout << "exp=" << exp << endl;
		}
		cout << "Apple" << endl;
	}


	void main()
	{
		int x = 10;
		try
		{
			try
			{
				if (10 == x)
					throw 200;
				cout << "Orange" << endl;
			}
			//catch (int exp)
			//catch (int exp)
			catch (int &exp)
			{
				exp += 800;
				cout << "inner exp=" << exp << endl;
				//throw 400;
				throw;
			}
			cout << "Apple" << endl;
		}
		catch (int exp)
		{
			cout << "outer exp=" << exp << endl;
		}
		cout << "Pine" << endl;
	}
}