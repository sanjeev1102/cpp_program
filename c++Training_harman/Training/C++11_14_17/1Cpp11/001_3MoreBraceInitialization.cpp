#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

class C
{
	int x[4];
public:
	C() /*: x{ 0, 1, 2, 3 } {}  */ //not working vs20xx
	{
	}
	void operator()()
	{
		for (size_t i = 0; i < 4; i++)
		{
			cout << x[i] << endl;
		}
	}
};
//void main()
void  main1_3_1()
{
	//C++11 brace-init
	int a{ 0 };
	string s{ "hello" };
	string s2{ s }; //copy construction
	vector <string> vs{ "alpha", "beta", "gamma" };
	map<string, string> stars
	{ { "Superman", "jhonty" },
	{ "Batsman", "sachin" } };
	double *pd = new double[3] {0.5, 1.2, 12.99};

	cout << "a=" << a << endl;
	cout << "s=" << s << endl;
	cout << "s2=" << s2 << endl;
	cout << "___________vector_________________" << endl;
	for (size_t i = 0; i < 3; i++)
	{
		cout << vs[i] << endl;
	}
	cout << "___________Map_____________________" << endl;
	map<string, string>::iterator it1 = stars.begin();
	map<string, string>::iterator it2 = stars.end();
	while (it1 != it2)
	{
		cout << it1->first << "=" << it1->second << endl;
		it1++;
	}
}