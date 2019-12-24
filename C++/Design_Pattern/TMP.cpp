#include<iostream>
using namespace std;
namespace nm01_1
{
	class DB
	{
	public:
		void OpenDb()
		{
			cout << "open DB" << endl;
		}
		void CloseDb()
		{
			cout << "close DB" << endl;
		}
	};
	//CRTP
	template<typename T>
	class Account
	{
		DB db;
	public:
		void DoJob()
		{
			db.OpenDb();
			((T*)this)->ActualJob();
			db.CloseDb();
		}

	};

	class SavingsAccount :public Account< SavingsAccount>
	{
	public:
		void ActualJob()
		{
			cout << "Do Savings Job" << endl;
		}
	};

	class CurrentAccount :public Account<CurrentAccount>
	{
	public:
		void ActualJob()
		{
			cout << "Do Current Job" << endl;
		}
	};

	int main()
	{
		SavingsAccount sa;
		sa.DoJob();
		cout << "_______________________________\n";
		CurrentAccount curr;
		curr.DoJob();
		return 0;
	}
}