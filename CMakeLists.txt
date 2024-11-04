cmake_minimum_required(VERSION 3.0)
project(Algorithms)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 20)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_subdirectory(sort)
add_subdirectory(string)