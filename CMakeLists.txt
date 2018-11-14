#1.cmake minimum required verson
cmake_minimum_required(VERSION 3.4)

# require C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#2.project name langevin
project(langevin VERSION 0.1.1 LANGUAGES CXX)

#3.head file path
#include_directories(include)

# default build type: Release
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

set(LIBRARY_NAME "lib${PROJECT_NAME}")
set(TEST_EXE "test_${PROJECT_NAME}")

add_subdirectory(src)
add_subdirectory(test)

#4.source directory
#aux_source_directory(src DIR_SRCS)

#5.set environment variable

#6.add executable file
#add_executable(${PROJECT_NAME} ${DIR_SRCS})

#7.add link library
#target_link_libraries(${PROJECT_NAME} -lgsl -lgslcblas)