#include "pch.h"
#include "BaseRecord.h"
#include <iostream>
#include <fstream>
#include "Field.h"

vector<Field> BaseRecord::m_schema;

BaseRecord::BaseRecord()
{
}

BaseRecord::~BaseRecord()
{
}

void BaseRecord::print(ofstream& out) const
{
	cout << "children count: " << m_records.size() << endl;
	for (auto& s : m_records)
	{
		cout << s << endl;
	}

}


void BaseRecord::printHeader(ofstream& out) const
{

}


void BaseRecord::loadEncodeSchema(const string& csvFilename)
{
	ifstream is(csvFilename);
	string line;
	std::getline(is, line);
	while (is.good())
	{
		std::getline(is, line);
		if (line.empty())
			continue;
		BaseRecord::m_schema.push_back(Field(line)) ;
	}

}

