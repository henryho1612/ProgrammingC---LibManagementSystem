#include "multimediacollection.h"
#include <iostream>
#include <cstdlib>
#include "cppconn/driver.h"
#include "cppconn/exception.h"
#include "cppconn/resultset.h"
#include "cppconn/statement.h"
#include "cppconn/prepared_statement.h"
#include <list>
#include <string>
#include <sstream>
#include <limits>
#include <iomanip>
#pragma comment(lib, "mysqlcppconn.lib")

using namespace std;

/* Convert to string */
template <typename T>
string to_string(T value)
{
	ostringstream os;
	os << value;
	return os.str();
}

/* Check collection id */
bool MultimediaCollection::checkCollectionId(string id)
{
	list<Collection>::iterator it = cols.begin();
	while(it != cols.end())
	{
		if(it->getCid() == id)
			return true;
		*it++;
	}
	return false;
}

/* Check borrower id */
bool MultimediaCollection::checkBorrowerId(string id)
{
	list<Borrower>::iterator it = borrowers.begin();
	while(it != borrowers.end())
	{
		if(it->getId() == id)
			return true;
		*it++;
	}
	return false;
}


MultimediaCollection::MultimediaCollection() {}

MultimediaCollection::~MultimediaCollection() {
	cols.clear();
	copyCols.clear();
	borrowers.clear();
}


void MultimediaCollection::showCollections()
{
	cout << "ID   |Type      |Data Type |Title          |Version|Publisher\n"; 
	cout << "Year |Duration  |Category  |Copies\n";
	cout << "--------------------------------------------------------------\n";

	list<Collection>::iterator it = cols.begin();
	cout.setf(ios::left, ios::adjustfield);
	while(it != cols.end()) {
		cout << setw(5) << it->getCid() << "|";
		cout << setw(10) << it->getType() << "|";
		cout << setw(10) << it->getDataType() << "|";
		cout << setw(15) << it->getTitle() << "|";
		cout << setw(7) << it->getVersion() << "|";
		cout << setw(10) << it->getPublisher() << "\n";
		cout << setw(5) << it->getYear() << "|";
		cout << setw(10) << it->getDuration() << "|";
		cout << setw(10) << it->getCate() << "|";
		cout << setw(6) << it->getNumCopy() << "\n";
		cout << "--------------------------------------------------------------\n";
		*it++;
	}
}

void MultimediaCollection::showCopies()
{
	cout << "Collection Id|Barcode   |Status    |Num Borrowed|Date       |Num Days\n";
	cout << "---------------------------------------------------------------------\n";

	list<CopyCollection>::iterator it = copyCols.begin();
	cout.setf(ios::left, ios::adjustfield);
	while(it != copyCols.end()) {
		cout << setw(13) << it->getCId()<< "|";
		cout << setw(10) << it->getBarcode() << "|";
		cout << setw(10) << it->getStatus() << "|";
		cout << setw(12) << it->getNumBorrowed() << "|";
		cout << setw(11) << it->getDateBorrowed() << "|";
		cout << setw(8) << it->getNumDayBorrowed() << "\n";
		*it++;
	}
}

void MultimediaCollection::showBorrowers()
{	
	cout << "Id        |Name      |Type      |Department|Mobile    |Borrowed  |Late Return\n";
	cout << "-----------------------------------------------------------------------------\n";

	list<Borrower>::iterator it = borrowers.begin();
	while(it != borrowers.end()) {
		cout.setf(ios::left, ios::adjustfield);
		cout << setw(10) << it->getId() << "|";
		cout << setw(10) << it->getName() << "|";
		cout << setw(10) << it->getType() << "|";
		cout << setw(10) << it->getDepartment() << "|";
		cout << setw(10) << it->getMobile() << "|";
		cout << setw(10) << it->getNumItemBorrow() << "|";
		cout << it->getNumItemLateBorrow() << "\n";
		*it++;
	}
}

void MultimediaCollection::addCollection(Collection c)
{
	cols.push_back(c);

	try {
		sql::Driver *driver;
		sql::Connection *con;
		sql::PreparedStatement *prepareStmt;

		driver = get_driver_instance();
		con = driver->connect("tcp://127.0.0.1:3306", "root", "dhis");
		con->setSchema("test");

		prepareStmt = con->prepareStatement(
			"INSERT INTO multimedia(id, type, datatype, title, version, publisher, year, duration, category, numcopy)" 
			"VALUES (?,?,?,?,?,?,?,?,?,?)");
		prepareStmt->setString(1,c.getCid());
		prepareStmt->setString(2,c.getType());
		prepareStmt->setString(3,c.getDataType());
		prepareStmt->setString(4,c.getTitle());
		prepareStmt->setString(5,c.getVersion());
		prepareStmt->setString(6,c.getPublisher());
		prepareStmt->setString(7,c.getYear());
		prepareStmt->setInt(8,c.getDuration());
		prepareStmt->setString(9,c.getCate());
		prepareStmt->setInt(10,c.getNumCopy());

		prepareStmt->execute();

		delete prepareStmt;
		delete con;

	} catch (sql::SQLException &e) {
	  cout << "# ERR: SQLException in " << __FILE__;
	  cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
	  cout << "# ERR: " << e.what();
	  cout << " (MySQL error code: " << e.getErrorCode();
	  cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}
}

