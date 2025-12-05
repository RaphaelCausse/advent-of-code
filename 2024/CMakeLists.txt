cmake_minimum_required(VERSION 3.16)

project(AOC2024 LANGUAGES C)

set(AOC_2024_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB DAY_DIRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} day*)

foreach(DAY ${DAY_DIRS})
    if(IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/${DAY}")
        add_subdirectory(${DAY})

        add_custom_target(run_${DAY}
            COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/${DAY}/${DAY}
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${DAY}
            DEPENDS ${DAY}
        )
    endif()
endforeach()
