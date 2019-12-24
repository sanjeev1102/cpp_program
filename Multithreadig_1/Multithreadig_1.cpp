// Multithreadig_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


#include<iostream>
#include<vector>
#include <thread>
	using namespace std;

	/*
	void Function_1() {

		cout<< "In side Function Function_1()" << endl;

	}

	int main() {

		thread t1(Function_1);

		t1.join();
		for (int i = 0; i < 200; i++) {
			cout << "From Main : " << i << endl;
		}


		return 0;
	}
	*/



	// using Functor.. without parameter..

	/*
	class Fctor {

	public:

		void operator () () {

			cout << "in side functorrrrr ------------" << endl;
			for (int j = 0; j < 50; j++) {
				cout << "From t1 " << j << endl;
			}

		}

	};

	int main() {

		Fctor fct;
		thread t1(fct);
		for (int i = 0; i < 50; i++) {
			cout << "From Main : " << i << endl;
		}

		t1.join();
		return 0;
	}

	*/

	// using Functor.. With parameter..

	/*
	class Fctor {

	public:

		void operator () (string msg) {

			cout << "t1 Says.." <<msg <<endl;

		}
	};

	int main() {

		string s = "Where there is no trust, there is no love";
		//Fctor fct;
		//thread t1(fct ,s);

		// instead of above two line we can also call functor as below..  note the extra bracket () in below line this is necessary in order to call functor as below.
		thread t1((Fctor()), s);

		cout << "from main.." << s << endl;

		t1.join();
		return 0;
	}

	*/

	// using Functor.. With parameter as reference.. here keyword ref() is important to pass parameter by reference..

	/*
	class Fctor {

	public:

		void operator () (string &msg) {

			cout << "t1 Says.." <<msg <<endl;

			msg = "trush is the mother of deceit..";

		}
	};

	int main() {

		string s = "Where there is no trust, there is no love..";
		//Fctor fct;
		//thread t1(fct ,s);

		// instead of above two line we can also call functor as below..  note the extra bracket () in below line this is necessary in order to call functor as below.
		thread t1((Fctor()), ref(s));

		t1.join();

		cout << "from main.." << s << endl;

		return 0;
	}

	//*/


