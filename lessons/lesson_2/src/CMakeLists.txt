cmake_minimum_required(VERSION 3.7.0)

#Project Name
project (chp_two)

#Build Problem Sets as Library
#Header Files 
set(LIB_H ${CMAKE_CURRENT_SOURCE_DIR}/inc/random_queue.h )
include_directories(include ${CMAKE_CURRENT_SOURCE_DIR}/inc)
#Source files
set(LIB random_queue.cpp)
add_library(chp_two SHARED ${LIB_H} ${LIB})

#target_include_directories(chp_two PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc/array_list.h)
