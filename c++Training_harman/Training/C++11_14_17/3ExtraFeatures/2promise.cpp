/*
A std::promise permits

to set a value, a notification or an exception. That result can in addition delayed be provided by the promise.
A std::future permits to

pick up the value from the promise.
asks the promise, if the value is available.
wait for the notification of the promise. That waiting can be done with a relative time duration or an absolute time point. => Replacement for condition variables.
create a shared future (std::shared_future).

*/
#include <future>
#include <iostream>
#include <thread>
#include <utility>
namespace nm02
{

	void initiazer(std::promise<int> * promObj)
	{
		std::cout << "Inside Thread" << std::endl;     promObj->set_value(35);
	}

	int main1()
	{
		std::promise<int> promiseObj;
		std::future<int> futureObj = promiseObj.get_future();
		std::thread th(initiazer, &promiseObj);
		std::cout << futureObj.get() << std::endl;
		th.join();
		return 0;
	}



	void product(std::promise<int>&& intPromise, int a, int b) {
		intPromise.set_value(a*b);
	}

	struct Div {

		void operator() (std::promise<int>&& intPromise, int a, int b) const {
			intPromise.set_value(a / b);
		}

	};

	int main2() {
		int a = 20;
		int b = 10;
		std::cout << std::endl;
		// define the promises
		std::promise<int> prodPromise;
		std::promise<int> divPromise;
		// get the futures
		std::future<int> prodResult = prodPromise.get_future();
		std::future<int> divResult = divPromise.get_future();
		// calculate the result in a separat thread
		std::thread prodThread(product, std::move(prodPromise), a, b);
		Div div;
		std::thread divThread(div, std::move(divPromise), a, b);

		// get the result
		std::cout << "20*10= " << prodResult.get() << std::endl;
		std::cout << "20/10= " << divResult.get() << std::endl;

		prodThread.join();

		divThread.join();

		std::cout << std::endl;
		return 0;
	}
}