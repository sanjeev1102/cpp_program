#include<iostream>
#include<string>
using namespace std;

class Employee
{
	int eId;
public:
	Employee(int eId) :eId(eId)
	{
		if (this->eId>5 && this->eId<15)
			throw invalid_argument("Wrong employee id...");
		cout << "Employee::Employee(int)" << endl;
	}
	Employee() :Employee(40)
	{
		cout << "Employee::Employee()" << endl;
	}
	Employee(string eId) :Employee(std::stoi(eId))
	{
		cout << "Employee::Employee(string)" << endl;
	}
};
void main12()
{
	try{
		//Employee emp1 = 10;
		Employee emp1 = 30;
		cout << "_____________" << endl;
		Employee emp2;
		cout << "_____________" << endl;
		Employee emp3="43";

	}
	catch (invalid_argument & exp)
	{
		cout << exp.what() << endl;
	}
}