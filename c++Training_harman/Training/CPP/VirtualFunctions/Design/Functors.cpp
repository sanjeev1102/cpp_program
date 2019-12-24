#include<iostream>
using namespace std;

class GameObject
{
};
struct IFunctor
{
	virtual void operator()(GameObject& lhs,GameObject &rhs)=0;  // call using operator
    virtual void Call(GameObject& lhs,GameObject &rhs)=0;        // call using function
};
template <typename T>
class Functor : public IFunctor
{
	typedef void (T::*FUNPTR)(GameObject& lhs,GameObject &rhs);
private:
 	  FUNPTR pfun;
      T* pObj;                  // pointer to object
public:
      // constructor - takes pointer to an object and pointer to a member and stores
      // them in two private variables
      Functor(T* _pObj, FUNPTR _pfun)
      { 
		  pObj = _pObj;  
		  pfun=_pfun; 
	  }
      virtual void operator()(GameObject& lhs,GameObject &rhs)
      { 
		  (*pObj.*pfun)(lhs,rhs);	             // execute member function
	  }
      virtual void Call(GameObject& lhs,GameObject &rhs)
      { 
		  (*pObj.*pfun)(lhs,rhs);	             // execute member function
	  }
   };

//-----------------------------------------------------------------------------------------
class CollideHandler1
{
public:
	void Collide(GameObject& lhs,GameObject &rhs) 
	{ 
		cout <<"Ship Collide With Satellite"<< endl; 
	}
};
class CollideHandler2
{
 public:
	void Collide(GameObject& lhs,GameObject &rhs) 
	{ 
		cout <<"Station Collide With Aestroid"<< endl; 
	}
};
int main()
{
      CollideHandler1 c1;
      CollideHandler2 c2;
      // 2. instantiate Functor objects ...
      //    a ) functor which encapsulates pointer to object and to member of TA
      Functor<CollideHandler1> handler1(&c1, &CollideHandler1::Collide);
      //    b) functor which encapsulates pointer to object and to member of TB
      Functor<CollideHandler2> handler2(&c2, &CollideHandler2::Collide);
      // 3. make array with pointers to TFunctor, the base class, and initialize it
      IFunctor* vTable[] = { &handler1, &handler2 };
      // 4. use array to call member functions without the need of an object
	  GameObject o1;
	  GameObject o2;

      vTable[0]->Call(o1,o2);        // via function "Call"
      (*vTable[1])(o1,o2);        // via operator "()"
}

