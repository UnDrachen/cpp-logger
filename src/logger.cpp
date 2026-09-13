#include "cpp_logger/logger.hpp"

#include <iostream>

namespace cpp_logger
{

static std::string_view logLevelToString(LogLevel level)
{
    switch(level)
    {
        case LogLevel::Debug:
            return "DEBUG";
        case LogLevel::Info:
            return "INFO";
        case LogLevel::Warning:
            return "WARNING";
        case LogLevel::Error:
            return "ERROR";
    }
    return "UNKNOWN";
}

void Logger::debug(std::string_view message) const
{
    log(LogLevel::Debug, message);
}

void Logger::info(std::string_view message) const
{
    log(LogLevel::Info, message);
}

void Logger::warning(std::string_view message) const
{
    log(LogLevel::Warning, message);
}

void Logger::error(std::string_view message) const
{
    log(LogLevel::Error, message);
}

void Logger::log(LogLevel level, std::string_view message) const
{
    if (level >= mMinLevel)
    {
        std::cout << "[" << logLevelToString(level) << "] " << message << '\n';
    }
}

void Logger::setLevel(LogLevel level)
{
    mMinLevel = level;
}

}  // namespace cpp_logger
