//
// Created by pedro on 16/05/19.
//

#ifndef TRABALHOTP1_MODEL_H
#define TRABALHOTP1_MODEL_H

#include "../include/Entidades.h"
#include "../include/Interfaces_Servicos.h"
#include <iostream>
#include <sqlite3.h>

class Model {
private:
    // Ponteiro para o bd
    sqlite3 *db;

    // Status do BD
    int status;

    // Mensagem de erro
    char *mensagem;

    // Criacao de tabelas

    void criarTabelaUsuario();

    void criarTabelaIngresso();

    void criarTabelaEvento();

    void criarTabelaApresentacao();

    // Funcao para Querys no database
    static int callback(void *notUsed, int argc, char **argv, char **azColName);

protected:
    // Informação proveniente das querys
    static list<string> listaResultados;

    string comandoSQL;

public:
    void criarTabelas();

    void executar();

    Model();

    virtual ~Model();
};


#endif //TRABALHOTP1_MODEL_H
