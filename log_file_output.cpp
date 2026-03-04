#include "log_file_output.h"

using namespace std;

bool LogFileOutput::Open(const string& file)
{
	ofs_.open(file, ios::app);  // Append
	if (ofs_.is_open()) return true;
	return false;
}

void LogFileOutput::Output(const string& log)
{
	ofs_ << log << "\n";
}