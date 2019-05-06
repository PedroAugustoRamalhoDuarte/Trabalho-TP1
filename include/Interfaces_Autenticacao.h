//
// Created by pedro on 06/05/19.
//

#ifndef TRABALHOTP1_INTERFACES_AUTENTICACAO_H
#define TRABALHOTP1_INTERFACES_AUTENTICACAO_H

#include "Dominios.h"
#include "Entidades.h"

typedef enum {
    ERRO_SENHA = 0,
    ERRO_CONEXAO = 1,
    ERRO_CPF = 2,
    NENHUM = 3

} ERRO_AUTENTICACAO;

class IAAutenticacao {
public:

    virtual bool executar(CPF &cpf) = 0;
};

class ISAutenticacao {
public:
    virtual ERRO_AUTENTICACAO autenticar(CPF cpf, Senha senha) = 0;

};

#endif //TRABALHOTP1_INTERFACES_AUTENTICACAO_H
