#include "LogLevel.h"

std::string logLevelToString(LogLevel logLevel)
{
    switch (logLevel)
    {
        case INFO:
            return "INFO";
        case WARNING:
            return "WARNING";
        case ERROR:
            return "ERROR";
        default:
            return "";
    }
}

int longestLogLevelStringLength()
{
    int longest = 0;
    for (int i = FIRST; i < LAST; i++)
    {
        std::string logLevelAsString = logLevelToString(static_cast<LogLevel>(i));
        if (logLevelAsString == "")
        {
            continue;
        }

        if (logLevelAsString.length() > longest)
        {
            longest = logLevelAsString.length();
        }
    }

    return longest;
}