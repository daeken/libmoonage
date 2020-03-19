cmake_minimum_required(VERSION 3.15)
project(ComprehensiveTests)

set(CMAKE_CXX_STANDARD 20)
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
find_package(Boost 1.72.0)
include_directories(${Boost_INCLUDE_DIRS})

include_directories(/usr/local/include ../)
link_directories(/usr/local/lib)
IF(CMAKE_BUILD_TYPE MATCHES Debug)
    link_directories(../cmake-build-debug)
ELSE()
    link_directories(../cmake-build-release)
ENDIF()
link_libraries(moonage)

#add_definitions(-fsanitize=address)
#set(CMAKE_EXE_LINKER_FLAGS -fsanitize=address)

set(CMAKE_EXE_LINKER_FLAGS -Wl,-image_base,0x100000000)

add_executable(comprehensivetests main.cpp)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/filteredInsns.bin DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/limitedInsns.bin DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/baselineStates.bin DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/run.py DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)
