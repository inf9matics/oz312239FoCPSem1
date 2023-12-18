cmake_minimum_required(VERSION 3.0.0)
project(CountingTwoWords VERSION 0.1.0)

set(GCC_CPP_VERSION_FLAGS "-std=c++20 -fcoroutines")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_CPP_VERSION_FLAGS}")

include(CTest)
enable_testing()

add_executable(CountingTwoWords main.cpp word_counter.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
