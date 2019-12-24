struct SA{
	void f(int i){
	}
};
struct SB{
	void f2(int i){
	}
};

struct Base{
	virtual void Call(int i)=0;
};
template<typename T>
struct Functor :Base
{
	void (T::*pfun)(int i);
    T* pObj;      

    virtual void Call(int i)
    { 
		  (*pObj.*pfun)(i);	             // execute member function
	}
};
void main()
{
	SA o1;	SB o2;
	Functor<SA> f1; Functor<SB> f2;
	f1.pObj= &o1;
	f1.pfun = SA::f;
	f2.pObj =&o2;
	f2.pObj = SB::f2;
	Base* vtable[] = {&f1,&f2};

	vtable[0]->Call(10);
	vtable[1]->Call(10);
}

