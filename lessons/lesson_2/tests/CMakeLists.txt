cmake_minimum_required(VERSION 3.7.0)

#Project Name
project(TESTING)

#Setting Test sources
set(TEST test_random_queue.cpp)

#Search for libraries
#set(LESSION ${CMAKE_SOURCE_DIR}/build/lib/libchp_two.dylib )
include_directories(${CMAKE_SOURCE_DIR}/lessons/lesson_2/src/inc/)

enable_testing()

#turn test into a library
add_library(test_chptwo SHARED ${TEST} ${CMAKE_SOURCE_DIR}/lessons/lesson_2/src/inc/random_queue.h)

target_link_libraries(test_chptwo gtest chp_two)