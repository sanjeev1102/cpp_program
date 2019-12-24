
#include<iostream>
#include<vector>

using namespace std;

class Addvalue {

	int val;

public:
	Addvalue(int j) : val(j) {
	}

	void operator () (int i) {

		cout << i + val << endl;
	}

};

int main() {

	vector <int> vec = { 2,3,4,5 };

	int x = 2;

	for each (vec.begin(), vec.end(), Addvalue(x));
	
	return  0;
}