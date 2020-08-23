cmake_minimum_required(VERSION 3.10)

#set the project name
project(Sniffer VERSION 0.1)

configure_file(SnifferConfig.h.in SnifferConfig.hpp)

target_include_directories(Sniffer PUBLIC "${PROJECT_BINARY_DIR}" )

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#add executable:
#add_executable(test )
