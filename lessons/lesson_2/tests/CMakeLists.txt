cmake_minimum_required(VERSION 3.7.0)

#Project Name
project(TESTING)

#Setting Test sources
set(TEST test_random_queue.cpp)

#Search for libraries
find_library(LESSIONS_LIBS chp_two PATHS {CMAKE_SOURCE_DIR}/build/lib/)
set_property(TARGET chp_two
             PROPERTY INCLUDE_DIRECTORIES ${CMAKE_SOURCE_DIR}/lessons/lesson_two/src/inc)

enable_testing()

#turn test into a library
add_library(test_chptwo SHARED ${TEST})

target_link_libraries(test_chptwo gtest LESSIONS_LIBS)