void MultimediaCollection::addCopy(CopyCollection cc)
{
	copyCols.push_back(cc);
	try {
		sql::Driver *driver;
		sql::Connection *con;
		sql::PreparedStatement *prepareStmt;

		driver = get_driver_instance();
		con = driver->connect("tcp://127.0.0.1:3306", "root", "dhis");
		con->setSchema("test");

		prepareStmt = con->prepareStatement(
			"INSERT INTO copycollection(id, barcode, numborrowed, status, numdayborrowed, dateborrowed)" 
			"VALUES (?,?,?,?,?,?)");
		prepareStmt->setString(1,cc.getCId());
		prepareStmt->setString(2,cc.getBarcode());
		prepareStmt->setInt(3,cc.getNumBorrowed());
		prepareStmt->setString(4,cc.getStatus());
		prepareStmt->setInt(5,cc.getNumDayBorrowed());
		prepareStmt->setString(6,cc.getDateBorrowed());

		prepareStmt->execute();

		delete prepareStmt;
		delete con;

	} catch (sql::SQLException &e) {
	  cout << "# ERR: SQLException in " << __FILE__;
	  cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
	  cout << "# ERR: " << e.what();
	  cout << " (MySQL error code: " << e.getErrorCode();
	  cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}
}

void MultimediaCollection::addBorrower(Borrower b)
{
	borrowers.push_back(b);
	try {
		sql::Driver *driver;
		sql::Connection *con;
		sql::PreparedStatement *prepareStmt;

		driver = get_driver_instance();
		con = driver->connect("tcp://127.0.0.1:3306", "root", "dhis");
		con->setSchema("test");

		prepareStmt = con->prepareStatement(
			"INSERT INTO borrower(id, name, type, department, mobile, numborrow, numreturnlate)" 
			"VALUES (?,?,?,?,?,?,?)");
		prepareStmt->setString(1, b.getId());
		prepareStmt->setString(2, b.getName());
		prepareStmt->setString(3, b.getType());
		prepareStmt->setString(4, b.getDepartment());
		prepareStmt->setString(5, b.getMobile());
		prepareStmt->setInt(6, b.getNumItemBorrow());
		prepareStmt->setInt(7, b.getNumItemLateBorrow());

		prepareStmt->execute();

		delete prepareStmt;
		delete con;

	} catch (sql::SQLException &e) {
	  cout << "# ERR: SQLException in " << __FILE__;
	  cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
	  cout << "# ERR: " << e.what();
	  cout << " (MySQL error code: " << e.getErrorCode();
	  cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}
}

void MultimediaCollection::enterCollectionAndCopies()
{	
	cout << "Enter New Collection Process\n";
	cout << "=============================\n";

	string sInput;
	int iInput;
	Collection col;

	cout << "Collection ID: ";
	while(getline(cin, sInput)) {
		if(sInput.empty())
			cout << "Collection id can't be empty. Re-enter: ";
		else
		{
			if(checkCollectionId(sInput)) {
				cout << sInput << " exists! Re-enter: ";
			}
			else {
				col.setCid(sInput);
				break;
			}
		}
	}

	cout << "Collection Type: ";
	while(getline(cin, sInput))
	{
		if(sInput.empty())
			cout << "Type can't be empty! Re-enter: ";
		else {
			col.setType(sInput);
			break;
		}
	}	

	cout << "Collection Data Type: ";
	while(getline(cin, sInput))
	{
		if(sInput.empty())
			cout << "Data Type can't be empty! Re-enter: ";
		else {
			col.setDataType(sInput);
			break;
		}
	}

	cout << "Collection Title: ";
	while(getline(cin, sInput))
	{
		if(sInput.empty())
			cout << "Title can't be empty! Re-enter: ";
		else {
			col.setTitle(sInput);
			break;
		}
	}

	cout << "Collection Version: ";
	while(getline(cin, sInput))
	{
		if(sInput.empty())
			cout << "Version can't be empty! Re-enter: ";
		else {
			col.setVersion(sInput);
			break;
		}
	}

	cout << "Collection Publisher: ";
	while(getline(cin, sInput))
	{
		if(sInput.empty())
			cout << "Publisher can't be empty! Re-enter: ";
		else {
			col.setPublisher(sInput);
			break;
		}
	}

	cout << "Collection Year: ";
	while(getline(cin, sInput))
	{
		if(sInput.empty())
			cout << "Year can't be empty! Re-enter: ";
		else {
			col.setYear(sInput);
			break;
		}
	}

	cout << "Collection Category: ";
	while(getline(cin, sInput))
	{
		if(sInput.empty())
			cout << "Category can't be empty! Re-enter: ";
		else {
			col.setCate(sInput);
			break;
		}
	}

	cout << "Collection Duration: ";
	while(!(cin >> iInput) || iInput < 0)
	{
		cout << "Duration must be positive number. Re-enter: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
	}
	col.setDuration(iInput);

	cout << "\nEnter new collection completed!\n\n";
	
	cout << "Enter copies of the collection\n";
	cout << "===============================\n";

	cout << "Enter number of copies: ";
	while(!(cin >> iInput) || iInput < 10 || iInput > 20)
	{
		cout << "Copies must be from 10 to 20. Re-enter: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
	}

	col.setNumCopy(iInput);
	addCollection(col);

	for(int i=0; i< iInput; i++)
	{	
		int choice;
		CopyCollection copy;
		copy.setCId(col.getCid());
		copy.setBarcode(sInput + "-" + to_string(i+1));
		cout << "Enter status for " << copy.getBarcode() << ": 1-In Library | 2-In storeroom: ";
		while(!(cin >> choice) || choice < 1 || choice > 2) {
			cout << "Not valid! 1-In Library | 2-In storeroom ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
		}

		(choice == 1) ? copy.setStatus("In library") : copy.setStatus("In storeroom");

		addCopy(copy);
	}

	cout << "Entering copies completed!\n";
}

