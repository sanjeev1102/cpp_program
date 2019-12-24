#include<iostream>
using std::cout;
using std::endl;
namespace nm6
{
	class Circle
	{
	public:
		virtual void DrawCircle() = 0;
		virtual void CirclePerimeter() = 0;
	};
	class Rect
	{
	public:
		virtual void DrawRect() = 0;
		virtual void RectPerimeter() = 0;
	};

	class Shape :public Circle, public Rect
	{
	public:
		virtual void DrawCircle()
		{
			cout << "Circle Drawn " << endl;
		}
		virtual void CirclePerimeter()
		{
			cout << "Circle Perimeter " << endl;
		}
		virtual void DrawRect()
		{
			cout << "Rect Drawn " << endl;
		}
		virtual void RectPerimeter()
		{
			cout << "Rect Perimeter " << endl;
		}
	};

	//factory
	Circle * CreateShape()
	{
		static Shape sp;
		//business
		return &sp;
	}

	void main()
	{
		Circle *circle = CreateShape();

		circle->DrawCircle();//circle->vptr->vtable[0]()
		circle->CirclePerimeter();//circle->vptr->vtable[1]()
		cout << "___________________________" << endl;
		//Rect *rect = (Rect*)circle;
		//rect++;
		//Rect *rect = (Rect*)(Shape*)circle;
		//Rect *rect = (Shape*)circle;//LSP -> liskov substitution principle (GRASP)
		Rect *rect = dynamic_cast<Rect*>(circle);
		cout << circle << "\t" << rect << endl;
		cout << "___________________________" << endl;
		rect->DrawRect();//rect->vptr->vtable[0]()
		rect->RectPerimeter();//rect->vptr->vtable[1]()
	}
}