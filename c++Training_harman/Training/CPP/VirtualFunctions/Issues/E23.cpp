#include<iostream>
using namespace std;

namespace Ex23
{
	struct Exception
	{
		void dump()		{			cout<<"unknown error"<<endl;		}
	};
	struct SocketException : Exception
	{
		void dump()		{			cout<<"Socket error"<<endl;		}
	};
};
using namespace Ex23;

void main23()
{
	try
	{
		//if(...)
			throw SocketException();

	}catch(Exception& e)
	{
		e.dump();
	}
}
