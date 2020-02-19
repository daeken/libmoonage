cmake_minimum_required(VERSION 3.15)
project(libmoonage)

set(CMAKE_CXX_STANDARD 20)
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
find_package(Boost 1.72.0 COMPONENTS format)
include_directories(${Boost_INCLUDE_DIRS})

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

add_library(moonage disassembler.generated.cpp common.h interpreter.generated.cpp interpreter.cpp interpreter.h state.h)

add_subdirectory("${PROJECT_SOURCE_DIR}/TestApp" "${PROJECT_SOURCE_DIR}/TestApp_output")
