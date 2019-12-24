#include<iostream>
#include<string>
using namespace std;
namespace nm16
{
	class IBusiness
	{
	public:
		virtual void DoBusiness(string msg) = 0;
	};

	class Business :public IBusiness
	{
	public:
		void DoBusiness(string msg) override
		{
			cout << "Business executed " << msg << endl;
		}
	};

	class Proxy :public IBusiness
	{
		Business& actual;
	public:
		Proxy(Business& actual) :actual(actual)
		{
		}
		void DoBusiness(string msg) override
		{
			actual.DoBusiness(msg);
			//channel communication 
			msg = "[ " + msg + "]";
			actual.DoBusiness(msg);
			cout << "--------------------------------" << endl;

		}
	};


	int main()
	{
		Business business;
		Proxy proxy(business);

		proxy.DoBusiness("India is great");
		proxy.DoBusiness("India wins WI");
		proxy.DoBusiness("India will win SouthAfrica");
		return 0;
	}
}