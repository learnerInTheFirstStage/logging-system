#pragma once

#include <string>
// Log Format Interface

class LogFormat
{
public:
	///////////////////////////////////////////////
	/// Formatted log To String
	/// @para level: Log level
	/// @para log: log content
	/// @para file: file path
	/// @para line: row number
	///
	virtual std::string Format(
		const std::string& level,
		const std::string& log,
		const std::string& file,
		int line
	) = 0;
};
