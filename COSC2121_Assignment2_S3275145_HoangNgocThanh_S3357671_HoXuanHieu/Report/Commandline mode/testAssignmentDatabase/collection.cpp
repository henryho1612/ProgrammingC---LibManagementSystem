#include "collection.h"
#include <iostream>

Collection::Collection(){}
Collection::Collection(string Cid, string type, string datatype, string title, string version, 
					   string publisher, string year, int duration, string cate):
							cId(Cid), cType(type), cDataType(datatype), cTitle(title), cVersion(version),
							cPublisher(publisher), cYear(year), cDuration(duration), cCate(cate)
							{numCopy = 0;}

Collection::~Collection(){
	std::cout << "Collection " << cId << " is deleted\n";
}

void Collection::setCid(string id){cId = id;}
void Collection::setType(string type){cType = type;}
void Collection::setDataType(string datatype){cDataType = datatype;}
void Collection::setTitle(string title){cTitle = title;}
void Collection::setVersion(string version){cVersion = version;}
void Collection::setPublisher(string publisher){cPublisher = publisher;}
void Collection::setYear(string year){cYear = year;}
void Collection::setCate(string cate){cCate = cate;}
void Collection::setDuration(int dur){cDuration = dur;}
void Collection::setNumCopy(int copy){numCopy = copy;}
string Collection::getCid(){return cId;}
string Collection::getType(){return cType;}
string Collection::getDataType(){return cDataType;}
string Collection::getTitle(){return cTitle;}
string Collection::getVersion(){return cVersion;}
string Collection::getPublisher(){return cPublisher;}
string Collection::getYear(){return cYear;}
string Collection::getCate(){return cCate;}
int Collection::getDuration(){return cDuration;}
int Collection::getNumCopy(){return numCopy;}
