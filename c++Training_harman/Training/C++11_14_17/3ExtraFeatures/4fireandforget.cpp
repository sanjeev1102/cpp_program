/*
std::async creates special futures. 
These futures wait in its destructor, until the work of the associated promise is done.

*/

#include <iostream>
#include <future>
namespace nm04
{
	int main1() {

		std::cout << std::endl;
		std::async([]() {std::cout << "fire and forget" << std::endl; });
		std::cout << "main done " << std::endl;
		return 0;
	}

	/*
	One after another(sequence)
	The future, that is created by std::async, waits in its destructor, until its work is done.
	An other word for waiting is blocking. The future blocks the progress of the program in its destructor.

	*/
	int main2() {

		std::cout << std::endl;

		std::async(std::launch::async, [] {
			std::this_thread::sleep_for(std::chrono::seconds(2));
			std::cout << "first thread" << std::endl;
		});

		std::async(std::launch::async, [] {
			std::this_thread::sleep_for(std::chrono::seconds(1));
			std::cout << "second thread" << std::endl; }
		);

		std::cout << "main thread" << std::endl;
		return 0;
	}

	/*
	bind the future to a variable,
	the blocking will take place at the time point,
	when the variable goes out of scope.
	*/




	int main3() {

		std::cout << std::endl;

		auto first = std::async(std::launch::async, [] {
			std::this_thread::sleep_for(std::chrono::seconds(2));
			std::cout << "first thread" << std::endl;
		});

		auto second = std::async(std::launch::async, [] {
			std::this_thread::sleep_for(std::chrono::seconds(1));
			std::cout << "second thread" << std::endl; }
		);

		std::cout << "main thread" << std::endl;
		return 0;
	}
}