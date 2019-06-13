//
// Created by pedro on 13/06/19.
//

#ifndef TRABALHOTP1_MODELUSUARIO_H
#define TRABALHOTP1_MODELUSUARIO_H


#include "Model.h"

class ModelUsuario : public Model, public ISUsuario {
public:
    bool cadastrarUsuario(Usuario usuario, CartaoDeCredito cartaoDeCredito) override;

    bool mostrarUsuario(CPF cpf, Usuario *usuario, CartaoDeCredito *cartaoDeCredito) override;

    bool excluirUsuario(CPF cpf) override;

    ModelUsuario();
};


#endif //TRABALHOTP1_MODELUSUARIO_H
