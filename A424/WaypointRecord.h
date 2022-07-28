#pragma once
#include "BaseRecord.h"
class WaypointRecord :
	public BaseRecord
{
public:
	WaypointRecord();
	virtual ~WaypointRecord();

	virtual bool match() const;
	virtual bool parse() const;
	virtual bool isContinuous(const string& record) const;
	virtual BaseRecord* clone() const;
	virtual void printHeader(ofstream& out) const;
	virtual void print(ofstream& out) const;
	virtual string getSection() const;

};

