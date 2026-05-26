cmake_minimum_required(VERSION 3.24.2)
project(testproj CXX)

set(CMAKE_CXX_STANDARD 17)

#add_subdirectory(googletest)

add_executable(${PROJECT_NAME} main.cpp candle.cpp candle.h)

#target_link_libraries(${PROJECT_NAME} gtest_main)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

target_link_libraries(${PROJECT_NAME} GTest::gtest_main)

enable_testing()
include(GoogleTest)
gtest_discover_tests(testproj)