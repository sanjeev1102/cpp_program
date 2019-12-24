#include<iostream>
using namespace std;
namespace nm23
{
	enum Signal;//forward declaration c++11

	void fun(Signal);

	enum Signal
	{
		Red,
		Green,
		Yellow
	};

	void fun(Signal  sig)
	{
		switch (sig)
		{
		case Red:
			cout << "apple" << endl;
			//[fallthrough] //c++17
		case Green:
			cout << "orange" << endl;
			break;
		case Yellow:
			cout << "pine" << endl;
			break;
		default:
			break;
		}
	}
	void main1()
	{
		fun(Signal::Red);
	}




	enum class  Weather//scoped enums from c++11 onwards
	{
		cloudy,
		hot,
		chill
	};


	enum class Drinks :int8_t //enums typed
	{
		soft,
		hot,
		cool
	};

	void main()
	{
		Weather wthr = Weather::cloudy;
		switch (wthr)
		{
		case Weather::cloudy:
			break;
		case Weather::hot:
			break;
		case Weather::chill:
			break;
		default:
			break;
		}
	}
}