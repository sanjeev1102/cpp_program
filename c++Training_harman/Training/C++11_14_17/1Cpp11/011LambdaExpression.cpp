#include <iostream>
#include<vector>
#include<future>
using namespace std;
using namespace std::placeholders;
//simple lambda creation
void main11_1()
{
	auto func = []() { cout << "Hello world" << endl; };
	func(); // now call the function
}

//************************************Lambda simple capture
//simple lambda using a capture by value
void main11_2()
{
	int x = 10;
	int y = 20;
	cout << "Environment ........" << endl;
	cout << "x=" << x << " and &x=" << &x << endl;
	cout << "y=" << y << " and &y=" << &y << endl;
	auto func = [=]() mutable{
				cout << "In lambda ..............." << endl;
				cout << "Hello x=" << x << " and y=" << y << endl; 
				cout << "x=" << x << " and &x=" << &x << endl;
				cout << "y=" << y << " and &y=" << &y << endl;
				x++;
	};
	func();
	auto func1 = [=]() mutable {
		cout << "In lambda ..............." << endl;
		cout << "Hello x=" << x << " and y=" << y << endl;
		cout << "x=" << x << " and &x=" << &x << endl;
		cout << "y=" << y << " and &y=" << &y << endl;
		x++;

	};
	func1();
}

//simple lambda using a capture by reference
void main11_3()
{
	int x = 10;
	int y = 20;
	cout << "Environment ........" << endl;
	cout << "x=" << x << " and &x=" << &x << endl;
	cout << "y=" << y << " and &y=" << &y << endl;
	auto func = [&](){
		cout << "In lambda ..............." << endl;
		cout << "Hello x=" << x << " and y=" << y << endl;
		cout << "x=" << x << " and &x=" << &x << endl;
		cout << "y=" << y << " and &y=" << &y << endl;
		x = 99;
		y = 999;
	};
	func();
	cout << "Environment ........" << endl;
	cout << "x=" << x << " and &x=" << &x << endl;
	cout << "y=" << y << " and &y=" << &y << endl;
}

//************************************Lambda capture*********************
//simple lambda capture selections 1
void main11_4()
{
	int x = 10;
	int y = 20;
	int z = 30;
	cout << "Environment ........" << endl;
	cout << "x=" << x << " and &x=" << &x << endl;
	cout << "y=" << y << " and &y=" << &y << endl;
	cout << "z=" << z << " and &z=" << &z << endl;
	auto func = [=,&z](){
		cout << "In lambda ..............." << endl;
		cout << "Hello x=" << x << " and y=" << y << endl;
		cout << "x=" << x << " and &x=" << &x << endl;
		cout << "y=" << y << " and &y=" << &y << endl;
		cout << "z=" << z << " and &z=" << &z << endl;
		//x = 99;
		//y = 999;
		z = 888;
	};
	func();
	cout << "Environment ........" << endl;
	cout << "x=" << x << " and &x=" << &x << endl;
	cout << "y=" << y << " and &y=" << &y << endl;
	cout << "z=" << z << " and &z=" << &z << endl;
}

//simple lambda capture selections 2
void main11_5()
{
	int x = 10;
	int y = 20;
	int z = 30;
	cout << "Environment ........" << endl;
	cout << "x=" << x << " and &x=" << &x << endl;
	cout << "y=" << y << " and &y=" << &y << endl;
	cout << "z=" << z << " and &z=" << &z << endl;
	auto func = [x, &z](){
		cout << "In lambda ..............." << endl;
		//cout << "Hello x=" << x << " and y=" << y << endl;
		cout << "x=" << x << " and &x=" << &x << endl;
		//cout << "y=" << y << " and &y=" << &y << endl;
		cout << "z=" << z << " and &z=" << &z << endl;
		//x = 99;
		//y = 999;
		z = 888;
	};
	func();
	cout << "Environment ........" << endl;
	cout << "x=" << x << " and &x=" << &x << endl;
	cout << "y=" << y << " and &y=" << &y << endl;
	cout << "z=" << z << " and &z=" << &z << endl;
}



