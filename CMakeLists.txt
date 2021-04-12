# @file CMakeLists.txt
# 
# CMake files for Partition

# Can be run by any version of CMake >= this
cmake_minimum_required(VERSION 3.19)

# project info
project(Partition)

# C++17 standard
set(CMAKE_CXX_STANDARD 17)

# force release debug since used for demonstration
set(CMAKE_BUILD_TYPE Debug)

# Partition tests
add_executable(PartitionHoare PartitionHoare.cpp)
add_executable(PartitionLomuto PartitionLomuto.cpp)

# Turn on warnings
if (MSVC)
    # warning level 4
    add_compile_options(/W4)
else()
    # standard warnings
    add_compile_options(-Wall)
endif()

# Demo run command
add_custom_target(run
        COMMENT "Run partition tests"
        COMMAND ./PartitionHoare
        COMMAND ./PartitionLomuto
        DEPENDS PartitionHoare
        DEPENDS PartitionLomuto
        USES_TERMINAL
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
