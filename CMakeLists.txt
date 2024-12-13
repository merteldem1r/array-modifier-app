cmake_minimum_required(VERSION 3.10)

project(array_modifier_app LANGUAGES C DESCRIPTION "Array modifier console app")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -g")

include_directories(${PROJECT_SOURCE_DIR}/include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

set(SRC
        src/main.c
        src/utils/utils.c
        src/methods/core_methods.c
        src/methods/search_methods.c
        src/methods/statistical_methods.c
        src/methods/transformation_methods.c
)

add_executable(${PROJECT_NAME} ${SRC})

add_custom_target(clean_all
        COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/${PROJECT_NAME}
        COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/CMakeFiles
        COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/CMakeCache.txt
        COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/Makefile
)