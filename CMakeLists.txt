cmake_minimum_required(VERSION 4.0)
project(libpololui2c C)

set(CMAKE_C_STANDARD 11)

add_library(libpololui2c STATIC
        pololu_i2c.c)
