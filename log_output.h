#pragma once
# include <string>
/// <summary>
/// Log Output Interface
/// </summary>
class LogOutput
{
public:
	/// <summary>
	/// Log Output
	/// @para log: formatted log's content
	/// </summary>
	virtual void Output(const std::string& log) = 0;
};