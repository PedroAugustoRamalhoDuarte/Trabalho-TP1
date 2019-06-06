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
    sqlite3* db;

    // Status do BD
    int status;

    // Mensagem de erro
    char* mensagem;

    // Criacao de tabelas

    void criarTabelaUsuario();

    void criarTabelaIngresso();

    void criarTabelaEvento();

    void criarTabelaApresentacao();

    // Funcao para Querys no database
    static int callback(void* notUsed, int argc, char** argv, char** azColName);

protected:
    // Informação proveniente das querys
    static list<string> listaResultados;

    string comandoSQL;

public:
    void criarTabelas();

    void executar();

    Model();

    //virtual ~Model();
};


class ModelUsuario : public Model, public ISUsuario {
public:
    bool cadastrarUsuario(Usuario usuario, CartaoDeCredito cartaoDeCredito) override;

    bool mostrarUsuario(CPF cpf, Usuario *usuario, CartaoDeCredito *cartaoDeCredito) override;

    bool excluirUsuario(CPF cpf) override;

    ModelUsuario();
};

class ModelAutenticacao : public Model, public  ISAutenticacao {
public:
    bool autenticar(CPF cpf, Senha senha) override;

    ModelAutenticacao();
};

class ModelEventos : public Model, public ISEventos {
private:
    const static int LIMITE_EVENTOS = 10;
    const static int LIMITE_APRESENTACAO = 10;

    // Retorna True caso não possa mais criar eventos
    bool isLimiteEventos(CPF cpf);

    void adicionarApresentacoes(CodigoDeEvento codigo, list<Apresentacao> listaApresentacao);

public:
    bool criarEvento(CPF cpf, Evento evento, list<Apresentacao> listaApresentacao) override;

    bool alterarEvento(CPF cpf, Evento evento) override;

    bool descadastrarEvento(CPF cpf, Evento evento) override;

    bool pesquisarEventos(list<Evento> &listaEventos, Data dataInicio, Data dataTermino, Cidade cidade, Estado estado) override;

    ModelEventos();
};

class ModelVendas : public Model, public ISVendas {
public:
    bool adquirirIngresso(CPF cpf, CodigoDeApresentacao codigo, int quantidade) override;

    ModelVendas();
};
#endif //TRABALHOTP1_MODEL_H
