cmake_minimum_required(VERSION 3.16)
project(lab2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)

add_library(mystring STATIC mystring.cpp string_constructors.cpp)
add_executable(lab2_app main.cpp)
target_link_libraries(lab2_app PRIVATE mystring)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(run_tests tests.cpp)
target_link_libraries(run_tests PRIVATE mystring gtest_main)

enable_testing()
include(GoogleTest)
gtest_discover_tests(run_tests)