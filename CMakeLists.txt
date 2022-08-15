cmake_minimum_required(VERSION 3.24.0)

project(Suffix_Array_Project)

add_executable(${PROJECT_NAME} src/main.cpp)

add_subdirectory(include/Functions)

target_include_directories(${PROJECT_NAME} PUBLIC include/Functions)

target_link_directories(${PROJECT_NAME} PRIVATE include/Functions)

target_link_libraries(${PROJECT_NAME} Functions)

#get googletest
include(FetchContent)
FetchContent_Declare(googletest
            GIT_REPOSITORY https://github.com/google/googletest
            GIT_TAG release-1.12.1)
FetchContent_GetProperties(googletest)
#googletest_POPULATED
#googletest_SOURCE_DIR
#googletest_BUILD_DIR
if(NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BUILD_DIR})
endif()

add_executable(Testing test/test.cpp)

target_include_directories(Testing PUBLIC include/Functions)

target_link_directories(Testing PRIVATE include/Functions)

target_link_libraries(Testing Functions gtest_main gmock_main)


add_subdirectory(benchmark)
add_executable(Benchmark src/benchmark.cpp)

target_include_directories(Benchmark PUBLIC include/Functions)

target_link_directories(Benchmark PRIVATE include/Functions)

target_link_libraries(Benchmark benchmark::benchmark Functions)