// C++ program to check whether two strings are anagrams 
// of each other 

#include<conio.h>
#include<string>
#include<stdio.h>
#include<iostream>
//#include <bits/stdc++.h> 

#include<Bits.h>


using namespace std;

/* program to check whether two strings are anagram ofeach other   : link: https://codescracker.com/cpp/program/cpp-anagram-program.htm
Here, fist we have to check the length of both the string, if length will be equal then further proceed else print the message for unequal length. 
Since to check for the anagram, the two string must having same length. Now we compare first character of first string to all the character of second string one by one,
then compare second character of first string to all the character of second string one by one, then compare third character of first string to all the character of second string one by one, 
and so on. When comparing, if any of the character of the first string will match to the character of second string, then we initialize 1 to the found, and exit the loop
and if there will no match found for any character, then 1 will not initialize to the found. So, found will be equal to 0, so that after exiting the inner loop, on checking "if(found==0)",
it becomes true and 1 will be initialize to not_found and exit the outer loop.	Now after exiting or completing the outer loop, we have to check whether not_found will be equal to 1 or 0.
If not_found will be equal to 1, then strings are not anagram and if not_found will be equal to 0 then strings are anagram.

*/


int main()
{
	
	char str1[20], str2[20];
	int len, len1, len2, i, j, found = 0, not_found = 0;
	cout << "Enter first string :";
	cin >> str1;
	cout << "Enter second string :";
	cin>>str2;
	len1 = strlen(str1);
	len2 = strlen(str2);
	if (len1 == len2)
	{
		len = len1;
		for (i = 0; i < len; i++)
		{
			found = 0;
			for (j = 0; j < len; j++)
			{
				if (str1[i] == str2[j])
				{
					found = 1;
					break;
				}
			}
			if (found == 0)
			{
				not_found = 1;
				break;
			}
		}
		if (not_found == 1)
		{
			cout << "Strings are not Anagram to each other";
		}
		else
		{
			cout << "Strings are Anagram";
		}
	}
	else
	{
		cout << "Two string must have same number of character to be Anagram";
	}
	
	return 0;
}