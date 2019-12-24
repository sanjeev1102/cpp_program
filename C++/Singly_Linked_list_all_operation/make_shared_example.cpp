
#include<iostream>
using namespace std;
#include<map>

// Map stores the element in accending order or alphabatical order w.r.t key, where are unordered map stores the element in random order
// hence performance wise we should always choose unordered map.

namespace nm05 {

class CWiFiPresCtrlWlanProxy
{
public:
	CWiFiPresCtrlWlanProxy() {

		cout << "CWiFiPresCtrlWlanProxy Constructorrrr....." <<endl;
	}

	~CWiFiPresCtrlWlanProxy() {

		cout << "Destructor CWiFiPresCtrlWlanProxy Destructor....." << endl;
	}
};
	int main()
	{
		// When we use shared_ptr  it called constructor as well as destructor automatically
		std::shared_ptr<CWiFiPresCtrlWlanProxy> mpWlanProxyInstance = nullptr;
		mpWlanProxyInstance = std::make_shared<CWiFiPresCtrlWlanProxy>();

		// below syntax will only call constructor but not destructor..
	//	CWiFiPresCtrlWlanProxy* mpWlanProxyInstance;
	//	mpWlanProxyInstance = new CWiFiPresCtrlWlanProxy();
		return 0;
	}
}