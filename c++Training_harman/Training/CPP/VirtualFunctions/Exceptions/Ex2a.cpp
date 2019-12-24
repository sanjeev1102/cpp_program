
struct Exception {};
struct DbException:Exception {};
struct ConcurrencyException :DbException{};
struct SocketException:Exception {};

void fun()
{
	try	{
		//1 
		//if(cond)
			throw SocketException();
		//2
	}catch(DbException& e){
		//4
	}catch(ConcurrencyException& e){
		//5
	}
	//6
}
void main()
{
	try
	{
		fun();
	}catch(SocketException& e){
		//7
	}
}
