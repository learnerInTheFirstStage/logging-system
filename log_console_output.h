#pragma once
#include "log_output.h"
class LogConsoleOutput :
    public LogOutput
{
public:
	/// <summary>
	/// Log Output
	/// @para log: formatted log's content
	/// </summary>
	void Output(const std::string& log) override;
};

