cmake_minimum_required(VERSION 4.2)

get_filename_component(DAY_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

set(SRC ${DAY_NAME}.c)
set(TARGET ${DAY_NAME})

add_executable(${TARGET} ${SRC})

target_include_directories(${TARGET} PRIVATE ${AOC_2024_INCLUDE_DIR})

set_target_properties(${TARGET} PROPERTIES
    C_STANDARD 99
    C_STANDARD_REQUIRED ON
    C_EXTENSIONS OFF
)

target_compile_options(${TARGET} PRIVATE -Wall -Wextra -pedantic -O2)

if(TEST)
    target_compile_definitions(${TARGET} PRIVATE TEST)
endif()

set_target_properties(${TARGET} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)