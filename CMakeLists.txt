cmake_minimum_required(VERSION 3.20)

project(cpp-logger
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(cpp_logger STATIC
    src/logger.cpp
)

target_include_directories(cpp_logger
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

add_executable(logger_example
    examples/basic.cpp
)

target_link_libraries(logger_example
    PRIVATE
        cpp_logger
)
