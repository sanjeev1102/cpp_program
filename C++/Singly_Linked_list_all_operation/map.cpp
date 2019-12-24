
#include<iostream>
using namespace std;
#include<map>

// Map stores the element in accending order or alphabatical order w.r.t key, where are unordered map stores the element in random order
// hence performance wise we should always choose unordered map.

namespace nm04 {

	int main()
	{

		// empty map container
		map<int, int> gquiz1;

		// insert elements in random order 
		gquiz1.insert(pair<int, int>(7, 40));
		gquiz1.insert(pair<int, int>(5, 30));
		gquiz1.insert(pair<int, int>(3, 60));
		gquiz1.insert(pair<int, int>(4, 20));
		gquiz1.insert(pair<int, int>(2, 50));
		gquiz1.insert(pair<int, int>(6, 50));
		gquiz1.insert(pair<int, int>(8, 80));

		// also we can use make_pair for inserting item in map
		gquiz1.insert(make_pair(1, 10));


		// Traversing an unordered map 
		for (auto x : gquiz1)
			cout << x.first << " " << x.second << endl;

		return 0;
	}
}