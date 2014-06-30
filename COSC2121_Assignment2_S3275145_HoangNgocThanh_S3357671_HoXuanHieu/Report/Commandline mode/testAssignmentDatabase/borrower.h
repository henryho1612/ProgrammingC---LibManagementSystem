#include <string>
using namespace std;

class Borrower
{
	string id, name, type, department, mobile;
	int numItemBorrow, numItemLateBorrow;

public:
	Borrower();
	Borrower(string, string, string, string, string, int, int);
	~Borrower();

	string getId();
	string getName();
	string getType();
	string getDepartment();
	string getMobile();
	int getNumItemBorrow();
	int getNumItemLateBorrow();
	void setId(string);
	void setName(string);
	void setType(string);
	void setDepartment(string);
	void setMobile(string);
	void setNumItemBorrow(int);
	void setNumItemLateBorrow(int);
};