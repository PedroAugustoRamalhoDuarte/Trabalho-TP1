cmake_minimum_required(VERSION 3.12)
project(TrabalhoTP1)

add_executable(TesteDominEntidade test/Teste_Dominios.cpp source/Dominios.cpp include/Dominios.h source/Entidades.cpp include/Entidades.h include/Dominios.h test/Teste_Entidades.cpp)
add_executable(ParaOClionPegar include/Interfaces_Servicos.h include/Interfaces_Apresentacao.h include/Model.h include/View.h source/Model.cpp source/View.cpp main.cpp mainwindow.h mainwindow.cpp)
add_executable(TesteModel test/Teste_Model.cpp source/Model.cpp source/Entidades.cpp source/Dominios.cpp)

#find_package(SQLite3)
#target_link_libraries(TesteModel sqlite3)