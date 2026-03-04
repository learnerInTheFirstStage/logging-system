#pragma once
#include <string>
#include "log_format.h"
#include "log_output.h"
/// <summary>
/// Composition
/// Delegate LogFormat & LogOutput
/// </summary>

enum class XLog
{
	DEBUG,
	INFO,
	ERROR,
	FATAL
};

class Logger
{
public:
	///////////////////////////////////////////////
	/// Formatt and write log
	/// @para level: Log level
	/// @para log: log content
	/// @para file: file path
	/// @para line: row number
	///
	void Write(
		XLog level,
		const std::string& log,
		const std::string& file,
		int line
	);

	void SetOutput(LogOutput* output) { output_ = output; }
	void SetFormat(LogFormat* format) { formater_ = format; }
	~Logger()
	{
		delete output_; output_ = nullptr;
		delete formater_; formater_ = nullptr;
	}
	void SetLevel(XLog level) { log_level_ = level; }

private:
	LogOutput* output_{ nullptr };
	LogFormat* formater_{nullptr};

	// Set lowest log level
	XLog log_level_{ XLog::DEBUG };
};

