#include<iostream>
using namespace std;

namespace Ex24
{
	struct Exception
	{
		virtual void dump()		{			cout<<"unknown error"<<endl;		}
	};
	struct SocketException : Exception
	{
		virtual void dump()		{			cout<<"Socket error"<<endl;		}
	};
};
using namespace Ex24;

void main24()
{
	try
	{
		//if(...)
			throw SocketException();

	}catch(Exception e)
	{
		e.dump();
	}
}
