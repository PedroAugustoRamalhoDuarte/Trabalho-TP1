cmake_minimum_required(VERSION 3.12)
project(TrabalhoTP1)

set(CMAKE_CXX_STANDARD 14)

add_executable(TrabalhoTP1 teste_chacon/Teste.cpp source/Dominios.cpp include/Dominios.h source/Entidades.cpp include/Entidades.h include/Dominios.h teste_chacon/Teste_Chacon.cpp teste_chacon/Teste_Chacon.h)