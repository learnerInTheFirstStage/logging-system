#include "log_fac.h"
#include "xLog_format.h"
#include "log_console_output.h"
#include "log_file_output.h"
#include "xconfig.h"
#define LOGFILE "log.txt"
#include <iostream>

using namespace std;

void LogFac::init(const std::string& con_file)
{
	logger_.SetFormat(new XLogFormat());
	XConfig conf;
	bool re = conf.Read(con_file);
	string log_type = "console";
	string log_file = LOGFILE;
	string log_level = "debug";
	// Read the config file
	if (re)
	{
		log_type = conf.Get("log_type");
		log_file = conf.Get("log_file");
		log_level = conf.Get("log_level");
		cout << "logtype: " << log_type << " logfile: " << log_file << " loglevel: "
			<< log_level << endl;
	}

	// Set Log level
	if (log_level == "info")
	{
		logger_.SetLevel(XLog::INFO);
	}
	else if (log_level == "error")
	{
		logger_.SetLevel(XLog::ERROR);
	}
	else if (log_level == "fatal")
	{
		logger_.SetLevel(XLog::FATAL);
	}

	if (log_type == "file")
	{
		if (log_file.empty()) log_file = LOGFILE;
		auto fout = new LogFileOutput();
		if (!fout->Open(log_file)) cerr << "Open file filed " << log_file << endl;
		logger_.SetOutput(fout);
	}
	else {
		logger_.SetOutput(new LogConsoleOutput());
	}
	
}