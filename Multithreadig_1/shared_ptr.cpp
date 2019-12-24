
#include<iostream>
#include<vector>
#include <thread>
using namespace std;

namespace nm01_shared_ptr
{
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
		return sp;;
	}

	int main() {

		cout << "Enter Main.." << endl;

		shared_ptr<Stest> spret = func();
		/* in this case it will call constructor as well as destructor no need to use delete
			O/P:	Enter Main..
					In Constructor..
					Enter Main..
					In Destructor..
		*/
		cout << "Exit Main.." << endl;
		return 0;
	}
}