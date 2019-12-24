
// shared_ptr-examples.cpp
// The following examples assume these declarations:
#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class Test
{
public:
	Test(int a = 0) : m_a(a)
	{
	}
	~Test()
	{
		cout << "Calling destructor" << endl;
	}
public:
	int m_a;
};
int main()
{
		shared_ptr<Test> sptr1(new Test[5], [](Test* p) { delete[] p; });

	return 0;

}