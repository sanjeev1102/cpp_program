#include<iostream>
using namespace std;

//It is a bad practice to throw exception in the destructor

namespace Ex33
{
	struct CA
	{
		bool flag;
		CA()		{		cout<<"CA created"<<endl;	}
		~CA()
		{
			if(flag==true)
				throw "Invalid State"; //throw cannot be nested

			cout<<"CA destroyed"<<endl;
		}
	};
};
using namespace Ex33;
void main33()
{
	try{
		CA obj;
		obj.flag = true;
		
		throw "some error";

	}catch(char* err){
		cout<<err<<endl;
	}
}