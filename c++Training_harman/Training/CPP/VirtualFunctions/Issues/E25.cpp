#include<iostream>
using namespace std;

namespace Ex25
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

using namespace Ex25;

void main25()
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
