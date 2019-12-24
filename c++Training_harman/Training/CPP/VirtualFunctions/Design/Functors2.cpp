#include<iostream>
using namespace std;

class BaseFunctor
{
public:
      // two possible functions to call member function. virtual cause derived
      // classes will use a pointer to an object and a pointer to a member function
      // to make the function call
      virtual void operator()(const char* string)=0;  // call using operator
      virtual void Call(const char* string)=0;        // call using function
};


template <typename T> 
class Functor : public BaseFunctor
{
	typedef void (T::*FUNPTR)(const char*);  
private:
      FUNPTR pfun;   // pointer to member function
      T* obj;                  // pointer to object
public:
      // constructor - takes pointer to an object and pointer to a member and stores
      // them in two private variables
      Functor(T* obj, FUNPTR pfun)
      { 
		  obj = obj;  
		  pfun=pfun; 
	  }

      // override operator "()"
      virtual void operator()(const char* string)
       { (*obj.*pfun)(string);};              // execute member function

      // override function "Call"
      virtual void Call(const char* string)
        { (*obj.*pfun)(string);};             // execute member function
};

class TClassA
{
public:
    void Display(const char* text) { cout << text << endl; };
};
class TClassB{
public:
      void Display(const char* text) { cout << text << endl; };
};

void main()
{
      TClassA objA;
      TClassB objB;

      Functor<TClassA> specFuncA(&objA, &TClassA::Display);
      Functor<TClassB> specFuncB(&objB, &TClassB::Display);

      BaseFunctor* vTable[] = { &specFuncA, &specFuncB };


      vTable[0]->Call("TClassA::Display called!");        // via function "Call"
      (*vTable[1])   ("TClassB::Display called!");        // via operator "()"

}

