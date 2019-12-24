#include<iostream>
#include<string>
using namespace std;

void main21_1()
{
	//auto str1 = u8"I'm a UTF-8 string.";
	//auto str2 = u"This is a UTF-16 string.";
	//auto str3	=U"This is a UTF-32 string.";
	auto str4 = R"(The String Data \n Stuff " )";
	auto str5 = R"delimiter(The String Data \n Stuff " )delimiter";
	cout << str4 << endl << str5 << endl;

}