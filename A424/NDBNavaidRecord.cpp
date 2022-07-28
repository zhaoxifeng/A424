#include "pch.h"
#include "NDBNavaidRecord.h"
#include <fstream>


NDBNavaidRecord::NDBNavaidRecord()
{

}

NDBNavaidRecord::~NDBNavaidRecord()
{
}
string NDBNavaidRecord::getSection() const
{
	return "PN";
}

bool NDBNavaidRecord::match() const
{
	//airport waypoint
	if (getRecord()[4] != 'P')
		return false;
	if (getRecord()[5] != 'N')
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

bool NDBNavaidRecord::parse() const
{
	return false;
}


bool NDBNavaidRecord::isContinuous(const string& record) const
{
	if (record.substr(0, 21) != getRecord().substr(0, 21))
		return false;
	if (record[21] - getRecord()[21] != 1)
		return false;
	return true;
}

BaseRecord* NDBNavaidRecord::clone() const
{
	auto p = new NDBNavaidRecord();
	p->setRecord(getRecord());
	return p;
}

void NDBNavaidRecord::printHeader(ofstream& out) const
{
	out << "1 continue number" << ",";
	out << "2 area code" << ",";
	out << "3 NDB idertifier" << ",";
	out << "4 NDB latitude" << ",";
	out << "5 NDB longitude" << ",";
	out << "6 airport:" << ",";
	out << "7 VOR name" << endl;

}

void NDBNavaidRecord::print(ofstream& out) const
{
	const string& line = getRecord();
	out << line[21] << ",";
	out << line.substr(1, 3) << ",";

	out << line.substr(13, 4) << ",";
	out << line.substr(32, 9) << ",";

	out << line.substr(41, 10) << ",";
	out << line.substr(6, 4) << ",";
	out << line.substr(93, 30) << endl;
}