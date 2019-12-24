// You tube link: for shared pointer: https://www.youtube.com/watch?v=_Sk9JT_gTV4
// https://github.com/CodesBay/CplusPlus_SmartPointer
/*
There are multiple sets of smart pointers which are extremely useful, however, as a normal programmer we'll end up using at most 3 of them. These 3 smart pointers are called as a trilogy and is known as
shared_ptr<>
unique_ptr<>
weak_ptr<>
*/
// Example 1 : object creation with normal pointer
class Stest {

public:
	Stest() {
		cout << "In Constructor.." << endl;

	}

	~Stest() {
		cout << "In Destructor.." << endl;
	}
};

int main() {

	Stest* p;
	p = new Stest;    
	/* in this case it will call constructor only and destructor will never be called.. (memory leak). here we need to use delete which is commented below for proper destruction of object . or we need to use smart pointer to solve this problem
	O/P: in constructor.. */
	
	//delete p;
	return 0;
}


// Example 2 : object creation with smart pointer (shared pointer)
class Stest {

public:
	Stest() {
		cout << "In Constructor.." << endl;

	}

	~Stest() {
		cout << "In Destructor.." << endl;
	}
};

int main() {

	shared_ptr <Stest> sp(new Stest); 
    /* in this case it will call constructor as well as destructor no need to use delete
		O/P: in constructor.. 
			 in destructor..    */
	return 0;
}

//========================================================

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
	return nullptr;
	// return sp;           // in this case also output sequence will be same
}

int main() {

	cout << "Enter Main.." << endl;

	func();
	/* in this case it will call constructor as well as destructor no need to use delete
		O/P:	Enter Main..
				In Constructor..
				In Destructor..
				Enter Main..   
	*/
	cout << "Enter Main.." << endl;
	return 0;
}

//=====================================================
// Example 4 : object creation with smart pointer (shared pointer). 
/*Check the out put sequence of example 3rd and 4rth its changed.
 when shared pointer of fun() goes out of scope it doesnot delete the pointer.
 Note: shared_ptr pointer is capable of doing two things 1. transfer of ownership 2. multiple ownership.
 */

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
	cout << "Enter Main.." << endl;
	return 0;
}





















