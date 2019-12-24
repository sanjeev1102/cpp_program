
#include<iostream>
#include<string>

using namespace std;
int main()
{
	char str[50], temp;
	//	string str; char temp;
	int i, j;
	cout << "Enter a string : ";
	//fgets(str, 50);
	//cin >> str;
	cin.getline(str, 100);
	
	cout << "\n string : " << str;
	j = strlen(str) - 1;
	//j = str.length() - 1;
	for (i = 0; i < j; i++, j--)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
	cout << "\nReverse string : " << str;
	return 0;
}
