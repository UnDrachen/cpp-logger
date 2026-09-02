#include "cpp_logger/logger.hpp"

#include <iostream>

namespace cpp_logger
{

void Logger::info(std::string_view message)
{
    std::cout << "[INFO] " << message << '\n';
}

}  // namespace cpp_logger
