#include<iostream>
#include<string>
using namespace std;

void function_name(std::initializer_list<float> list)
{
	initializer_list<float>::iterator it1 = list.begin();
	initializer_list<float>::iterator it2 = list.end();
	while (it1 != it2)
	{
		cout << *it1 << endl;
		it1++;
	}
}

std::initializer_list<int> fun2()
{
	return { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
}

//void main()
void main5_1()
{
	function_name({ 1.0f, -3.45f, -0.4f });
	cout << "_____________________________" << endl;
	initializer_list<int> list= fun2();
	initializer_list<int>::iterator it1 = list.begin();
	initializer_list<int>::iterator it2 = list.end();
	while (it1 != it2)
	{
		cout << *it1 << endl;
		it1++;
	}

}