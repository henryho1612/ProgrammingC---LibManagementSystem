#include "copycollection.h"
#include <iostream>

using namespace std;

CopyCollection::CopyCollection()
{
	numBorrowed = 0;
	numDayBorrowed = 0;
	dateBorrowed = "Not yet be borrowed!";
}

CopyCollection::CopyCollection(string id, string bar, string sts, string date, int num, int numDay) : 
cId(id), barcode(bar), status(sts), dateBorrowed(date), numBorrowed(num), numDayBorrowed(numDay) {}

CopyCollection::~CopyCollection()
{
	cout << "copy collection is deleted\n";
}

void CopyCollection::setBarcode(string bar){barcode = bar;}
void CopyCollection::setStatus(string sts){status = sts;}
void CopyCollection::setDateBorrowed(string date){dateBorrowed = date;} 
void CopyCollection::setNumBorrowed(int num){numBorrowed = num;}
void CopyCollection::setNumDayBorrowed(int day){numDayBorrowed = day;}
void CopyCollection::setCId(string id){cId = id;}
string CopyCollection::getBarcode(){return barcode;}
string CopyCollection::getStatus(){return status;}
string CopyCollection::getDateBorrowed(){return dateBorrowed;}
int CopyCollection::getNumBorrowed(){return numBorrowed;}
int CopyCollection::getNumDayBorrowed(){return numDayBorrowed;}
string CopyCollection::getCId(){return cId;}