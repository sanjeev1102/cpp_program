#include<iostream>
using namespace std;
#include<list>
#include<unordered_map>


// Map stores the element in accending order or alphabatical order w.r.t key, where are unordered map stores the element in random order
// hence performance wise we should always choose unordered map.
//namespace nm06 {


	int main()
	{

		list <int> gqlist1, gqlist2;
		for (int i = 0; i < 10; ++i)
		{
			gqlist1.push_back(i * 2);
			gqlist2.push_front(i * 3);
		}

		// Traversing an unordered map 
	//	for (auto ir = gqlist1.rbegin(); ir != gqlist1.rend(); ++ir)
	//		cout << *ir << " ";

			// Traversing an unordered map 
		for (auto x : gqlist1)
			cout << x << " " << endl;

		return 0;
	}
//}