//simple lambda capture selections 3
void main11_6()
{
	int x = 10;
	int y = 20;
	int z = 30;
	cout << "Environment ........" << endl;
	cout << "x=" << x << " and &x=" << &x << endl;
	cout << "y=" << y << " and &y=" << &y << endl;
	cout << "z=" << z << " and &z=" << &z << endl;
	auto func = [x](){
		cout << "In lambda ..............." << endl;
		//cout << "Hello x=" << x << " and y=" << y << endl;
		cout << "x=" << x << " and &x=" << &x << endl;
		//cout << "y=" << y << " and &y=" << &y << endl;
		//cout << "z=" << z << " and &z=" << &z << endl;
		//x = 99;
		//y = 999;
		//z = 888;
	};
	func();
	cout << "Environment ........" << endl;
	cout << "x=" << x << " and &x=" << &x << endl;
	cout << "y=" << y << " and &y=" << &y << endl;
	cout << "z=" << z << " and &z=" << &z << endl;
}



//simple lambda capture selections 4
class CA
{
	int x;
	int y;
public:
	CA(int x, int y) :x(x), y(y)
	{
	}
	void fun()
	{
		int z = 199;
		auto func = [this,&z](){
			x++;
			y++;
			z++;
			cout << "x=" << x << " and y=" << y <<" and z="<<z<< endl; };
		func();
		cout << "x=" << x << " and y=" << y << " and z=" << z << endl;
	}
	
};

void main11_7()
{
	CA obj = { 11, 22 };
	obj.fun();
}
//********************Lambda nesting
void main11_7_1()
{
	int x = 10;
	int y = 20;
	auto f1 = [&]() {
		cout << "Apple  x=" << x << " and y=" << y << endl;
		int z = 30;
		//int x = 999;
		auto f2 = [&](){cout << "Orange z=" << z << " x=" << ++x << " and y=" << y << endl; };
		x = 1000;
		f2();
	};

	f1();
	cout << "x=" << x << endl;
}


//************************************************************lambda call back****************** 
//simple lambda in callback
typedef void(*FPTR)();
void DoBusiness(FPTR fp)
{
	cout << "Business started ..." << endl;
	fp();
	cout << "Business completed ..." << endl;
}

void  main11_8()
{
	int x = 10;
	int y = 20;
	int z = 30;
	DoBusiness([](){cout << "Hello ..." << endl; });
}

//a simpe call back
template<typename T> 
void DoBusinessEx(T fp)
{
	cout << "Business started ..." << endl;
	fp();
	cout << "Business completed ..." << endl;
}

void  main11_9()
{
	int x = 10;
	int y = 20;
	int z = 30;
	DoBusinessEx([=](){cout << "Hello ..." << endl;	cout << "x=" << x << " and y=" << y << " and z=" << z << endl; });
}


//The use of function type
void DoBusinessWithFunctionType(std::function<void(void)> fp)
{
	cout << "Business started new..." << endl;
	fp();
	cout << "Business completed new ..." << endl;
}

void main11_10()
{
	int x = 10;
	int y = 20;
	int z = 30;
	DoBusinessWithFunctionType([=](){cout << "Hello ..." << endl;	cout << "x=" << x << " and y=" << y << " and z=" << z << endl; });
}


//*******************************callback on member functions
class CB
{
	int x;
	int y;
public:
	CB(int x, int y) :x(x), y(y)
	{
	}
	void fun(std::function<void(void)> fp)
	{
		cout << "in cb fun" << endl;
		fp();
	}
};


void main11_11()
{
	int h = 10;
	CB obj = { 11, 22 };
	obj.fun([=](){cout << "from main h=" << h << endl; });
}
//**********************************************using bind
float div1(float a, float b){ return a / b; }
void main11_11_1()
{
	cout << "6 / 1 =" << div1(6, 1) << endl;
	cout << "6 / 2 =" << div1(6, 2) << endl;
	cout << "6 / 3 =" << div1(6, 3) << endl;
	cout << "______________________________" << endl;
	function<float(float, float)> inv_div = bind(div1, _2, _1);
	cout << "1/6 =" << inv_div(6, 1) << endl;
	cout << "2/6 =" << inv_div(6, 2) << endl;
	cout << "3/6 =" << inv_div(6, 3) << endl;
	cout << "______________________________" << endl;
	function<float(float)> div_by_6 = bind(div1, _1, 6);
	cout << "1 / 6=" << div_by_6(1) << endl;
	cout << "2 / 6=" << div_by_6(2) << endl;
	cout << "3 / 6=" << div_by_6(3) << endl;
}
//*******************************member function callback
struct Abc
{
	void f1(int x)
	{
		cout << "india ... x=" << x << endl;
	}
	void f2(int x)
	{
		cout << "Bharath ... x=" << x << endl;
	}
};

