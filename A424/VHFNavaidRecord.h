#pragma once
#include "BaseRecord.h"
class VHFNavaidRecord :
	public BaseRecord
{
public:
	VHFNavaidRecord();
	~VHFNavaidRecord();
	virtual bool match() const;
	virtual bool parse() const;
	virtual bool isContinuous(const string& record) const;
	virtual BaseRecord* clone() const;
	virtual void printHeader(ofstream& out) const;
	virtual void print(ofstream& out) const;
	virtual string getSection() const;

};

