#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

namespace nm02 {

	struct Point
	{
		double x, y;

		Point() {
			x = (rand() % 10000) - 5000;
			y = (rand() % 10000) - 5000;
		}

		void Print() {

			cout << "[" << x << ", " << y << "]";
		}

	};

	int main() {
		int count = 100;
		vector<Point> points;

		for (int i = 0; i < count; i++)
			points.push_back(Point());

		cout << "Unsorted: " << endl;

		for (int i = 0; i < 10; i++)
			points[i].Print();

		sort(points.begin(), points.end(),
			[](const Point& a, const Point& b)->bool {
				return (a.x * a.x + (a.y * a.y) < (b.x * b.x) + (b.y * b.y));
			});

		cout << endl;

		cout << "Sorted : " << endl;

		for (int i = 0; i < 10; i++)
			points[i].Print();

		return 0;
	}

}