#pragma once
#include "BaseRecord.h"
#include "Database.h"
class AirportRecord :
	public BaseRecord
{
public:
	AirportRecord();
	virtual ~AirportRecord();
	virtual bool match() const;
	virtual bool parse() const;
	virtual bool isContinuous(const string& record) const;
	virtual BaseRecord* clone() const;
	virtual void printHeader(ofstream& out) const;
	virtual void print(ofstream& out) const;
	virtual string getSection() const;



private:

};

