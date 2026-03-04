#pragma once
#include "log_output.h"
#include <fstream>
class LogFileOutput :
    public LogOutput
{
public:
	/// <summary>
	/// Open the file you write into
	/// </summary>
	/// <param name="file">file path</param>
	/// <returns>If Open</returns>
	bool Open(const std::string& file);

	/// <summary>
	/// Log Output
	/// @para log: formatted log's content
	/// </summary>
	void Output(const std::string& log) override;

private:
	std::ofstream ofs_;
};

