cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(NW_Raytracer)


include(FetchContent)
FetchContent_Declare (
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
)

#stop windows overriding project compiler/linker stuff
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

set(Headers 
        "include/tuple.h")
set(Sources 
        "include/tuple.cpp")

add_library(RayLib STATIC ${Sources} ${Headers})

add_executable (
    main src/main.cpp
)
target_include_directories(main PUBLIC include)
target_link_libraries(main PUBLIC RayLib)

add_executable (
    intro_test tests/intro_test.cpp
)
target_link_libraries(
    intro_test
    GTest::gtest_main
)

add_executable( 
    main_tests tests/main_tests.cpp
)

target_link_libraries(
    main_tests PUBLIC
    GTest::gtest_main
    RayLib
)
include_directories(include)

include(GoogleTest)
gtest_discover_tests(intro_test)
gtest_discover_tests(main_tests)
