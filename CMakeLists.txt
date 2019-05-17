cmake_minimum_required(VERSION 3.12)
project(TrabalhoTP1)

add_executable(TesteDominEntidade test/Teste_Dominios.cpp source/Dominios.cpp include/Dominios.h source/Entidades.cpp include/Entidades.h include/Dominios.h test/Teste_Entidades.cpp)
add_executable(TesteBanco source/Entidades.cpp include/Entidades.h SQLite/BdController.cpp SQLite/BdController.h SQLite/teste.cpp include/Interfaces_Servicos.h include/Interfaces_Apresentacao.h source/Model.cpp include/Model.h source/View.cpp include/View.h)