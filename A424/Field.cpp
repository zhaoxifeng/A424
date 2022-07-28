#include "pch.h"
#include "Field.h"
#include <iostream>

#include <iostream>
#include <string>
#include <algorithm>

const std::string WHITESPACE = " \n\r\t\f\v\"";

std::string ltrim(const std::string &s)
{
	size_t start = s.find_first_not_of(WHITESPACE);
	return (start == std::string::npos) ? "" : s.substr(start);
}

std::string rtrim(const std::string &s)
{
	size_t end = s.find_last_not_of(WHITESPACE);
	return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

std::string trim(const std::string &s) {
	return rtrim(ltrim(s));
}


Field::Field()
{

} 

Field::Field(const string& lineOfCSV)
{
	load(lineOfCSV);
}


void Field::load(const string& lineOfCSV)
{
	size_t comma1 = lineOfCSV.find_first_of(',');
	size_t comma2 = lineOfCSV.find_last_of(',');
	string range = lineOfCSV.substr(0, comma1);
	size_t space1 = range.find_first_of(' ');
	size_t space2 = range.find_last_of(' ');
	//no space
	if (space1 == string::npos)
	{
		range = trim(range);
		this->start = std::stoi(range) - 1;
		this->len = 1;
		this->name = lineOfCSV.substr(comma1 + 1, comma2 - comma1 - 1);
		this->name = trim(this->name);
		return;
	}
	
	if (space1 >= 0 && space2 >= 0)
	{
		string from = range.substr(0, space1);
		from = trim(from);
		string to = range.substr(space2 + 1);
		to = trim(to);
		int s = std::stoi(from);
		int e = std::stoi(to);
		this->start = s - 1;
		this->len = e - s + 1;
		this->name = lineOfCSV.substr(comma1 + 1, comma2 - comma1 - 1);
		this->name = trim(name);
		return;
	}

	cout << "error: field range can not be decoded" << endl;
	cout << lineOfCSV << endl;
	return;

}

