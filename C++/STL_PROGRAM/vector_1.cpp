

#include<iostream>
#include<vector>

using namespace std;

namespace vector_1
{
	template <typename mytype>

	auto findNull(const mytype& c)
	{
		cout << "findnull functionnnnn" << endl;
		auto it = begin(c);

		for (; it != end(c); ++it)
			if (*it == nullptr)
			{
				cout << "breakinggggggggggg" << endl;
				break;
			}

		return it;
	}

	int main()
	{

		int a = 10, b = 20, c = 30;

		vector <int*> myvec{ &a , &b, &c };

		auto cit = findNull(myvec);

		if (cit == myvec.end())
		{
			cout << "No Null pointer in myvec" << endl;
		}
		else
		{
			cout << " Null pointer in myvec" << endl;
		}
		return 0;

	}

	
}