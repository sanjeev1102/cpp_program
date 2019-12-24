#include<iostream>
#include <cstdint>
using namespace std;

//enum forward declaration new c++11
enum class Colors;

void FunUseColors(Colors color);

enum class Colors{Red,Green,Blue};
void FunUseColors(Colors color)
{
	switch (color)
	{
	case Colors::Red:
		cout << "red prefered " << endl;
		break;
	case Colors::Green:
		cout << "green prefered " << endl;
		break;
	case Colors::Blue:
		cout << "blue prefered " << endl;
		break;
	default:
		break;
	}

}
//void main()
void main15_1()
{
	FunUseColors(Colors::Green);
}
//******************************************************************************

//enum values are scoped
enum class Color { RED, GREEN, BLUE };
enum class Feelings { EXCITED, MOODY, BLUE };

//void main()
void main15_2()
{
	Color blue = Color::BLUE;
	Feelings feel = Feelings::BLUE;
	switch (blue)
	{
	case Color::RED:
		break;
	case Color::GREEN:
		break;
	case Color::BLUE:
		break;
	default:
		break;
	}

	switch (feel)
	{
	case Feelings::EXCITED:
		break;
	case Feelings::MOODY:
		break;
	case Feelings::BLUE:
		break;
	default:
		break;
	}
}

//Well-defined enum sizes 
enum class ColorsWithCharSize : char { RED = 1, GREEN = 2, BLUE = 3 };
//#include <cstdint>
enum class ColorsWith8Bits : std::int8_t { RED = 1, GREEN = 2, BLUE = 3 };

void main15_3()
{
	ColorsWithCharSize c = ColorsWithCharSize::RED;
	ColorsWith8Bits d = ColorsWith8Bits::GREEN;
	switch (c)
	{
	case ColorsWithCharSize::RED:
		break;
	case ColorsWithCharSize::GREEN:
		break;
	case ColorsWithCharSize::BLUE:
		break;
	default:
		break;
	}
	switch (d)
	{
	case ColorsWith8Bits::RED:
		break;
	case ColorsWith8Bits::GREEN:
		break;
	case ColorsWith8Bits::BLUE:
		break;
	default:
		break;
	}
}