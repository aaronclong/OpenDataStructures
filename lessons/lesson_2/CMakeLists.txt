cmake_minimum_required(VERSION 3.7.0)

#Project Name
project (Lesson_Two)

#Subdirectories
add_subdirectory (src) 

add_subdirectory (tests) 

#include directory
include_directories(include ${CMAKE_CURRENT_SOURCE_DIR}/src/inc)

#Main function for this lesson
set(SOURCES main.cpp)
add_executable(lesson_two ${SOURCES})
target_link_libraries(lesson_two gtest)
