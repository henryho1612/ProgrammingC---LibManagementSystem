#ifndef COLLECTION_H
#define COLLECTION_H

#include <string>
using namespace std;

class Collection
{
	string cId, cType, cDataType, cTitle, cVersion, cPublisher, cYear, cCate;
	int cDuration;
	int numCopy;

public:	
	Collection();
	Collection(string, string, string, string, string, string, string, int, string);
	~Collection();

	void setCid(string);
	void setType(string);
	void setDataType(string);
	void setTitle(string);
	void setVersion(string);
	void setPublisher(string);
	void setYear(string);
	void setCate(string);
	void setDuration(int);
	void setNumCopy(int);
	string getCid();
	string getType();
	string getDataType();
	string getTitle();
	string getVersion();
	string getPublisher();
	string getYear();
	string getCate();
	int getDuration();
	int getNumCopy();
};
#endif