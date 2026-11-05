cmake_minimum_required(VERSION 3.20)
project(esercitazione9)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

## Creo i target per gli eseguibili che effettueranno i test unitari
add_executable(test_visit main.cpp)
add_test(NAME Visit COMMAND test_visit)

enable_testing()