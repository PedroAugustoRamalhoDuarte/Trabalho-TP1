cmake_minimum_required(VERSION 3.12)
project(TrabalhoTP1)

set(CMAKE_CXX_STANDARD 14)

add_executable(TrabalhoTP1 source/main.cpp source/Dominios.cpp include/Dominios.h source/Entidades.cpp include/Entidades.h include/Dominios.h teste_chacon/Teste.cpp teste_chacon/Teste.h teste_chacon/testeCPF.cpp)