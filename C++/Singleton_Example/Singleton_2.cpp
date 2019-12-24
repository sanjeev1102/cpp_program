#include <mutex>
#include <iostream>
using namespace std;
#include <thread>         // std::thread
#include <mutex>          // std::mutex

std::mutex mtx;

// singletonSingleThreaded.cpp

class MySingleton {
public:
	static MySingleton* getInstance() {
		mtx.lock();
		if (!instance)
		{
			instance = new MySingleton;
			cout << "creatingggggggggggggggg" << endl;

		}
		// volatile int dummy{};
		mtx.unlock();
		return instance;
	}
	int data;
	int getData() {
		return this->data;
	}

	void setData(int data) {
		this->data = data;
	}
private:
	static MySingleton* instance;
	MySingleton() { data = 0; }
	~MySingleton() = default;
	MySingleton(const MySingleton&) = delete;
	MySingleton& operator=(const MySingleton&) = delete;

};


//Initialize pointer to zero so that it can be initialized in first call to getInstance
MySingleton* MySingleton::instance = nullptr;

int main() {
	MySingleton* s = s->getInstance();
	cout << s->getData() << endl;
	s->setData(100);
	cout << s->getData() << endl;
	return 0;
}
