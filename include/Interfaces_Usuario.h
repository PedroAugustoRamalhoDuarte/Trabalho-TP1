//
// Created by pedro on 06/05/19.
//

#ifndef TRABALHOTP1_INTERFACES_USUARIO_H
#define TRABALHOTP1_INTERFACES_USUARIO_H


#include "Dominios.h"
#include "Entidades.h"

class IAUsuario {
public:
    virtual void executar(CPF cpf) = 0;
};

class ISUsuario {
public:
    virtual bool cadastrar(Usuario usuario, CartaoDeCredito cartaoDeCredito) = 0;
    virtual bool excluir(CPF cpf) = 0;
};
#endif //TRABALHOTP1_INTERFACES_USUARIO_H
