
#include<iostream>
using namespace std;
#include<map>
#include<unordered_map>


// Map stores the element in accending order or alphabatical order w.r.t key, where are unordered map stores the element in random order
// hence performance wise we should always choose unordered map.
namespace nm03
{


	int main()
	{
		// Declaring umap to be of <string, double> type 
	// key will be of string type and mapped value will 
	// be of double type
		unordered_map<string, double> employee_data;

		cout << " this is an unordered map example" << endl;

		// inserting value by insert function 
		employee_data.insert(make_pair("Sanjeev", 1000));
		employee_data.insert(make_pair("Vineet", 4000));

		employee_data.insert(make_pair("Vivek", 5000));

		// inserting values by using [] operator 
		employee_data["Ramanuj"] = 2000;

		// Traversing an unordered map 
		for (auto x : employee_data)
			cout << x.first << " " << x.second << endl;

		return 0;
	}
}