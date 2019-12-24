


#include<iostream>
#include<stdio.h>
using namespace std;

// CPP program to implement run length encoding 
//Run Length Encoding
//Given an input string, write a function that returns the Run Length Encoded string for the input string.
//For example, if the input string is “wwwwaaadexxxxxx”, then the function should return “w4a3d1e1x6”.

/* 
void printRLE(string str)
{
	int n = str.length();
	for (int i = 0; i < n; i++) {

		// Count occurrences of current character 
		int count = 1;
		while (i < n - 1 && str[i] == str[i + 1]) {
			count++;
			i++;
		}

		// Print character and its count 
		cout << str[i] << count;
	}
}

int main()
{
	string str = "wwwwaaadexxxxxxywww";
	printRLE(str);
	return 0;
}

*/
