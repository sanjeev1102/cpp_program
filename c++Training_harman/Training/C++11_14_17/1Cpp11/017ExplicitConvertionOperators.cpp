#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

struct A {
	A(int) {}
};

struct B {
	int m;
	B(int x) : m(x) {}
	explicit operator A() { cout << "explicit operator called " << endl; return A(m); }
};

void f(A){}
//void main()
int main17(){
	B b(1);
	A a = static_cast<A>(b);
	f(static_cast<A>(b));
	return 0;
}
