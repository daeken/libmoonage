cmake_minimum_required(VERSION 3.15)
project(libmoonage)

set(CMAKE_CXX_STANDARD 20)
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
find_package(Boost 1.72.0)
include_directories(${Boost_INCLUDE_DIRS})

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

set(LLVM_LIB_DEPS LLVMX86AsmPrinter LLVMX86AsmParser)
find_package(llvm 9.0.1)
include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})
llvm_map_components_to_libnames(llvm_libs core support mc mcjit native nativecodegen target)
message("${llvm_libs}")
link_libraries(${llvm_libs})
add_definitions(-fsanitize=address)

add_library(moonage disassembler.generated.cpp common.h interpreter.generated.cpp interpreter.cpp interpreter.h state.h recompiler.generated.cpp recompiler.h runtimeValue.cpp runtimeValue.h recompiler.cpp property.h cacheManager.cpp cacheManager.h interface.h interface.cpp)

add_subdirectory("${PROJECT_SOURCE_DIR}/TestApp" "${PROJECT_SOURCE_DIR}/TestApp_output")
