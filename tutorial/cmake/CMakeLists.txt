cmake_minimum_required (VERSION 2.8) 
project (test C CXX)

set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-Og -g")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")
SET(CMAKE_BUILD_TYPE "DEBUG")

# BOOST
FIND_PACKAGE(Boost REQUIRED COMPONENTS system program_options)
include_directories(SYSTEM ${Boost_INCLUDE_DIRS})
list(APPEND test_LINKER_LIBS
    ${Boost_SYSTEM_LIBRARIES}
    ${Boost_PROGRAM_OPTIONS_LIBRARY})

set(PROJECT_ROOT ".")
file(GLOB src_file ${PROJECT_ROOT}/*.cpp)

add_executable(main boost_program_options.cpp ${src_file})
target_link_libraries(main ${test_LINKER_LIBS})
