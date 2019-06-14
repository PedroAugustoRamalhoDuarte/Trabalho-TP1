#ifndef TRABALHOTP1_INTERFACES_SERVICOS_H
#define TRABALHOTP1_INTERFACES_SERVICOS_H

/**
 * @file Interfaces_Apresentacao.h
 * @brief Arquivo que define as interfaces de serviço do sistema
 *
 * @copyright Pedro Augusto
 * @copyright Waliff Cordeiro
 */

#include <unordered_map>
#include <tuple>
#include "Dominios.h"
#include "Entidades.h"
#include <utility>

class ISAutenticacao {
public:
    virtual bool autenticar(CPF cpf, Senha senha) = 0;
};

class ISEventos {
public:
    virtual bool criarEvento(CPF cpf, Evento evento, list<Apresentacao> listaApresentacao) = 0;

    virtual void alterarEvento(CPF cpf, Evento evento) = 0;

    virtual bool descadastrarEvento(CPF cpf, CodigoDeEvento codigo) = 0;

    virtual void
    pesquisarEventos(list<Evento> &listaEventos, Data dataInicio, Data dataTermino, Cidade cidade, Estado estado) = 0;

    virtual void meusEventos(list<Evento> &listaEventos, CPF cpf) = 0;

    virtual void mostrarApresentacao(list<Apresentacao> &listaApresentacao, CodigoDeEvento codigoDeEvento) = 0;
};

class ISUsuario {
public:
    virtual void cadastrarUsuario(Usuario usuario, CartaoDeCredito cartaoDeCredito) = 0;

    virtual void mostrarUsuario(CPF cpf, Usuario *usuario, CartaoDeCredito *cartaoDeCredito) = 0;

    virtual bool excluirUsuario(CPF cpf) = 0;
};


class ISVendas {
public:
    virtual void listarApresentacao(list<CodigoDeApresentacao> &listCodigosApr) = 0;

    virtual void listarEventos(list<CodigoDeEvento> &listCodigoEve, CPF cpf) = 0;

    virtual bool adquirirIngresso(CPF cpf, CodigoDeApresentacao codigo, int quantidade) = 0;

    virtual void
    vendasDoEvento(CodigoDeEvento codigoDeEvento, list<pair<CodigoDeApresentacao, int>> &tabelaQtdIngressos) = 0;

    virtual void vendasPorCpf(CodigoDeApresentacao codigoDeApresentacao, list<pair<CPF, int>> &tabelaCpfIngressos) = 0;
};

#endif //TRABALHOTP1_INTERFACES_SERVICOS_H
