cmake_minimum_required(VERSION 3.7.0)

#Project Name
project(TESTING)

#Setting Test sources
set(TEST test_random_queue.cpp)


#Search for libraries
enable_testing()
LINK_DIRECTORIES(${CMAKE_SOURCE_DIR}/build/lib)

#turn test into a library
add_library(test_chptwo SHARED ${TEST})