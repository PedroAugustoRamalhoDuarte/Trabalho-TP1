//
// Created by pedro on 06/05/19.
//

#ifndef TRABALHOTP1_INTERFACES_VENDAS_H
#define TRABALHOTP1_INTERFACES_VENDAS_H

#include "Dominios.h"

class IAVendas {
public:
    virtual void executar(CPF cpf) = 0;
    virtual void vendasDoEvento(CodigoDeEvento codigoDeEvento) = 0;
};

class ISVendas {
public:
    virtual bool adquirirIngresso(CPF cpf, CodigoDeApresentacao codigo,int quantidade) = 0;
};

#endif //TRABALHOTP1_INTERFACES_VENDAS_H
