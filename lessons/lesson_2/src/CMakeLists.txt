cmake_minimum_required(VERSION 3.7.0)

#Project Name
project (Lesson_Two_Sources)

#Build Problem Sets as Library
#set(LIB_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/inc/array_list.h)
include_directories(include ${CMAKE_CURRENT_SOURCE_DIR}/inc)
set(LIB array_list.cpp)
add_library(chp_two SHARED ${LIB})

#Main function for this lesson
set(SOURCES main.cpp)

add_executable(lesson_two ${SOURCES})
