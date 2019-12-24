
#include<iostream>
#include <list> 

using namespace std;

template <typename mytype>

	auto findNull(const mytype& g)
	{
		cout << "findnull functionnnnn" << endl;
		auto it = begin(g);

		for (it = g.begin(); it != g.end(); ++it)
			cout << '\t' << *it;
		cout << '\n';

		return it;
	}

	int main()
	{

		int a = 10, b = 20, c = 30;

		list <int*> mylist1, mylist2;

		for (int i = 0; i < 10; ++i)
		{
			mylist1.push_back((&i) + 2);
			//mylist2.push_front(i * 3);
		}
		mylist1.push_back(NULL);
		auto cit = findNull(mylist1);

		if (cit == mylist1.end())
		{
			cout << "No Null pointer in myvec" << endl;
		}
		else
		{
			cout << " Null pointer in myvec" << endl;
		}

		return 0;
	}
