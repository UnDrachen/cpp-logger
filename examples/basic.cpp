#include "cpp_logger/logger.hpp"

int main()
{
    cpp_logger::Logger logger;

    logger.debug("Hello from cpp-logger!");
    logger.info("Hello from cpp-logger!");
    logger.warning("Hello from cpp-logger!");
    logger.error("Hello from cpp-logger!");

    return 0;
}