void Catty(std::function<void(Abc&, int)> pt, Abc &obj)
{
	cout << "app" << endl;
	pt(obj, 10);
	cout << "dd" << endl;
}


void main11_11_2()
{
	Abc obj;
	std::function<void(Abc&, int)> pt = mem_fn(&Abc::f2);
	Catty(pt, obj);
	//----------------------------------------------
	function<void(int)> f1 = bind(&Abc::f2, obj, _1);//using namespace std::placeholders;
	f1(20);
}

//********************call back and stl*********************
void main11_12()
{
	vector<int> v{ 1, 2, 3, 45, 6 };
	for_each(v.begin(), v.end(), [](int val){cout << val * 2 << endl; });
}


//**************************************Deduce with return 1*****************
void main11_13()
{
	int x=10;
	int y=30;
	auto func = []{return 404; };
	cout << func() << endl;
}

//*********************************Deduce with return 2*********************
void VendorJob(std::function<int()> val)
{
	cout << "Red Apple" << endl;
	int m=val();
	cout << "green Apple order="<<m << endl;
}
void  main11_14()
{
	int local = 909;
	VendorJob([=]{cout << "local=" << local << endl; return 401; });

}

//******************************************deduce with return 3******************
template<typename T>
void VendorJobEx(std::function<T()> val)
{
	cout << "Red Apple delhi " << endl;
	T m = val();
	cout << "green Apple ooty order=" << m << endl;
}
void main11_15()
{
	int local = 909;
	//VendorJobEx([=]{cout << "local=" << local << endl; return 405; }); //cannot be deduced
	VendorJobEx<int>([=]{cout << "local=" << local << endl; return 405; });
}

//*********************************specify return type.....
void DoJob(std::function<int()> val)
{
	cout << "Red Apple delhi " << endl;
	int m = val();
	cout << "green Apple ooty order=" << m << endl;
}
void main11_16()
{
	int local = 909;
	DoJob([=]()->int{cout << "local=" << local << endl; return 407; });
	//DoJob([=](){cout << "local=" << local << endl; return 407; });//also called like this
}

//*********************************specify return type and templates.....

template<typename T1,typename T2>
void DoJobEx(T1 val)
{
	cout << "Red Apple delhi " << endl;
	T2 m = val();
	cout << "green Apple ooty order=" << m << endl;
}

template<typename T>
void DoJobExNew(std::function<T()> val)
{
	cout << "Red Apple delhi " << endl;
	T m = val();
	cout << "green Apple ooty order=" << m << endl;
}
void main11_17()
{
	int local = 909;
	DoJobEx<std::function<int()>,int>([=]()->int{cout << "local=" << local << endl; return 325; });
	DoJobExNew<int>([=]()->int{cout << "local=" << local << endl; return 407; });
}
//*****************************lambda and exception restriction*****************
void MyBusiness(std::function<int()throw()> fp)
{
	cout << "what has happened ...?" << endl;
	try
	{

		int y = fp();
		cout << "something has happenned...!!! y=" << y << endl;
	}
	catch (invalid_argument args)
	{
		cout << args.what() << endl;
	}
}
void main11_18()
{
	int local = 999;
	MyBusiness([=]() throw()->int {cout << "here we are ...local=" << local << endl;  return 123; });
}

//*********************************************************************************
//*****************************recursive lambda*******************************
void main11_19()
{
	function<int(int)> f = [&f](int n)
	{
		return n <= 1 ? 1 : n * f(n - 1);
	};

	int x = f(4); //x = 24
	cout << "x=" << x << endl;
}

//*****************************************