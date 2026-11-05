
cmake_minimum_required(VERSION 3.20)

project(Esercitazione_2) 

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")
set(SOURCES es_2.cpp)

add_executable(memory_positions es_1.cpp)
add_executable(computations es_2.cpp)

