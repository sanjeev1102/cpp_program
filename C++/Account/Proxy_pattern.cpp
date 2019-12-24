#include<iostream>
#include<string>
using namespace std;

/*
Proxy pattern -> Proxy Design Pattern
Proxy means ‘in place of’, representing’ or ‘in place of’ or ‘on behalf of’ are literal meanings of proxy and that directly explains Proxy 
Design Pattern.
Proxy is a structural design pattern that lets you provide a substitute or placeholder for another object. A proxy controls access to the original object,
allowing you to perform something either before or after the request gets through to the original object.

A real world example can be a cheque or credit card is a proxy for what is in our bank account. It can be used in place of cash, and provides a means of accessing that cash when required. 
And that’s exactly what the Proxy pattern does – “Controls and manage access to the object they are protecting“.

When to use this pattern?
Proxy pattern is used when we need to create a wrapper to cover the main object’s complexity from the client.

Types of proxies : 
Remote proxy:
Virtual proxy:
Protection proxy:
Smart Proxy:

Some Examples

A very simple real life scenario is our college internet, which restricts few site access. The proxy first checks the host you are connecting to, if it is not part of restricted site list, 
then it connects to the real internet. This example is based on Protection proxies.
*/
//namespace nm16
//{
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
			//channel communication 
			msg = "[ " + msg + "]";
			actual.DoBusiness(msg);
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
//}