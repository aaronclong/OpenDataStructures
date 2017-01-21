cmake_minimum_required(VERSION 3.7.0)

#Project Name
project (Lesson_Two)

#Subdirectories
add_subdirectory (src) 

add_subdirectory (tests) 

#Link Directories
LINK_DIRECTORIES(${CMAKE_SOURCE_DIR}/build/lib)

#Main function for this lesson
set(SOURCES main.cpp)
add_executable(lesson_two ${SOURCES})
