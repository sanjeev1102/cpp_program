#include<iostream>
using std::cout;
using std::endl;
namespace nm20
{
	void PrintMe()//specilized function 
	{
		cout << endl;
	}

	template<typename T1, typename ...T2>//variadic templates c++11 onwards
	void PrintMe(T1 x, T2 ...par)
	{
		cout << x << "\t";
		PrintMe(par...);//unpack
	}

	void main1()
	{
		PrintMe(10, 20, 30, 40);
		PrintMe(12, 'x', 56.78);
	}

	int sum()
	{
		return 0;
	}

	template<typename First, typename ...Rest>
	First sum(First first, Rest ...rest)
	{
		return first + sum(rest...);
	}

	void main2()
	{
		cout << sum(1, 2, 3, 4, 5, 6, 7) << endl;
	}

	class CA
	{
		int x = 10;//member initialization from c++11 onwards
	protected:
		int y = 20;
	public:
		int z = 30;
		friend class CB;//vertical access control
		void fun()
		{
			cout << "CA :: fun" << endl;
		}
		void AddFun(int x)
		{
			cout << "CA::Addfun(int)" << endl;
		}
		void AddFun(int x, int y)
		{
			cout << "CA::Addfun(int,int)" << endl;
		}
	};

	class CB :public CA
	{
	public:
		void Display()
		{
			cout << "x=" << x << endl;
			cout << "y=" << y << endl;
			cout << "z=" << z << endl;
		}
	};

	class CC :public CA
	{
		using CA::y;
	protected:
		using CA::z;//vertical access control
	public:
		using CA::AddFun;
		void Display()
		{
			cout << "y=" << y << endl;
			cout << "z=" << z << endl;
		}
		void fun()
		{
			cout << "CC :: fun" << endl;
		}
		void AddFun(int x, int y, int z)
		{
			cout << "CA::Addfun(int,int,int)" << endl;
		}
	};

	void main3()
	{
		CC obj;
		obj.fun();
		//CA obj1 = obj;
		//obj1.fun();

		obj.AddFun(10);
		obj.AddFun(1, 2);
		obj.AddFun(1, 2, 3);
	}
	//c++11 feature
	template<typename...>//1 
	class CMath;

	template<typename First, typename ...Rest>
	class CMath<First, Rest...> :public CMath<Rest...>//3
	{
	public:
		using CMath<Rest...>::AddFun;
		First AddFun(First x, First y)
		{
			cout << "Addfun for " << typeid(First).name() << endl;
			return x + y;
		}
	};


	template<>
	class CMath<>//2
	{
	public:
		void AddFun()
		{

		}
	};
	void main()
	{
		CMath<int, float, double> obj;
		obj.AddFun(12.3, 4.5);
		obj.AddFun(3, 4);
		obj.AddFun(1.f, 3.f);
	}
}