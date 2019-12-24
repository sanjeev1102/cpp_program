#include <new> // Required for placement 'new'.

struct Point {
	Point() {}
	Point(int x, int y) : x_(x), y_(y) {}
	int x_, y_;
};

union U {
	int z;
	double w;
	//Point p; // Illegal in C++03; legal in C++11.
	//U() { new(&p) Point(); } // Due to the Point member, a constructor definition is now required.
};


void main19()
{
	U u;
}