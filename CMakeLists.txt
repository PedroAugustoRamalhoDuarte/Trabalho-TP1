cmake_minimum_required(VERSION 3.12)
project(TrabalhoTP1)

set(CMAKE_CXX_STANDARD 14)

add_executable(TesteDominEntidade test/Teste_Dominios.cpp source/Dominios.cpp include/Dominios.h source/Entidades.cpp include/Entidades.h include/Dominios.h test/Teste_Entidades.cpp include/Interfaces_Autenticacao.h include/Interfaces_Usuario.h include/Interfaces_Eventos.h include/Interfaces_Vendas.h)