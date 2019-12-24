#include<iostream>
#include<string>
using namespace std;
namespace nm12
{
	//
	//.h
	class Logger//
	{
		struct Body;
		Body *ptr;
	public:
		Logger(int x, int y);

		virtual void Log(string info);
	};

	//3.cpp
	struct Logger::Body
	{
		int _x;
		int _y;
		Body(int x, int y) :_x(x), _y(y)
		{
		}
		int GetX()
		{
			return _x;
		}
	};
	//1.cpp

	Logger::Logger(int x, int y) :ptr(new Body(x, y))
	{

	}

	void Logger::Log(string info)
	{
		cout << "info logged " << info << " " << ptr->GetX() << endl;
	}


	//2.cpp
	void main()
	{
		Logger log(100, 200);
		log.Log("asdsa");
	}
}