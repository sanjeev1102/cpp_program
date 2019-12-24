
/* class ClassWithVirtualFunctions {

public:
	//virtual void display() {
	//}
};

int main() {

	//ClassWithVirtualFunctions obj;
	cout << sizeof(ClassWithVirtualFunctions) << endl;

	return 0;
}

#include <iostream>

using namespace std;

*/
class EmptyClass
{
};

class AbstractClass
{
public:
	virtual void funcOne() = 0;
	virtual void funcTwo() = 0;
};

class NotAbstrClass
{
  public: int virtFunc(int);	
};

class VirtualFunc
{
	//public: int virtFunc(int);
	virtual void display() {
	}
};

class MixClass
{
public:
	virtual void clFunc(int);
	static int i;
	int j;
};

int main()
{
	// Print size of class or class objects
	cout << "Size of empty class: " << sizeof(EmptyClass) << endl;
	cout << "Size of Abstract class :" << sizeof(AbstractClass) << endl;
	cout << "Size of Non Abstract class normal function: " << sizeof(NotAbstrClass) << endl;
	cout << "Size of class with virtual function: " << sizeof(VirtualFunc) << endl;
	cout << "Size of Mix class: " << sizeof(MixClass) << endl;


	return 0;
}