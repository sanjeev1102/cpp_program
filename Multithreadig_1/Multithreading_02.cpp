
#include<iostream>
#include<vector>
#include <thread>
using namespace std;

void Function_1() {

	cout << "In side Function Function_1()" << endl;

}

int main() {

	thread t1(Function_1);

	t1.join();
	for (int i = 0; i < 200; i++) {
		cout << "From Main : " << i << endl;
	}


	return 0;
}