#include "pch.h"
#include "Database.h"
#include <iostream>
#include <fstream>
#include "AirportRecord.h"
#include "RunwayRecord.h"
#include "WaypointRecord.h"
#include <set>
#include <algorithm> 
#include <cctype>
#include <locale>
#include "VHFNavaidRecord.h"
#include "NDBNavaidRecord.h"

Database::Database()
{
	registRecordClass(new AirportRecord());
	registRecordClass(new RunwayRecord());
	registRecordClass(new WaypointRecord());
	registRecordClass(new VHFNavaidRecord());
	registRecordClass(new NDBNavaidRecord());
	for (auto p : m_classifiers)
		p->loadEncodeSchema("./schema/" + p->getSection() + ".csv");
}

void Database::registRecordClass(BaseRecord* p)
{
	m_classifiers.push_back(p);
	string recordClassName = typeid(*p).name();
	recordClassName = recordClassName.substr(6);
	m_records[recordClassName] = {};
}

Database::~Database()
{
	for (auto& p : m_classifiers)
		delete p;
	for (auto& m : m_records)
	{
		for (auto p : m.second)
		{
			delete p;
		}
	}

}

Database& Database::instance() {
	static Database db = Database();
	return db;
}

bool Database::parse(const string& file)
{
	try
	{
		ifstream is(file, ios::in);
		if (!is) {
			cout << "open file failed" << endl;
		}
		int n = 0;
		string line;
		while (is.good()) {
			n++;
			std::getline(is, line);
			//trim(line);
			if (line.length() == 0)
			{
				cout << "empty line:" << endl;
				continue;
			}
			if (line.length() != 132)
			{
				cout << "bad line" << endl;
				continue;
			}

			int matchedCount = 0;
			for (auto& p : m_classifiers)
			{
				p->setRecord(line);
				if (p->match())
				{
					matchedCount++;
					p->parse();
					updateDB(p);
				}
				else
				{
					//do nothing
				}

			}
			if (matchedCount > 1/* || matchedCount == 0*/)
				m_wrongClassified[line] = matchedCount;
			else if (matchedCount == 0)
				m_unclassified.push_back(line);
		}
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
	return true;
}


void Database::print()
{
	cout << "unclassified: " << m_unclassified.size() << endl;
	cout << "wrong classified: " << m_wrongClassified.size() << endl;
	cout << endl;
	for (auto& m : m_records)
	{
		cout << m.first << ":" <<  m.second.size() << endl;
	}

	for (auto& m : m_records)
	{
		ofstream out(m.first + ".csv", ios::out | ios::trunc);
		if(!m.second.empty())
			m.second.front()->printHeader(out);
		for (auto p : m.second)
			p->print(out);
	}

}


void Database::updateDB(BaseRecord* p)
{
	string recordClassName = typeid(*p).name();
	recordClassName = recordClassName.substr(6);

	if (m_records[recordClassName].empty())
	{
		m_records[recordClassName].push_back(p->clone());
	}
	else
	{
		auto pre = m_records[recordClassName].back();
		bool isContinuous = pre->isContinuous(p->getRecord());
		if (isContinuous)
		{
			pre->push_back(p->getRecord());
		}
		else
		{
			m_records[recordClassName].push_back(p->clone());
		}
	}
}
