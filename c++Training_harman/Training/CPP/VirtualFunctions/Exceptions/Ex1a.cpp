//Programs using exceptions are about "5-10% larger and 5-10% slower."

struct Excpetion {};
struct DbException:Exception {};
struct ConcurrencyException :DbException{};

void fun()
{
	try	{
		//1 
		//if(cond)
			throw ConcurrencyException();
		//2
	}catch(Exception& e){
		//3
	}catch(DbException& e){
		//4
	}catch(ConcurrencyException& e){
		//5
	}
	//6
}
void main()
{
	fun();
}