//
// Created by pedro on 03/06/19.
//

#ifndef TRABALHOTP1_BUILDER_H
#define TRABALHOTP1_BUILDER_H

#include "controladora.h"
#include "viewAutenticacao.h"
#include "viewEventos.h"
#include "viewUsuario.h"
#include "Model.h"
#include "Interfaces_Apresentacao.h"
#include "Interfaces_Servicos.h"

class Builder {
public:
    void build(Controladora* controladora);
};


#endif //TRABALHOTP1_BUILDER_H
