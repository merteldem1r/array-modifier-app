cmake_minimum_required(VERSION 3.10)

project(array_modifier_app LANGUAGES C DESCRIPTION "Array modifier console app")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -g")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include_directories(${PROJECT_SOURCE_DIR}/include)

set(SRC
        src/main.c
        src/utils/utils.c
        src/methods/core_methods.c
        src/methods/search_methods.c
        src/methods/statistical_methods.c
        src/methods/transformation_methods.c
)

add_executable(${PROJECT_NAME} ${SRC})

if (WIN32)
    add_custom_target(run
            COMMAND start cmd.exe /k "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}.exe"
            DEPENDS ${PROJECT_NAME}
            WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    )
elseif (UNIX)
    add_custom_target(run
            COMMAND "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}"
            DEPENDS ${PROJECT_NAME}
            WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    )
endif ()

add_custom_target(clean_all
        COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/${PROJECT_NAME}
        COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/CMakeFiles
        COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/CMakeCache.txt
        COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/Makefile
)