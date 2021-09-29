#pragma once

#include <iostream>

enum LogLevel
{
    FIRST, // for iterating
    INFO,
    WARNING,
    ERROR,
    LAST // for iterating
};

std::string logLevelToString(LogLevel logLevel);
int longestLogLevelStringLength();
