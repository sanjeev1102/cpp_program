#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

namespace nm03 {

	// Sort the numbers according to comparing logic
	void MySort(std::vector<int>& ilist, bool(*pCompare)(int, int))
	{
		// Sorting code here
		std::cout << "Address of the comparing function :" << pCompare << std::endl;

	}

	int main()
	{
		std::vector<int> v = { 8,5, 9,4, 5,2,0,3 };
		//Sort asending
		MySort(v, [](int val1, int val2) {return val1 < val2; });

		//Sort Dessending
		MySort(v, [](int val1, int val2) {return val1 > val2; });

		cout << "Sorted : " << endl;

		for (auto it = v.begin(); it != v.end(); it++) {
			cout << *it << endl;
		}
		return 0;
	}

}