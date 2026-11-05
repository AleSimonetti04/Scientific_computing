
cmake_minimum_required(VERSION 3.20)

project(Esercitazione_1) 

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow")

# A questo punto siamo pronti a dichiarare l'eseguibile che vogliamo produrre.
# Con il comando add_executable chiediamo di creare un eseguibile chiamato
# passo3 a partire dai file sorgente passo3_main.cpp e passo3_functions.cpp.
# In qualche modo questo genererà le seguenti chiamate al compilatore
#
#    g++ -o passo3_main.o passo3_main.cpp
#    g++ -o passo3_functions.o passo3_functions.cpp
#    g++ -o passo3 passo3_main.o passo3_functions.o
#
# La prima chiamata compila passo3_main.cpp e produce il codice oggetto
# passo3_main.o. La seconda chiamata fa la stessa cosa per passo3_functions.# L'ultima chiamata esegue il collegamento dei due file oggetto producendo
# l'eseguibile passo3

add_executable(Printargs printargs.cpp)
add_executable(Esercitazione_1 media_t.cpp)

