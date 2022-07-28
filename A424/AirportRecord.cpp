#include "pch.h"
#include "AirportRecord.h"
#include <ctype.h>
#include <iostream>
#include <fstream>
using namespace std;


AirportRecord::AirportRecord()
{
}

AirportRecord::~AirportRecord()
{
}

string AirportRecord::getSection() const
{
	return string("PA");
}

bool AirportRecord::match() const
{
	if (getRecord()[4] != 'P')
		return false;
	if (getRecord()[5] != ' ')
		return false;
	if (getRecord()[12] != 'A')
		return false;
	if (getRecord().substr(18, 3) != "   ")
		return false;
	return true;
}

bool AirportRecord::parse() const
{
	return false;
}


bool AirportRecord::isContinuous(const string& record) const
{
	if (record.substr(0, 21) != getRecord().substr(0, 21))
		return false;
	if (record[21] - getRecord()[21] != 1)
		return false;
	return true;
}


BaseRecord* AirportRecord::clone() const
{
	auto p = new AirportRecord();
	p->setRecord(getRecord());
	return p;
}

void AirportRecord::printHeader(ofstream& out) const
{
	out << "continue number" << ",";
	out << "area code" << ",";
	out << "airport name" << ",";
	out << "ICAO identifier" << ",";
	out << "ICAO code" << ",";
	out << "ICAO code" << endl;

}

void AirportRecord::print(ofstream& out) const
{
	const string& line = getRecord();
	out << line[21] << ",";
	out << line.substr(1, 3) << ",";
	out << line.substr(93, 30) << ",";
	out << line.substr(6, 4) << ",";
	out << line.substr(10, 2) << ",";
	out << line.substr(68, 2) << endl;
}
