#include<iostream>
#include<string>
using namespace std;
namespace NS0006
{
	class CA
	{
	public:
		CA(int x, int y)
		{
			this->x = x;
			this->y = y;
		}
		int x;
		int y;
	};
	class Animal
	{
	public:
		string _name;
		Animal(string name) :_name(name)
		{
		}
	};
	Animal* CreateAnimal()
	{
		return new Animal("Tiger");
	}

}

//void main()
void main6_1()
{
	using namespace NS0006;
	auto x = 101;
	auto y = 45.6;
	auto z = "sachin";
	auto obj = new CA(12, 13);
	auto anm = CreateAnimal();
	cout << "type of x=" << typeid(x).name() << endl;
	cout << "type of y=" << typeid(y).name() << endl;
	cout << "type of z=" << typeid(z).name() << endl;
	cout << "type of obj=" << typeid(obj).name() << endl;
	cout << "type of anm=" << typeid(anm).name() << endl;
}