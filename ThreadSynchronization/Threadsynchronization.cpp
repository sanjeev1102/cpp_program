
#include<iostream>
#include<thread>


using namespace std;

void threadFn() {

	cout << "i am inside threadFn() function" << endl;

}

int main() {

	thread t1(threadFn);

	

	t1.join();
	return 0;
}
