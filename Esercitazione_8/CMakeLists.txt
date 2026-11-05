cmake_minimum_required(VERSION 3.20)
project(esercitazione6)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

## Creo i target per gli eseguibili che effettueranno i test unitari
add_executable(test_edges edges.cpp)
add_test(NAME Edges COMMAND test_edges)

add_executable(test_graphs2 graphs2.cpp)
add_test(NAME Graphs2 COMMAND test_graphs2)

enable_testing()