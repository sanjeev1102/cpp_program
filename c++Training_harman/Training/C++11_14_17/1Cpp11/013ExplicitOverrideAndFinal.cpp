#include<iostream>
using namespace std;

class CAT
{
public:
	int x=100;
	CAT()
	{
	}
	virtual void Habbit(float f)
	{
		cout << "general habbit of cat" << endl;
	}
};

class Tiger :public CAT
{
public:
	Tiger()
	{
		
	}
	//virtual void Habbit(int f) //older problem of creating new virtual function
	//virtual void Habbit(int f) override //error compiler detects
	//virtual void Habbit(float f) override //works perfectly
	virtual void Habbit(float f) override final //restricts overriding 
	{
		cout << "general habbit of tiger" << endl;
	}
};

class CUB :public Tiger
{
public:
	CUB()
	{

	}
	/*virtual void Habbit(float f) override
	{
		cout << "general habbit of CUB" << endl;
	}*/
};
void main13_1()
{
	CAT *obj1 = new CUB();
	obj1->Habbit(10);
}
//*******************************************Final with classes

class Animal final
{
public:
	Animal()
	{
	}
};

/*class Human:public Animal
{

};*/

void main13_2()
{


}