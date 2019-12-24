#include<iostream>
#include<string>
using namespace std;

//void main()
void main10()
{
	int my_array[5] = { 1, 2, 3, 4, 5 };
	// double the value of each element in my_array:
	for (int &x : my_array) {
		x *= 2;
	}

	for (auto x : my_array)
	{
		cout << x << endl;
	}
	cout << "___________________" << endl;
	// similar but also using type inference for array elements
	for (auto &x : my_array) {
		x *= 2;
	}
	//The for each syntax
	for each (auto var in my_array)
	{
		cout << var << endl;
	}
}