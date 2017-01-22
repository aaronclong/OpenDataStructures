cmake_minimum_required(VERSION 3.7.0)

#Project Name
project (Lesson_Two)

#Subdirectories
add_subdirectory (src) 

add_subdirectory (tests) 

#include directory
#target_include_directories(include ${CMAKE_CURRENT_SOURCE_DIR}/src/inc)
MESSAGE( STATUS "LIBRARY_OUTPUT_PATH:     " ${include} )
find_library(LESSIONS_LIBS chp_two PATHS ${CMAKE_SOURCE_DIR}/build/lib)

#Main function for this lesson
set(SOURCES main.cpp)
add_executable(lesson_two ${include} ${SOURCES})
target_link_libraries(lesson_two gtest ${LESSIONS_LIBS})
