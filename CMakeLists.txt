cmake_minimum_required(VERSION 3.17)
project(gps_analysis C)

set(CMAKE_C_STANDARD 99)

include(cmakeconf/building_output.cmake)
include(cmakeconf/compiler_conf.cmake)

add_subdirectory(src)
add_subdirectory(test)