#include "pch.h"
#include "PBxAirportGateRecord.h"
#include <fstream>


PBxAirportGateRecord::PBxAirportGateRecord()
{
}

PBxAirportGateRecord::~PBxAirportGateRecord()
{
}

string PBxAirportGateRecord::getSection() const
{
	return "PB";
}

bool PBxAirportGateRecord::match() const
{
	//airport waypoint
	if (getRecord()[4] != 'P')
		return false;
	if (getRecord()[5] != ' ')
		return false;
	if (getRecord()[12] != 'B')
		return false;
	//if (getRecord()[18] != ' ')
	//	return false;
	//if (getRecord()[31] != ' ')
	//	return false;
	//if (getRecord().substr(22, 4) != string(4, ' '))
	//	return false;
	//if (getRecord().substr(51,23) != string(23, ' '))
	//	return false;
	return true;
}

bool PBxAirportGateRecord::parse() const
{
	return false;
}


bool PBxAirportGateRecord::isContinuous(const string& record) const
{
	if (record.substr(0, 21) != getRecord().substr(0, 21))
		return false;
	if (record[21] - getRecord()[21] != 1)
		return false;
	return true;
}

BaseRecord* PBxAirportGateRecord::clone() const
{
	auto p = new PBxAirportGateRecord();
	p->setRecord(getRecord());
	return p;
}

void PBxAirportGateRecord::printHeader(ofstream& out) const
{
	out << "1 continue number" << ",";
	out << "2 area code" << ",";

	out << "3 idertifier" << ",";
	out << "4 latitude" << ",";
	out << "5 longitude" << ",";

	out << "6 airport:" << ",";
	out << "7 ICAO code:" << ",";
	out << "9 name" << endl;

}

void PBxAirportGateRecord::print(ofstream& out) const
{
	const string& line = getRecord();
	out << line[21] << ",";
	out << line.substr(1, 3) << ",";

	out << line.substr(13, 5) << ",";
	out << line.substr(32, 9) << ",";
	out << line.substr(41, 10) << ",";
	out << line.substr(6, 4) << ",";

	out << line.substr(10, 2) << ",";
	out << line.substr(98, 25) << endl;
}