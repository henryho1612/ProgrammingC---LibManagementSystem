#include <string>
using namespace std;

class CopyCollection
{
	string barcode, status, dateBorrowed;
	int numBorrowed, numDayBorrowed;
	string cId;
public:
	CopyCollection();
	CopyCollection(string, string, string, string, int, int);
	~CopyCollection();

	void setBarcode(string);
	void setStatus(string);
	void setDateBorrowed(string);
	void setNumBorrowed(int);
	void setNumDayBorrowed(int);
	void setCId(string);
	string getBarcode();
	string getStatus();
	string getDateBorrowed();
	int getNumBorrowed();
	int getNumDayBorrowed();
	string getCId();
};