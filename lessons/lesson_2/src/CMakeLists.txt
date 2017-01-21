cmake_minimum_required(VERSION 3.7.0)

#Project Name
project (Lesson_Two_Sources)

#Build Problem Sets as Library
#Header Files 
include_directories(include ${CMAKE_CURRENT_SOURCE_DIR}/inc/)
#Source files
set(LIB random_queue.cpp ${include})
add_library(chp_two SHARED ${LIB})
