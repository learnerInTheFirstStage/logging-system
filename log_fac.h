#pragma once
#include <string>
#include "logger.h"
// logger factory -> build logger
// Maintain logger's life cycle
class LogFac
{
public:
	static LogFac& Instance()
	{
		static LogFac fac;
		return fac;
	}

	// Initialize logger instance
	void init(const std::string& con_file = "log.conf");
	Logger& logger() { return logger_; }

private:
	LogFac(){}
	Logger logger_;
};

#define XLOGOUT(l, s) LogFac::Instance().logger().Write(l, s, __FILE__, __LINE__)
#define LOGDEBUG(s) XLOGOUT(XLog::DEBUG, s)
#define LOGINFO(s) XLOGOUT(XLog::INFO, s)
#define LOGERROR(s) XLOGOUT(XLog::ERROR, s)
#define LOGFATAL(s) XLOGOUT(XLog::FATAL, s)

