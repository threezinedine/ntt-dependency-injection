cmake_minimum_required(VERSION 3.10)

project(
    FirstExample_Injection
)

file(
    GLOB
    SRC_FILES
    ./*.cpp
)

add_executable(
    ${PROJECT_NAME}
    ${SRC_FILES}
)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    NTTDependencyInjection
)

if (DEBUG)
    target_link_libraries(
        ${PROJECT_NAME}
        PRIVATE
        CPPMemoryChecker
    )
endif()