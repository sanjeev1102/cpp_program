#include<iostream>
using std::cout;
using std::endl;
namespace nm22
{
	class CB
	{
	public:
		CB()
		{
			cout << "CB()" << endl;
		}
		CB(const CB& par)
		{
			cout << "CB(Copy)" << endl;
		}
		CB(CB&& par)
		{
			cout << "CB(Move)" << endl;
		}
	};

	class CA
	{
	public:
		CA()
		{
			cout << "CA() " << endl;
		}
		CA(int k)
		{
			cout << "CA(int) " << endl;
		}
		CA(int k, int j)
		{
			cout << "CA(int,int) " << endl;
		}
		CA(int k, int j, int i)
		{
			cout << "CA(int,int,int) " << endl;
		}
		CA(CB obj)
		{
			cout << "CA(CB) " << endl;
		}
	};

	class Wrapper
	{
		CA obj;
	public:
		template<typename ...T>
		//Wrapper(T ...pct):obj(pct...)//forward ctor c++11 onwards
		Wrapper(T ...pct) :obj(std::forward<T>(pct)...)//perfect forward ctor c++11 onwards
		{

		}
		/*Wrapper()
		{
		}
		Wrapper(int x):obj(x)
		{
		}
		Wrapper(int x,int y):obj(x,y)
		{
		}
		Wrapper(int x,int y,int z):obj(x,y,z)
		{
		}*/
	};
	void main()
	{
		Wrapper wrap1;
		Wrapper wrap2(10);
		Wrapper wrap3(10, 20);
		Wrapper wrap4(11, 22, 33);
		CB obj;
		cout << "_____________________________" << endl;
		Wrapper wrap5(obj);
		cout << "_____________________________" << endl;
	}
}