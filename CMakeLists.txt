cmake_minimum_required(VERSION 3.0)
project(Algorithms)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

include_directories(./3rd/gtest/include)
include_directories(.)
link_directories(./3rd/gtest/lib)

enable_testing()
add_subdirectory(test)
add_subdirectory(algo)