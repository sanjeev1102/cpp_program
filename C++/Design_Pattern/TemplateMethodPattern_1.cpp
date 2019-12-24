#include<iostream>
using namespace std;
namespace nm01
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

	class Account
	{
		DB db;
	protected:
		virtual void ActualJob() = 0;
	public:
		void DoJob()
		{
			db.OpenDb();
			ActualJob();
			db.CloseDb();
		}

	};

	class SavingsAccount :public Account
	{
	protected:
		void ActualJob() override
		{
			cout << "Do Savings Job" << endl;
		}
	};

	class CurrentAccount :public Account
	{
	protected:
		void ActualJob() override
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