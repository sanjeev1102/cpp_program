#include<iostream>
using std::cout;
using std::endl;
namespace nm14
{
	using FPTR = void(*)();
	void DoJob1(FPTR fp)
	{
		cout << "Vandor job started" << endl;
		fp();//callback
		cout << "Vandor job completed" << endl;
	}
	class IUrJob
	{
	public:
		virtual void YourJob() = 0;
	};

	void DoJob2(IUrJob *job)
	{
		cout << "Vandor job started" << endl;
		job->YourJob();//callback
		cout << "Vandor job completed" << endl;
	}
	template<typename T>
	void DoJob3(T obj)
	{
		cout << "Vandor job started" << endl;
		obj->MyJob();//callback
		cout << "Vandor job completed" << endl;
	}
	template<typename T>
	void DoJob4(T obj)
	{
		cout << "Vandor job started" << endl;
		obj();//callback
		cout << "Vandor job completed" << endl;
	}
	//--------------------vendor code ends-----------
	void ClientFun()
	{
		cout << "Client Job done " << endl;
	}
	class ClientClass :public IUrJob
	{
	public:
		void YourJob() override
		{
			cout << "Client Class fun" << endl;
		}
	};

	class ClientClassNew
	{
	public:
		void MyJob()
		{
			cout << "Client My Job" << endl;
		}
	};

	class FUNCTOR
	{
	public:
		void operator()()
		{
			cout << "Client job from functor" << endl;
		}
	};
	void main1()
	{
		FPTR fp = ClientFun;
		DoJob1(fp);
		cout << "___________________________" << endl;
		DoJob2(new ClientClass());
		cout << "___________________________" << endl;
		DoJob3(new ClientClassNew());
		cout << "___________________________" << endl;
		DoJob4(fp);
		cout << "___________________________" << endl;
		FUNCTOR fnc;
		DoJob4(fnc);
	}

	//---vendor code---
	class CA
	{
		int x;
	public:
		CA(int x) :x(x)
		{
		}
		void fun1()
		{
			cout << "CA::fun1 x=" << x << endl;
		}
		void fun2()
		{
			cout << "CA::fun2 x=" << x << endl;
		}
	};
	using DLG = void(CA::*)();//typedef void (CA::*DLG)();
	void DoJob5(CA & obj, DLG dlg)
	{
		cout << "Apple" << endl;
		(obj.*dlg)();
		cout << "Orange" << endl;
	}
	//-------vendor code ends

	void main()
	{
		CA obj1(100), obj2(200);
		DLG dl = &CA::fun2;
		DoJob5(obj2, dl);
	}
}