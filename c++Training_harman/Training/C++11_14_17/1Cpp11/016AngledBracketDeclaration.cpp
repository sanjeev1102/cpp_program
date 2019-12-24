#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

void main16()
{
	//look at angled braket nesting ( > > ) earlier space was required
	map<string, vector<int>> MyMap = { { "Albert", { 1, 2, 3, 4, 5 } }, { "rahul", { 11, 22, 33, 44, 55 } } };
	auto it1 = MyMap.begin();
	auto it2 = MyMap.end();
	while (it1!=it2)
	{
		cout << "details of " << it1->first << endl;
		auto it3 = (*it1).second.begin();
		auto it4 = (*it1).second.end();
		while (it3!=it4)
		{
			cout << *it3 << "\t\t";
				it3++;
		}
		it1++;
	}
}