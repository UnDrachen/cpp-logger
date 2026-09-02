#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string_view>

namespace cpp_logger
{

class Logger
{
public:
    void info(std::string_view message);
};

}  // namespace cpp_logger

#endif  // LOGGER_HPP
