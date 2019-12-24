#include<iostream>
using namespace std;

//************************************************************
class CA1
{
	int *pt;
public:
	CA1(int x) :pt(new int(x))//param
	{
		cout << "param" << endl;
	}
	CA1(const CA1& par) :pt(new int(*par.pt))//copy ctor
	{
		cout << "copy" << endl;
	}
	CA1(CA1 && par) :pt(par.pt)
	{
		par.pt = nullptr;
	}
	int * getAddress()
	{
		return pt;
	}
	~CA1()
	{
		cout << "destructor ..." << endl;
		delete pt;
	}
};
CA1  getFactory(int s)
{
	CA1 temp(s);
	cout << "temp.pt =" << temp.getAddress() << endl;
	return temp;
}
void main28_1()
{
	CA1 c1(10);
	CA1 c2 = getFactory(45);
	cout << "c1.pt =" << c1.getAddress() << endl;
	cout << "c2.pt =" << c2.getAddress() << endl;
}
//************************************************************
class ArrayWrapper
{
public:
	ArrayWrapper(int n)
		: _p_vals(new int[n])
		, _size(n)
	{
		cout << "ArrayWrapper param was called ..." << endl;
		for (size_t i = 0; i < n; i++)
		{
			_p_vals[i] = (i + 1) * 10;

		}
	}
	// copy constructor
	ArrayWrapper(const ArrayWrapper& other)
		: _p_vals(new int[other._size])
		, _size(other._size)
	{
		cout << "ArrayWrapper copy was called ..." << endl;
		for (int i = 0; i < _size; ++i)
		{
			_p_vals[i] = other._p_vals[i];
		}
	}
	// move constructor
	ArrayWrapper(ArrayWrapper&& other)
		: _p_vals(other._p_vals)
		, _size(other._size)
	{
		cout << "ArrayWrapper Move was called ..." << endl;
		other._p_vals = NULL;
		other._size = 0;
	}
	
	void Display()
	{
		for (size_t i = 0; i < _size; i++)
		{
			cout <<_p_vals<<"_p_vals[" << i << "]=" << _p_vals[i] << endl;
		}
	}
	~ArrayWrapper()
	{
		delete[] _p_vals;
	}
	int *_p_vals;
private:

	int _size;
};

ArrayWrapper getWrapper(int size)
{
	ArrayWrapper temp(size);
	cout << "&temp=" << &temp << " and arr ="<<temp._p_vals <<endl;
	return temp;
}


void main28_2()
{
	ArrayWrapper wrap(5);
	//ArrayWrapper wrap1(move(wrap));
	ArrayWrapper wrap1=getWrapper(5);
	cout << "&wrap=" << &wrap << " and arr =" << wrap._p_vals << endl;
	cout << "&wrap1=" << &wrap1 << " and arr =" << wrap1._p_vals << endl;
	cout << "______________________________" << endl;
	wrap.Display();
	cout << "______________________________" << endl;
	wrap1.Display();
	cout << "______________________________" << endl;

}
//***********************The use of move****************************************
class Metadata
{
	int *arr;
public:
	Metadata(int val) :arr(new int(val))
	{
		cout << "metadata param called ..." << endl;
	}
	Metadata(const Metadata & par) :arr(new int(*par.arr))
	{
		cout << "metadata copy called ..." << endl;
	}
	Metadata(Metadata&& par) :arr(par.arr)
	{
		cout << "metadata move called ..." << endl;
		par.arr = nullptr;
	}
	~Metadata()
	{
		delete arr;
	}
};
class Container1
{
	int *pt;
	Metadata met;
public:
	Container1(int x) :pt(new int(x)), met(x)
	{
		cout << "param pt=" << pt << endl;
	}
	Container1(const Container1 & par) :pt(new int(*par.pt)), met(par.met)
	{
		cout << "copy pt=" << pt << endl;
	}
	Container1(Container1 && par) :pt(par.pt), met(std::move(par.met))
	{
		cout << "move pt=" << pt << endl;
		par.pt = nullptr;
	}
	int * getAddress()
	{
		return pt;
	}
	~Container1()
	{
		delete pt;
	}
};

Container1  getContainer(int size)
{
	Container1 temp(size);
	return temp;
}

void main28_3()
{
	Container1 c1(10);
	Container1 c2(c1);
	Container1 c3 = getContainer(3);
	cout << "__________________" << endl;
	cout << "c1=" << c1.getAddress() << endl;
	cout << "c2=" << c2.getAddress() << endl;
	cout << "c3=" << c3.getAddress() << endl;
}
//**********************************************************************
int x=99;

int getInt()
{
	return x;
}

int && getRvalueInt()
{
	// notice that it's fine to move a primitive type--remember, std::move is just a cast
	return std::move(x);
}
void printAddress(const int& v) // const ref to allow binding to rvalues
{
	cout << reinterpret_cast<const void*>(&v) << endl;
}

void main28_4()
{
	printAddress(getInt());
	printAddress(x);
	cout << "_____________" << endl;
	printAddress(getRvalueInt());
	printAddress(x);

}