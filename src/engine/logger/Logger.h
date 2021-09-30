#pragma once

#include "LogLevel.h"
#include <iostream>

class Logger
{
public:
    Logger();

private:
    LogLevel logLevel_;
    std::string beforeLogLevel_;
    std::string afterLogLevel_;
    int maxLogLevelStringLength_;

public:
    void info(std::string message);
    void warn(std::string message);
    void error(std::string message);
    void clearConsole();

private:
    void log(LogLevel targetLogLevel, std::string& message);
    std::string toComposedLogLevel(LogLevel logLevel);
    void logLoggerError(std::string& error);

public:
    void setBeforeLogLevel(std::string& beforeLogLevel);
    void setAfterLogLevel(std::string& afterLogLevel);
    void setLogLevel(LogLevel logLevel);
};
