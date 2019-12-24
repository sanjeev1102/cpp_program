#include<iostream>
using std::cout;
using std::endl;
namespace nm23
{
	class CA
	{
		int x = 10;
	public:
		CA()
		{
			cout << "CA default" << endl;
		}
		explicit CA(int par) :CA(par, 100)//ctor delegation from c++11
		{
			cout << "CA one param " << endl;
		}
		explicit CA(int par1, int par2)//c++ 11 onwards
		{
			cout << "CA multi param" << endl;
		}
		CA(std::initializer_list<int> list)//c++11 onwards
		{
			cout << "CA Init Ctor" << endl;
			auto it1 = list.begin();
			auto it2 = list.end();
		}
	};

	void main1()
	{

		CA obj1;
		//CA obj2 = 10;
		cout << "____________________" << endl;
		CA obj2_1(100);
		cout << "____________________" << endl;
		CA obj3{ 20 };//c++11 brace init
		//CA obj4 = { 30 };
		//CA obj5 = (11, 22);
		//obj4 = 900;
		CA obj6(123, 456);
		CA obj7{ 12,34 };
		//CA obj8 = { 123,456 };
	}
}