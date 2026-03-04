#include "xconfig.h"
#include <fstream>
#include <iostream>

using namespace std;

const std::string& XConfig::Get(const string& key)
{
	auto it = conf_.find(key);
	if (it == conf_.end()) return "";
	return it->second;
}

bool XConfig::Read(const std::string& file)
{
	ifstream ifs(file);
	if (!ifs.is_open()) return false;
	string line;
	for (;;)
	{
		getline(ifs, line);
		string k, v;
		if (!line.empty())
		{
			auto p = line.find('=');
			if (p <= 0) continue;
			k = line.substr(0, p);
			v = line.substr(p + 1);
			conf_[k] = v;
		}
		if (!ifs.good()) break;
	}
	return true;
}