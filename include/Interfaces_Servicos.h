#ifndef TRABALHOTP1_INTERFACES_SERVICOS_H
#define TRABALHOTP1_INTERFACES_SERVICOS_H

/**
 * @file Interfaces_Apresentacao.h
 * @brief Arquivo que define as interfaces de serviço do sistema
 *
 * @copyright Pedro Augusto
 * @copyright Waliff Cordeiro
 */

#include "Dominios.h"
#include "Entidades.h"

class ISAutenticacao {
public:
    virtual bool autenticar(CPF cpf, Senha senha) = 0;
};

class ISEventos {
public:
    virtual bool criarEvento(CPF cpf, Evento evento, list<Apresentacao> listaApresentacao) = 0;

    virtual bool alterarEvento(CPF cpf, Evento evento) = 0;

    virtual bool descadastrarEvento(CPF, Evento) = 0;

    /*Em resposta à consulta, o sistema lista os seguintes dados sobre cada evento que atenda aos requisitos da consulta
     : nome do evento, código de cada apresentação, data de
cada apresentação, horário de cada apresentação, preço do ingresso de cada apresentação, número da sala de cada
apresentação, quantidade de ingressos disponíveis para cada apresentação, classe e faixa etária do evento.
     */
    virtual bool pesquisarEventos(Evento &, Data dataInicio, Data dataTermino, Cidade cidade, Estado estado) = 0;
};

class ISUsuario {
public:
    virtual bool cadastrarUsuario(Usuario usuario, CartaoDeCredito cartaoDeCredito) = 0;

    virtual bool mostrarUsuario(CPF cpf, Usuario *usuario, CartaoDeCredito *cartaoDeCredito) = 0;

    virtual bool excluirUsuario(CPF cpf) = 0;
};


class ISVendas {
public:
    virtual bool adquirirIngresso(CPF cpf, CodigoDeApresentacao codigo, int quantidade) = 0;
};

#endif //TRABALHOTP1_INTERFACES_SERVICOS_H
