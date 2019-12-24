#include<iostream>
#include<string>
using namespace std;

class SmartArrayNew
{
	int arr[5];

public:
	SmartArrayNew(int x, int y)
	{
		cout << "smart array param ctor called.." << endl;
		arr[0] = arr[1] = x;
		arr[2] = arr[3] = arr[4] = y;
	}
	SmartArrayNew()
	{
		cout << "smart array default ctor called.." << endl;
		arr[0] = arr[1] = arr[2] = arr[3] = arr[4] = 99;
	}
	SmartArrayNew(initializer_list<int> list)
	{
		cout << "smart array Init constructor called ..." << endl;
		if (list.size() != 5)
			throw invalid_argument("Arguement shoukd be exactly 5");
		initializer_list<int>::iterator it;
		size_t i;
		for (i = 0, it = list.begin(); it != list.end(); i++, it++)
		{
			arr[i] = *it;
		}
	}
	void operator()()
	{
		for (size_t i = 0; i < 5; i++)
		{
			cout << "arr[" << arr[i] << "]=" << arr[i] << endl;
		}
		cout << "_______________________________________________" << endl;
	}

};
//void main()
void main4()
{
	SmartArrayNew sa1;
	sa1();
	SmartArrayNew sa2(11, 22);
	sa2();
	try
	{

		//SmartArray sa { 1, 2, 4 ,3,5}; //or
		SmartArrayNew sa = { 1, 2, 4, 3, 5 };
		sa();
	}
	catch (invalid_argument arg)
	{
		cout << arg.what() << endl;
	}
}