void MultimediaCollection::enterBorrower()
{
	cout << "Enter New Borrower Process\n";
	cout << "=============================\n";

	string sInput;
	Borrower borrower;

	cout << "Borrower ID: ";
	while(getline(cin, sInput)) {
		if(sInput.empty())
			cout << "Borrower id can't be empty. Re-enter: ";
		else
		{
			if(checkBorrowerId(sInput)) {
				cout << sInput << " exists! Re-enter: ";
			}
			else {
				borrower.setId(sInput);
				break;
			}
		}
	}

	cout << "Borrower Name: ";
	while(getline(cin, sInput))
	{
		if(sInput.empty())
			cout << "Name can't be empty! Re-enter: ";
		else {
			borrower.setName(sInput);
			break;
		}
	}
	

	cout << "Borrower Type: ";
	while(getline(cin, sInput))
	{
		if(sInput.empty())
			cout << "Type can't be empty! Re-enter: ";
		else {
			borrower.setType(sInput);
			break;
		}
	}

	cout << "Borrower Department: ";
	while(getline(cin, sInput))
	{
		if(sInput.empty())
			cout << "Department can't be empty! Re-enter: ";
		else {
			borrower.setDepartment(sInput);
			break;
		}
	}

	cout << "Borrower Mobile: ";
	while(getline(cin, sInput))
	{
		if(sInput.empty())
			cout << "Phone can't be empty! Re-enter: ";
		else {
			borrower.setMobile(sInput);
			break;
		}
	}
	
	borrower.setNumItemBorrow(0);
	borrower.setNumItemLateBorrow(0);
	
	addBorrower(borrower);
	
	cout << "Entering borrower completed!\n";
}


void MultimediaCollection::loadDatabase()
{
	try {
		sql::Driver *driver;
		sql::Connection *con;
		sql::ResultSet *resultSet;
		sql::PreparedStatement *prepareStmt;

		driver = get_driver_instance();
		con = driver->connect("tcp://127.0.0.1:3306", "root", "dhis");
		con->setSchema("test");

		prepareStmt = con->prepareStatement("SELECT * FROM multimedia");
		resultSet = prepareStmt->executeQuery();
		while(resultSet->next()) {
			Collection col(resultSet->getString("id"),
									 resultSet->getString("type"),
									 resultSet->getString("datatype"),
									 resultSet->getString("title"),
									 resultSet->getString("version"),
									 resultSet->getString("publisher"),
									 resultSet->getString("year"),
									 resultSet->getInt("duration"),
									 resultSet->getString("category"));
			col.setNumCopy(resultSet->getInt("numcopy"));
			cols.push_back(col);
		}

		prepareStmt = con->prepareStatement("SELECT * FROM copycollection");
		resultSet = prepareStmt->executeQuery();
		while(resultSet->next()) {
			CopyCollection copyCol(resultSet->getString("id"),
									 resultSet->getString("barcode"),
									 resultSet->getString("status"),
									 resultSet->getString("dateborrowed"),
									 resultSet->getInt("numdayborrowed"),
									 resultSet->getInt("numborrowed"));

			copyCols.push_back(copyCol);
		}

		prepareStmt = con->prepareStatement("SELECT * FROM borrower");
		resultSet = prepareStmt->executeQuery();
		while(resultSet->next()) {
			Borrower borrower(resultSet->getString("id"),
									 resultSet->getString("name"),
									 resultSet->getString("type"),
									 resultSet->getString("department"),
									 resultSet->getString("mobile"),
									 resultSet->getInt("numborrow"),
									 resultSet->getInt("numreturnlate"));

			borrowers.push_back(borrower);
		}

		delete resultSet;
		delete prepareStmt;
		delete con;

	} catch (sql::SQLException &e) {
	  cout << "# ERR: SQLException in " << __FILE__;
	  cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
	  cout << "# ERR: " << e.what();
	  cout << " (MySQL error code: " << e.getErrorCode();
	  cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}
}
