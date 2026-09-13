cmake_minimum_required(VERSION 3.20)

project(cpp-logger
    VERSION 0.1.0
    LANGUAGES CXX
)

add_library(cpp_logger STATIC
    src/logger.cpp
)

target_compile_features(cpp_logger  # Set target specific standard
    PUBLIC
        cxx_std_20
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

include(FetchContent)
include(CTest)

if(BUILD_TESTING)
    add_subdirectory(tests)
endif()
