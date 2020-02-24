cmake_minimum_required(VERSION 3.15)
project(UnitTests)

set(CMAKE_CXX_STANDARD 20)
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
find_package(Boost 1.72.0)
include_directories(${Boost_INCLUDE_DIRS})

include_directories(/usr/local/include ../)
link_directories(/usr/local/lib)
IF(CMAKE_BUILD_TYPE MATCHES DEBUG)
    link_directories(../cmake-build-debug)
ELSE()
    link_directories(../cmake-build-release)
ENDIF(CMAKE_BUILD_TYPE MATCHES DEBUG)
link_libraries(moonage)

add_definitions(-fsanitize=address)
set(CMAKE_EXE_LINKER_FLAGS -fsanitize=address)

add_executable(unittests main.cpp insts.h)
