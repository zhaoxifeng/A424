#pragma once
#include <string>
using namespace std;
class Field
{
public:
	Field();
	Field(const string& lineOfCSV);
	unsigned char start;
	unsigned char len;
	string name;
private:
	void load(const string& lineOfCSV);
};

