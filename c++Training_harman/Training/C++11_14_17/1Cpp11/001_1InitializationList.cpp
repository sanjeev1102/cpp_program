#include<iostream>
#include<vector>
#include<string>
using namespace std;
//*********************************************************
struct TestClass {
	float first;
	int second;
};
//void main()
void main1_1()
{
	TestClass scalar = { 0.43f, 10 }; //One Object, with first=0.43f and second=10
	TestClass anArray[] = { { 13.4f, 3 }, { 43.28f, 29 }, { 5.934f, 17 } }; //An array of three Objects
	cout << "scalar.first=" << scalar.first << " and scalar.second=" << scalar.second<<endl;
	cout << "__________________________________" << endl;
	for (size_t i = 0; i < 3; i++)
	{
		cout << "scalar.first=" << anArray[i].first << " and scalar.second=" << anArray[i].second<<endl;
	}
	cout << "__________________________________" << endl;
}

//*********************************************************
class CEmployee
{
public:
	string EName;
	string EDept;
	int salary;
	string jobsAssingned[3];
	void operator()()
	{
		cout << "EName=" << EName << endl;
		cout << "EDept=" << EDept << endl;
		cout << "salary=" << salary << endl;
		cout << "jobs assingned are ..." << endl;
		for (size_t i = 0; i < 3; i++)
		{
			cout << "\t\t" << jobsAssingned[i] << endl;
		}
	}
};

//void main()
void main1_2()
{
	CEmployee emp{ "sachin", "bat", 1000, { "development", "testing", "NFR" } };
	emp();

}

//****************************************************************************
//void main()
void main1_3()
{
	vector<int> vec{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	//vector<int>::iterator it2 = vec.end();
	vector<int>::iterator it2 = vec.end();
	for (vector<int>::iterator it = vec.begin(); it != it2; it++)
	{
		cout << *it << endl;
	}

	/*for (int i = 0; i < vec.size; i++)
	{
	cout << vec[i] << endl;
	}*/
}

//*************************************************

//void main()
void main1_4()
{




}
//**************************************************