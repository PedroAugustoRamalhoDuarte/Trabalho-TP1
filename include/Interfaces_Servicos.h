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
    virtual bool criarEvento(CPF cpf,Evento evento,Apresentacao* lista) = 0;
    virtual bool alterarEvento(CPF cpf, Evento evento) = 0;
    virtual bool descadastrarEvento(CPF, Evento) = 0;
    virtual bool pesquisarEventos(Evento&, Data dataInicio, Data dataTermino, Cidade cidade, Estado estado) = 0;
};

class ISUsuario {
public:
    virtual bool cadastrarUsuario(Usuario usuario, CartaoDeCredito cartaoDeCredito) = 0;
    virtual bool mostrarUsuario(CPF cpf, Usuario* usuario, CartaoDeCredito* cartaoDeCredito) = 0;
    virtual bool excluirUsuario(CPF cpf) = 0;
};


class ISVendas {
public:
    virtual bool adquirirIngresso(CPF cpf, CodigoDeApresentacao codigo,int quantidade) = 0;
};

#endif //TRABALHOTP1_INTERFACES_SERVICOS_H
