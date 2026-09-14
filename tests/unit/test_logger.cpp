#include <gtest/gtest.h>

#include <iostream>
#include <sstream>
#include <streambuf>
#include <string>

#include "cpp_logger/logger.hpp"

struct LogFilteringCase
{
    cpp_logger::LogLevel minimumLevel;
    cpp_logger::LogLevel messageLevel;
};

// Fixture test class
class CTestLogger : public testing::Test
{
public:
    void SetUp()
    {
        mOriginalBuffer = std::cout.rdbuf(mStream.rdbuf());
    }

    void TearDown()
    {
        std::cout.rdbuf(mOriginalBuffer);
    }

    std::string getCapturedStream()
    {
        return mStream.str();
    }

private:
    std::ostringstream mStream;
    std::streambuf *mOriginalBuffer;
};

// Paremeterized test class
class LoggerFilteringTest : public CTestLogger,
                            public testing::WithParamInterface<LogFilteringCase>
{
};

// Tests

TEST_P(LoggerFilteringTest, FilterLogLevel)
{
    const LogFilteringCase& testCase = GetParam();

    cpp_logger::Logger logger;
    logger.setLevel(testCase.minimumLevel);

    switch (testCase.messageLevel)
    {
        case cpp_logger::LogLevel::Debug:
            logger.debug("Test message");
            break;

        case cpp_logger::LogLevel::Info:
            logger.info("Test message");
            break;

        case cpp_logger::LogLevel::Warning:
            logger.warning("Test message");
            break;

        case cpp_logger::LogLevel::Error:
            logger.error("Test message");
            break;
    }

    if (testCase.messageLevel >= testCase.minimumLevel)
    {
        EXPECT_FALSE(getCapturedStream().empty());
    }
    else
    {
        EXPECT_TRUE(getCapturedStream().empty());
    }
}

INSTANTIATE_TEST_SUITE_P(
    AllLogLevels,
    LoggerFilteringTest,
    testing::Values(
        LogFilteringCase{
            cpp_logger::LogLevel::Debug,
            cpp_logger::LogLevel::Debug,
        },
        LogFilteringCase{
            cpp_logger::LogLevel::Debug,
            cpp_logger::LogLevel::Info,
        },
        LogFilteringCase{
            cpp_logger::LogLevel::Debug,
            cpp_logger::LogLevel::Warning,
        },
        LogFilteringCase{
            cpp_logger::LogLevel::Debug,
            cpp_logger::LogLevel::Error,
        },

        LogFilteringCase{
            cpp_logger::LogLevel::Info,
            cpp_logger::LogLevel::Debug,
        },
        LogFilteringCase{
            cpp_logger::LogLevel::Info,
            cpp_logger::LogLevel::Info,
        },
        LogFilteringCase{
            cpp_logger::LogLevel::Info,
            cpp_logger::LogLevel::Warning,
        },
        LogFilteringCase{
            cpp_logger::LogLevel::Info,
            cpp_logger::LogLevel::Error,
        },

        LogFilteringCase{
            cpp_logger::LogLevel::Warning,
            cpp_logger::LogLevel::Debug,
        },
        LogFilteringCase{
            cpp_logger::LogLevel::Warning,
            cpp_logger::LogLevel::Info,
        },
        LogFilteringCase{
            cpp_logger::LogLevel::Warning,
            cpp_logger::LogLevel::Warning,
        },
        LogFilteringCase{
            cpp_logger::LogLevel::Warning,
            cpp_logger::LogLevel::Error,
        },

        LogFilteringCase{
            cpp_logger::LogLevel::Error,
            cpp_logger::LogLevel::Debug,
        },
        LogFilteringCase{
            cpp_logger::LogLevel::Error,
            cpp_logger::LogLevel::Info,
        },
        LogFilteringCase{
            cpp_logger::LogLevel::Error,
            cpp_logger::LogLevel::Warning,
        },
        LogFilteringCase{
            cpp_logger::LogLevel::Error,
            cpp_logger::LogLevel::Error,
        }
    )
);
