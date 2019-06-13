//
// Created by pedro on 13/06/19.
//

#ifndef TRABALHOTP1_MODELAUTENTICACAO_H
#define TRABALHOTP1_MODELAUTENTICACAO_H


#include "Model.h"

class ModelAutenticacao : public Model, public  ISAutenticacao {
public:
    bool autenticar(CPF cpf, Senha senha) override;

    ModelAutenticacao();
};

#endif //TRABALHOTP1_MODELAUTENTICACAO_H
