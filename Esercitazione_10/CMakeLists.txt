cmake_minimum_required(VERSION 3.20)
project(esercitazione10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

find_package(Eigen3 REQUIRED)


## Creo i target per gli eseguibili che effettueranno i test unitari
add_executable(test_cg test_cg.cpp)
add_test(NAME CG COMMAND test_cg)
target_link_libraries(test_cg PRIVATE Eigen3::Eigen)

enable_testing()

