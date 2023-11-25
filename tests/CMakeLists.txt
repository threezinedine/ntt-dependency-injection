project(
    NTTDependencyInjection_Test
)

file(
    GLOB
    SRC_FILES
    ./*.cpp
)

add_subdirectory(vendors)

add_executable(
    ${PROJECT_NAME}
    ${SRC_FILES}
)


target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC
    gtest
    gmock
)