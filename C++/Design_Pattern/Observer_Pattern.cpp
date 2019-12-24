#include<iostream>
#include<string>
#include<vector>
using namespace std;
//namespace nm20
//{
	class IClient
	{
	public:
		virtual void Notify(string msg) = 0;
	};
	class Observer
	{
		vector<IClient*> subscribers;
	public:
		void Subscribe(IClient* client)
		{
			subscribers.push_back(client);
		}
		void NotifyAll(string msg)
		{
			cout << "___________________________________\n";
			for (auto v : subscribers)
			{
				v->Notify(msg);
			}
			cout << "___________________________________\n";
		}
	};

	class Cricket :public Observer
	{
		string score;
	public:
		Cricket() :score("200")
		{
		}
		void SetScore(string score)
		{
			this->score = score;
			NotifyAll("The Current score is *** " + score + " ***");
		}
	};


	class Election :public Observer
	{
		string info;
	public:
		Election() :info("EVM not working")
		{
		}
		void SetNews(string info)
		{
			this->info = info;
			NotifyAll("The News from EC is ( " + info + " )");
		}
	};

	class Entertainment :public Observer
	{
		string info;
	public:
		Entertainment() :info("Malya and padakone no more kins")
		{
		}
		void SetInfo(string info)
		{
			this->info = info;
			NotifyAll("Breaking news [ " + info + " ]");
		}
	};


	class ClientBase :public IClient
	{
	protected:
		string _name;
	public:
		ClientBase(string name) :_name(name)
		{
		}
		void Subscribe(Observer& obs)
		{
			obs.Subscribe(this);
		}
	};
	class Zee :public ClientBase
	{
	public:
		Zee(string name) :ClientBase(name)
		{
		}
		void Notify(string msg) override
		{
			cout << _name << " ############## " << msg << endl;
		}
	};
	class NDTV :public ClientBase
	{
	public:
		NDTV(string name) :ClientBase(name)
		{
		}
		void Notify(string msg) override
		{
			cout << _name << " %%%%%%%%%%%%%%% " << msg << endl;
		}
	};
	class DD :public ClientBase
	{
	public:
		DD(string name) :ClientBase(name)
		{
		}
		void Notify(string msg) override
		{
			cout << _name << " $$$$$$$$$$$$$ " << msg << endl;
		}
	};


	int main()
	{
		Entertainment ent;
		Cricket cric;
		Election elec;

		Zee zee("ZEE");
		NDTV ndtv("NDTV");
		DD dd("DD");

		zee.Subscribe(ent);
		zee.Subscribe(elec);

		ndtv.Subscribe(cric);
		ndtv.Subscribe(elec);

		dd.Subscribe(ent);
		dd.Subscribe(cric);

		cric.SetScore("400");
		ent.SetInfo("Robo 3.0 1000 crs");
		elec.SetNews("Yeddi anger");

		return 0;
	}
//}