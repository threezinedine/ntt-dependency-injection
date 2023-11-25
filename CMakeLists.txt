cmake_minimum_required(VERSION 3.10)

project(
    NTTDependencyInjection
)

option(DEBUG "Build in Debug mode" ON)

if(DEBUG)
    add_compile_definitions(_DEBUG=1) 
endif()


add_subdirectory(vendors)

file(
    GLOB
    SRC_FILES
    src/*.cpp
)

add_library(
    ${PROJECT_NAME}
    STATIC
    ${SRC_FILES}
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
    src/include
)

add_subdirectory(examples)
add_subdirectory(tests)