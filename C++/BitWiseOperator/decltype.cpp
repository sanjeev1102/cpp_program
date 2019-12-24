
#include<iostream>
using namespace std;

//namespace nm03
//{


class ABC {
public:
	ABC() {}

	virtual void fun1(){ cout << "ABC Fun1()..." << endl; }
};

class PQR :public ABC{

public:

	PQR() {

	}

	void fun1() override
	{

		cout << "PQR Fun1()..." << endl;
	}
};

int foo() {
	return 10;
}

int main()
{
	float y = 1.5f;
	decltype(foo()) x;
	decltype(y) z;

	int *const  ptr = &x;
	const int * ptr2 = &x;
	cout << "typeid of x = " << typeid(x).name() << endl;

	cout << "typeid of z = " << typeid(z).name() << endl;

	cout << "typeid of ptr = " << typeid(ptr).name() << endl;
	cout << "typeid of ptr2 = " << typeid(ptr2).name() << endl;

	ABC* pr;
	ABC abc;

	pr = &abc;
	cout << "typeid of abc = " << typeid(abc).name() << endl;

	cout << "typeid of pr = " << typeid(pr).name() << endl;
	pr->fun1();
	decltype(abc) obj1;
	cout << "typeid of obj1 = " << typeid(obj1).name() << endl;

	PQR pqr;
	cout << "typeid of pqr = " << typeid(pqr).name() << endl;
	pr = &pqr;

	cout << "typeid of pr = " << typeid(pr).name() << endl;

	pr->fun1();

	return 0;
}






//}