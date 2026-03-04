// test_class_xlog.cpp
//

#include <iostream>
//#include "xLog_format.h"
//#include "log_console_output.h"
//#include "log_file_output.h"
//#include "logger.h"
#include "log_fac.h"
//#include "xconfig.h"

using namespace std;

// XLogFormat -> LogFormat

int main()
{
    system("chcp 65001");

    //XConfig conf;
    //conf.Read("log.conf");
    //cout << conf.Get("log_file") << endl;
    LogFac::Instance().init();

    // LogFac::Instance().logger().Write(XLog::DEBUG, "test logger", __FILE__, __LINE__);
    LOGDEBUG("test LogFac debug");
    LOGINFO("test LogFac info");
    LOGERROR("test LogFac error");
    LOGFATAL("test LogFac fatal");

    /*
    {
        Logger logger;
        logger.SetLevel(XLog::ERROR);
        logger.SetFormat(new XLogFormat());
        //auto fout = new LogFileOutput();
        //fout->Open("log2.txt");
        logger.SetOutput(new LogConsoleOutput());
        logger.Write(XLog::DEBUG, "test debug Logger", __FILE__, __LINE__);
        logger.Write(XLog::INFO, "test info Logger", __FILE__, __LINE__);
        logger.Write(XLog::ERROR, "test error Logger", __FILE__, __LINE__);
        logger.Write(XLog::FATAL, "test fatal Logger", __FILE__, __LINE__);
    }

    return 0;

    LogFileOutput file_out;
    file_out.Open("log.txt");
    file_out.Output("test file log");

    LogConsoleOutput con_out;
    con_out.Output("test LogConsoleOutput");

    XLogFormat xlog;
    auto str = xlog.Format("debug", "test log format", __FILE__, __LINE__);
    cout << "str: " << str << endl;
    */
}
