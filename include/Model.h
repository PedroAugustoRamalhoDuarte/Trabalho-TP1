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

    // Criacao de tabelas

    void criarTabelaUsuario();

    void criarTabelaIngresso();

    void criarTabelaEvento();

    void criarTabelaApresentacao();

    // Funcao para Querys no database
    static int callback(void* data, int argc, char** argv, char** azColName);

protected:
    // Informação proveniente das querys
    string data;

    string comandoSQL;

public:
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

class ModelAutenticacao : public ModelServico, public  ISAutenticacao {
public:
    bool autenticar(CPF cpf, Senha senha) override;
};

class ModelEventos : public ModelServico, public ISEventos {
public:
    bool criarEvento(CPF cpf, Evento evento, Apresentacao *lista) override;

    bool alterarEvento(CPF cpf, Evento evento) override;

    bool descadastrarEvento(CPF cpf, Evento evento) override;

    bool pesquisarEventos(Evento &evento, Data dataInicio, Data dataTermino, Cidade cidade, Estado estado) override;
};

class ModelVendas : public ModelServico, public ISVendas {
public:
    bool adquirirIngresso(CPF cpf, CodigoDeApresentacao codigo, int quantidade) override;

};
#endif //TRABALHOTP1_MODEL_H
