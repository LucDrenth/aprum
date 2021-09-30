#include "Logger.h"

Logger::Logger()
{
    beforeLogLevel_ = "[";
    afterLogLevel_ = "]: ";
    logLevel_ = ERROR;
    maxLogLevelStringLength_ = longestLogLevelStringLength();
}

void Logger::info(std::string message)
{
    log(INFO, message);
}

void Logger::warn(std::string message)
{
    log(WARNING, message);
}

void Logger::error(std::string message)
{
    log(ERROR, message);
}

void Logger::clearConsole()
{
    system("clear");
}

void Logger::log(LogLevel targetLogLevel, std::string& message)
{
    if (targetLogLevel < logLevel_)
    {
        return;
    }

    std::string composedLogLevel = toComposedLogLevel(targetLogLevel);
    std::cout << composedLogLevel << message << std::endl;
}

std::string Logger::toComposedLogLevel(LogLevel logLevel)
{
    std::string logLevelString = logLevelToString(logLevel);
    std::string composedLogLevel = beforeLogLevel_ + logLevelString + afterLogLevel_;
    int logLevelTargetLength = maxLogLevelStringLength_ + beforeLogLevel_.length() + afterLogLevel_.length();
    for (int i = composedLogLevel.length(); i < logLevelTargetLength; i++)
    {
        composedLogLevel.append(" ");
    }
    return composedLogLevel;
}

void Logger::logLoggerError(std::string& error)
{
    std::cout << "LOGGER ERROR: " << error << std::endl;
}

void Logger::setBeforeLogLevel(std::string &beforeLogLevel)
{
    beforeLogLevel_ = beforeLogLevel;
}

void Logger::setAfterLogLevel(std::string &afterLogLevel)
{
    afterLogLevel_ = afterLogLevel;
}

void Logger::setLogLevel(LogLevel logLevel)
{
    logLevel_ = logLevel;
}
