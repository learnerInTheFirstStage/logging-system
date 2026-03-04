#pragma once
#include <string>
#include <map>

// Read Config File
/*
* log.conf

log_type=console
log_file=log.txt
log_level=debug
*/

class XConfig
{
public:
	bool Read(const std::string& file);

	const std::string& Get(const std::string& key);

private:
	std::map<std::string, std::string> conf_;
};

