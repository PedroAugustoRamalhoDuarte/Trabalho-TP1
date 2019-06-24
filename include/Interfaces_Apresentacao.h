#ifndef TRABALHOTP1_INTERFACES_APRESENTACAO_H
#define TRABALHOTP1_INTERFACES_APRESENTACAO_H

/**
 * @file Interfaces_Apresentacao.h
 * @brief Arquivo que define as interfaces de apresentação dos sistema
 *
 * @copyright Pedro Augusto
 * @copyright Waliff Cordeiro
 */

#include "Dominios.h"
#include "Interfaces_Servicos.h"

class IAAutenticacao {
public:

    virtual void executar(CPF *cpf) = 0;

    virtual void setModelAutenticacao(ISAutenticacao *modelAutenticacao) = 0;
};

class IAEventos {
public:

    virtual void executar(CPF cpf) = 0;

    virtual void setModelEventos(ISEventos *modelEventos) = 0;
};

class IAUsuario {
public:
    virtual void executar(CPF *cpf) = 0;

    virtual void setModelUsuario(ISUsuario *modelUsuario) = 0;
};

class IAVendas {
public:
    virtual void executar(CPF cpf) = 0;

    virtual void setModelVendas(ISVendas *modelVendas) = 0;
};

#endif //TRABALHOTP1_INTERFACES_APRESENTACAO_H
