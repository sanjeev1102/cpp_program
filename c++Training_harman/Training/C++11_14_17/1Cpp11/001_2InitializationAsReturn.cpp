#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct Player {
	std::string name;
	int age;
};

Player player_Factory() {
	return{ "foo", 42 }; //Note the lack of explicit type.
}
//void main()
void main1_2_1()
{
	Player p = player_Factory();
	cout << p.name << endl;
	cout << p.age << endl;

}