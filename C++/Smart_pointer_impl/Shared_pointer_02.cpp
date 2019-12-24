#include<iostream>
using namespace std;

namespace nm02 {

	// Example 3 : object creation with smart pointer (shared pointer)
	class Stest {

	public:
		Stest() {
			cout << "In Constructor.." << endl;
		}
		~Stest() {
			cout << "In Destructor.." << endl;
		}
	};

	shared_ptr<Stest> func() {
		shared_ptr <Stest> sp(new Stest);
		//return nullptr;      // in this case also output sequence will be same . this is only applicable when we use syntax func(); in main. i.e line 26
		return sp;
	}

	int main() {

		cout << "Enter Main.." << endl;

		//func();    // below output after using this line i.e fun();
				/* in this case it will call constructor as well as destructor no need to use delete
				O/P:	Enter Main..
						In Constructor..
						In Destructor..
						Enter Main ends.. ..
				*/

		shared_ptr<Stest> spret = func();   // output changed when we use below syntax instead of fun();  directly.. note that, sequence on executing mail is changed.

				/* in this case it will call constructor as well as destructor no need to use delete
				O/P:	Enter Main..
						In Constructor..
						Enter Main ends.. ..
						In Destructor..
				*/
		cout << "Enter Main ends.. .." << endl;
		return 0;
	}
}


