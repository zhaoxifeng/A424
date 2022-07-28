#include "pch.h"
#include "RunwayRecord.h"
#include <iostream>
#include <fstream>

RunwayRecord::RunwayRecord()
{
}


RunwayRecord::~RunwayRecord()
{
}

string RunwayRecord::getSection() const
{
	return "PG";
}
bool RunwayRecord::match() const
{
	if (getRecord()[4] != 'P')
		return false;
	if (getRecord()[5] != ' ')
		return false;
	if (getRecord()[12] != 'G')
		return false;
	if (getRecord().substr(18, 3) != string(3, ' '))
		return false;
	if (getRecord().substr(31, 1) != string(1, ' '))
		return false;
	if (getRecord().substr(56, 4) != string(4, ' '))
		return false;	
	//if (getRecord().substr(75, 2) != string(2, ' '))
	//	return false;
	//if (getRecord().substr(90, 5) != string(5, ' '))
	//	return false;
	return true;
}

bool RunwayRecord::parse() const
{
	return false;
}


bool RunwayRecord::isContinuous(const string& record) const
{
	if (record.substr(0, 21) != getRecord().substr(0, 21))
		return false;
	if (record[21] - getRecord()[21] != 1)
		return false;
	return true;
}

BaseRecord* RunwayRecord::clone() const
{
	auto p = new RunwayRecord();
	p->setRecord(getRecord());
	return p;
}

void RunwayRecord::printHeader(ofstream& out) const
{
	out << "continue number" << ",";
	out << "area code" << ",";
	out << "ICAO identifier" << ",";
	out << "ICAO code" << ",";
	out << "runway length" << ",";
	out << "runway width" << ",";
	out << "runway latitude" << ",";
	out << "runway longitude" << ",";
	out << "runway desc" << endl;

}

void RunwayRecord::print(ofstream& out) const
{
	const string& line = getRecord();
	out << line[21] << ",";
	out << line.substr(1, 3) << ",";
	out << line.substr(6, 4) << ",";
	out << line.substr(10, 2) << ",";
	out << line.substr(22, 5) << ",";
	out << line.substr(77, 3) << ",";
	out << line.substr(32, 9) << ",";
	out << line.substr(41, 10) << ",";
	out << line.substr(101, 22) << endl;
}
