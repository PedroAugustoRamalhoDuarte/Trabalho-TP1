//
// Created by pedro on 16/05/19.
//

#ifndef TRABALHOTP1_MODEL_H
#define TRABALHOTP1_MODEL_H

#include "../include/Entidades.h"
#include "../include/Interfaces_Servicos.h"
#include <iostream>
#include <sqlite3.h>

class ModelServico {
private:
    // Ponteiro para o bd
    sqlite3* db;

    // Status do BD
    int status;

    // Mensagem de erro
    char** mensagem;

    /* Criacao de tabelas */

    void criarTabelaUsuario();

    void criarTabelaIngresso();

    void criarTabelaEvento();

    void criarTabelaApresentacao();

    static int callback(void* data, int argc, char** argv, char** azColName);

    void static verificarErro(int status, char* mensagem);

protected:
    // Informação proveniente das querys
    string data;

    string comandoSQL;

public:

    //void inserirUsuario(const Usuario &usuario,const CartaoDeCredito &cartaoDeCredito);

    //void inserirIngresso(const Ingresso &ingresso, const CPF &cpf);

    void criarTabelas();

    void executar();

    ModelServico();

    virtual ~ModelServico();
};


class ModelServicoUsuario : public ModelServico, public ISUsuario {
public:
    bool cadastrarUsuario(Usuario usuario, CartaoDeCredito cartaoDeCredito) override;

    bool mostrarUsuario(CPF cpf, Usuario *usuario, CartaoDeCredito *cartaoDeCredito) override;

    bool excluirUsuario(CPF cpf) override;

    ModelServicoUsuario();
};
#endif //TRABALHOTP1_MODEL_H
