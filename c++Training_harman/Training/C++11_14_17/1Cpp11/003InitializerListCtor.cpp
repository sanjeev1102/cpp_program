#include<iostream>
#include<string>
using namespace std;

class SmartArray
{
	int arr[5];

public:
	SmartArray(initializer_list<int> list)
	{
		cout << "smart array Init constructor called ..." << endl;
		if (list.size() != 5)
			throw invalid_argument("Arguement shoukd be exactly 5");
		initializer_list<int>::iterator it;
		size_t i;
		for (i = 0,it = list.begin(); it != list.end(); i++,it++)
		{
			arr[i] = *it;
		}
	}
		void operator()()
		{
			for (size_t i = 0; i < 5; i++)
			{
				cout << "arr[" <<arr[i] << "]=" <<arr[i] << endl;
			}
		}
	
};
//void main()
void main3()
{
	try
	{

		//SmartArray sa { 1, 2, 4 ,3,5}; //or
		SmartArray sa = { 1, 2, 4, 3, 5 };
		sa();
	}
	catch (invalid_argument arg)
	{
		cout << arg.what() << endl;
	}

}