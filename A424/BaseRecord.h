#pragma once
#include <string>
#include <vector>
#include "Database.h"
#include "Field.h"
using namespace std;

class BaseRecord
{
public:
	BaseRecord();
	virtual ~BaseRecord();
	virtual bool match() const { return false; }
	virtual bool isContinuous(const string& record) const { return false; }
	virtual bool parse() { return false; }
	virtual BaseRecord* clone() const { return 0;  }
	const string& getRecord() const { return m_record; }
	void setRecord(const string& record) { m_record = record; }
	void push_back(const string& record) { m_records.push_back(record);  }
	virtual void printHeader(ofstream& out) const;
	virtual void print(ofstream& out) const;
	virtual string getSection() const { return ""; }
	void loadEncodeSchema(const string& csvFilename);
private:
	vector<string> m_records;
	static vector<Field> m_schema;
	string m_record;
};

