#pragma once
#include "BaseRecord.h"
class NDBNavaidRecord :
	public BaseRecord
{
public:
	NDBNavaidRecord();
	~NDBNavaidRecord();
	virtual bool match() const;
	virtual bool parse() const;
	virtual bool isContinuous(const string& record) const;
	virtual BaseRecord* clone() const;
	virtual void printHeader(ofstream& out) const;
	virtual void print(ofstream& out) const;
	virtual string getSection() const;

};

