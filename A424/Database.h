#pragma once
#include <vector>
#include <string>
#include <map>
#include <vector>
class BaseRecord;
using namespace std;
class Database
{
public:
	~Database();
	static Database& instance();
	bool parse(const string& file);
	vector<BaseRecord*> m_airports;
	vector<BaseRecord*> m_runways;
	vector<BaseRecord*> m_waypoints;
	vector<BaseRecord*> m_classifiers;
	map<string, int> m_wrongClassified;
	vector<string> m_unclassified;
	map<string, vector<BaseRecord*>> m_records;
	void updateDB(BaseRecord* p);

	void print();
private:
	void registRecordClass(BaseRecord* p);
	Database();
};

