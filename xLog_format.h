#pragma once
#include "log_format.h"
class XLogFormat :
    public LogFormat
{
public:
	///////////////////////////////////////////////
	/// Formatted log To String
	/// @para level: Log level
	/// @para log: log content
	/// @para file: file path
	/// @para line: row number
	/// @return: formatted log
	///
	std::string Format(
		const std::string& level,
		const std::string& log,
		const std::string& file,
		int line
	) override;
};

