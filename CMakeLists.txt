cmake_minimum_required(VERSION 3.20)
project(libpololui2c C CXX)

set(CMAKE_C_STANDARD 11)

add_library(libpololui2c STATIC
        pololu_i2c.c
        pololu_i2c.h
        tests/pololui2c_tests.cpp
        tests/pololui2c_tests.cpp
        tests/pololui2c_tests.cpp
        tests/pololui2c_tests.cpp
        tests/pololui2c_tests.cpp)
target_include_directories(libpololui2c PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR})

# ---- Testing setup ----
include(CTest)
enable_testing()

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(libpololui2c_tests
        tests/pololui2c_tests.cpp)
target_link_libraries(libpololui2c_tests PRIVATE
        libpololui2c
        gtest_main)
if(UNIX AND NOT APPLE)
    target_link_libraries(libpololui2c_tests PRIVATE pthread)
endif()
add_test(NAME libpololui2c_tests COMMAND libpololui2c_tests)
