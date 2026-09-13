#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string_view>

namespace cpp_logger
{

enum class LogLevel
{
    Debug   = 0U,
    Info    = 1U,
    Warning = 2U,
    Error   = 3U
};

class Logger
{
    LogLevel mMinLevel{LogLevel::Debug};

    void log(LogLevel level, std::string_view message) const;

public:
    void setLevel(LogLevel level);
    void debug(std::string_view message) const;
    void info(std::string_view message) const;
    void warning(std::string_view message) const;
    void error(std::string_view message) const;
};

}  // namespace cpp_logger

#endif  // LOGGER_HPP
