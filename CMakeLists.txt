cmake_minimum_required(VERSION 3.29)
project(untitled)

set(CMAKE_CXX_STANDARD 17)
set(gtest_SRC_DIR test/googletest-1.15.2)

# 파일 이름 변경 위치
set(PROBLEM_FILE_NAME "barkingdog/[0x09]BFS/241009-14442")
add_definitions(-DPROBLEM_FILE_NAME="${PROBLEM_FILE_NAME}")

add_subdirectory(${gtest_SRC_DIR})

include_directories(${gtest_SRC_DIR}/googletest/include)

add_library(algorithm SHARED ${PROBLEM_FILE_NAME}.cpp algorithm-frame.h)

add_executable(runTests test/algorithm-test.cpp)
target_link_libraries(runTests gtest gtest_main)
target_link_libraries(runTests algorithm)

add_executable(241001-15665 "Baekjoon/241001-15665.cpp")
add_executable(241001-15666 "Baekjoon/241001-15666.cpp")
add_executable(241003-2493 "barkingdog/[0x05]stack/241003-2493.cpp")
add_executable(241003-3015 "barkingdog/[0x05]stack/241003-3015.cpp")
add_executable(241007-6549 "barkingdog/[0x05]stack/241007-6549.cpp")
add_executable(241009-5430 barkingdog/[0x07]dequeue/241009-5430.cpp)
add_executable(241009-11003 barkingdog/[0x07]dequeue/241009-11003.cpp)

add_executable(241009-14442 barkingdog/[0x09]BFS/241009-14442.cpp)

