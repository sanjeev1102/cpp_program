

#include<iostream>
#include<vector>

using namespace std;

class Addvalue {

	int val;

public:
	Addvalue(int j) : val(j) {

		cout << "in side constructor ------------" << endl;
	}

	void operator () (int i) {

		cout << "in side functorrrrr ------------" << endl;
		cout << i + val << endl;
	}



};

int main() {

	vector <int> vec = { 2,3,4,5 };

	int x = 2;
	Addvalue add(x);
	for (auto t = vec.begin(); t != vec.end(); t++) {
		add(*t);
		//cout << "value at t => " << *t << endl;
	}

		return 0;
}