# XLog - Modular C++ Logging System

A lightweight, decoupled logging framework for C++ applications that follows the **Strategy** and **Factory** design patterns. This system allows for flexible log formatting and multiple output destinations through a simple interface.

---

## ## Features

* **Multi-Level Logging**: Supports four distinct log levels: `DEBUG`, `INFO`, `ERROR`, and `FATAL`.
* **Flexible Output Targets**:
    * **Console Output**: Standard output logging via `LogConsoleOutput`.
    * **File Output**: Persistent logging to disk via `LogFileOutput` with configurable file paths.
* **Pluggable Formatting**: Uses a dedicated `LogFormat` interface to transform raw log data into structured strings.
* **Configuration Driven**: Dynamically switches log types (console/file), file names, and priority levels using an external `.conf` file.
* **Macro-Based API**: Provides easy-to-use macros that automatically capture the calling file name and line number.
* **Memory Management**: The `Logger` class handles the lifecycle of its delegate formatters and outputters.

---

## ## Core Architecture

The system is built on a composition-based design:

1.  **Logger**: The core engine that manages log levels and delegates work to the formatter and outputter.
2.  **LogFormat (Interface)**: Defines how the log message, level, file, and line number are stringified.
3.  **LogOutput (Interface)**: Defines where the formatted string is sent.
4.  **LogFac (Factory)**: A singleton class that manages the global logger instance and handles initialization from configuration files.

---

## ## Quick Start

### 1. Configuration (`log.conf`)
Define your settings in a simple key-value format:
```ini
log_type=file
log_file=log.txt
log_level=info

#include "log_fac.h"

int main() {
    // Initialize with config file
    LogFac::Instance().init("log.conf");

    // Log messages
    LOGINFO("Application started.");
    LOGDEBUG("This will only show if log_level is debug.");
    LOGERROR("An unexpected error occurred.");

    return 0;
}
```
## Roadmap & Future Enhancements
XML Formatting Support: Implementation of an XMLLogFormat class to allow logs to be parsed easily by automated tools.

Asynchronous Logging: Adding a thread-safe queue to prevent logging operations from blocking the main application thread.

Log Rotation: Support for rolling log files based on file size or time intervals.

Colored Console Output: Enhancing the LogConsoleOutput to support ANSI color codes for different log levels.