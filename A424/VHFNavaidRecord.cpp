#include "pch.h"
#include "VHFNavaidRecord.h"
#include <iostream>
#include <fstream>

VHFNavaidRecord::VHFNavaidRecord()
{
}


VHFNavaidRecord::~VHFNavaidRecord()
{
}

string VHFNavaidRecord::getSection() const
{
	return "D";
}

bool VHFNavaidRecord::match() const
{
	//airport waypoint
	if (getRecord()[4] != 'D')
		return false;
	if (getRecord()[5] != ' ')
		return false;
	if (getRecord()[12] != ' ')
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

bool VHFNavaidRecord::parse() const
{
	return false;
}


bool VHFNavaidRecord::isContinuous(const string& record) const
{
	if (record.substr(0, 21) != getRecord().substr(0, 21))
		return false;
	if (record[21] - getRecord()[21] != 1)
		return false;
	return true;
}

BaseRecord* VHFNavaidRecord::clone() const
{
	auto p = new VHFNavaidRecord();
	p->setRecord(getRecord());
	return p;
}

void VHFNavaidRecord::printHeader(ofstream& out) const
{
	out << "1 continue number" << ",";
	out << "2 area code" << ",";
	out << "3 VOR idertifier" << ",";
	out << "4 VOR latitude" << ",";
	out << "5 VOR longitude" << ",";
	out << "6 airport:" << ",";
	out << "7 VOR name" << endl;

}

void VHFNavaidRecord::print(ofstream& out) const
{
	const string& line = getRecord();
	out << line[21] << ",";
	out << line.substr(1, 3) << ",";
	out << line.substr(13, 4) << ",";
	out << line.substr(32, 9) << ",";
	out << line.substr(41, 10) << ",";
	out << line.substr(6, 4) << ",";
	out << line.substr(93, 25) << endl;
}