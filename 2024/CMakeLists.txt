cmake_minimum_required(VERSION 4.2)

project(AdventOfCode_2024 LANGUAGES C)

set(AOC_2024_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB DAY_DIRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} day*)

foreach(DAY ${DAY_DIRS})
    if(IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/${DAY}")
        add_subdirectory(${DAY})
    endif()
endforeach()
