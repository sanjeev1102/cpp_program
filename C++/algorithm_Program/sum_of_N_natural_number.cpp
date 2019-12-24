
// WAP to calculate sum of N natural number

#include<iostream>

using namespace std;

int findsum(int num)
{
	int temp =0;
	for (int i = 1; i <= num; ++i)
	{
		temp = temp + i;
		cout << temp << endl;
	}
	return temp;
}
int main()
{
	int n;

	cout << "enter the number to be calculate sum of all natural no till number" << endl;
	cin >> n;

	int totalsum = findsum(n);

	cout << "sum of all natural number for given number is " << totalsum << endl;


	return 0;
}