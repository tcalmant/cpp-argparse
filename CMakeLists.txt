cmake_minimum_required(VERSION 3.10)

project(cpp-mini-argparse)

# The library
add_subdirectory(argparse)

# Sample executable
add_executable(basic-sample sample/basic.cpp)
target_link_libraries(basic-sample PUBLIC cpp-mini-argparse)
