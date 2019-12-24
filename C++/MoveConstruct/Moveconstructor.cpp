

#include <iostream>
using namespace std;

class MemoryPage

{

	size_t size;

	char* buf;

public:

	explicit MemoryPage(int sz = 512) :

		size(sz), buf(new char[size]) {}

	~MemoryPage(delete[] buf;
}

//typical C++03 copy ctor and assignment operator

MemoryPage(const MemoryPage&);

MemoryPage& operator=(const MemoryPage&);

};