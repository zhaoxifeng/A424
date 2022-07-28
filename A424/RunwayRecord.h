#pragma once
#include "BaseRecord.h"
class RunwayRecord :
	public BaseRecord
{
public:
	RunwayRecord();
	virtual ~RunwayRecord();
	virtual bool match() const;
	virtual bool parse() const;
	virtual bool isContinuous(const string& record) const;
	virtual BaseRecord* clone() const;
	virtual void printHeader(ofstream& out) const;
	virtual void print(ofstream& out) const;
	virtual string getSection() const;

};

